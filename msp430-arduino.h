/**
 * \file msp430-arduino.h
 * \date 4 november 2021
 * \author Alexandre BARRAT
 * \version 1.0
 */



#define LOW  0
#define HIGH 1
#define INPUT  0
#define OUTPUT 1
#define INPUT_PULLUP 2



/**
 * \fn void pinMode(int pin, int mode)
 * \brief Set the mode of a pin (INPUT/OUTPUT/INPUT_PULLUP)
 * \param pin The pin to set the mode (10-17/20-27).
 * \param mode The mode to set (INPUT/OUTPUT/INPUT_PULLUP)
 */
void pinMode(int pin, int mode);



/**
 * \fn void digitalWrite(int pin, int value)
 * \brief Write a digital value on a pin.
 * \param pin The pin to modify (10-17/20-27).
 * \param value The digital value to write (LOW/HIGH)
 */
void digitalWrite(int pin, int value);



/**
 * \fn int digitalRead(int pin)
 * \brief Read the value of the given digital pin.
 * \param pin The pin to read (10-17/20-27).
 * \return value The digital value of the pin (0/1) or -1 if wrong pin.
 */
int digitalRead(int pin);
