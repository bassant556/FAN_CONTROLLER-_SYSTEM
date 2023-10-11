/*
 * motor.h
 *
 *  Created on: Oct 10, 2023
 *      Author: bassant
 */

#ifndef MOTOR_H_
#define MOTOR_H_


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	stop=0xFC,ANTI_CLOCKWISE=0xFD,CLOCKWISE=0xFE
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the DC_motor driver.
 */
void DcMotor_Init(void);
/*
 * Description :
 * Function responsible for Taking The State And Speed As AN Input And Adjust The Motor According To Them
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
