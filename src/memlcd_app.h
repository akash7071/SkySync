/***************************************************************************//**
 * @file memlcd_app.h
 * @brief Memory Liquid Crystal Display (LCD) example functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef MEMLCD_APP_H
#define MEMLCD_APP_H

/***************************************************************************//**
 * Initialize example
 ******************************************************************************/
void memlcd_app_init(void);

/***************************************************************************//**
 * Ticking function
 ******************************************************************************/
void memlcd_app_process_action(void);


void lcdTemp();

void dataDisplay(int32_t temp, uint32_t humidity, uint32_t pressure, float lux, float uvi, uint8_t aqi, uint16_t tvoc, uint16_t eco2);

#endif // MEMLCD_APP_H
