#ifndef I2C_H
#define I2C_H
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g0b1/stm32g0b1.h"

// void i2c_init(I2C_peripheral_registers_t volatile * i2c_bus, uint32_t timing, uint8_t self_address);
// bool i2c_transmit(uint8_t targetAddress, uint8_t * txBuf, uint8_t len);
// bool i2c_read(uint8_t targetAddress, uint8_t * rxBuf, uint8_t len);

#ifdef __cplusplus
}
#endif
#endif //I2C_H