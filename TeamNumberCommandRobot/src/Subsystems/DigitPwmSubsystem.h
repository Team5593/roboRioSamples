// ============================================================================
// FileName: DigitPwmSubsystem.h
//
// Description:
// This class is used to write to the segment pins on a 4 digit character display.
// The PWM outputs are used so that the brightness of the segments can be varied.
// Before a segment write occurs the correct control pin must be set to specify
// which of the 4 characters is desired.
//
// Author(s):
// Aaron Clauson (aaron.clauson@gmail.com)
//
// History:
// 30 Aug 2016	Aaron Clauson	Created.
//
// License:
// Public Domain
// ============================================================================

#ifndef DigitPwmSubsystem_H
#define DigitPwmSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

#define MOTOR_SPEED 0.5

class DigitPwmSubsystem: public Subsystem
{
private:
	Talon _pwmA;
	Talon _pwmB;
	Talon _pwmC;
	Talon _pwmD;
	Talon _pwmE;
	Talon _pwmF;
	Talon _pwmG;
	Talon _pwmDecimalPoint;

public:
	DigitPwmSubsystem();
	void InitDefaultCommand();
	void DisplayDigit(short digit);
	void TurnOff();
};

#endif
