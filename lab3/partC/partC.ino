/*

    Lab 3 - Part C
    Samuel Volk, 2014

    This program makes 6 LEDs blink in succession one way then back using for
    loops.

*/


int led = 13; // Start at 10 and decrement

// the setup routine runs once when you press reset:
void setup()
{
    // initialize the digital pins 8 through 13 as an output.
    for (led = 8; led <= 13; led++)
    {
        pinMode(led, OUTPUT);
    }
}

void loop()
{
    // turn on the LEDs one way...
    for (led = 13; led > 8; led--)
    {
        digitalWrite(led, HIGH);    // turn the LED on (HIGH)
        delay(500);                 // wait for a second
        digitalWrite(led, LOW);     // turn the LED off (LOW)
        delay(5);                   // wait for a second
    }

    // ...turn on the LEDs the other way
    for (led = 8; led < 13; led++)
    {
        digitalWrite(led, HIGH);    // turn the LED on (HIGH)
        delay(500);                 // wait for a second
        digitalWrite(led, LOW);     // turn the LED off (LOW)
        delay(5);                   // wait for a second
    }
}
