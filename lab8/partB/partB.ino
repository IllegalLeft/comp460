/*

    Lab 8 - Part B
    Keypad & 7 Segment Display

    This sketch will display the digits from a keypad on a seven segment
    display. The digit will stay on the display for 5 seconds before allowing
    change to the next digit pressed.

    PROBLEMS & FIXES:
    - So right after writing all the code, it doesn't work... Wonder what's
      wrong this time :(  (gonna use serial to debug)
    - Looks like the ASCII math in the displayChars() function was subtracting
      47 when it should've been 48. Changed it.
    - The lower half of the keypad does not work and if pressed, the rest of
      the keypad does not work
    - fixed above bug: getKey()'s wait for release needed to access the array!
    - Some characters are wrong (2, 3, 4, 5, 7, 9)
    - Turns out 3, 5, & 9 were put into the chars array wrong. Fixing them only
      resulted in fixing 5 & 9. That means that our problem is with segments
      A and F!
    - I had the electrical connections for A and F switched. WHOOPS

*/

const int ROWS = 4;        // number of rows in the keypad
const int COLS = 3;        // number of columns in the keypad
const int DEBOUNCE = 20;   // debounce wait in ms
const int CHARS = 19;      // number of characters available

// Pins
const int sevSegPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int rowPins[ROWS] = {22, 24, 26, 28};
const int colPins[COLS] = {30, 32, 34};

const char keypad[ROWS][COLS] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

const int chars[CHARS][8] =
{
//   A  B  C  D  E  F  G  DP
    {1, 1, 1, 1, 1, 1, 0, 0},   // '0' - 0
    {0, 1, 1, 0, 0, 0, 0, 0},   // '1' - 1
    {1, 1, 0, 1, 1, 0, 1, 0},   // '2' - 2
    {1, 1, 1, 1, 0, 0, 1, 0},   // '3' - 3
    {0, 1, 1, 0, 0, 1, 1, 0},   // '4' - 4
    {1, 0, 1, 1, 0, 1, 1, 0},   // '5' - 5
    {1, 0, 1, 1, 1, 1, 1, 0},   // '6' - 6
    {1, 1, 1, 0, 0, 0, 0, 0},   // '7' - 7
    {1, 1, 1, 1, 1, 1, 1, 0},   // '8' - 8
    {1, 1, 1, 1, 0, 1, 1, 0},   // '9' - 9
    {1, 1, 1, 0, 1, 1, 1, 0},   // 'A' - 10
    {0, 0, 1, 1, 1, 1, 1, 0},   // 'B' - 11
    {1, 0, 0, 1, 1, 1, 0, 0},   // 'C' - 12
    {0, 1, 1, 1, 1, 0, 1, 0},   // 'D' - 13
    {1, 0, 0, 1, 1, 1, 1, 0},   // 'E' - 14
    {1, 0, 0, 0, 1, 1, 1, 0},   // 'F' - 15
    {0, 0, 0, 0, 0, 0, 0, 0},   // ' ' - 16
    {0, 0, 0, 0, 0, 0, 0, 1},   // '.' - 17
    {0, 0, 0, 0, 0, 0, 1, 0}    // '-' - 18
};

/* ========================================================================= */

int displayChar(char character)
{
    int index;  // index number for accessing correct array for the digit
    // find the right index
    switch (character)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            index = character - 48; // ASCII mathz
            break;                  // '0' = 48, so subtract 48 off to get 0!
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            index = character - 65 + 10;    // Same as above but 'A' = 65
            break;                          // Our 'A' is 10 so add 10
        case ' ':
            index = 16;
            break;
        case '.':
            index = 17;
            break;
        case '-':
            index = 18;
            break;
        case '#':
        case '*':
            index = 17;
            break;
        default:
            return 1; // That is one weird char... I can't display that!
    }

    // display that character
    for (int segment = 0; segment < 8; segment++)
        digitalWrite(sevSegPins[segment], chars[index][segment]);

    return 0; // Everything is all good!
}

char getKey()
{
    // iterate through columns
    for (int col = 0; col < COLS; col++)
    {
        // activate the current column for testing keys
        digitalWrite(colPins[col], LOW);
        // iterate through rows
        for (int row = 0; row < ROWS; row++)
        {
            // check for keypress
            if (digitalRead(rowPins[row]) == LOW)
            {
                delay(DEBOUNCE);
                // wait for key to be released
                while (digitalRead(rowPins[row]) == LOW); // << SEMI COLON
                return keypad[row][col];
            }
        }
        // turn the row back to the default
        digitalWrite(colPins[col], HIGH);
    }
    // return no key becuase none was found
    return 0;
}

/* ========================================================================= */

void setup()
{
    // Turn on the display pins (2-9)
    for (int i = 0; i < 8; i++)
        pinMode(sevSegPins[i], OUTPUT);

    // Turn on the keypad pins
    // Columns
    for (int i = 0; i < COLS; i++)
    {
        pinMode(colPins[i], OUTPUT);
        digitalWrite(colPins[i], HIGH); // active low
    }
    // Rows
    for (int i = 0; i < ROWS; i++)
    {
        pinMode(rowPins[i], INPUT_PULLUP);
        //digitalWrite(rowPins[i], HIGH); // pullup resistor
    }

    // default state
    displayChar('-');
}

void loop()
{
    char key = getKey();

    if (key != 0)
    {
        // display the digit
        displayChar(key);
        delay(1000);
        displayChar('-'); // clear display
    }
}
