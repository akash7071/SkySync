/*
 * timer.c
 *
 *  Created on: Dec 8, 2023
 *      Author: akash
 */

#include "timer.h"
#include "app.h"
#include "em_letimer.h"
#include "em_common.h"
#include "em_cmu.h"
#include "ble.h"

static uint32_t topValue;
static uint32_t secondsTimer;
static LETIMER_Init_TypeDef letimerInit;
extern uint8_t timerStatus;

// int32_t temperature;
// uint32_t humidity;
// uint32_t pressure;
// float lux;
// float uvi;
// float aqi;


void initTimer()
{
  secondsTimer=2;
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;
  // Select LFXO for the LETIMER
  CMU_LFXOInit(&lfxoInit);
  CMU_ClockSelectSet(cmuClock_EM23GRPACLK, cmuSelect_LFXO);

  //GPIO_PinModeSet(BSP_LED0_PORT, BSP_LED0_PIN, gpioModePushPull, 1);

  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

  // Calculate the top value (frequency) based on clock source
  topValue = CMU_ClockFreqGet(cmuClock_LETIMER0) * secondsTimer;

  // Reload top on underflow, pulse output, and run in free mode
  letimerInit.comp0Top = true;
  letimerInit.topValue = topValue;
  //letimerInit.ufoa0 = letimerUFOANone;
  letimerInit.repMode = letimerRepeatFree;

  // Enable LETIMER0 output0 on PA6
  /*GPIO->LETIMERROUTE[0].ROUTEEN = GPIO_LETIMER_ROUTEEN_OUT0PEN;
  GPIO->LETIMERROUTE[0].OUT0ROUTE = \
      (gpioPortA << _GPIO_LETIMER_OUT0ROUTE_PORT_SHIFT) \
      | (6 << _GPIO_LETIMER_OUT0ROUTE_PIN_SHIFT);
      */

  // Initialize and enable LETIMER
  LETIMER_Init(LETIMER0, &letimerInit);

  LETIMER_IntEnable(LETIMER0, LETIMER_IF_UF); // random addition

  NVIC_EnableIRQ(LETIMER0_IRQn); // random addition


}


void LETIMER0_IRQHandler()
 {
    //GPIO_PinOutToggle(LED_port, LED_pin);


    if(timerStatus==0)
      timerStatus=1;

//    //printf("\n\n\rInterrupted\n\r");
//    if(secondsTimer==3)
//      {
//        secondsTimer=7;
//        timerStatus=2;
//        //printf("\n\n\rInterrupted 5\n\r");
//      }
//    else if(secondsTimer==7)
//      {
//        secondsTimer=3;
//        timerStatus=1;
//        //printf("\n\n\rInterrupted 15\n\r");
//      }

    topValue = CMU_ClockFreqGet(cmuClock_LETIMER0) * secondsTimer;
    letimerInit.topValue = topValue;
    LETIMER_TopSet(LETIMER0,topValue);
    LETIMER_IntClear(LETIMER0, LETIMER_IF_UF);
    //LETIMER_Init(LETIMER0, &letimerInit);

 }

