#pragma once

#include "../Api/NsAppRoutines.hpp"

class BluetoothRoutine : public NsAppRoutines::AppRoutine {
	void loop();
	void setup();

private:
	String BluetoothRoutine::customReadStringUntil(char terminator);
};
