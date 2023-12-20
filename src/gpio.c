/*
 * gpio.c
 *
 *  Created on: Dec 8, 2023
 *      Author: akash
 */

#include "src/gpio.h"
#include "app.h"
#include "em_common.h"
#include <stdio.h>
#include "gpio.h"
#include "src/ens160.h"


extern uint8_t timerStatus;

void LEDInit()
{
  GPIO_PinModeSet(LED_port, LED_pin, gpioModePushPull, false);    //led pin set to output
  GPIO_PinModeSet(ENS_ENABLE_PORT, ENS_ENABLE_PIN, gpioModePushPull, false);    //led pin set to output
//  GPIO_PinModeSet(gpioPortC, 6, gpioModeInputPullFilter, true);
//  GPIO_ExtIntConfig (gpioPortC, 6, 6, false, true, true);
//  NVIC_ClearPendingIRQ (GPIO_EVEN_IRQn); //clear pending interrupts in LETIMER
//  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

}
