// ============================================================================
// FileName: DigitSelectSubsystem.cpp
//
// Description:
// Implementation for the DigitSelectSubsystem class.
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

#include "DigitSelectSubsystem.h"
#include "../RobotMap.h"

DigitSelectSubsystem::DigitSelectSubsystem() :
		Subsystem("DigitSelectSubsystem"),
		_digSelectOne { DIGIT_CONTROL_ONE_DIO_PIN },
		_digSelectTwo { DIGIT_CONTROL_TWO_DIO_PIN },
		_digSelectThree { DIGIT_CONTROL_THREE_DIO_PIN },
		_digSelectFour { DIGIT_CONTROL_FOUR_DIO_PIN }
{ }

void DigitSelectSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Sets the signals on the 4 character display so that the next write
// to the segement pins will set the desired character.
void DigitSelectSubsystem::Display(DigitSelectEnum digitSelect)
{
	switch(digitSelect)
	{
		case DigitSelectEnum::First:
			_digSelectOne.Set(0);
			_digSelectTwo.Set(1);
			_digSelectThree.Set(1);
			_digSelectFour.Set(1);
			break;
		case DigitSelectEnum::Second:
			_digSelectOne.Set(1);
			_digSelectTwo.Set(0);
			_digSelectThree.Set(1);
			_digSelectFour.Set(1);
			break;
		case DigitSelectEnum::Third:
			_digSelectOne.Set(1);
			_digSelectTwo.Set(1);
			_digSelectThree.Set(0);
			_digSelectFour.Set(1);
			break;
		case DigitSelectEnum::Fourth:
			_digSelectOne.Set(1);
			_digSelectTwo.Set(1);
			_digSelectThree.Set(1);
			_digSelectFour.Set(0);
			break;
	}
}
