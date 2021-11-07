# MSP430-Arduino

This project is a simple C library adding some Arduino functions to the MSP430 board of Texas Instrument.

Code is commented but you can find documentation [here](./msp430-arduino.pdf).


## Example
```c
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
* 1.1 : Add port 1 to digital I/O functions
* 1.0 : Only port 2 digital I/O functions


## License
This project is under the [CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/) license.  
![CC BY-NC-SA logo](https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png)
