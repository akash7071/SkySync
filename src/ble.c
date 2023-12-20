#include "sl_bluetooth.h"
#include "app_assert.h"
#include "gatt_db.h"
#include <stdio.h>




static uint8_t advertising_set_handle = 0xff;
static uint8_t connectionHandle=0x00;
uint8_t temp;
uint16_t pressure_temp;
static uint8_t connectionOpen=0;




void handle_ble_event(sl_bt_msg_t *evt)
{
  sl_status_t sc;

    switch (SL_BT_MSG_ID(evt->header)) {
      // -------------------------------
      // This event indicates the device has started and the radio is ready.
      // Do not call any stack command before receiving this boot event!
      case sl_bt_evt_system_boot_id:
        // Create an advertising set.
        sc = sl_bt_advertiser_create_set(&advertising_set_handle);
        if (sc != SL_STATUS_OK)
                  printf("sl_bt_advertiser_create_set");
        //app_assert_status(sc);

        // Generate data for advetising
        sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                   sl_bt_advertiser_general_discoverable);
        if (sc != SL_STATUS_OK)
                          printf("sl_bt_legacy_advertiser_generate_data");
        //app_assert_status(sc);

        // Set advertising interval to 100ms.
        sc = sl_bt_advertiser_set_timing(
          advertising_set_handle,
          160, // min. adv. interval (milliseconds * 1.6)
          160, // max. adv. interval (milliseconds * 1.6)
          0,   // adv. duration
          0);  // max. num. adv. events
        //app_assert_status(sc);
        // Start advertising and enable connections.
        sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                           sl_bt_advertiser_connectable_scannable);
        if (sc != SL_STATUS_OK)
                                  printf("sl_bt_legacy_advertiser_start");
        //app_assert_status(sc);
        break;

      // -------------------------------
      // This event indicates that a new connection was opened.
      case sl_bt_evt_connection_opened_id:


        connectionOpen=1;
        connectionHandle=evt->data.evt_connection_opened.connection;
        sl_bt_advertiser_stop(advertising_set_handle);
        if (sc != SL_STATUS_OK)
          printf("sl_bt_advertiser_stop");
        break;

      // -------------------------------
      // This event indicates that a connection was closed.
      case sl_bt_evt_connection_closed_id:
        connectionOpen=0;
        // Generate data for advertising
        sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                   sl_bt_advertiser_general_discoverable);
        if (sc != SL_STATUS_OK)
                  printf("sl_bt_legacy_advertiser_generate_data");
        //app_assert_status(sc);

        // Restart advertising after client has disconnected.
        sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                           sl_bt_advertiser_connectable_scannable);
        if (sc != SL_STATUS_OK)
                  printf("sl_bt_legacy_advertiser_start");
        //app_assert_status(sc);
        break;

      ///////////////////////////////////////////////////////////////////////////
      // Add additional event handlers here as your application requires!      //
      ///////////////////////////////////////////////////////////////////////////

      // -------------------------------
      // Default event handler.
      default:
        break;
    }
}


void sendDataBLE(uint32_t temperature, uint32_t humidity, uint32_t pressure, float lux, float uvi, uint8_t aqi, uint16_t tvoc, uint16_t eco2)
{

  if(connectionOpen==1)
    {



  //printf("\n\rtemperature %ld",temperature);

  //temp=temperature/100;
  //printf("\n\rtemp %ld",temp);


    char temperature_str[8];


    float temp_float;
    temp_float = (float)((float)temperature/100.00);
    //printf("\n\rtemp float %f uint32 temp %ld",temp_float,temperature);


    sprintf(temperature_str,"%.1f",temp_float);

    strcat(temperature_str," C  ");
    //printf("temperature after sprintf %s",temperature_str);
  //Temperature
  sl_status_t sc= sl_bt_gatt_server_write_attribute_value(gattdb_temperature,
                                                      0,
                                                      8,
                                                      (uint8_t *)&temperature_str);
  if (sc != SL_STATUS_OK)
           printf("\n\r sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x Temperature\n\r", (unsigned int) sc );






  sc = sl_bt_gatt_server_send_notification(connectionHandle,
                                      gattdb_temperature,
                                      8,
                                      (uint8_t *)&temperature_str);

  if (sc != SL_STATUS_OK)
    printf("\n\r sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x Temperature\n\r", (unsigned int) sc );















  temp=humidity;
  char humidity_str[4];
  sprintf(humidity_str,"%02d",humidity);
  strcat(humidity_str,"% ");

  //Humidity
   sc= sl_bt_gatt_server_write_attribute_value(gattdb_humidity,
                                                      0,
                                                     4,
                                                     (uint8_t *)&humidity_str);
  if (sc != SL_STATUS_OK)
    printf("\n\r sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x Humidity\n\r", (unsigned int) sc );
  sc = sl_bt_gatt_server_send_notification(connectionHandle,
                                           gattdb_humidity,
                                           4,
                                           (uint8_t *)&humidity_str);

  if (sc != SL_STATUS_OK)
    printf("\n\r sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x Humidity\n\r", (unsigned int) sc );















  //pressure_temp=pressure;
  char pressure_str[8];
  sprintf(pressure_str,"%03d",pressure);
  strcat(pressure_str," mBar");
  //printf("\n\rPressure after sprintf %s",pressure_str);
  pressure_temp= (uint16_t)(((pressure & 0xFF) << 8) | ((pressure & 0xFF00) >> 8));
  //Pressure
   sc= sl_bt_gatt_server_write_attribute_value(gattdb_pressure,
                                                      0,
                                                      8,
                                                      (uint8_t *)&pressure_str);
  if (sc != SL_STATUS_OK)
    printf("\n\r Pressure sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x \n\r", (unsigned int) sc );
  sc = sl_bt_gatt_server_send_notification(connectionHandle,
                                      gattdb_pressure,
                                      8,
                                      (uint8_t *)&pressure_str);

  if (sc != SL_STATUS_OK)
    printf("\n\r Pressure sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x \n\r", (unsigned int) sc );













  //Lux
  char lux_char[5];
  sprintf(lux_char,"%05d",(uint16_t)lux);
   sc= sl_bt_gatt_server_write_attribute_value(gattdb_lux,
                                                      0,
                                                      5,
                                                      (uint8_t *)&lux_char);
  if (sc != SL_STATUS_OK)
    printf("\n\r Lux sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x \n\r", (unsigned int) sc );
  sc = sl_bt_gatt_server_send_notification(connectionHandle,
                                           gattdb_lux,
                                           5,
                                           (uint8_t *)&lux_char);

  if (sc != SL_STATUS_OK)
    printf("\n\r Lux sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x \n\r", (unsigned int) sc );












  //UVI
  char uvi_char[4];
  sprintf(uvi_char,"%.2f",uvi);
   sc= sl_bt_gatt_server_write_attribute_value(gattdb_uvi,
                                                      0,
                                                      4,
                                                      (uint8_t *)&uvi_char);
  if (sc != SL_STATUS_OK)
    printf("\n\r UVI sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x \n\r", (unsigned int) sc );
  sc = sl_bt_gatt_server_send_notification(connectionHandle,
                                           gattdb_uvi,
                                      4,
                                      (uint8_t *)&uvi_char);

  if (sc != SL_STATUS_OK)
    printf("\n\r UVI sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x \n\r", (unsigned int) sc );









//  AQI
  char aqi_char[2];
  sprintf(aqi_char,"%01d",aqi);
   sc= sl_bt_gatt_server_write_attribute_value(gattdb_aqi,
                                                      0,
                                                      1,
                                                      (uint8_t *)&aqi_char);
  if (sc != SL_STATUS_OK)
    printf("\n\r AQI sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x \n\r", (unsigned int) sc );

  sl_bt_gatt_server_send_notification(connectionHandle,
                                      gattdb_aqi,
                                      1,
                                      (uint8_t *)&aqi_char);

  if (sc != SL_STATUS_OK)
    printf("\n\r aqi sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x \n\r", (unsigned int) sc );




  //tvoc

  char tvoc_char[4];
  sprintf(tvoc_char,"%04d",tvoc);
   sc= sl_bt_gatt_server_write_attribute_value(gattdb_tvoc,
                                                      0,
                                                      4,
                                                      (uint8_t *)&tvoc_char);
  if (sc != SL_STATUS_OK)
    printf("\n\r TVOC sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x \n\r", (unsigned int) sc );
  sc = sl_bt_gatt_server_send_notification(connectionHandle,
                                           gattdb_tvoc,
                                      4,
                                      (uint8_t *)&tvoc_char);

  if (sc != SL_STATUS_OK)
    printf("\n\r tvoc sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x \n\r", (unsigned int) sc );





//  //eco2
//
//  char eco2_char[4];
//  sprintf(eco2_char,"%04d",eco2);
//   sc= sl_bt_gatt_server_write_attribute_value(gattdb_eco2,
//                                                      0,
//                                                      4,
//                                                      (uint8_t *)&eco2_char);
//  if (sc != SL_STATUS_OK)
//    printf("\n\r eco2 sl_bt_gatt_server_write_attribute_value() returned != 0 status=0x%04x \n\r", (unsigned int) sc );
//  sc = sl_bt_gatt_server_send_notification(connectionHandle,
//                                           gattdb_eco2,
//                                      4,
//                                      (uint8_t *)&eco2_char);
//
//  if (sc != SL_STATUS_OK)
//    printf("\n\r eco2 sl_bt_gatt_server_send_notification() returned != 0 status=0x%04x \n\r", (unsigned int) sc );


    }




}
