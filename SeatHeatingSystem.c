/**
 * @file SeatHeatingSystem.c
 * @author Preetham N
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
//#include "Activity1.h"
//#include "Activity2.h"
//#include "Activity3.h"
//#include "Activity4.h"
#include <avr/io.h>
#include<util/delay.h>

 void Buttons_LED_Init()
 {

DDRB|=(1<<PB0);
DDRB&=~(1<<PB6); //clear bit
PORTB|=(1<<PB6); //Set bit
DDRB&=~(1<<PB7); //clear bit
PORTB|=(1<<PB7);//Set bit

 }
 void InitADC()
{

    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
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
void timer()
{
  TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
  TCCR1B|=(1<<WGM12)|(1<<CS11);
  DDRB|=(1<<PB1);
}
char pulse_width(uint16_t temp)
{
    char temperature;
     if((temp>=0) && (temp<=209))
        {
        //20% duty cycle
        OCR1A = 205;
        temperature = 20;
        _delay_ms(20);
        }
    else if((temp>=210) && (temp<=509))
        {
        //40% duty cycle
        OCR1A = 410;
        temperature = 25;
        _delay_ms(20);
       }
    else if((temp>=510) && (temp<=709))
    {
        //70% duty cycle
        OCR1A = 717;
        temperature = 29;
        _delay_ms(20);
    }
    else if((temp>=710) && (temp<=1024))
    {
        //95% duty cycle
        OCR1A = 973;
        temperature = 33;
        _delay_ms(20);
    }
    else
    {
        //0% output
        OCR1A = 0;
        temperature = 0;
    }
    return temperature;
}
void UARTinit(uint16_t ubrr_value)
{

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ01);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

char UARTreadchar()
{
while(!(UCSR0A & (1<<RXC0)))
    {
    }
return UDR0;
}
void UARTwritecharacter(char data)
{
 while(!(UCSR0A &(1<<UDRE0)))
 {
}
UDR0 = data;
}
int main(void)
{
    Buttons_LED_Init();
    InitADC();
    uint16_t temp;
    timer();
    UARTinit(103);
    char data;
while(1)
    {
        if(!(PINB&(1<<PB7))){

            if(!(PINB&(1<<PB6)))
            {
                PORTB|=(1<<PB0);
                _delay_ms(200);
                temp= ReadADC(0);
                pulse_width(temp);
                UARTwritecharacter(data);
            }
            else
            {
                PORTB&=~(1<<PB0);
            }
        }
        else
        {
                PORTB&=~(1<<PB0);
        }
    }
return 0;
}

