#include <avr/pgmspace.h>
#pragma once

#include "NsAppRoutines.hpp"

#include <AFMotor.h>
#include <Servo.h>
#include <Vector.h>

#pragma region Value macros.
#define WHEEL_SPEED              170
#define SERVO_POINT              103
#define ARDUINO_SERIAL_BAUD_RATE 9600

// Ultrasonic pins:
#define PIN_ULTRASONIC_ECHO A0
#define PIN_ULTRASONIC_TRIG A1

// Misc. Pins:
#define PIN_SERVO 10
#pragma endregion

#pragma region Functional macros.
// Debugging ones!:
#ifdef DEBUG
#define DEBUG_PRINT(...)          \
		Serial.print(F("[DEBUG] "));  \
		Serial.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...)        \
		Serial.print(F("[DEBUG] "));  \
		Serial.println(__VA_ARGS__)
#else // Define these as empty!:
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif

// Compile-time type information! (Thanks to ):
template <typename TypeT> struct TypeInfo { static const char  *name; }; // Can't go into `PROGMEM`...
template <typename TypeT> const char *TypeInfo<TypeT>::name = "Unknown";

#define TYPE_NAME(var) TypeInfo<typeof(var)>::name
#define MAKE_TYPE_INFO(type) template<> const char* TypeInfo<type>::name = #type;
#pragma endregion

#pragma region Global values.
const Servo           g_servo;
const AF_DCMotor      g_dcMotors[4] = {
				 AF_DCMotor(1),
				 AF_DCMotor(2),
				 AF_DCMotor(3),
				 AF_DCMotor(4),
};
#pragma endregion

// #pragma region Global functions.
void (*restart)(void) = 0;
// #pragma endregion
