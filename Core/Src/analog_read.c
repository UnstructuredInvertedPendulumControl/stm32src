/*
 * analog_read.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Jonathan Martini
 */


#include "main.h"
#include "stdint.h"

extern uint16_t analog_read(ADC_HandleTypeDef *adc)
{
	HAL_ADC_Start(adc);
	HAL_ADC_PollForConversion(adc, HAL_MAX_DELAY);
	return HAL_ADC_GetValue(adc);
};
