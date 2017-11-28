#ifndef MSSP_I2C_MASTER_H
#define	MSSP_I2C_MASTER_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

void I2C_Init();                                                                //Call this function before the others
void I2C_Start();                                                               //I2C start
void I2C_Stop();                                                                //I2C stop
uint8_t I2C_Read(bool ack);                                                     //Read a byte with ack bit
void I2C_Write(uint8_t data_out);                                               //Write a byte to I2C

#endif