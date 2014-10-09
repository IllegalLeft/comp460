/*
crap i have to write about because it didn't work:


*/

int led = 8;
int tconst = 200;

void blink(int ontime, int offtime)
{
    digitalWrite(led, HIGH);
    delay(tconst * ontime);     // ontime is a multiplier...
    digitalWrite(led, LOW);     //
    delay(tconst * offtime);    // ...same with offtime
}


void setup()
{
    pinMode(led, OUTPUT);
    // all our pins are ready!
    // let's rock and roll ladies
}

void loop()
{
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
