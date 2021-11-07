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



/**
 * \fn pinMode
 * \brief Set the mode of a pin (INPUT/OUTPUT)
 * \param pin The pin of the port 2 to modify (0-7).
 * \param mode The mode to set (INPUT/OUTPUT)
 * By default pull-up resistor is activated.
 */
void pinMode(int pin, int mode);



/**
 * \fn digitalWrite
 * \brief Write a digital value on a pin.
 * \param pin The pin to modify.
 * \param value The digital value to write (LOW/HIGH)
 */
void digitalWrite(int pin, int value);



/**
 * \fn digitalRead
 * \brief Read the value from the given digital pin.
 * \param pin The pin to read.
 * \return value The digital value on the pin (LOW/HIGH)
 */
int digitalRead(int pin);
