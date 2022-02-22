/*
 * AS5600.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Jonathan Martini
 */

#ifndef INC_AS5600_H_
#define INC_AS5600_H_

// configuration register
#include "stdint.h"
#include "main.h"

#define ZMCO   0x00
#define ZPOS_1   0x01
#define ZPOS_2   0x02

#define MPOS_1   0x03
#define MPOS_2   0x04

#define MANG_1   0x05
#define MANG_2   0x06

#define CONF_1   0x07
#define CONF_2   0x08


// output Registers
#define RAW_ANGLE_1   0x0C
#define RAW_ANGLE_2   0x0D

#define ANGLE_1   0x0E
#define ANGLE_2   0x0F

// status registers

#define as_status   0x0B
#define AGC      0x1A

#define magnitude_1   0x1B
#define magnitude_2   0x1C

#define BURN   0xFF

#define AS_ADDR   0x36

#define AS5600_RNG 0.0
#define AS5600_UNC 0.0

uint8_t read_as5600(I2C_HandleTypeDef* devref);

#endif /* AS5600_H_ */
