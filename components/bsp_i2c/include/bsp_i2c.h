

#ifndef _BSP_I2C_H_
#define _BSP_I2C_H_
#include "driver/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

void i2c_master_init(void);
esp_err_t i2c_read(i2c_port_t i2c_num, uint8_t* data_rd, size_t size);
esp_err_t i2c_write(i2c_port_t i2c_num, uint8_t* data_wr, size_t size);

#ifdef __cplusplus
}
#endif

#endif