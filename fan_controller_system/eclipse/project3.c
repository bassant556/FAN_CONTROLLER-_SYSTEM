/*
 * project3.c
 *
 *  Created on: Oct 9, 2023
 *      Author: bassant
 */

#include"adc.h"/*For ADC_init*/
#include"std_types.h"/*For Declarations As uint8 */
#include"motor.h"/*For Using The Prototypes Of Motor Driver*/
#include"lm35_sensor.h"/*For Using The Prototypes Of lm35_sensor */
int main(){
	uint8 temp=0;
	ADC_ConfigType ADC_Configurations = {F_CPU_8,INTERNAL};/*Define The Prescalar And The Reference Voltage We Want To Use In The In The Project  */
	ADC_init(&ADC_Configurations);/*Initialize ADC By Sending The Address Of The Struct */
	DcMotor_Init();/*Initialize DC_motor*/
	LCD_init();/*Initialize LCD*/
	LCD_moveCursor(0,3);/*Move Cursor To Row :0 And Column :3*/
	LCD_displayString("FAN IS ");/*Display This String In ROw :0 And Column:3*/
	while(1){
		temp=LM35_getTemperature();/*In The While Loop We Continiously Get The Temperature From The Sensor And Check For It */
		if(temp<30){/*If The Temperature <30 ,The Motor Stops And Display FAN IS OFF And Display The Temperature On the Second Line */
			DcMotor_Rotate(stop,0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			if(temp<10){/* In case the digital value is one digits print space in the next digit place */
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}else{
				LCD_intgerToString(temp);
			}
		}else if(temp>=30&&temp<60){/*If The Temperature >30 And <60 ,The Motor Begin Rotating ClockWise With 25% From Its Maximum Speed And Display FAN IS ON And Display The Temperature On the Second Line */
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter('    ');
			DcMotor_Rotate(CLOCKWISE,25);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);
		}else if(temp>=60&&temp<90){/*If The Temperature >60 And <90,The Motor Rotates ClockWise And Display FAN IS ON With 50% From Its Maximum Speed And Display The Temperature On the Second Line */
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			DcMotor_Rotate(CLOCKWISE,50);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);
		}else if(temp>=90&&temp<120){/*If The Temperature >90 And <120,The Motor Rotates ClockWise With 75% From Its Maximum Speed And Display FAN IS ON And Display The Temperature On the Second Line */
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			DcMotor_Rotate(CLOCKWISE,75);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{/* In case the digital value is two or one digits print space in the next digit place */
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
		}else {
			/*If The Temperature >90 And <120,The Motor Rotates ClockWise With 100% From Its Maximum Speed And Display FAN IS ON And Display The Temperature On the Second Line */
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			DcMotor_Rotate(CLOCKWISE,100);
			LCD_moveCursor(1,4);
			LCD_displayString("TEMP=");
			LCD_moveCursor(1,9);
			LCD_intgerToString(temp);
		}



	}



}
