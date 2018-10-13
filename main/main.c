

#include <stdio.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "esp_log.h"

#include "OLED_I2C.h"
#include "bsp_i2c.h"

static const char *TAG = "main";


void app_main()
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES)
    {
      ESP_ERROR_CHECK(nvs_flash_erase());
      err = nvs_flash_init();
      ESP_ERROR_CHECK(err); 
    }

    i2c_master_init();
    OLED_Init();
    OLED_Fill(0xff);
    OLED_CLS();

    OLED_ShowStr(30, 2, (uint8_t *)"hello world!",2);
    while(1)
    {
        vTaskDelay(5000 / portTICK_RATE_MS);
        ESP_LOGI(TAG, "current heap size:%d", heap_caps_get_free_size(MALLOC_CAP_INTERNAL));
    }
}

