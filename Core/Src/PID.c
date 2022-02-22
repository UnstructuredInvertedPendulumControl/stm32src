/*
 * PID.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Jonathan Martini
 */


#include "PID.h"

double eval_PID(double value, PID_t* controller)
{
	double error = controller->spoint - value;
	double proportional = error * controller->Kp;
	double integral = (error - controller->last_error) * controller->time_step_size;
	double derivative = (error - controller->last_error) / controller->time_step_size;
	error = proportional + integral + derivative;
	controller->last_error = error;
	return error;
};

void setup_pid(PID_t* controller)
{
	controller->Ki = controller->Kp / controller->Ti;
	controller->Kd = controller->Kp * controller->Td;
	controller->error_accumulator = 0;
	controller->last_error = 0;
};

