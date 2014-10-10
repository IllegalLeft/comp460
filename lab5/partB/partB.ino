/*

    Lab 5 - Part B
    Traffic Lights
    Samuel Volk, 2014

    The arduino is attatched to a total of 5 LEDs. 3 are red, green and yellow
    for the traffic light. The two others are red and green for the walk light.
    Normally the traffic light is green while the walk light is red. If 10
    seconds of this has happened, the program can enter the ChangeLights()
    function when the button is pressed.

    ChangeLights()
    - turn the light from green to yellow (2 seconds) then red
    - wait 1 second before the walk light turns green
    - after a period of time (CrossTime) flash the walk lights on and off
      (0.2 seconds delay)
    - change the pedestrian light back to red and the traffic light to green

*/

int button = 12;

// Lights are numbered so that:
//  - green are first, then yellow to red
//  - traffic lights for the cars are first
int trafficRed      = 7;
int trafficYellow   = 6;
int trafficGreen    = 5;

int walkRed    = 9;
int walkGreen  = 8;

int CrossTime = 5000;

unsigned long delayStart;


void ChangeLights()
{
    // change traffic to yellow
    digitalWrite(trafficGreen, LOW);
    digitalWrite(trafficYellow, HIGH);
    delay(2000);

    // red traffic
    digitalWrite(trafficYellow, LOW);
    digitalWrite(trafficRed, HIGH);
    delay(1000);

    // Good to walk now!
    // Green the pedestrians
    digitalWrite(walkRed, LOW);
    digitalWrite(walkGreen, HIGH);
    delay(CrossTime);
    // Warning that the signal is gonna change
    // flash on and off 10 times with a 0.2s in between
    digitalWrite(walkGreen, LOW);
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(walkGreen, HIGH);
        delay(200);
        digitalWrite(walkGreen, LOW);
        delay(200);
    }

    // return the lights back to car having green
    digitalWrite(walkGreen, LOW);
    digitalWrite(walkRed, HIGH);
    digitalWrite(trafficRed, LOW);
    digitalWrite(trafficGreen, HIGH);
}


void setup()
{
    // LED pins
    pinMode(trafficGreen, OUTPUT);
    pinMode(trafficYellow, OUTPUT);
    pinMode(trafficRed, OUTPUT);
    pinMode(walkGreen, OUTPUT);
    pinMode(walkRed, OUTPUT);
    // push button
    pinMode(button, INPUT);

    // set pin defaults
    digitalWrite(trafficGreen, HIGH);
    digitalWrite(trafficYellow, LOW);
    digitalWrite(trafficRed, LOW);
    digitalWrite(walkGreen, LOW);
    digitalWrite(walkRed, HIGH);
}


void loop()
{
    delayStart = millis();

    while(1)
    {
        if(((millis() - delayStart) >= 10000) && digitalRead(button))
            break;
    }

    ChangeLights();

}
