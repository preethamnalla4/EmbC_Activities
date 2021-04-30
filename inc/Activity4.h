/**
 * @file Activity4.h
 * @author Preetham N (Preethamnalla4@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _ACTIVITY4_H
#define _ACTIVITY4_H

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Program to initialize the UART serial communication
 * 
 * @param ubrr_value 
 */
void UARTinit(uint16_t ubrr_value);

/**
 * @brief Function to read characters coming from other UART port
 * 
 * @return char 
 */
char UARTreadchar();

/**
 * @brief Function to write characters to send it to other UART port
 * 
 * @param data 
 */
void UARTwritecharacter(char data);

#endif 