// =========================================================================
// Released under the MIT License
// Copyright 2017-2018 Natanael Josue Rabello. All rights reserved.
// For the license information refer to LICENSE file in root directory.
// =========================================================================

/**
 * @file mpu_i2c.cpp
 * Example on how to setup MPU through I2C for basic usage.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "esp_log.h"
#include "sdkconfig.h"

#include "zk_i2c.h"
#include "hw_motors_impl.hpp"
#include "position_unit.h"
#include "serial.h"

static const char *TAG = "Main task";

#define ESP_RETURN_RES_ON_ERROR(x) do {\
    esp_err_t res = (x);\
    if (res != ESP_OK) return res;\
    } while(0)


static esp_err_t start_mpu(void)
{
    ESP_RETURN_RES_ON_ERROR(i2c_master_init(GPIO_NUM_21, GPIO_NUM_19, 100000));
    ESP_RETURN_RES_ON_ERROR(mpu_init());
    ESP_LOGI(TAG, "MPU ready!");
    return ESP_OK;
}

static esp_err_t start_i2c_slave(void)
{
    uint8_t addr = 0x2a;
    i2c_slave_init(GPIO_NUM_13, GPIO_NUM_12, addr);
    ESP_LOGI(TAG, "I2C slave ready! Address: 0x%x", addr);
    return ESP_OK;
}

static void start_motors(void){
        motors.MoveForward(100);
        // vTaskDelay(100 / portTICK_RATE_MS);
        motors.Stop(150);
        // vTaskDelay(150 / portTICK_RATE_MS);
        motors.MoveLeft(150);
        // vTaskDelay(150 / portTICK_RATE_MS);
        motors.Stop(150);
        // vTaskDelay(150 / portTICK_RATE_MS);
        motors.MoveRight(150);
        // vTaskDelay(150 / portTICK_RATE_MS);
        // motors.Stop();
}

extern "C" void app_main()
{
    ESP_LOGI(TAG, "Start!");
    start_mpu();
    start_i2c_slave();
    start_motors();
    serial_init();
    ESP_LOGI(TAG, "Init done");
    // serial_poll();

}
