/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 *   Author: bassant
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{


	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);/*Here We Select If We Want The Voltage Reference To Be AREF Or AVCC Or Internal*/


	ADCSRA = (1<<ADEN);/*Enable ADC*/
	ADCSRA=(ADCSRA&0xF8)|((Config_Ptr->prescaler)&0x07);/*Here We Adjust The Prescaler By Clearing The First 3 Bits In ADCSRA Register And Then Inserting The Prescaler In Them*/

}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = ADMUX&0xE0| channel_num&0x07;/*First We Clear The First Five Bits in ADMUX register And Then Insert in them the channel But Before Inserting We Make Sure That The Channel_Num Is 3 Digits */
	SET_BIT(ADCSRA,ADSC);/* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));/* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);/* Clear ADIF by write '1' to it :) */
	return ADC;/* Read the digital value from the data register */
}
