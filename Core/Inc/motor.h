/*
 * motor.h
 *
 *  Created on: Feb 22, 2022
 *      Author: Jonathan Martini
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"
#include "stdint.h"
#include "stdbool.h"

#define SYSCLK_FREQ 16000000		// MHz

typedef
struct
{
	// timer output and configuration
	TIM_HandleTypeDef* timer_instance;
	uint32_t*		   TIM_CCRx;
	uint32_t           PWM_TIM_CH;
	uint32_t 		   TIM_CLK;




	//  GPIO Direction Pin configuration
	uint32_t GPIO_PIN;
	GPIO_TypeDef* gpio_port;

	bool state; // 1 -> CW; 0 -> CCW

} motorCFG;

extern void motor_req_duty_cycle(uint8_t, motorCFG*);
extern void motor_req_direction(bool dir, motorCFG*);
extern void motor_req_speed(double, motorCFG*);
extern void motor_req_force(double, motorCFG*);

#endif /* INC_MOTOR_H_ */
