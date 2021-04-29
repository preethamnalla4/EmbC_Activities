/**
 * @file Activity1.c
 * @author Preetham N (Preethamnalla4@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include<util/delay.h>
#include<Activity1.h>
/**
 * @brief Function to operate the button and heater sensor
 * 
 * @return int 
 */
int main(void)
{

DDRB|=(1<<PB0);
DDRB&=~(1<<PB6); //clear bit
PORTB|=(1<<PB6); //Set bit
DDRB&=~(1<<PB7); //clear bit
PORTB|=(1<<PB7);//Set bit

}
