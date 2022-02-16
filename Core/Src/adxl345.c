/*
 * adxl345.c
 *
 *  Created on: Feb 9, 2022
 *      Author: jsmartini
 */

#include "adxl345.h"
#include "main.h"
#include "cmsis_os.h"

double u2f(uint8_t LSB, uint8_t MSB, double m_rng, double uncertainty)
{
	return ((double)(MSB << 8 | LSB) * m_rng - uncertainty);
}

void ADXL345_DeviceSetup(uint32_t CS_PIN, I2C_HandleTypeDef *ref)
{
	// enable device i2c bus connected on the chip select gpio pin
	HAL_GPIO_WritePin(GPIOA, CS_PIN, GPIO_PIN_SET);
	uint8_t buffer[2];
	// run setup code
	uint8_t* payload(uint8_t reg, uint8_t data)
	{
		// lil macro
		buffer[0] = reg;
		buffer[1] = data;
		return buffer;
	}
	// initialize device into FIFO read status
	HAL_I2C_Master_Transmit(ref, (uint16_t)ADXL345_ADDR, payload(FIFO_CTL, ADXL_FIFO_CONFIGURATION), 2, 100);
	// initialize stream mode for FIFO
	HAL_I2C_Master_Transmit(ref, (uint16_t)ADXL345_ADDR, payload(POWER_CTL, ADXL_MEASURE_MODE), 2, 100);
	// disable device i2c bus connected on the chip select gpio pin
	HAL_GPIO_WritePin(GPIOA, CS_PIN, GPIO_PIN_RESET);
};

void ADXL345_DeviceRead(AccelerometerData_t *ref, I2C_HandleTypeDef* devref)
{
	// select device
	HAL_GPIO_WritePin(GPIOA, ref->CS_GPIO_PIN, GPIO_PIN_SET);
	uint8_t LSBMSB_OUT[6];
	// get 2 byte msb, lsb data
	for (int i = 0; i < 5; i++) LSBMSB_OUT[i] = HAL_I2C_Master_Receive(devref, (uint16_t)ADXL345_ADDR, LSBMSB_REG[i], 1, 100);
	// combine and scale msb, lsb data
	for (int i = 0; i < 2; i++) ref->data[i] = u2f(LSBMSB_OUT[i], LSBMSB_OUT[i+3], m_rng, uncertainty);
	// deselect device
	HAL_GPIO_WritePin(GPIOA, ref->CS_GPIO_PIN, GPIO_PIN_RESET);
};
