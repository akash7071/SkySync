/***************************************************************************//**
 * @file
 * @brief Core application logic.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "sl_sleeptimer.h"
#include "sl_si1133.h"
#include "sl_i2cspm_instances.h"

#include "em_cmu.h"
#include <stdio.h>
#include "em_gpio.h"
#include "glib.h"

#include "app.h"
#include <src/bme280.h>
#include "src/timer.h"
#include "src/gpio.h"
#include <src/memlcd_app.h>
#include "src/ble.h"
#include "src/ens160.h"

#if !LOWEST_ENERGY_MODE
#define APP_IS_OK_TO_SLEEP      (false)   //for EM0 mode
#else
#define APP_IS_OK_TO_SLEEP      (true)    //for EM1, EM2, EM3 modes
#endif


#define APP_SLEEP_ON_ISR_EXIT   (SL_POWER_MANAGER_IGNORE)





// *************************************************
// Power Manager Callbacks
// The values returned by these 2 functions AND
// adding and removing power manage requirements is
// how we control when EM mode the MCU goes to when
// sl_power_manager_sleep() is called in the main
// while (1) loop.
// *************************************************

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)

bool app_is_ok_to_sleep(void)
{
  return APP_IS_OK_TO_SLEEP;
} // app_is_ok_to_sleep()

sl_power_manager_on_isr_exit_t app_sleep_on_isr_exit(void)
{
  return APP_SLEEP_ON_ISR_EXIT;
} // app_sleep_on_isr_exit()

#endif // defined(SL_CATALOG_POWER_MANAGER_PRESENT)





// The advertising set handle allocated from Bluetooth stack.

GLIB_Context_t glibContext;
int currentLine;
uint8_t timerStatus;




/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
  temperature =0;
  humidity=0;
  pressure=0;
  lux=0;
  uvi=0;
  aqi=0;
  tvoc=0;
  eco2=0;
  timerStatus=0;

  printf("Init");
  initTimer();                          //LETIMER init
  if(LOWEST_ENERGY_MODE == EM0)
     {
        //nothing to be executed
     }
    else if(LOWEST_ENERGY_MODE == EM1)
    sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
    else if(LOWEST_ENERGY_MODE == EM2)
    sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM2);
    else if(LOWEST_ENERGY_MODE == EM3)
      {
        //nothing to be executed
      }

  /*Sensor Initializations*/
  initBME();                            // BME280 Init
  bme280_ctrl_measure_set_to_sleep();   //put BME to sleep
  sl_si1133_init(sl_i2cspm_I2CSPM);     //  Si1133 Init
  sl_si1133_deinit(sl_i2cspm_I2CSPM);   //Si1133 Sleep
  initENS160();                         //ENS160 init
  sleepENS();                           //ENS160 sleep
  LEDInit();                            //user LED init

  memlcd_app_init();










}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{




  if(timerStatus==1)
    {




    bme280_ctrl_measure_set_to_work();
    bme280_read_temperature(&temperature);
    bme280_read_humidity(&humidity);
    bme280_read_pressure(&pressure);
    bme280_ctrl_measure_set_to_sleep();   //put BME to sleep


    sl_si1133_init(sl_i2cspm_I2CSPM);     //  Si1133 Init
    sl_si1133_measure_lux_uvi(sl_i2cspm_I2CSPM,&lux,&uvi);
    sl_si1133_deinit(sl_i2cspm_I2CSPM);   //Si1133 Sleep


    ensReInit();
    readENS(&aqi, &tvoc, &eco2);
    //sleepENS();                           //ENS160 sleep




    dataDisplay( temperature,  humidity/1000,  pressure,  lux,  uvi, aqi, tvoc, eco2);
    sendDataBLE(temperature,  humidity/1000,  pressure,  lux,  uvi,  aqi, tvoc, eco2);




    timerStatus=0;
    }
//  else if (timerStatus==2)
//    {
//      ensReInit();
//      timerStatus=0;
//    }





    //sl_sleeptimer_delay_millisecond(5 * 1000);
}

/**************************************************************************//**
 * Bluetooth stack event handler.
 * This overrides the dummy weak implementation.
 *
 * @param[in] evt Event coming from the Bluetooth stack.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t *evt)
{
  handle_ble_event(evt);
}


// void GPIO_EVEN_IRQHandler()
//{
// GPIO_PinOutToggle(LED_port, LED_pin);
//
//// int flags=GPIO_IntGetEnabled();
//// GPIO_IntClear(flags);
//
// if(timerStatus==0)
//       timerStatus=1;
//
//}

