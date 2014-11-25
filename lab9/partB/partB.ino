/*

    Lab 9 -- Part B
    LCD & TMP36
    Samuel Volk, 2014


    The arduino is connected to a TMP36 and a 2x16 LCD display. It will read
    the voltages off the TMP36 and then display the reading on the LCD screen.

*/

#include <LiquidCrystal.h>

#define DEGREES B10110010

// Pins
const int tmp36 = 0;

// Constants
const int rows = 2;
const int cols = 16;

// LCD setup
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    // LCD Display
    lcd.begin(rows, cols);
}


void loop()
{
    // read TMP36
    int reading = analogRead(0);

    float voltage, celsius, fahrenheit, kelvin, rankine;


    // calculate values
    // millivolts
    voltage = map(reading, 0, 255, 0, 5000);
    // Celsius
    celsius = (voltage - 500.0) / 100.0;
    // Fahrenheit
    fahrenheit = celsius * (9.0/5.0) + 32.0;
    // Kelvin
    kelvin = celsius + 273.15;
    // Rankine
    rankine = (celsius + 273.15) * (9.0/5.0);

    // display values
    // Celsius
    lcd.print(celsius);
    lcd.write(DEGREES);
    lcd.print("C");
    // Fahrenheit
    lcd.setCursor(8, 0);
    lcd.print(fahrenheit);
    lcd.write(DEGREES);
    lcd.print("F");
    // Kelvin
    lcd.setCursor(0, 1);
    lcd.print(kelvin);
    //lcd.write(DEGREES);
    lcd.print("K");
    // Rankine
    lcd.setCursor(8, 1);
    lcd.print(rankine);
    lcd.write(DEGREES);
    lcd.write("R");

    delay(1000);
    lcd.clear();
}
