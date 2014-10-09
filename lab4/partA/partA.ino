byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Create array for LED pins
int ledDelay;   // delay between changes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2; // select the input pin for the potentiometer


void setup()
{
    for (int x=0; x<10; x++)
        pinMode(ledPin[x], OUTPUT); // set all pins to output

    changeTime = millis();
}

void loop()
{
    ledDelay = analogRead(potPin); // read the value from the pot

    if ((millis() - changeTime) > ledDelay) // if it has been ledDelay ms since last change
    {
        for (int x=0; x<10; x++)
        {
            digitalWrite(ledPin[x], LOW); // turn off all LED's
        }
        digitalWrite(ledPin[currentLED], HIGH); // turn on the current LED

        currentLED += direction; // increment by the direction value

        // return to the start if the end is reached
        if (currentLED == 10) currentLED = 0;

        changeTime = millis();
    } //close if
} //close loop
