/* Switch and LED test program */

int led1Pin = 12;   // first LED is connected to pin 12
int led2Pin = 11;   // second LED is connected to pin 11
int switchPin = 2;  // switch is connected to pin 2
int val;            // variable for reading the pin status

void setup() {
    pinMode(led1Pin, OUTPUT);   // Set the LED pin as output
    pinMode(led2Pin, OUTPUT);
    pinMode(switchPin, INPUT);  // Set the switch pin as input
}

void loop() {
    val = digitalRead(switchPin);   // read input value and store it in val

    if (val == LOW) {   // check if the button is pressed
        digitalWrite(led1Pin, HIGH);    // turn first LED on
        digitalWrite(led2Pin, LOW);     // turn off second LED
    }

    if (val == HIGH) {  // check if the button is not pressed
        digitalWrite(led1Pin, LOW);     // turn first LED off
        digitalWrite(led2Pin, HIGH);    // turn on second LED
    }
}
