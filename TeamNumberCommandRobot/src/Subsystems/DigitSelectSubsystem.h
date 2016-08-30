// ============================================================================
// FileName: DigitSelectSubsystem.h
//
// Description:
// This class defines a robot sub-system that selects which digit on a 4 segment
// character display to set. The display only allows one digit at a time to be set.
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

#ifndef DigitSelectSubsystem_H
#define DigitSelectSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

enum DigitSelectEnum
{
	First = 1,
	Second = 2,
	Third = 3,
	Fourth = 4
};

class DigitSelectSubsystem: public Subsystem
{
private:
	DigitalOutput _digSelectOne;
	DigitalOutput _digSelectTwo;
	DigitalOutput _digSelectThree;
	DigitalOutput _digSelectFour;

public:
	DigitSelectSubsystem();
	void InitDefaultCommand();
	void Display(DigitSelectEnum digitSelect);
};

#endif
