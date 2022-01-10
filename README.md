# MSP430-Arduino

This project is a simple C library adding some Arduino elements to the Launchpad board of Texas Instrument based on the MSP430.
Functions are based on [Arduino References](https://www.arduino.cc/reference/en/)

Code is commented but you can find documentation [here](./msp430-arduino.pdf).


## Functions
This table groups Arduino's functions and there equivalent for MSP430.

| Category       | Arduino              | MSP430         | Header           |
| -------------- | -------------------- | -------------- | ---------------- |
| Digital I/O    | digitalRead()        | digitalRead()  | msp430-arduino.h |
| Digital I/O    | digitalWrite()       | digitalWrite() | msp430-arduino.h |
| Digital I/O    | pinMode()            | pinMode()      | msp430-arduino.h |
| Analog I/O     | analogRead()         |                |                  |
| Analog I/O     | analogReference()    |                |                  |
| Analog I/O     | analogWrite()        |                |                  |
| Advanced I/O   | noTone()             |                |                  |
| Advanced I/O   | pulseIn()            |                |                  |
| Advanced I/O   | pulseInLong()        |                |                  |
| Advanced I/O   | shiftIn()            |                |                  |
| Advanced I/O   | shiftOut()           | shiftOut()     | msp430-arduino.h |
| Advanced I/O   | tone()               |                |                  |
| Time           | delay()              |                |                  |
| Time           | delayMicroseconds()  |                |                  |
| Time           | micros()             |                |                  |
| Time           | millis()             |                |                  |
| Math           | abs()                | abs()          | msp430-arduino.h |
| Math           | constrain()          | constrain()    | msp430-arduino.h |
| Math           | map()                |                |                  |
| Math           | max()                | max()          | msp430-arduino.h |
| Math           | min()                | min()          | msp430-arduino.h |
| Math           | pow()                | pow()          | math.h           |
| Math           | sq()                 | sq()           | msp430-arduino.h |
| Math           | sqrt()               | sqrt()         | math.h           |
| Math           | round()              | round()        | msp430-arduino.h |
| Trigonometry   | radians()            | radians()      | msp430-arduino.h |
| Trigonometry   | degrees()            | degrees()      | msp430-arduino.h |
| Trigonometry   | cos()                | cos()          | math.h           |
| Trigonometry   | sin()                | sin()          | math.h           |
| Trigonometry   | tan()                | tan()          | math.h           |
| Characters     | isAlpha()            | isalpha()      | ctype.h          |
| Characters     | isAlphaNumeric()     | isalphanum()   | ctype.h          |
| Characters     | isAscii()            | isascii()      | ctype.h          |
| Characters     | isControl()          | iscntrl()      | ctype.h          |
| Characters     | isDigit()            | isdigit()      | ctype.h          |
| Characters     | isGraph()            | isgraph()      | ctype.h          |
| Characters     | isHexadecimalDigit() | isxdigit()     | ctype.h          |
| Characters     | isLowerCase()        | islower()      | ctype.h          |
| Characters     | isPrintable()        | isprint()      | ctype.h          |
| Characters     | isPunct()            | ispunct()      | ctype.h          |
| Characters     | isSpace()            | isspace()      | ctype.h          |
| Characters     | isUpperCase()        | isupper()      | ctype.h          |
| Characters     | isWhitespace()       | isblank()      | ctype.h          |
| Random Numbers | random()             | rand()         | stdlib.h         |
| Random Numbers | randomSeed()         | srand()        | stdlib.h         |
| Bits and Bytes | bit()                | bit()          | msp430-arduino.h |
| Bits and Bytes | bitClear()           | bitClear()     | msp430-arduino.h |
| Bits and Bytes | bitRead()            | bitRead()      | msp430-arduino.h |
| Bits and Bytes | bitSet()             | bitSet()       | msp430-arduino.h |
| Bits and Bytes | bitWrite()           | bitWrite()     | msp430-arduino.h |
| Bits and Bytes | bitToggle()          | bitToggle()    | msp430-arduino.h |
| Bits and Bytes | highByte()           | highByte()     | msp430-arduino.h |
| Bits and Bytes | lowByte()            | lowByte()      | msp430-arduino.h |
| Interrupts     | interrupts()         |                |                  |
| Interrupts     | noInterrupts()       |                |                  |


## Example
```c
#include <msp430.h>
#include "msp430-arduino.h"

#define PIN_LED    12  // A LED on the pin 2 of the port 1
#define PIN_BUTTON 22  // A button on the pin 2 of the port 2

// Copy button state to the LED
void main(){
    pinMode(PIN_LED, OUTPUT);    // Set the LED pin as an output
    pinMode(PIN_BUTTON, INPUT);  // Set the button pin as an input

    while(1){
        digitalWrite(PIN_LED, digitalRead(PIN_BUTTON));
    }
}
```


## Changelog
* 1.2 : Add shiftOut() and BUILTIN_LED
* 1.1 : Add port 1 to digital I/O functions
* 1.0 : Only port 2 digital I/O functions


## License
This project is under the [CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/) license.  
![CC BY-NC-SA logo](https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png)
