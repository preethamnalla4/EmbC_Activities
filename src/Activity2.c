/**
 * @file Activity2.c
 * @author Preetham N (Preethamnalla4@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include<util/delay.h>
#include<Activity2.h>
/**
 * @brief Function to Start ADC
 * 
 */

void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

/**
 * @brief funciton to receive temperature sensor inputs from analog pin and output it to a register ADC which has 2 8 bit registers ADCL and ADCH.
 * 
 * @param ch 
 * @return uint16_t 
 */
uint16_t ReadADC(uint16_t ch)
{
    //select ADC channel ch must be 0-7
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //Start Single conversion
    ADCSRA|=(1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));
    //Clear ADIF by writing one to it
    ADCSRA|=(1<ADIF);
    return(ADC);
}
uint8_t read_ADC(){
    uint16_t digital_value=0; uint8_t temp=0;
    initialise_ADC();
    digital_value = get_digital_value(0);
    if(digital_value<=200){
        temp = 20;
    }
    else if(digital_value<=500){
        temp = 25;
    }
    else if(digital_value<=700){
        temp = 29;
    }
    else if (digital_value<=1024){
        temp = 33;
    }
    return temp;
}