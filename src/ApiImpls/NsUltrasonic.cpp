#include "Arduino.h"
#include "CarApi/NsServo.hpp"
#include "CarApi/NsUltrasonic.hpp"
#include "Api/DebuggingMacros.hpp"

namespace NsUltrasonic {

	int read() {
		// Lower `TRIG` for `4` microseconds as an error check:
		digitalWrite(PIN_ULTRASONIC_TRIG, LOW);
		delayMicroseconds(4); // ...We'll also wait this out.

		// From the HC-SR04 datasheet:
		// Set `TRIG` for `10` microseconds:
		digitalWrite(PIN_ULTRASONIC_TRIG, HIGH);
		delayMicroseconds(10);

		// Set it low again for next use! ...things go wrong, okay!?
		digitalWrite(PIN_ULTRASONIC_TRIG, LOW);

		// Giving the ultrasonic sensor a duration gets us a reading:
		unsigned long pulseDur = pulseIn(PIN_ULTRASONIC_ECHO, HIGH); // Pulse duration.

		if (pulseDur == 0) {
			ERROR_PRINTLN("Ultrasonic sensor wiring broke!");
			return 0;
		}

		pulseDur = pulseDur / 29 / 2;	// Time-to-centimeters conversion.
		return pulseDur;
	}

	int lookLeft() {
		NsServo::servo.write(180);
		delay(800);
		return NsUltrasonic::read();
	}

	int lookRight() {
		NsServo::servo.write(20);
		delay(800);
		return NsUltrasonic::read();
	}

}
