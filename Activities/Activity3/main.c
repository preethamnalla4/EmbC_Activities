// PWM with timer 0
#include <avr/io.h>
#include<util/delay.h>
/** \brief Function to generate a PWM signal of a particular duty cycle based on the input ADC temperature values
 *
 *
 */

int main(void)
{
    // Compare match set for timer 0 channel A, bit 1 in register A, setting the wave generation mode to Fast PWM 0xFF using WGM
    TCCR0A |= (1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    //resolution set as 64 bit for the pre-scalar using timer 0 channel B
    TCCR0B |= (1<<CS01) | (1<<CS00);
    // Setting pin PD6 as OUTPUT PWM pin
    DDRD |= (1<<PD6);

    while(1)
    {
        // OC - OUTPUT COMPARE MATCH, 0- TIMER 0, A/B - CHANNELS

        // 20% duty cycle - 20% of 255 = 51 generated
        OCR0A = 51;
        _delay_ms(2000);

        // 40% duty cycle - 40% of 255 = 102 generated
        OCR0A = 102;
        _delay_ms(2000);

        // 70% duty cycle - 70% of 255 = 178.5 generated
        OCR0A = 178.5;
        _delay_ms(2000);

        // 95% duty cycle - 95% of 255 = 242.25 generated
        OCR0A = 242.25;
        _delay_ms(2000);

    }

    return 0;
}
