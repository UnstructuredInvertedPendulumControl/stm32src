/*
 * as5600.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Jonathan Martini
 */



#include "AS5600.h"
#include "main.h"
#include "cmsis_os.h"
#include "stdio.h"
#include "adxl345.h"

extern double read_as5600(I2C_HandleTypeDef* devref)
{
	uint8_t buffer2[1];
		uint8_t* payloadreg(uint8_t reg)
			{
					// lil macro
					buffer2[0] = reg;
					return buffer2;
			}

	uint8_t res_buff[2];
	res_buff[0] = HAL_I2C_Master_Receive(devref, (uint16_t)AS_ADDR, payloadreg(ANGLE_1), 1,100);
	res_buff[1] = HAL_I2C_Master_Receive(devref, (uint16_t)AS_ADDR, payloadreg(ANGLE_2), 1,100);
	return u2f(res_buff[0], res_buff[1], AS5600_RNG, AS5600_UNC);
}
