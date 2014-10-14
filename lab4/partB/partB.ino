/*
    Lab 4 - Part B
    SOS LED

    Samuel Volk, 07/10/2014

    This sketch just blinks an LED with morse code of "SOS". It blinks it 5
    times then waits 1 second then repeats. Dits are 1 unit, dahs are 3, there
    is a 7 unit wait between words ("SOS" is a word), 1 unit in between
    letters.


    Debugging and Verification:
    - moved repetitive blinking code to blink() function
    - wrote wait() function
    - modified blink() function to include delays so delay() is now not needed
    - blink rate a little too slow, was 250 now set to 200
*/

// Global variables
int led = 8;        // led pin #
int tconst = 200;   // time constant value


// blink function to blink led with an on time and an offtime (both multiplied
// against the time constant)
void blink(int ontime, int offtime)
{
    digitalWrite(led, HIGH);
    delay(tconst * ontime);     // ontime is a multiplier...
    digitalWrite(led, LOW);     //
    delay(tconst * offtime);    // ...same with offtime
}


void setup()
{
    pinMode(led, OUTPUT);   // all our pins are ready!
                            // let's rock and roll ladies
}

void loop()
{
     // cycle 5 times through SOS
    for (int i = 0; i < 5; i++)
    {
        // S
        // ...
        blink(1, 1);
        blink(1, 1);
        blink(1, 3);    // 3 time constants because end of letter

        // O
        // ---
        blink(3, 1);
        blink(3, 1);
        blink(3, 3);    // 3 time constants because end of letter

        // S
        // ...
        blink(1, 1);
        blink(1, 1);
        blink(1, 7);    // 7 time constants because end of word
    }

    // standard wait between 5 cycles
    delay(1000);
}
