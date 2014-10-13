byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Create array for LED pins
int ledDelay; // delay between changes
float reading;
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2; // select the input pin for the potentiometer

void setup()
{
    for (int x=0; x<10; x++)
        pinMode(ledPin[x], OUTPUT); // set all pins to output

    Serial.begin(9600);

    changeTime = millis();
}

void loop()
{
    ledDelay = analogRead(potPin); // read the value from the pot
    reading = ledDelay;

    // send pot data for debugging
    Serial.println(reading);
    Serial.print(4.9 * reading);
    Serial.println("mV");
    Serial.print((reading / 1024) * 100);
    Serial.println("%");

    if ((millis() - changeTime) > ledDelay) // if it has been ledDelay ms since last change
    {
        for (int x=0; x<10; x++)
            digitalWrite(ledPin[x], LOW); // turn off all LED's

        digitalWrite(ledPin[currentLED], HIGH); // turn on the current LED

        currentLED += direction; // increment by the direction value

        // change direction if we reach the end
        if (currentLED == 9) direction = -1;
        if (currentLED == 0) direction = 1;

        changeTime = millis();
    } //close if
} //close loop}
