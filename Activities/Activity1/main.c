#include <avr/io.h>

int main(void)
{

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
