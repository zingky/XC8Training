#include "BLD.h"
                                                                                // <editor-fold defaultstate="collapsed" desc="BOOTLOADER SECURITY INFO">
#define ACCESSKEY_LEN   8                                                       // Length of access key
const uint8_t ACCESSKEY[ACCESSKEY_LEN]="12345678";                              // Bootloader access code
const uint8_t PVID[9]="UMB16001";                                               // Device name and firmware version
                                                                                // </editor-fold>
//void interrupt ISRCode(void)                                                    // <editor-fold defaultstate="collapsed" desc="Interrupt Porting">
//{
//    asm("LJMP 0x0020");
//}                                                                               // </editor-fold>

void main()                                                                     // <editor-fold defaultstate="collapsed" desc="Main function">
{
                                                                                // <editor-fold defaultstate="collapsed" desc="System Init">
    SYSTEM_Initialize();                                                        // Oscillator, timer, uart, spi, gpio init
    Delay_Init();                                                               // Delay using tick timer service init
    Delay_ms(100);                                                              // Waiting for system stabling
                                                                                // </editor-fold>
                                                                                // <editor-fold defaultstate="collapsed" desc="Bootloader Init">
    Task.Prev=ENTER_BLD_MODE;
    Task.Next=INIT;
    Hex.Addr.ELin=0;
    Tick_Reset(Tick.Led);                                                       // Reset status led tick
                                                                                // </editor-fold>
                                                                                // <editor-fold defaultstate="collapsed" desc="Infinite Loop">
    while(1)
    {
        CLRWDT();                                                               // Reset WDT
        if(Tick_Is_Over(&Tick.Led, 500)) STT_LED_Toggle();                      // Toggle LED every 1s, handling

        switch(Task.Next)
        {
            case INIT:                                                          // <editor-fold defaultstate="collapsed" desc="Reset buffer counter">
                Tick_Reset(Tick.RxTout);
                Tick_Reset(Tick.BldTout);
                Buf.Len=0;
                Task.Next=GET_DATA;
                break;                                                          // </editor-fold>

            case GET_DATA:                                                      // <editor-fold defaultstate="collapsed" desc="Get UART data">
                if(UART_RX(&Buf.Dat[Buf.Len]))                                  // Check received data
                {
                    if(Buf.Dat[Buf.Len]=='\r') Task.Next=Task.Prev;             // Check frame stop character
                    else if(Buf.Len>45) Task.Next=REP_ERROR;                    // Data isn't over 45 bytes in one frame
                    else Buf.Len++;                                             // Increate buffer index
                    Tick_Reset(Tick.RxTout);
                    Tick_Reset(Tick.BldTout);
                }
                else if((Buf.Len>0)&&Tick_Is_Over(&Tick.RxTout, 100))           // Check no received data in 100ms
                    Task.Next=REP_ERROR;
                else if(Tick_Is_Over(&Tick.BldTout, 1500)) Task.Next=DEFAULT;   // Check empty buffer in 1500ms 
                break;                                                          // </editor-fold>

            case ENTER_BLD_MODE:                                                // <editor-fold defaultstate="collapsed" desc="Enter to bootloader mode">
                for(i=0; i<ACCESSKEY_LEN; i++)                                  // Check access key
                {
                    if(Buf.Dat[i]!=ACCESSKEY[i])
                    {
                        Task.Next=INIT;
                        break;
                    }
                }
                if(Task.Next!=INIT)                                             // If access key is accepted
                {
                    UART_Puts((uint8_t *) PVID);                                // Send device info
                    Hex.Addr.ELin=0;
                    Task.Prev=CONVERT;
                    Task.Next=REP_SUCCESS;
                }
                break;                                                          // </editor-fold>

            case CONVERT:                                                       // <editor-fold defaultstate="collapsed" desc="Convert received data to byte">
                // Data before convert: [@][BC=2][Addr=4][Rec=2][Data=2n][CRC=2]
                //                       0  1,2   3...6    7,8    9...    9+2n
                Buf.Len--;
                if(Buf.Dat[0]=='@')
                {
                    for(i=1, j=0; i<Buf.Len; i+=2, j++)
                    {
                        Buf.Dat[i]-='A';
                        Buf.Dat[i+1]-='A';
                        Buf.Dat[j]=(Buf.Dat[i]<<4)|Buf.Dat[i+1];
                    }
                    Buf.Len=j;
                    Task.Next=CHECKSUM;
                }
                else Task.Next=REP_ERROR;
                break;                                                          // </editor-fold>

            case CHECKSUM:                                                      // <editor-fold defaultstate="collapsed" desc="Checksum">
                for(i=0; i<Buf.Len; i++)
                    Buf.Dat[Buf.Len-1]=(uint8_t) Buf.Dat[Buf.Len-1]+Buf.Dat[i];
                if(Buf.Dat[Buf.Len-1]==0)                                       // If checksum is true, get hex parameters
                {
                    // Data after convert: [BC=1][Addr=2][Rec=1][Data=n][CRC=1]
                    //                       0     1,2     3    4...     4+n
                    Hex.Data.BCount=Buf.Dat[0];                                 // Get byte count
                    Hex.Addr.Phy=Make168a(&Buf.Dat[1]);                         // Get address
                    Hex.RecType=Buf.Dat[3];                                     // Get record type
                    for(i=0; i<Hex.Data.BCount; i+=2)                           // Arrange data to Big endian
                    {
                        Buf.Dat[i]=Buf.Dat[i+5];
                        Buf.Dat[i+1]=Buf.Dat[i+4];
                    }
                    for(i=Hex.Data.BCount; i<32; i++) Buf.Dat[i]=0xFF;          // Add to full block
                    Task.Next=PROGRAM;
                }
                else Task.Next=REP_ERROR;
                break;                                                          // </editor-fold>

            case PROGRAM:                                                       // <editor-fold defaultstate="collapsed" desc="Write data to user's application memory">
                Task.Next=REP_SUCCESS;
                switch(Hex.RecType)
                {
                    case DATA_RECORD:
                        Hex.Addr.Phy=((Hex.Addr.Phy+Hex.Addr.ELin)>>1);         // Writing address=(present address+ ext_address)/2
                        if(Hex.Addr.Phy<=0x0004)                                // Backup Reset vector
                        {
                            uint16_t backup=FLASH_ReadWord(0x0000);
                            Buf.Dat[0]=(uint8_t) (backup>>8);
                            Buf.Dat[1]=(uint8_t) backup;
                        }
                        if(Hex.Addr.Phy<=APP_STOP_ADDR) 
                            FLASH_WriteBlock(Hex.Addr.Phy, Buf.Dat);
                        break;

                    case EXT_LIN_ADRS_RECORD:
                        Hex.Addr.ELin=Make168a(&Buf.Dat[4]);
                        Hex.Addr.ELin<<=16;
                        break;

                    default:
                        break;
                }
                break;                                                          // </editor-fold>

            case REP_SUCCESS:                                                   // <editor-fold defaultstate="collapsed" desc="Success report">
                UART_TX('Y');
                Task.Next=INIT;
                break;                                                          // </editor-fold>

            case REP_ERROR:                                                     // <editor-fold defaultstate="collapsed" desc="Error report">
                UART_TX('N');
                Task.Next=INIT;
                break;                                                          // </editor-fold>

            default:                                                            // <editor-fold defaultstate="collapsed" desc="Check valid user's application">
                Task.Prev=ENTER_BLD_MODE;
                Task.Next=INIT;
                break;                                                          // </editor-fold>
        }
    }                                                                           // </editor-fold>
}// </editor-fold>