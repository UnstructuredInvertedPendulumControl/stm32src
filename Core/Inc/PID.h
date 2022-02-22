/*
 * PID.h
 *
 *  Created on: Feb 22, 2022
 *      Author: Jonathan Martini
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "string.h"

typedef struct
{
	double spoint; // set point
	double Kp;
	double Ti;
	double Ki;
	double Td;
	double Kd;
	double error_accumulator;		// integral error accumulator
	double last_error;					// place holder for last error for derivative calculation
	double time_step_size;				// Milli Seconds
} PID_t;


extern double eval_PID(double, PID_t*);
extern void setup_PID(PID_t*);
// SET subcommands







#endif /* INC_PID_H_ */
