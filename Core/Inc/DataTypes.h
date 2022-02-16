/*
 * DataTypes.h
 *
 *  Created on: Feb 9, 2022
 *      Author: jsmartini
 */

#ifndef INC_DATATYPES_H_
#define INC_DATATYPES_H_

#include "stdint.h"
#include "main.h"

// holds data from accelerometer query
typedef
struct
{
	uint32_t CS_GPIO_PIN;
	union
	{
		double data[3];
		char _data[24];
	};
}
AccelerometerData_t;

// Holds all 3 accelerometer data
typedef
struct
{
	AccelerometerData_t data[3];
}
AccelerometerQuery_t;





#endif /* INC_DATATYPES_H_ */
