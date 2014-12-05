/*

    Final Project -- COMP460
    Samuel Volk, 2014

    A 2x16 LCD, red & green LED, pushbutton, and servo motor will be connected
    to the arduino. When the push button is pressed, the servo will sweep back
    and forth between 0 and 180 degrees. When the push button is released, the
    servo will no longer sweep and remain still The red LED lights up when the
    servo reaches 0 and 180 degrees while the green LED lights up during the
    rest of the sweep. The LCD will display whether the servo is "ON" or "OFF"
    as well as the current position in degrees, the total degrees swept, and
    number of complete 180 cycles.

    PROBLEMS AND FIXES:
    - LCD screen doesn't work. Only half-lit blocks on top row
    - Above problem was fixed by modifying the lcd() call
    - When the servo is not in use, the screen flickers: needs a delay?
    - You can set a manual delay but it only prevents the servo from working at
      higher speeds. I am adding a delay with millis() so that the screen is
      only refreshed about every 300ms or some other delay while the motor can
      still be moved
    - a simple delay is not a real debounce so I added a real debounce. It
      doesn't work.
    - scanButton() rewritten

*/

// Libraries
#include <LiquidCrystal.h>
#include <Servo.h>


// Pins
#define PIN_SERVO       30

#define PIN_RED_LED     24
#define PIN_GREEN_LED   22

#define PIN_SWITCH      28


// LCD
#define LCD_ROWS    2
#define LCD_COLS    16
#define LCD_REFRESH 200 // ms
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
unsigned long lastRefresh = 0;

// Servo
#define SERVO_UPPER 180 // degrees
#define SERVO_LOWER 5   // degrees
Servo servomotor;

// Debounce
#define DEBOUNCE_TIME   20//ms
unsigned long lastPress = 0;

bool moving = false;
int direction = 1;
int angle = 0;
int degreesSwept = 0;
int cycles = 0;


bool scanButton()   // returns LOW if pressed
{
    bool status = digitalRead(PIN_SWITCH);

    // initial peak for debounce (start of debounce)
    if (status == LOW && moving == false)
    {
        lastPress = millis();
        return LOW;
    }
    // debounce time
    else if (millis() - lastPress <= DEBOUNCE_TIME)
    {
        return LOW;
    }
    // normal pressed button operation
    else if (status == LOW)
    {
        return LOW;
    }

    return HIGH;
}


void setup()
{
    lcd.begin(LCD_COLS, LCD_ROWS);

    servomotor.attach(PIN_SERVO);
    // set at starting position
    servomotor.write(SERVO_LOWER + 1);
    angle = servomotor.read();

    pinMode(PIN_RED_LED, OUTPUT);
    pinMode(PIN_GREEN_LED, OUTPUT);

    pinMode(PIN_SWITCH, INPUT_PULLUP);
}


void loop()
{

    while ((millis() - lastRefresh) <= LCD_REFRESH)
    {

        // Check push button
        if (scanButton() == LOW)
        {
            // move servo
            moving = true;
            // switch directions if servo is at end of the sweep
            if (angle >= SERVO_UPPER)       // upper limit
                direction = -1;
            else if (angle <= SERVO_LOWER)  // lower limit
            {
                direction = 1;
                // everytime it reaches back to here, the one cycle is complete
                cycles++;
            }

            angle += direction;
            degreesSwept += abs(direction);
            servomotor.write(angle);
            delay(25); // let the motor catch up
        }
        else
            moving = false;

        // turn on LEDs
        if (angle <= SERVO_LOWER || angle >= SERVO_UPPER)
        {
            digitalWrite(PIN_RED_LED, HIGH);
            digitalWrite(PIN_GREEN_LED, LOW);
        }
        else
        {
            digitalWrite(PIN_RED_LED, LOW);
            digitalWrite(PIN_GREEN_LED, HIGH);
        }
    }

    // display info
    lcd.clear();
    // status
    if (moving)
        lcd.print("ON");
    else
        lcd.print("OFF");
    // angle
    lcd.setCursor(8, 0);
    lcd.print(angle);
    // degrees swept
    lcd.setCursor(0, 1);
    lcd.print(degreesSwept);
    // cycles
    lcd.setCursor(8, 1);
    lcd.print(cycles);



    lastRefresh = millis();
}
