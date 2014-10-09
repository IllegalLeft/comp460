/*

    Lab 3 - Part A
    Samuel Volk, 2014

    This sketch blinks 6 LEDs one way using if statements.

*/

// create a counter to keep track of which pin to use
int led = 8;

// SETUP
void setup()
{
    // set pins 8 through 13 as outputs
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
}

// LOOP
void loop()
{
    // turn on the current LED
    digitalWrite(led, HIGH);
    // wait half a second
    delay(500);
    // turn off the LED
    digitalWrite(led, LOW);
    delay(5);

    // increment the counter
    led++;

    // if the next LED doesn't exist...
    if (led > 13)
    {
        // ...reset the current LED back to the start
        led = 8;
    }
}
