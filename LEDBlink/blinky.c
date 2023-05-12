#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5

int main()
{
    DDRB |= (1 << LED_PIN);
    while (1)
    {
        PORTB |= (1 << LED_PIN);  // turn LED on
        _delay_ms(1000);          // delay for 1 second
        PORTB &= ~(1 << LED_PIN); // turn LED off
        _delay_ms(1000);          // delay for 1 second
    }
    return 0;
}
