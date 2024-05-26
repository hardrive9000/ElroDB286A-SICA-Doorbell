#define TX_PIN         5   // Wemos D1 Mini -> 5 GPIO5(D1) // ATtiny13 -> 4
#define LED_PIN        4   // Wemos D1 Mini -> 4 GPIO4(D2) // ATtiny13 -> 3

#define MAX_SEQUENCE   66
#define LAST_SEQUENCE  63
#define NUM_SEQ_REPEAT 19

// 34262a6c
const word sequence[MAX_SEQUENCE] PROGMEM = { 1500, 500, 1500, 500, 500, 1500, 500, 1500, 1500, 500, 500, 1500, 1500, 500, 1500, 500, 1500, 500, 1500, 500, 500, 1500, 1500, 500, 1500, 500, 500, 1500, 500, 1500, 1500, 500, 1500,
                                              500, 1500, 500, 500, 1500, 1500, 500, 500, 1500, 1500, 500, 500, 1500, 1500, 500, 1500, 500, 500, 1500, 500, 1500, 1500, 500, 500, 1500, 500, 1500, 1500, 500, 1500, 500, 500, 7000 };

bool state = HIGH;

void setup()
{
    pinMode(TX_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    //--- Start sequence ---
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(TX_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(TX_PIN, LOW);
    delayMicroseconds(7000);
    for(byte i = 0; i < NUM_SEQ_REPEAT; i++)
    {
        for(byte j = 0; j < MAX_SEQUENCE; j++)
        {
            digitalWrite(TX_PIN, state);
            delayMicroseconds(pgm_read_word_near(&sequence[j]));
            state = !state;
        }
    }
    state = HIGH;
    for(byte k = 0; k < LAST_SEQUENCE; k++)
    {
        digitalWrite(TX_PIN, state);
        delayMicroseconds(pgm_read_word_near(&sequence[k]));
        state = !state;
    }
    digitalWrite(TX_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    //--- End sequence ---
}

void loop()
{
}
