/*

    Lab 3 - Part D
    Samuel Volk, 2014

    This program blinks 10 LEDs from both ends to the center then back.

*/


// set current LED
int currentLED;

// the setup function is run once at the start
void setup()
{
    // set pins 4 through 13 as outputs
    for (currentLED = 4; currentLED <= 13; currentLED++)
        pinMode(currentLED, OUTPUT);
}

// the loop function is ran forever
void loop()
{
    // blink the LEDs from the outside, inwards so that they overlap and then
    // outwards
    for (currentLED = 4; currentLED <= 13; currentLED++)
    {
        // turn on the correct pins
        digitalWrite(currentLED, HIGH);
        digitalWrite(13 - (currentLED - 4), HIGH);
        // wait half a second
        delay(500);
        // turn off the pins
        digitalWrite(currentLED, LOW);
        digitalWrite(13 - (currentLED - 4), LOW);
    }
}
