#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_
#include "Timer.h"

void ServoMotor_Init(void);

void ServoMotor_SetDegree(uint8 Deg);

void ServoMotor_Start(void);

void ServoMotor_Stop(void);

#endif /* SERVO_MOTOR_H_ */