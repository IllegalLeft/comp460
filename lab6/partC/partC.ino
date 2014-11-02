/*

   pew

*/

int led1Pin = 12;   // first LED is connected to pin 12
int led2Pin = 11;   // second LED is connected to pin 11
int switchPin = 2;  // switch is connected to pin 2

int val;                    // variable for reading the pin status
unsigned int presses = 0;   // number of button presses

void setup() {
    pinMode(led1Pin, OUTPUT);   // Set the LED pin as output
    pinMode(led2Pin, OUTPUT);
    pinMode(switchPin, INPUT);  // Set the switch pin as input

    Serial.begin(9600); // start serial communications
}

void loop() {
    val = digitalRead(switchPin);   // read input value and store it in val

    if (val == LOW) {   // check if the button is pressed
        presses++;  // one button press!

        digitalWrite(led1Pin, HIGH);    // turn first LED on
        digitalWrite(led2Pin, LOW);     // turn off second LED

        Serial.println("LED 1 is ON.");
        Serial.println("LED 2 is OFF.");
    }

    if (val == HIGH) {  // check if the button is not pressed
        digitalWrite(led1Pin, LOW);     // turn first LED off
        digitalWrite(led2Pin, HIGH);    // turn on second LED

        Serial.println("LED 1 is OFF.");
        Serial.println("LED 2 is ON.");
    }

    while (val == digitalRead(switchPin))
    {
        // do nothing because the state has not changed
    }

    Serial.print("The button has been pressed ");
    Serial.print(presses);
    Serial.println(" times.");
}
