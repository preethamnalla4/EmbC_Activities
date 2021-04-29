/**
 * @file main.c
 * @author Preethamnalla ()
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <avr/io.h>
/**
 * @brief By using the button sensor turn on the heater sensor that turn on heater sensor shows by LED
 * 
 * @return int 
 */
int main(void)
{

  /**
   * @brief Main Code
   * 
   */

 DDRB|=(1<<PB0);
DDRB&=~(1<<PB6); //clear bit
PORTB|=(1<<PB6); //Set bit
DDRB&=~(1<<PB7); //clear bit
PORTB|=(1<<PB7);//Set bit
    while(1)
    {
        if(!(PINB&(1<<PB7))){

            if(!(PINB&(1<<PB6)))
            {
                PORTB|=(1<<PB0);
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
