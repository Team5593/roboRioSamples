// ============================================================================
// FileName: SetTeamNumCmdGroup.cpp
//
// Description:
// This class implements a command group which sets a team number on a 4 digit
// character display. Setting a digit is a two step process that first requires
// the control lines to be set and the second step is to write to the required
// pattern 9 segment LEDs.
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

#ifndef SetTeamNumCmdGroup_H
#define SetTeamNumCmdGroup_H

#include "Commands/SetDigitCommand.h"
#include "Subsystems/DigitSelectSubsystem.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class SetTeamNumCmdGroup: public CommandGroup
{
public:
	SetTeamNumCmdGroup(ushort teamNumber);
	virtual void Execute();
	void DoBackgroundWork();
private:
	ushort _teamNumber;
};

#endif
