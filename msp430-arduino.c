/**
 * \file msp430-arduino.c
 * \date 4 november 2021
 * \author Alexandre BARRAT
 * \version 1.1
 */

#include <msp430.h>
#include <msp430-arduino.h>


const static int BITS[8] = {BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7};

/**
 * \fn void pinMode(int pin, int mode)
 * \brief Set the mode of a pin (INPUT/OUTPUT)
 * \param pin The pin to set the mode (10-17/20-27).
 * \param mode The mode to set (INPUT/OUTPUT)
 * By default pull-up resistor is activated.
 */
void pinMode(int pin, int mode){
    // Parameters control
    if(pin < 10 || (17 < pin && pin < 20) || 27 < pin) return;
    if(mode != INPUT && mode != OUTPUT) return;

    // Get the bit and the port linked to the pin
    int port = pin / 10;
    pin = pin % 10;
    int bit = BITS[pin];

    switch(port){
    case 1:
        P1SEL &= ~bit;          // Set the pin as normal I/O
        P1SEL2 &= ~bit;         // Set the pin as normal I/O
        if(mode == INPUT) {
            P1DIR &= ~bit;      // Set the pin to input
            P1REN |= bit;       // Enable intern resistor
            P1OUT |= bit;       // Set the intern resistor as pull-up
        }
        else {
            P1DIR |= bit;       // Set the pin to output
            P1OUT &= ~bit;      // Set the output to 0
        }
        break;
    case 2:
        P2SEL &= ~bit;          // Set the pin as normal I/O
        P2SEL2 &= ~bit;         // Set the pin as normal I/O
        if(mode == INPUT) {
            P2DIR &= ~bit;      // Set the pin to input
            P2REN |= bit;       // Enable intern resistor
            P2OUT |= bit;       // Set the intern resistor as pull-up
        }
        else {
            P2DIR |= bit;       // Set the pin to output
            P2OUT &= ~bit;      // Set the output to 0
        }
        break;
    default:
        break;
    }
}



/**
 * \fn void digitalWrite(int pin, int value)
 * \brief Write a digital value on a pin.
 * \param pin The pin to modify (10-17/20-27).
 * \param value The digital value to write (LOW/HIGH)
 */
void digitalWrite(int pin, int value){
    if(pin < 10 || (17 < pin && pin < 20) || 27 < pin) return;
    if(value != LOW && value != HIGH) return;

    int port = pin / 10;
    pin = pin % 10;
    int bit = BITS[pin];

    switch(port){
    case 1:
        if(value == LOW) P1OUT &= ~bit;
        else             P1OUT |= bit;
        break;
    case 2:
        if(value == LOW) P2OUT &= ~bit;
        else             P2OUT |= bit;
        break;
    default:
        break;
    }
}



/**
 * \fn int digitalRead(int pin)
 * \brief Read the value of the given digital pin.
 * \param pin The pin to read (10-17/20-27).
 * \return value The digital value of the pin (0/1) or -1 if wrong pin.
 */
int digitalRead(int pin){
    if(pin < 10 || (17 < pin && pin < 20) || 27 < pin) return -1;

    int port = pin / 10;
    pin = pin % 10;
    int bit = BITS[pin];

    switch(port){
    case 1:
        if((P1IN & bit) == bit) return 1;
        else                    return 0;
        break;
    case 2:
        if((P2IN & bit) == bit) return 1;
        else                    return 0;
        break;
    default:
        break;
    }
}


