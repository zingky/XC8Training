#include "mmc_spi.h"
#include "mcc_generated_files/mcc.h"
#define MMC_DEBUG printf
#define mmc_read_disable() mmc_stop_transmission()
#define nCS_SetLow()    MMC_CS_SetLow()

mmc_state_t mmc_state;

MMC_EC mmc_init(void)
{
    int16_t result;
    int8_t to=50;

    mmc_state=MMC_STARTUP_STATE;

    MMC_CS_SetHigh();
    MMC_DO_SetHigh(); // set pin levels
    MMC_CLK_SetHigh();

    __delay_ms(15);

    do
    {
        nCS_SetLow();
        result=mmc_send_cmd(MMC_CMD_GO_IDLE_STATE, 0, 1);
        nCS_SetHigh();
        if(result==1) break;
        else
        {
            __delay_ms(10);
            to--;
        }
    }
    while(to);

    if(result!=1)
    {
        MMC_DEBUG(" ERR: after reset, device isn't idle");
        return (MMC_EC_NOT_IDLE);
    }

    to=50;

    do
    {
        nCS_SetLow();
        result=mmc_send_cmd(MMC_CMD_SEND_OP_COND, 0, 1); // puts card into ready state
        nCS_SetHigh();
        if(result&&(result!=1))
        {
            MMC_DEBUG(" ERR: after init we got a funky error %LX", result);
            return (MMC_EC_NOT_INIT);
        }
        else if(result==1)
        {
            to--;
            __delay_ms(1);
        }
        else break;
    }
    while(to); // loop until not busy

    MMC_DEBUG(" init cmd returns: %X\n\r", result);

    nCS_SetLow();
    result=mmc_send_cmd(MMC_CMD_CRC_ON_OFF, 0, 1);
    nCS_SetHigh();
    if(result)
    {
        MMC_DEBUG(" ERR: CRC didn't turn off");
        return (MMC_EC_NO_CRC);
    }

    mmc_state=MMC_STANDBY_STATE; // set current state
    return (MMC_EC_OK);
}

MMC_EC mmc_modify_block(int32_t address, int16_t size, int *ptr)
{
    int8_t mmc_buffer[MMC_BLOCK_SIZE];
    int val;
    int16_t i;
    int32_t block_start;
    int16_t num;
    MMC_EC res;

    val=0;
    block_start=address&0xFFFFFE00;
    i=address-block_start;

    while(size)
    {
        res=mmc_read_block(block_start, MMC_BLOCK_SIZE, mmc_buffer);
        if(res)
        {
            MMC_DEBUG(" cannot read 512 byte block.  nothing written! \n\r");
            return (res);
        }

        MMC_DEBUG(" read 512\r\n");

        if((size+i)>MMC_BLOCK_SIZE) num=MMC_BLOCK_SIZE-i;
        else num=size;

        memcpy(&mmc_buffer[i], ptr, num);

        res=mmc_write_block(block_start, MMC_BLOCK_SIZE, mmc_buffer);
        if(res)
        {
            MMC_DEBUG(" cannot write MMC_BLOCK_SIZE byte block\r\n");
            return (res);
        }
        MMC_DEBUG(" 512 written\r\n");

        ptr+=num;
        block_start+=MMC_BLOCK_SIZE;
        size-=num;
        i=0;
    }
    return (MMC_EC_OK);
}

MMC_EC mmc_modify_byte(int32_t address, int8_t val)
{
    return (mmc_modify_block(address, 1, &val));
}

MMC_EC mmc_write_block(int32_t address, int16_t size, int *ptr)
{
    int16_t j;
    int8_t val;
    int8_t res;

    nCS_SetLow();
    res=mmc_send_cmd(MMC_CMD_SET_BLOCKLEN, MMC_BLOCK_SIZE, 1);
    nCS_SetHigh();
    if(res)
    {
        MMC_DEBUG(" set block size failed\n\r");
        return (MMC_EC_SET_WRITE_BLOCKSIZE_FAIL);
    }

    nCS_SetLow();
    res=mmc_send_cmd(MMC_CMD_WRITE_BLOCK, address, 1); // command to write byte at address
    if(res)
    {
        MMC_DEBUG(" write byte failed.  Nothing written!\n\r");
        nCS_SetHigh();
        return (MMC_EC_SET_WRITE_ADDRESS_FAIL);
    }

    mmc_send_data(0xFF); // send nothing for 8 bits
    mmc_send_data(0xFE); // send start bit

    for(j=0; j<MMC_BLOCK_SIZE; j++)
    {
        if(size)
        {
            val=*ptr;
            ptr++;
            size--;
        }
        else val=0;
        mmc_send_data(val); // writes the byte
    }
    mmc_send_data(0xFF); //crc
    mmc_send_data(0xFF); //crc
    val=mmc_read_data() & 0x1F;

    MMC_DEBUG(" write data returned:  %X\n\r", val);

    if(!mmc_wait_for_not_busy(1000))
    {
        MMC_DEBUG(" ERR: mmc spi is busy\r\n");
        return (MMC_EC_WRITE_ALWAYS_BUSY);
    }

    nCS_SetHigh();

    if(val!=5) // if not stored correctly
    {
        MMC_DEBUG(" data not stored\n\r");
        return (MMC_EC_BLOCK_NOT_WRITTEN);
    }

    MMC_DEBUG(" data was stored\n\r");

    return (MMC_EC_OK);
}

MMC_EC mmc_read_block(int32_t address, int16_t block_size, int *ptr)
{
    int16_t result;

    nCS_SetLow();
    result=mmc_send_cmd(MMC_CMD_SET_BLOCKLEN, block_size, 1);
    nCS_SetHigh();
    if(result)
    { // sets the block size
        MMC_DEBUG(" ERR: couldn't set read block size\r\n");
        return (MMC_EC_SET_READ_BLOCKSIZE_FAIL);
    }

    nCS_SetLow();
    result=mmc_send_cmd(MMC_CMD_READ_SINGLE_BLOCK, address, 1);
    if(result) // command to read byte at address
    {
        nCS_SetHigh();
        MMC_DEBUG(" ERR: couldnt set read address\r\n");
        return (MMC_EC_SET_READ_ADDRESS_FAIL);
    }

    mmc_receive_data(ptr, block_size);

    nCS_SetHigh();
    return (MMC_EC_OK);
}

MMC_EC mmc_erase(int32_t address, int32_t sectors)
{
    int32_t sector_start;
    int32_t sector_end;
    int8_t res;

    if(sectors)
    {
        sector_start=address/MMC_BLOCK_SIZE;
        sector_end=sector_start+sectors-1;

        nCS_SetLow();
        res=mmc_send_cmd(MMC_CMD_TAG_SECTOR_START, sector_start, 1);
        nCS_SetHigh();
        if(res) return (MMC_EC_ERASE_SECTOR_START_FAIL);

        nCS_SetLow();
        res=mmc_send_cmd(MMC_CMD_TAG_SECTOR_END, sector_end, 1);
        nCS_SetHigh();
        if(res) return (MMC_EC_ERASE_SECTOR_END_FAIL);

        nCS_SetLow();
        res=mmc_send_cmd(MMC_CMD_ERASE, 0, 1);
        nCS_SetHigh();
        if(res) return (MMC_EC_ERASE_SECTORS_FAIL);
    }
    return (MMC_EC_OK);
}

MMC_EC mmc_read_enable(int32_t address, int16_t block_size)
{
    int16_t ret;

    if(mmc_state!=MMC_STANDBY_STATE)
    { // make sure not currently in other state
        MMC_DEBUG(" ERR: not in good state for multi-read\r\n");
        return (MMC_EC_BAD_STATE);
    }

    mmc_state=MMC_READ_STATE; // set to correct state
    mmc_blk_size=block_size;

    nCS_SetLow();
    ret=mmc_send_cmd(MMC_CMD_SET_BLOCKLEN, block_size, 1);
    nCS_SetHigh();
    if(ret)
    { // sets the block size
        MMC_DEBUG(" ERR: multi read didnt set block\r\n");
        return (MMC_EC_SET_MULTI_BLOCKSIZE_FAIL);
    }

    nCS_SetLow();
    ret=mmc_send_cmd(MMC_CMD_READ_MULTITPLE_BLOCK, address, 1);
    if(ret)
    { // sets the address to read from
        MMC_DEBUG(" ERR: doesnt like multi read\r\n");
        nCS_SetHigh();
        return (MMC_EC_START_MULTI_READ_FAIL);
    }

    return (MMC_EC_OK);
}

MMC_EC mmc_read_mult_block(int *ptr)
{
    if(mmc_state!=MMC_READ_STATE)
    { // check for correct state
        MMC_DEBUG(" err: bad state\r\n");
        return (MMC_EC_BAD_STATE);
    }

    if(!mmc_receive_data(ptr, mmc_blk_size))
    {
        MMC_DEBUG(" err: cant read multi block\r\n");
        nCS_SetHigh();
        return (MMC_EC_READ_NEXT_BLOCK_FAIL);
    }

    return (MMC_EC_OK);
}

MMC_EC mmc_stop_transmission(void)
{
    int8_t res;
    mmc_state=MMC_STANDBY_STATE;

    res=mmc_send_cmd(MMC_CMD_STOP_TRANSMISSION, 0, 1);
    nCS_SetHigh();

    return (MMC_EC_OK);
}

int16_t mmc_send_cmd(int cmd, int32_t arg, int8_t mode)
{
    int i;
    int out[6];
    int8_t to=50;
    int8_t bits;

    if(!mmc_wait_for_not_busy(50))
    {
        MMC_DEBUG(" ERR: mmc spi is busy\r\n");
        mmc_last_result=0xFFFF;
        return (mmc_last_result);
    }

    out[0]=cmd|0x40; // bits 47 to 40
    out[4]=make8(arg, 0); // bits 15 to 8
    out[3]=make8(arg, 1); // bits 23 to 16
    out[2]=make8(arg, 2); // bits 31 to 24
    out[1]=make8(arg, 3); // bits 39 to 32
    if(cmd==0) out[5]=0x95;
    else out[5]=0xFF; //ignore the CRC

    for(i=0; i<6; i++) mmc_send_data(out[i]);

    MMC_DEBUG("\n\r sent cmd %U, arg %LU\n\r", cmd, arg);

    if(!mode) return (0);

    if(mode==1) bits=8;
    else if(mode==2) bits=16;
    else if(mode==3) bits=48;
    else bits=0;

    for(i=0; i<5; i++) out[i]=0;

    i=0;

    do
    {
        i++;
        mmc_delay_clk();
        MMC_CLK_SetLow();
        mmc_delay_clk();
        MMC_CLK_SetHigh();
    }
    while((MMC_DI_GetValue())&&(to--));

    if(MMC_DI_GetValue())
    {
        MMC_DEBUG(" err: no start bit waiting for response\r\n");
        mmc_last_result=0xFFFE;
        return (mmc_last_result);
    }


    shift_left(out, 5, MMC_DI_GetValue()); // input start bit = '0'
    mmc_delay_clk();

    for(i=0; i<(bits-1); i++)
    {
        MMC_CLK_SetLow();
        shift_left(out, 5, MMC_DI_GetValue());
        mmc_delay_clk();
        MMC_CLK_SetHigh();
        mmc_delay_clk();
    }

    MMC_DEBUG(" i=%U\r\n", i);
    MMC_DEBUG(" cmd data in = %x", out[0]);

    /*
       do {
          out[0]=mmc_read_data();
       } while ((bit_test(out[0],7))&&(to--));

       MMC_DEBUG(" cmd data in = %x", out[0]);

       if (mode==2) {
          out[1]=mmc_read_data();
       }
       if (mode==3) {
          out[2]=mmc_read_data();
          out[3]=mmc_read_data();
          out[4]=mmc_read_data();
       }
     */

    if(mode==1)
    {
        MMC_DEBUG("\r\n");
        mmc_last_result=out[0];
    }
    else if(mode==2)
    {
        MMC_DEBUG(", %x\r\n", out[1]);
        mmc_last_result=make16(out[1], out[0]); //not tested
    }
    else if(mode==3)
    {
        MMC_DEBUG("\r\n");
        mmc_last_result=out[0]; //not tested
    }

    return (mmc_last_result);
}

void mmc_spi_exchange(int8_t out, int8_t *in)
{
    int8_t i;

    for(i=0; i<8; i++)
    {
        MMC_CLK_SetLow();
        output_bit(MMC_DO,(&out, 1, 0));
        mmc_delay_clk();
        shift_left(in, 1, MMC_DI_GetValue());
        MMC_CLK_SetHigh();
        mmc_delay_clk();
    }
}

void mmc_send_data(int8_t data)
{
    int8_t null;
    mmc_spi_exchange(data, &null);
}

int8_t mmc_read_data(void)
{
    int8_t ret;
    mmc_spi_exchange(0xFF, &ret);
    return (ret);
}

void nCS_SetHigh(void)
{
    mmc_send_data(0xFF); //send 8 clocks for MMC to get ready for next command
    MMC_CS_SetHigh();
}

bool mmc_wait_for_not_busy(int16_t to)
{
    int8_t i;

    do
    {
        for(i=0; i<8; i++)
        {
            mmc_delay_clk();
            MMC_CLK_SetLow();
            mmc_delay_clk();
            MMC_CLK_SetHigh();
        }
    }
    while((!MMC_DI_GetValue())&&(to--));

    if(MMC_DI_GetValue())
        return (true);

    return (false);
}

bool mmc_receive_data(int8_t *ptr, int16_t size)
{
    int8_t to=50;
    int16_t i;

    do
    {
        if(mmc_read_data()==0xFE)
            break;
        else
        {
            to--;
            __delay_ms(1);
            if(!to)
            {
                MMC_DEBUG(" ERR: didnt get repsone when reading\r\n");
                return (false);
            }
        }
    }
    while(to);

    for(i=0; i<size; i++)
    {
        *ptr=mmc_read_data(); // reads each byte
        ptr++;
    }
    mmc_read_data();
    mmc_read_data();

    return (true);
}
