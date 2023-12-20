/*
 * ens160.h
 *
 *  Created on: Dec 13, 2023
 *      Author: akash
 */

#ifndef SRC_ENS160_H_
#define SRC_ENS160_H_


#define ENS_ENABLE_PORT gpioPortB
#define ENS_ENABLE_PIN 03

//register addresses
#define ENS160_REG_PART_ID            0x00    // 2 byte register
#define ENS160_REG_OPMODE   0x10
#define ENS160_REG_DATA_STATUS    0x20
#define ENS160_REG_DATA_AQI   0x21
#define ENS160_REG_DATA_TVOC    0x22
#define ENS160_REG_DATA_ECO2    0x24
#define ENS160_PARTID       0x0160



//commands
#define ENS160_OPMODE_RESET   0xF0
#define ENS160_OPMODE_DEP_SLEEP   0x00
#define ENS160_OPMODE_IDLE    0x01
#define ENS160_OPMODE_STD   0x02


#include "sl_i2cspm_instances.h"
#include <stdio.h>
#include <stdint.h>
#include "sl_i2cspm.h"
#include "sl_sleeptimer.h"
#include "sl_si1133.h"
#include "src/ens160.h"
#include "sl_i2cspm_instances.h"
#include "em_gpio.h"
#include "app.h"
#include "sl_bluetooth.h"
#include "app_assert.h"
#include "gatt_db.h"
#include <stdio.h>




sl_status_t ens160_read_register(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t *data);
sl_status_t ens160_write_register(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t data);
sl_status_t ens160_write_register_block(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t length, const uint8_t *data);
sl_status_t ens160_read_register_block(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t length, uint8_t *data);
sl_status_t ens160_get_hardware_id(sl_i2cspm_t *i2cspm, uint8_t *hardwareID);


void sleepENS();
void ensReInit();
void initENS160();
void readENS(uint8_t *aqi, uint16_t *tvoc, uint16_t *eco2);



#endif /* SRC_ENS160_H_ */
