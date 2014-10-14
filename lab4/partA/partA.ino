/*
    Lab 4 - Part A
    Potentiometer + LED Blinking speed control

    Samuel Volk, 07/10/2014

    This sketch makes 10 LEDs blink one way but the speed is controlled by a
    potentiometer.


    Debugging and Verification
    - copied 4-b from powerpoint but most of the whitespace messed up, fixed
    - needed to sop LEDs from cycling back so commented out both reversing
      lines, LEDs went one way then randomly blinked (overflow or something?)
    - uncommented on reversing line, LEDs blinked one way then the other then
      stopped
    - changed single remaining reversing if() statement to reset current LED
      back to 0, works
*/


// Global Variables
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};// Create array for LED pins
int ledDelay;               // delay between changes
int direction = 1;          // holds step + direction
int currentLED = 0;         // holds current LED
unsigned long changeTime;   // time since delay started related to the
                            // processor runtime
int potPin = 2;             // select the input pin for the potentiometer


void setup()
{
    for (int x=0; x<10; x++)
        pinMode(ledPin[x], OUTPUT); // set all pins to output

    changeTime = millis();
}

void loop()
{
    ledDelay = analogRead(potPin); // read the value from the pot

    if ((millis() - changeTime) > ledDelay) // has it been longer than ledDelay
                                            // since last blink
    {
        for (int x=0; x<10; x++)
        {
            digitalWrite(ledPin[x], LOW); // turn off all LED's
        }
        digitalWrite(ledPin[currentLED], HIGH); // turn on the current LED

        currentLED += direction; // increment by the direction value

        // return to the start if the end is reached
        if (currentLED == 10) currentLED = 0;

        // reset time since last blink
        changeTime = millis();
    }
}
