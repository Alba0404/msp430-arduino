/**
 * \file msp430-arduino.h
 * \date 4 november 2021
 * \author Alexandre BARRAT
 * \version 1.2
 */
#include <math.h>

#define LOW  0
#define HIGH 1

#define INPUT  0
#define OUTPUT 1
#define INPUT_PULLUP 2

#define MSBFIRST 7
#define LSBFIRST 0

#define LED_BUILTIN 10

// Maths constants
#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

// Arduino's macros
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))
#define bitRead(value,bit) (((value) >> (bit)) & 0x01)
#define bitSet(value,bit) ((value) |= (1UL << (bit)))
#define bitClear(value,bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value,bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value,bit,bitvalue) ((bitvalue) ? bitSet(value,bit) : bitClear(value,bit))
#define bit(bit) (pow(2,bit))


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

/**
 * \fn void shiftOut(dataPin, clockPin, bitOrder, value)
 * \brief Shifts out a byte of data one bit at a time.
 * \param dataPin The pin to send data (10-17/20-27).
 * \param clockPin The pin for the clock (10-17/20-27).
 * \param bitOrder The first bit to shift : most or least significant (MSBFIRST/LSBFIRST).
 */
void shiftOut(int dataPin, int clockPin, int bitOrder, unsigned char value);

