# ESP32 I2C OLED display Demo

This project shows that how to use esp32 drive the 128 x 64 OLED display screen

# Hardware Environment
>* ESP32-DevKit
>* 0.96" Inch IIC Serial 128x64 OLED LCD Module

### Pin Map
| ESP32 Pin | OLED Pin | 
| --------   | ----- |
| IO19 | SCL |
| IO18 | SDA |
| 3V3 | VCC |
| GND | GND |-- 
# Configuring the Project

`make menuconfig`

# Compiling and Flash Project

`make -j4 flash`


# Viewing Serial Output

`make monitor`