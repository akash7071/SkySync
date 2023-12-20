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



#define ENS160_I2C_DEVICE_BUS_ADDRESS   (0x53)

// float aqi;
// float tvoc;
// float eco2;




void ensReInit()
{
  uint8_t opMode=0;
  GPIO_PinOutSet(ENS_ENABLE_PORT, ENS_ENABLE_PIN);    //led pin set to output
  ens160_write_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, ENS160_OPMODE_IDLE);

  sl_sleeptimer_delay_millisecond(1 * 100);

  ens160_write_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, ENS160_OPMODE_STD);
  sl_sleeptimer_delay_millisecond(1 * 100);
  ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, &opMode);
  printf("\n\r opmode in reinit : %d\n\r",opMode);
}



void initENS160()
{

  GPIO_PinOutSet(ENS_ENABLE_PORT, ENS_ENABLE_PIN);    //led pin set to output
  uint8_t opMode=0;





  ens160_write_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, ENS160_OPMODE_RESET);
  sl_sleeptimer_delay_millisecond(1 * 1000);
  //ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, &opMode);
  //printf("opmode : %d\n\r",opMode);

  ens160_write_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, ENS160_OPMODE_IDLE);
  sl_sleeptimer_delay_millisecond(1 * 1000);
  //ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, &opMode);
  //printf("opmode : %d\n\r",opMode);

  ens160_write_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, ENS160_OPMODE_STD);
  sl_sleeptimer_delay_millisecond(1 * 1000);
  ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, &opMode);
  printf("\n\r opmode in init: %d\n\r",opMode);


//  ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_DATA_STATUS, &opMode);
//  printf("\n\n\ropmode : %b\n\r",opMode);







}


void sleepENS()
{
  //GPIO_PinOutSet(ENS_ENABLE_PORT, ENS_ENABLE_PIN);
  ens160_write_register(sl_i2cspm_I2CSPM, ENS160_REG_OPMODE, ENS160_OPMODE_DEP_SLEEP);
  GPIO_PinOutClear(ENS_ENABLE_PORT, ENS_ENABLE_PIN);    //led pin set to output
}



void readENS(uint8_t *aqi, uint16_t *tvoc, uint16_t *eco2)
{
  uint8_t opMode=0;
  uint8_t tvoc_temp[2];
  uint8_t eco2_temp[2];

    ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_DATA_STATUS, &opMode);
    printf("\n\n\ropmode : %b\n\r",opMode);

  ens160_read_register(sl_i2cspm_I2CSPM, ENS160_REG_DATA_AQI, aqi);
  //printf("aqi : %d\n\r",*aqi);

  ens160_read_register_block(sl_i2cspm_I2CSPM, ENS160_REG_DATA_TVOC, 2, &tvoc_temp[0]);
  *tvoc = (uint16_t)((tvoc_temp[1] << 8) | tvoc_temp[0]);
  //printf("voc : %d\n\r",*tvoc);

  ens160_read_register_block(sl_i2cspm_I2CSPM, ENS160_REG_DATA_ECO2, 2, &eco2_temp[0]);
  *eco2 = (uint16_t)((eco2_temp[1] << 8) | eco2_temp[0]);
  //printf("eco2 : %d\n\r",*eco2);
}



/***************************************************************************//**
 *    Reads register from the Si1133 sensor
 ******************************************************************************/
sl_status_t ens160_read_register(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t *data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  sl_status_t retval;

  retval = SL_STATUS_OK;

  seq.addr = ENS160_I2C_DEVICE_BUS_ADDRESS << 1;
  seq.flags = I2C_FLAG_WRITE_READ;
  /* Select register to start reading from */
  i2c_write_data[0] = reg;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = data;
  seq.buf[1].len = 1;

  ret = I2CSPM_Transfer(i2cspm, &seq);
  if ( ret != i2cTransferDone ) {
    *data = 0xff;
    retval = SL_STATUS_TRANSMIT;
  }

  return retval;
}

/***************************************************************************//**
 *    Writes register in the Si1133 sensor
 ******************************************************************************/
sl_status_t ens160_write_register(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[2];
  uint8_t i2c_read_data[1];
  sl_status_t retval;

  retval = SL_STATUS_OK;

  seq.addr = ENS160_I2C_DEVICE_BUS_ADDRESS << 1;
  seq.flags = I2C_FLAG_WRITE;
  /* Select register and data to write */
  i2c_write_data[0] = reg;
  i2c_write_data[1] = data;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 2;
  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len = 0;

  ret = I2CSPM_Transfer(i2cspm, &seq);
  if ( ret != i2cTransferDone ) {
    retval = SL_STATUS_TRANSMIT;
  }

  return retval;
}



/***************************************************************************//**
 *    Writes a block of data to the Si1133 sensor.
 ******************************************************************************/
sl_status_t ens160_write_register_block(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t length, const uint8_t *data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[10];
  uint8_t i2c_read_data[1];
  uint8_t i;
  sl_status_t retval;

  retval = SL_STATUS_OK;

  seq.addr = ENS160_I2C_DEVICE_BUS_ADDRESS << 1;
  seq.flags = I2C_FLAG_WRITE;
  /* Select register to start writing to*/
  i2c_write_data[0] = reg;
  for ( i = 0; i < length; i++ ) {
    i2c_write_data[i + 1] = data[i];
  }
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = length + 1;
  seq.buf[1].data = i2c_read_data;
  seq.buf[1].len = 0;

  ret = I2CSPM_Transfer(i2cspm, &seq);
  if ( ret != i2cTransferDone ) {
    retval = SL_STATUS_TRANSMIT;
  }

  return retval;
}

/***************************************************************************//**
 *    Reads a block of data from the Si1133 sensor.
 ******************************************************************************/
sl_status_t ens160_read_register_block(sl_i2cspm_t *i2cspm, uint8_t reg, uint8_t length, uint8_t *data)
{
  I2C_TransferSeq_TypeDef seq;
  I2C_TransferReturn_TypeDef ret;
  uint8_t i2c_write_data[1];
  sl_status_t retval;

  retval = SL_STATUS_OK;

  seq.addr = ENS160_I2C_DEVICE_BUS_ADDRESS << 1;
  seq.flags = I2C_FLAG_WRITE_READ;
  /* Select register to start reading from */
  i2c_write_data[0] = reg;
  seq.buf[0].data = i2c_write_data;
  seq.buf[0].len = 1;
  /* Select length of data to be read */
  seq.buf[1].data = data;
  seq.buf[1].len = length;

  ret = I2CSPM_Transfer(i2cspm, &seq);
  if ( ret != i2cTransferDone ) {
    retval = SL_STATUS_TRANSMIT;
  }

  return retval;
}



/***************************************************************************//**
 *    Reads Hardware ID from the SI1133 sensor
 ******************************************************************************/
sl_status_t ens160_get_hardware_id(sl_i2cspm_t *i2cspm, uint8_t *hardwareID)
{
  sl_status_t retval;

  retval = sl_si1133_read_register(i2cspm, SI1133_REG_PART_ID, hardwareID);

  return retval;
}
