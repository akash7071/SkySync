/***************************************************************************//**
 * @file memlcd_app.c
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
#include <stdio.h>

//#include "sl_board_control.h"
//#include "sl_simple_button_instances.h"
#include "em_assert.h"
#include "glib.h"
#include "dmd.h"
#include "app.h"
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

#ifndef BUTTON_INSTANCE_0
#define BUTTON_INSTANCE_0   sl_button_btn0
#endif

#ifndef BUTTON_INSTANCE_1
#define BUTTON_INSTANCE_1   sl_button_btn1
#endif

#ifndef LCD_MAX_LINES
#define LCD_MAX_LINES      11


#endif

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/
static GLIB_Context_t glibContext;
static int currentCount = 0;

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************//**
 * Initialize example.
 ******************************************************************************/
void memlcd_app_init(void)
{
  uint32_t status;

  /* Enable the memory lcd */

//  status = sl_board_enable_display();
//  EFM_ASSERT(status == SL_STATUS_OK);


  /* Initialize the DMD support for memory lcd display */

  status = DMD_init(0);
  EFM_ASSERT(status == DMD_OK);


  /* Initialize the glib context */
  status = GLIB_contextInit(&glibContext);
  EFM_ASSERT(status == GLIB_OK);

  glibContext.backgroundColor = White;
  glibContext.foregroundColor = Black;

  /* Fill lcd with background color */
  GLIB_clear(&glibContext);

  /* Use Narrow font */
  GLIB_setFont(&glibContext, (GLIB_Font_t *) &GLIB_FontNarrow6x8);

  /* Draw text on the memory lcd display*/
  GLIB_drawStringOnLine(&glibContext,
                        "SkySync",
                        0,
                        GLIB_ALIGN_CENTER,
                        5,
                        0,
                        true);
//  GLIB_drawStringOnLine(&glibContext,
//                        "Ready",
//                        currentLine++,
//                        GLIB_ALIGN_LEFT,
//                        5,
//                        5,
//                        true);


  DMD_updateDisplay();
}


void dataDisplay(int32_t temp, uint32_t humidity, uint32_t pressure, float lux, float uvi, uint8_t aqi, uint16_t tvoc, uint16_t eco2)
{
  char param[30]="lux: ";
  char measure[10];

  //lux
  sprintf(measure,"%f",lux);
  strcat(param,measure);
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        2,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);

  //uvi
  strcpy(param, "uvi: ");
  sprintf(measure,"%f",uvi);
  strcat(param,measure);
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        3,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);


  //temp
  strcpy(param, "Temperature: ");
  sprintf(measure,"%ld",temp/100);

  strcat(param,measure);
  strcat(param,".");
  sprintf(measure,"%ld",temp%100);
  strcat(param,measure);
  strcat(param," C");
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        4,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);

  //humidity
  strcpy(param, "humidity: ");
  sprintf(measure,"%ld",humidity);
  strcat(param,measure);
  strcat(param,"%");
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        5,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);

  //pressure
  strcpy(param, "pressure: ");
  sprintf(measure,"%ld",pressure);
  strcat(param,measure);
  strcat(param," mBar");
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        6,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);

  //aqi
  strcpy(param, "aqi: ");
  sprintf(measure,"%d",aqi);
  strcat(param,measure);
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        7,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);

  //tvoc
  strcpy(param, "tvoc: ");
  sprintf(measure,"%d",tvoc);
  strcat(param,measure);
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        8,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);


  //eco2
  strcpy(param, "ECO2: ");
  sprintf(measure,"%d",eco2);
  strcat(param,measure);
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        9,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);

  //count

  strcpy(param, "Count: ");
  sprintf(measure,"%d",currentCount++);
  strcat(param,measure);
  GLIB_drawStringOnLine(&glibContext,
                        param,
                        10,
                        GLIB_ALIGN_LEFT,
                        5,
                        5,
                        true);








  DMD_updateDisplay();
}



//void lcdTemp()
//{
//
//
//
//GLIB_drawStringOnLine(&glibContext,
//                      "Chinmay",
//                      currentLine++,
//                      GLIB_ALIGN_LEFT,
//                      5,
//                      5,
//                      true);
//
// DMD_updateDisplay();
//}

/***************************************************************************//**
 * Ticking function.
 ******************************************************************************/
void memlcd_app_process_action(void)
{
  return;
}

/***************************************************************************//**
 * Callback on button change.
 *
 * This function overrides a weak implementation defined in the simple_button
 * module. It is triggered when the user activates one of the buttons.
 *
 ******************************************************************************/
//void sl_button_on_change(const sl_button_t *handle)
//{
//  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {
//    if (&BUTTON_INSTANCE_0 == handle) {
//      currentLine = 0;
//      GLIB_clear(&glibContext);
//    } else if (&BUTTON_INSTANCE_1 == handle) {
//      if (currentLine > LCD_MAX_LINES) {
//        currentLine = 0;
//        GLIB_clear(&glibContext);
//      }
//      GLIB_drawStringOnLine(&glibContext,
//                            "Hello World!",
//                            currentLine++,
//                            GLIB_ALIGN_LEFT,
//                            5,
//                            5,
//                            true);
//    }
//    DMD_updateDisplay();
//  }
//}
