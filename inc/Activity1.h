/**
 * @file Activity1.h
 * @author Preetham N (Preethamnalla4@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _ACTIVITY1_H
#define _ACTIVITY1_H

#define AVR_ATmega328

#include <avr/io.h>

/**
 * @brief A macro to check if the button is pressed or not.
 * 
 */
#define SENSOR_ON !(PIND&(1<<PD0))

/**
 * @brief A macro to check if the heater is pressed or not.
 * 
 */
#define HEATER_ON !(PIND&(1<<PD4))

/**
 * @brief A macro to turn on the LED 
 * 
 */
#define SET_LED PORTD|=(1<<PD6)

/**
 * @brief A macro to turn off the LED
 * 
 */
#define CLEAR_LED PORTD&=~(1<<PD6)

void Buttons_LED_Init();


#endif //ACTIVITY1_H_INCLUDED 