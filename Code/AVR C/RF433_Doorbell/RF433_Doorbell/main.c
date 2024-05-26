#define F_CPU          9600000
#define LED_PIN        PB3
#define TX_PIN         PB4
#define MAX_SEQUENCE   65
#define LAST_SEQUENCE  63
#define NUM_SEQ_REPEAT 19

#define DELAY_SHORT    500
#define DELAY_LONG     1500
#define DELAY_SPACE    7000

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// 0 = 500
// 1 = 1500
const uint8_t sequence[MAX_SEQUENCE] PROGMEM = { 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1,
                                                 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 };

int main(void)
{
    DDRB |= (1 << LED_PIN) | (1 << TX_PIN);

    PORTB |= (1 << LED_PIN) | (1 << TX_PIN);
    _delay_us(DELAY_SHORT);
    PORTB &= ~(1 << TX_PIN);
    _delay_us(DELAY_SPACE);
    for (uint8_t i = 0; i < NUM_SEQ_REPEAT; i++)
    {
        for (uint8_t j = 0; j < MAX_SEQUENCE; j++)
        {
            PORTB ^= (1 << TX_PIN);
            if (pgm_read_byte_near(&sequence[j]) == 0)
                _delay_us(DELAY_SHORT);
            else
                _delay_us(DELAY_LONG);
        }
        PORTB ^= (1 << TX_PIN);
        _delay_us(DELAY_SPACE);
    }
    for (uint8_t k = 0; k < LAST_SEQUENCE; k++)
    {
        PORTB ^= (1 << TX_PIN);
        if (pgm_read_byte_near(&sequence[k]) == 0)
            _delay_us(DELAY_SHORT);
        else
            _delay_us(DELAY_LONG);
    }
    PORTB &= ~((1 << LED_PIN) | (1 << TX_PIN));

    return 0;
}
