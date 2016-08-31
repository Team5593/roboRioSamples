// ============================================================================
// FileName: SetDigitCommand.h
//
// Description:
// This class implements an atomic command to set a single digit on a 4 character
// segment display.
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

#ifndef SET_DIGIT_ONE_COMMAND_H
#define SET_DIGIT_ONE_COMMAND_H

#include "../CommandBase.h"
#include "Subsystems/DigitSelectSubsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

#define SET_DIGIT_WAIT_SECONDS 2	// The time to pause with the segment pins set so that the character stays long enough to be viewed.

class SetDigitCommand : public CommandBase
{
public:
	SetDigitCommand();
	SetDigitCommand(DigitSelectEnum selectedDigit);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	DigitSelectEnum _selectedDigit;
};

#endif
