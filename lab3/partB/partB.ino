/*

    Lab 3 - Part B
    Samuel Volk, 2014

    This program makes 6 LEDs blink in succession one way then back using while
    loops.

*/

// set starting pin
int led = 13;

void setup() {
    // set pin modes for pins 8 through 13 as output
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    while (led > 8)
    {
        digitalWrite(led, HIGH);    // turn the LED on (HIGH)
        delay(500);                 // wait for a second
        digitalWrite(led, LOW);     // turn the LED off (LOW)
        delay(5);                   // wait for a second
        led = led--;                // decrement
    }

    while (led < 13)
    {
        digitalWrite(led, HIGH);    // turn the LED on (HIGH)
        delay(500);                 // wait for a second
        digitalWrite(led, LOW);     // turn the LED off (LOW)
        delay(5);                   // wait for a second
        led = led++;                // increment
    }

    led = 13;
}
