#include "./USB/usb.h"
#include "./USB/usb_function_cdc.h"
#include "HardwareProfile.h"

__CONFIG(FOSC_INTOSC & WDTE_OFF & PWRTE_ON & MCLRE_OFF & CP_OFF & BOREN_ON & CLKOUTEN_OFF & IESO_OFF & FCMEN_OFF);
__CONFIG(WRT_OFF & CPUDIV_NOCLKDIV & USBLSCLK_48MHz & PLLMULT_3x & PLLEN_ENABLED & STVREN_ON & BORV_LO & LPBOR_OFF & LVP_ON);

#include "GenericTypeDefs.h"
#include "Compiler.h"
#include "usb_config.h"
#include "USB/usb_device.h"
#include "USB/usb.h"
#include "HardwareProfile.h"
#include <stdbool.h>
#include <stdint.h>

char USB_Out_Buffer[CDC_DATA_OUT_EP_SIZE];
char RS232_Out_Data[CDC_DATA_IN_EP_SIZE];

uint8_t NextUSBOut;
uint8_t NextUSBOut;
uint8_t LastRS232Out; // Number of characters in the buffer
uint8_t RS232cp; // current position within the buffer
uint8_t RS232_Out_Data_Rdy=0;
USB_HANDLE lastTransmission;
uint8_t sending=0;
uint8_t receiving=0;

static void InitializeSystem(void);
void ProcessIO(void);
void USBDeviceTasks(void);
void YourHighPriorityISRCode();
void YourLowPriorityISRCode();
void USBCBSendResume(void);
void BlinkUSBStatus(void);
void UserInit(void);
void InitializeUSART(void);
void putcUSART(char c);
uint8_t getcUSART();

void interrupt ISRCode()
{
    USBDeviceTasks();
}

int main(void)
{
    InitializeSystem();
    USBDeviceAttach();
    while(1) ProcessIO();
}

static void InitializeSystem(void)
{
    ANSELA=0x00;
    ANSELC=0x00;
    OSCTUNE=0;
    OSCCON=0xFC; //16MHz HFINTOSC with 3x PLL enabled (48MHz operation)
    ACTCON=0x90; //Enable active clock tuning with USB
    UserInit();
    USBDeviceInit(); //usb_device.c.  Initializes USB module SFRs and firmware
}

void UserInit(void)
{
    uint8_t i;
    InitializeUSART();
    for(i=0; i<sizeof (USB_Out_Buffer); i++) USB_Out_Buffer[i]=0;
    NextUSBOut=0;
    LastRS232Out=0;
    lastTransmission=0;
    mInitAllLEDs();
}

void InitializeUSART(void)
{
    uint8_t c;

    UART_TRISRx=1; // RX
    UART_TRISTx=0; // TX
    TXSTA=0x24; // TX enable BRGH=1
    RCSTA=0x90; // Single Character RX
    SPBRG=0x71;
    SPBRGH=0x02; // 0x0271 for 48MHz -> 19200 baud
    BAUDCON=0x08; // BRG16 = 1
    c=RCREG; // read
}


#define mDataRdyUSART() PIR1bits.RCIF
#define mTxRdyUSART()   TXSTAbits.TRMT

void putcUSART(char c)
{
    TXREG=c;
    sending=1;
}

#if defined(USB_CDC_SET_LINE_CODING_HANDLER)

void mySetLineCodingHandler(void)
{
    if(cdc_notice.GetLineCoding.dwDTERate.Val>115200);
    else
    {
        //Update the baudrate info in the CDC driver
        CDCSetBaudRate(cdc_notice.GetLineCoding.dwDTERate.Val);
        //Update the baudrate of the UART
        DWORD_VAL dwBaud;
        dwBaud.Val=(DWORD) (GetSystemClock()/4)/line_coding.dwDTERate.Val-1;
        SPBRG=dwBaud.v[0];
        SPBRGH=dwBaud.v[1];
    }
}
#endif

uint8_t getcUSART()
{
    char c;

    if(RCSTAbits.OERR) // in case of overrun error
    { // we should never see an overrun error, but if we do,
        RCSTAbits.CREN=0; // reset the port
        c=RCREG;
        RCSTAbits.CREN=1; // and keep going.
    }
    else c=RCREG;
    receiving=1;
    return c;
}

void ProcessIO(void)
{
    //Blink the LEDs according to the USB device status
    BlinkUSBStatus();
    // User Application USB tasks
    if((USBDeviceState<CONFIGURED_STATE)||(USBSuspendControl==1)) return;
    if(RS232_Out_Data_Rdy==0) // only check for new USB buffer if the old RS232 buffer is
    { // empty.  This will cause additional USB packets to be NAK'd
        LastRS232Out=getsUSBUSART(RS232_Out_Data, 64); //until the buffer is free.
        if(LastRS232Out>0)
        {
            RS232_Out_Data_Rdy=1; // signal buffer full
            RS232cp=0; // Reset the current position
        }
    }
    //Check if one or more bytes are waiting in the physical UART transmit
    //queue.  If so, send it out the UART TX pin.
    if(RS232_Out_Data_Rdy&&mTxRdyUSART())
    {
        //Hardware flow control not being used.  Just send the data.
        putcUSART(RS232_Out_Data[RS232cp]);
        ++RS232cp;
        if(RS232cp==LastRS232Out) RS232_Out_Data_Rdy=0;
    }
    //Check if we received a character over the physical UART, and we need
    //to buffer it up for eventual transmission to the USB host.
    if(mDataRdyUSART() && (NextUSBOut<(CDC_DATA_OUT_EP_SIZE-1)))
    {
        USB_Out_Buffer[NextUSBOut]=getcUSART();
        ++NextUSBOut;
        USB_Out_Buffer[NextUSBOut]=0;
    }
    if((USBUSARTIsTxTrfReady()) && (NextUSBOut>0))
    {
        putUSBUSART(&USB_Out_Buffer[0], NextUSBOut);
        NextUSBOut=0;
    }
    CDCTxService();
}

void BlinkUSBStatus(void)
{
    static WORD led_count=0;

    if(led_count==0)led_count=10000U;
    led_count--;

#define mLED_Both_Off()         {mLED_1_Off();mLED_2_Off();}
#define mLED_Both_On()          {mLED_1_On();mLED_2_On();}
#define mLED_Only_1_On()        {mLED_1_On();mLED_2_Off();}
#define mLED_Only_2_On()        {mLED_1_Off();mLED_2_On();}

    if(USBSuspendControl==1)
    {
        if(led_count==0)
        {
            mLED_1_Toggle();
            if(mGetLED_1()) mLED_2_On();
            else mLED_2_Off();
        }//end if
    }
    else
    {
        if(USBDeviceState==DETACHED_STATE)
        {
            mLED_Both_Off();
        }
        else if(USBDeviceState==ATTACHED_STATE)
        {
            mLED_Both_On();
        }
        else if(USBDeviceState==POWERED_STATE)
        {
            mLED_Only_1_On();
        }
        else if(USBDeviceState==DEFAULT_STATE)
        {
            mLED_Only_2_On();
        }
        else if(USBDeviceState==ADDRESS_STATE)
        {
            if(led_count==0)
            {
                mLED_1_Toggle();
                mLED_2_Off();
            }//end if
        }
        else if(USBDeviceState==CONFIGURED_STATE)
        {
            if(led_count==0)
            {
                if(UART_DTR)
                { // no DTR
                    if(mGetLED_1())
                    {
                        mLED_1_Off();
                        receiving=0;
                    }
                    else if(receiving)
                        mLED_1_On();
                }
                else
                { // DTR
                    if(!mGetLED_1())
                    {
                        mLED_1_On();
                        receiving=0;
                    }
                    else if(receiving)
                        mLED_1_Off();
                }
                if(mGetLED_2())
                {
                    mLED_2_Off();
                    sending=0;
                }
                else if(sending)
                    mLED_2_On();
            }
        }
    }
}

void USBCBSuspend(void)
{

}

void USBCBWakeFromSuspend(void)
{

}

void USBCB_SOF_Handler(void)
{

}

void USBCBErrorHandler(void)
{

}

void USBCBCheckOtherReq(void)
{
    USBCheckCDCRequest();
}

void USBCBStdSetDscHandler(void)
{

}

void USBCBInitEP(void)
{
    CDCInitEP();
}

void USBCBSendResume(void)
{
    static WORD delay_count;

    if(USBGetRemoteWakeupStatus()==true)
    {
        if(USBIsBusSuspended()==true)
        {
            USBMaskInterrupts();
            USBCBWakeFromSuspend();
            USBSuspendControl=0;
            USBBusIsSuspended=false;
            delay_count=3600U;
            do delay_count--;
            while(delay_count);
            USBResumeControl=1; // Start RESUME signaling
            delay_count=1800U; // Set RESUME line for 1-13 ms
            do delay_count--;
            while(delay_count);
            USBResumeControl=0; //Finished driving resume signalling
            USBUnmaskInterrupts();
        }
    }
}

BOOL USER_USB_CALLBACK_EVENT_HANDLER(int event, void *pdata, WORD size)
{
    switch(event)
    {
        case EVENT_TRANSFER:
            //Add application specific callback task or callback function here if desired.
            break;
        case EVENT_SOF:
            USBCB_SOF_Handler();
            break;
        case EVENT_SUSPEND:
            USBCBSuspend();
            break;
        case EVENT_RESUME:
            USBCBWakeFromSuspend();
            break;
        case EVENT_CONFIGURED:
            USBCBInitEP();
            break;
        case EVENT_SET_DESCRIPTOR:
            USBCBStdSetDscHandler();
            break;
        case EVENT_EP0_REQUEST:
            USBCBCheckOtherReq();
            break;
        case EVENT_BUS_ERROR:
            USBCBErrorHandler();
            break;
        case EVENT_TRANSFER_TERMINATED:
            break;
        default:
            break;
    }
    return true;
}