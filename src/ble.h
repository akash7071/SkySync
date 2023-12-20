/*
 * ble.h
 *
 *  Created on: Dec 8, 2023
 *      Author: akash
 */

#ifndef SRC_BLE_H_
#define SRC_BLE_H_
#include "sl_bluetooth.h"



void handle_ble_event(sl_bt_msg_t *evt);
void sendDataBLE(uint32_t temperature, uint32_t humidity, uint32_t pressure, float lux, float uvi, float aqi, uint16_t tvoc, uint16_t eco2);


#endif /* SRC_BLE_H_ */
