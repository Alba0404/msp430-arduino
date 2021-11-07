/**
 * \file msp430-arduino.c
 * \date 4 november 2021
 * \author Alexandre BARRAT
 * \version 1.0
 */

#include <msp430-arduino.h>
#include <msp430.h>


const static int BITS[8] = {BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7};

/**
 * \fn void pinMode(int pin, int mode)
 * \brief Set the mode of a pin (INPUT/OUTPUT)
 * \param pin The pin of the port 2 to modify (0-7).
 * \param mode The mode to set (INPUT/OUTPUT)
 * By default pull-up resistor is activated.
 */
void pinMode(int pin, int mode){
    // Parameters control
    if(pin < 0 || 7 < pin) return;
    if(mode != INPUT && mode != OUTPUT) return;

    // Get the bit linked to the pin
    int bit = BITS[pin];

    // Set the pin as normal I/O
    P2SEL &= ~bit;
    P2SEL2 &= ~bit;

    if(mode == INPUT) {
        P2DIR &= ~bit;      // Set the pin to input
        P2REN |= bit;       // Enable intern resistor
        P2OUT |= bit;       // Set the intern resistor as pull-up
    }
    else {
        P2DIR |= bit;       // Set the pin to output
        P2OUT &= ~bit;      // Set the output to 0
    }
}



/**
 * \fn void digitalWrite(int pin, int value)
 * \brief Write a digital value on a pin.
 * \param pin The pin to modify.
 * \param value The digital value to write (LOW/HIGH)
 */
void digitalWrite(int pin, int value){
    if(pin < 0 || 7 < pin) return;
    if(value != LOW && value != HIGH) return;

    int bit = BITS[pin];
    if(value == LOW) P2OUT &= ~bit;
    else             P2OUT |= bit;
}



/**
 * \fn int digitalRead(int pin)
 * \brief Read the value from the given digital pin.
 * \param pin The pin to read.
 * \return value The digital value on the pin (LOW/HIGH)
 */
int digitalRead(int pin){
    if(pin < 0 || 7 < pin) return -1;
    int bit = BITS[pin];
    if((P2IN & bit) == bit) return 1;
    else                    return 0;
}

