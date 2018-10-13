

#include "bsp_i2c.h"
#include "OLED_I2C.h"

#include "esp_err.h"

#define SCL_PIN          19               /*!< gpio number for I2C master clock */
#define SDA_PIN          18               /*!< gpio number for I2C master data  */
#define WRITE_BIT        I2C_MASTER_WRITE /*!< I2C master write */
#define ACK_CHECK_EN     0x1              /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS    0x0              /*!< I2C master will not check ack from slave */
#define ACK_VAL          0x0              /*!< I2C ack value */
#define NACK_VAL         0x1              /*!< I2C nack value */

#define OLED_ADDR  0x78



esp_err_t i2c_write(i2c_port_t i2c_num, uint8_t* data_wr, size_t size)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, OLED_ADDR, ACK_CHECK_EN);
    i2c_master_write(cmd, data_wr, size, ACK_CHECK_EN);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(i2c_num, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}


void i2c_master_init(void)
{
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = SDA_PIN;
    conf.scl_io_num = SCL_PIN;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = 100000;
    i2c_param_config(I2C_NUM_0, &conf);
    i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);
}