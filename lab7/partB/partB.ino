byte seven_seg_digits[16][7] = {
    { 1,1,1,1,1,1,0 }, // = 0
    { 0,1,1,0,0,0,0 }, // = 1
    { 1,1,0,1,1,0,1 }, // = 2
    { 1,1,1,1,0,0,1 }, // = 3
    { 0,1,1,0,0,1,1 }, // = 4
    { 1,0,1,1,0,1,1 }, // = 5
    { 1,0,1,1,1,1,1 }, // = 6
    { 1,1,1,0,0,0,0 }, // = 7
    { 1,1,1,1,1,1,1 }, // = 8
    { 1,1,1,1,0,1,1 }, // = 9
    { 1,1,1,0,1,1,1 }, // = A
    { 0,0,1,1,1,1,1 }, // = B
    { 1,0,0,1,1,1,0 }, // = C
    { 0,1,1,1,1,0,1 }, // = D
    { 1,0,0,1,1,1,1 }, // = E
    { 1,0,0,0,1,1,1 }  // = F
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
    for (int count = 15; count >= 0; count--)
    {
        delay(1000);
        sevenSegWrite(count);
    }
    delay(4000);
}

void writeDot(int dot) {
    digitalWrite(9, dot);
}

void sevenSegWrite(byte digit) {
    byte pin = 2;
    for (byte segCount = 0; segCount < 7; ++segCount)
    {
        digitalWrite(pin, seven_seg_digits[digit][segCount]);
        ++pin;
    }
}
