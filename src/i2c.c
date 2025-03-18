// #include "stm32g0b1/i2c.h"

// void
// i2c_init(I2C_peripheral_registers_t volatile * i2c_bus, uint32_t timing, uint8_t self_address)
// {
//     //disable peripheral
//     i2c_bus->cr1.bits = 0;

//     //Configure the time register for Standard mode
//     i2c_bus->timingr.bits = timing;

//     //Configure self address for target mode
//     I2C_oar1_t oar1;
//     i2c_bus->oar1.bits = 0;
//     oar1.bits = i2c_bus->oar1.bits;
//     oar1.oa1 = (self_address << 1);
//     oar1.oa1mode = BIT_CLEAR;
//     oar1.oa1en = BIT_SET;
//     i2c_bus->oar1.bits = oar1.bits;

//     i2c_bus->oar2.bits = 0;

//     //Configure control register
//     i2c_bus->cr2.bits = 0;
//     I2C_cr2_t cr2;
//     cr2.bits = i2c_bus->cr2.bits;
//     cr2.autoend = BIT_SET;
//     i2c_bus->cr2.bits = cr2.bits;

//     //enable peripheral
//     I2C_cr1_t cr1;
//     cr1.bits = i2c_bus->cr1.bits;
//     i2c_bus->icr.bits = 0;
//     cr1.pe = BIT_SET;
//     i2c_bus->cr1.bits = cr1.bits;
// }

// bool
// i2c_transmit(uint8_t targetAddress, uint8_t * txBuf, uint8_t len)
// {
//     //Todo: add timer for timeout
//     while(I2C->isr.busy != BIT_CLEAR);
//     I2C_cr2_t cr2;
// 	cr2.bits = I2C->cr2.bits;

// 	cr2.sadd = (targetAddress << 1);
// 	cr2.rd_wrn = BIT_CLEAR; //0 = write mode
// 	cr2.nbytes = len;
// 	cr2.autoend = BIT_SET;
// 	cr2.start = BIT_SET;

//     I2C->cr2.bits = cr2.bits;

//     for (uint8_t i = 0; i < len; i++)
//     {
//         //Todo: add timer for timeout
//         while (I2C->isr.txis != 1);
//         I2C->txdr.txdata = txBuf[i];
//     }
//     return true;

// }

// bool
// i2c_read(uint8_t targetAddress, uint8_t * rxBuf, uint8_t len)
// {
//     I2C_cr2_t cr2;
// 	cr2.bits = I2C->cr2.bits;

// 	cr2.sadd = (targetAddress << 1);
// 	cr2.rd_wrn = BIT_SET; //1 = read mode
// 	cr2.nbytes = len;
// 	cr2.autoend = BIT_SET;
// 	cr2.start = BIT_SET;

//     I2C->cr2.bits = cr2.bits;

//     for (uint8_t i = 0; i < len; i++)
//     {
//         //Todo: add timer for timeout
//         while (I2C->isr.rxne != BIT_SET);
//         rxBuf[i] = I2C->rxdr.rxdata;
//     }
//     return true;
// }