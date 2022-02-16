/*
 * adxl345.c
 *
 *  Created on: Feb 9, 2022
 *      Author: jsmartini
 */

#include "adxl345.h"
#include "main.h"
#include "cmsis_os.h"
#include "stdio.h"

uint8_t LSBMSB_REGS[] = {DATAX0, DATAY0, DATAZ0, DATAX1, DATAY1, DATAZ1};

extern double u2f(uint8_t LSB, uint8_t MSB, double m_rng, double uncertainty)
{
	return ((double)(MSB << 8 | LSB) * m_rng - uncertainty);
}

extern void vADXL345_DeviceSetup(AccelerometerData_t *acc_ref, I2C_HandleTypeDef *ref)
{
	printf("Running setup on adxl device CS: #%lu\n\r\n", acc_ref->CS_PIN);
	// enable device i2c bus connected on the chip select gpio pin
	HAL_GPIO_WritePin(acc_ref->gpio_port, acc_ref->CS_PIN, GPIO_PIN_SET);
	uint8_t buffer[2];
	// run setup code
	uint8_t* payload(uint8_t reg, uint8_t data)
	{
		// lil macro
		buffer[0] = reg;
		buffer[1] = data;
		return buffer;
	}
	uint8_t buffer2[1];
	uint8_t* payloadreg(uint8_t reg)
		{
				// lil macro
				buffer2[0] = reg;
				return buffer2;
		}
	// initialize device into FIFO read status
	HAL_I2C_Master_Transmit(ref, (uint16_t)ADXL345_ADDR, payload(FIFO_CTL, ADXL_FIFO_CONFIGURATION), 2, 100);
	// initialize stream mode for FIFO
	HAL_I2C_Master_Transmit(ref, (uint16_t)ADXL345_ADDR, payload(POWER_CTL, ADXL_MEASURE_MODE), 2, 100);
	// disable device i2c bus connected on the chip select gpio pin
	uint8_t dev_id = HAL_I2C_Master_Receive(ref, (uint16_t)ADXL345_ADDR, payloadreg(DEVID),1,100);
	printf("Successfully setup device ID: %d\n\r\n", dev_id);
	HAL_GPIO_WritePin(acc_ref->gpio_port, acc_ref->CS_PIN, GPIO_PIN_RESET);
};

extern void vADXL345_DeviceRead(AccelerometerData_t *ref, I2C_HandleTypeDef* devref)
{
	// select device
	printf("Grabbing Data from Accelerometer on CS_PIN: #%lu\n\r\n", ref->CS_PIN);
	HAL_GPIO_WritePin(ref->gpio_port, ref->CS_PIN, GPIO_PIN_SET);
	uint8_t buffer[1];
		// run setup code
	uint8_t* payload(uint8_t reg)
	{
			// lil macro
			buffer[0] = reg;
			return buffer;
	}
	uint8_t LSBMSB_OUT[6];
	// get 2 byte msb, lsb data
	for (int i = 0; i < 5; i++) LSBMSB_OUT[i] = HAL_I2C_Master_Receive(devref, (uint16_t)ADXL345_ADDR,payload(LSBMSB_REGS[i]), 1, 100);
	// combine and scale msb, lsb data
	for (int i = 0; i < 2; i++) ref->data[i] = u2f(LSBMSB_OUT[i], LSBMSB_OUT[i+3], MRNG, UNC);
	// deselect device
	HAL_GPIO_WritePin(ref->gpio_port, ref->CS_PIN, GPIO_PIN_RESET);
};
