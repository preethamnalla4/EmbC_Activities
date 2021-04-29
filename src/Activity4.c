/**
 * @file Activity4.c
 * @author Preetham N (Preethamnalla4@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "SerialCommunicationUART.h"
/**
 * @brief A program to initialize the UART serial communication
 *
 * @param ubrr_value
 */
void UARTinit(uint16_t ubrr_value){

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UART_CHARACTER_SIZE; // 8 bit size of data
    UART_ENABLED; //enable rx and tx of uart with interrupts

}


/**
 * @brief A function to read characters coming from other UART port
 *
 * @return char
 */
char UARTreadchar(){

while(UART_DATA_NOT_RECEIVED){

}

return UDR0;

}


/**
 * @brief A function to write characters to send it to other UART port
 *
 * @param data
 */
void UARTwritecharacter(char data){

while(UART_DATA_NOT_WRITTEN){

}

UDR0 = data;

}
