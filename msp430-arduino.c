/**
 * \file msp430-arduino.c
 * \date 1 march 2022
 * \author Alexandre BARRAT
 * \version 1.3
 */

#include <msp430.h>
#include "msp430-arduino.h"


// Linked bits to their positions.
const static int BITS[8] = {BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7};

/**
 * \fn static int isACorrectPin(int pin)
 * \brief Test if the given pin exist.
 * \param pin The pin to test.
 */
static int isACorrectPin(int pin){
    int ret = 0;
    if(pin < 10 || (17 < pin && pin < 20) || 27 < pin){
        ret = 0;
    }
    else {
        ret = 1;
    }
    return ret;
}



/**
 * \fn void pinMode(int pin, int mode)
 * \brief Set the mode of a pin (INPUT/OUTPUT/INPUT_PULLUP)
 * \param pin The pin to set the mode (10-17/20-27).
 * \param mode The mode to set (INPUT/OUTPUT/INPUT_PULLUP)
 */
void pinMode(int pin, int mode){
    // Parameters control
    if(isACorrectPin(pin)){
        if(mode == INPUT || mode == OUTPUT || mode == INPUT_PULLUP){

            // Get the bit and the port linked to the pin
            int port = pin / 10;
            pin = pin % 10;
            int bit = BITS[pin];

            switch(port){
            case 1:
                P1SEL &= ~bit;          // Set the pin as normal I/O
                P1SEL2 &= ~bit;         // Set the pin as normal I/O
                switch(mode){
                case INPUT_PULLUP:
                    P1DIR &= ~bit;      // Set the pin to input
                    P1REN |= bit;       // Enable intern resistor
                    P1OUT |= bit;       // Set the intern resistor as pull-up
                    break;
                case OUTPUT:
                    P1DIR |= bit;       // Set the pin to output
                    P1OUT &= ~bit;      // Set the output to 0
                    break;
                case INPUT:
                    P1DIR &= ~bit;      // Set the pin to input
                    P1REN |= bit;       // Enable intern resistor
                    P1OUT &= ~bit;      // Set the intern resistor as pull-down
                    break;
                default:
                    break;
                }
                break;
            case 2:
                P2SEL &= ~bit;          // Set the pin as normal I/O
                P2SEL2 &= ~bit;         // Set the pin as normal I/O
                switch(mode){
                case INPUT_PULLUP:
                    P2DIR &= ~bit;      // Set the pin to input
                    P2REN |= bit;       // Enable intern resistor
                    P2OUT |= bit;       // Set the intern resistor as pull-up
                    break;
                case OUTPUT:
                    P2DIR |= bit;       // Set the pin to output
                    P2OUT &= ~bit;      // Set the output to 0
                    break;
                case INPUT:
                    P2DIR &= ~bit;      // Set the pin to input
                    P2REN |= bit;       // Enable intern resistor
                    P2OUT &= ~bit;      // Set the intern resistor as pull-down
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
}



/**
 * \fn void digitalWrite(int pin, int value)
 * \brief Write a digital value on a pin.
 * \param pin The pin to modify (10-17/20-27).
 * \param value The digital value to write (LOW/HIGH)
 */
void digitalWrite(int pin, int value){
    if(isACorrectPin(pin)){
        if(value == LOW || value == HIGH){
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
    }
}



/**
 * \fn int digitalRead(int pin)
 * \brief Read the value of the given digital pin.
 * \param pin The pin to read (10-17/20-27).
 * \return value The digital value of the pin (0/1) or 0 if wrong pin.
 */
int digitalRead(int pin){
    int value = LOW;
    if(isACorrectPin(pin)){

        int port = pin / 10;
        pin = pin % 10;
        int bit = BITS[pin];

        switch(port){
        case 1:
            if((P1IN & bit) == bit) {
                if((P1OUT & bit) == bit) value = LOW;
                else                     value = HIGH;
            }
            else {
                if((P1OUT & bit) == bit) value = HIGH;
                else                     value = LOW;
            }
            break;
        case 2:
            if((P2IN & bit) == bit) {
                if((P2OUT & bit) == bit) value = LOW;
                else                     value = HIGH;
            }
            else {
                if((P2OUT & bit) == bit) value = HIGH;
                else                     value = LOW;
            }
            break;
        default:
            break;
        }
    }

    return value;
}



/**
 * \fn void shiftOut(dataPin, clockPin, bitOrder, value)
 * \brief Shifts out a byte of data one bit at a time.
 * \param dataPin The pin to send data (10-17/20-27).
 * \param clockPin The pin for the clock (10-17/20-27).
 * \param bitOrder The first bit to shift : most or least significant (MSBFIRST/LSBFIRST).
 */
void shiftOut(int dataPin, int clockPin, int bitOrder, unsigned char value){
    if(dataPin < 10 || (17 < dataPin && dataPin < 20) || 27 < dataPin) return;
    if(clockPin < 10 || (17 < clockPin && clockPin < 20) || 27 < clockPin) return;
    if(bitOrder != MSBFIRST && bitOrder != LSBFIRST) return;
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    int BYTE_SIZE = 8;
    int i, t;
    unsigned char c;
    for(i=BYTE_SIZE; i>0; i--){
        if(bitOrder == MSBFIRST) c = value >> i-1;
        else                     c = value >> BYTE_SIZE-i;
        c &= 0x01;
        digitalWrite(dataPin, (int)c);
        digitalWrite(clockPin, HIGH);
        for(t=32000; t>0; t--);
        digitalWrite(clockPin, LOW);
        for(t=32000; t>0; t--);
    }
    digitalWrite(dataPin, LOW);
    digitalWrite(clockPin, LOW);
}



/**
 * \fn void analogWrite(int pin, int value)
 * \brief Write a PWM to the given pin. The frequency of the PWM is 490Hz.
 * \param pin The pin to write PWM (10-17/20-27).
 * \param value Duty cycle of the PWM (0-255).
 */
void analogWrite(int pin, int value){
    if(isACorrectPin(pin)){
        int port = pin / 10;
        pin = pin % 10;
        int bit = BITS[pin];

        switch(port){
        case 1:
            P1DIR |= bit;
            P1SEL |= bit;
            P1SEL2 &= ~bit;
            break;
        case 2:
            P2DIR |= bit;
            P2SEL |= bit;
            P2SEL2 &= ~bit;
            break;
        default:
            break;
        }
        TA1CTL = TASSEL_2 | MC_1;
        TA1CCTL1 |= OUTMOD_7;
        TA1CCR0 = PWM_DELAY;
        TA1CCR1 = (int) PWM_DELAY * (value/255);
    }
}

