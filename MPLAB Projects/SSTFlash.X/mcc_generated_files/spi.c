#include <xc.h>
#include "spi.h"
#include "pin_manager.h"

void SPI_Initialize(void)
{
    // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP Middle; UA dontupdate; CKE Active to Idle; D_nA lastbyte_address; 
    SSPSTAT = 0x40;
    // SSPEN enabled; WCOL no_collision; CKP Idle:Low, Active:High; SSPM0 FOSC/4; SSPOV no_overflow; 
    SSPCON1 = 0x20;
    // SSPADD 0; 
    SSPADD = 0x00;
}

uint8_t SPI_RW(uint8_t data)
{
    SSPCON1bits.WCOL = 0;
    SSPBUF = data;
    while(SSPSTATbits.BF == 0);
    return (SSPBUF);
}

void SPI_Xfer(bool enCS, uint8_t *data, uint8_t lenIn, uint8_t lenOut, bool dnCS)
{
    uint8_t i;
    if(enCS) FCS_SetLow();
    for(i=0; i<lenIn; i++) SPI_RW(data[i]);
    for(i=0; i<lenOut; i++) data[i]=SPI_RW(0xFF);
    if(dnCS) FCS_SetHigh();
}