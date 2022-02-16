/*
 * adxl345.h
 *
 *  Created on: Feb 9, 2022
 *      Author: jsmartini
 */

#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_


#include "DataTypes.h"
#include "stdint.h"
#include "main.h"

#define ADXL345_ADDR 0x53
#define DEVID 0x00
#define THRESH_TAP 0x1D
#define OFSX 0x1E
#define OFSY 0x1F
#define OFSZ 0x20
#define DUR 0x21
#define Latent 0x22
#define Window 0x23
#define THRESH_ACT 0x24
#define THRESH_INACT 0x25
#define TIME_INACT 0x26
#define ACT_INACT_CTL 0x27
#define THRESH_FF 0x28
#define TIME_FF 0x29
#define TAP_AXES 0x2A
#define ACT_TAP_STATUS 0x2B
#define BW_RATE 0x2C
#define POWER_CTL 0x2D
#define INT_ENABLE 0x2E
#define INT_MAP 0x2F
#define INT_SOURCE 0x30
#define DATA_FORMAT 0x31
#define DATAX0 0x32
#define DATAX1 0x33
#define DATAY0 0x34
#define DATAY1 0x35
#define DATAZ0 0x36
#define DATAZ1 0x37
#define FIFO_CTL 0x38
#define FIFO_STATUS 0x39


typedef unsigned char u8;
u8 LSBMSB_REG[] = {DATAX0, DATAY0, DATAZ0, DATAX1, DATAY1, DATAZ1};
double m_rng= 0;
double uncertainty = 0;

// application specific bitfield configurations
// FIFO mode control
#define ADXL_FIFO_MODE 0b10
#define ADXL_TRIGGER   0b0
#define ADXL_SAMPLES   0b00011
#define ADXL_FIFO_CONFIGURATION (ADXL_FIFO_MODE << 6) | (ADXL_TRIGGER) | ADXL_SAMPLES

#define ADXL_MEASURE_MODE 0b00001000

// Function Calls Associated with device
double u2f(uint8_t LSB, uint8_t MSB, double m_rng, double uncertainty);
void vADXL345_DeviceSetup(uint32_t CS_PIN, I2C_HandleTypeDef *ref);
void vADXL345_DeviceRead(AccelerometerData_t *ref,I2C_HandleTypeDef *devref);

#endif /* INC_ADXL345_H_ */
