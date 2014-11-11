/*

    Lab 7 -- Part C
    Date of Birth on 7 Segment
    Samuel Volk, 2014

    This sketch should display Samuel Volk's birth on a 7 segment display in the
    format of YYYY-MM-DD. Each digit will stay on for 0.75s, with an offtime of
    0.5s in between digits. The time between each section will be 1s. The time
    between delay between each iteration will be determined by the DD
    (DD x 100ms). It's modified from the part B.

    PROBLEMS & FIXES:
    - So turns out I don't have a common cathode 7 segment so I am using a
      common anode one with 2 x 74LS04 hex inverters. It should work the same
      with a common cathode though.

*/

const int day = 16;

byte birthday[10][7] = {
    { 0,1,1,0,0,0,0 }, // = 1
    { 1,1,1,1,0,1,1 }, // = 9
    { 1,1,1,1,0,1,1 }, // = 9
    { 1,1,1,1,0,0,1 }, // = 3
    { 0,0,0,0,0,0,1 }, // = -
    { 0,1,1,0,0,0,0 }, // = 1
    { 1,1,1,1,1,1,0 }, // = 0
    { 0,0,0,0,0,0,1 }, // = -
    { 0,1,1,0,0,0,0 }, // = 1
    { 1,0,1,1,1,1,1 }, // = 6
};

void setup()
{
    for(int i = 2; i < 10; i++)
    {
        pinMode(i, OUTPUT);
    }
    writeDot(0); // start with the "dot" off
}

void loop() {
    for (int count = 0; count < 10; count++)
    {
        sevenSegWrite(count);
        if ((count == 4) || (count == 7))   // special delay for '-'
            delay(1000);
        else 
            delay(750);                     // normal delay
        // turn of all LEDs currently on
        for (int i = 0; i < 7; i++)
        {
            if (birthday[count][i] == 1)
                digitalWrite(i+2, 0);
        }
        delay(500);
    }
    delay(day * 100);
}

void writeDot(int dot) {
    digitalWrite(9, dot);
}

void sevenSegWrite(byte digit) {
    byte pin = 2;
    for (byte segCount = 0; segCount < 7; ++segCount)
    {
        digitalWrite(pin, birthday[digit][segCount]);
        ++pin;
    }
}
