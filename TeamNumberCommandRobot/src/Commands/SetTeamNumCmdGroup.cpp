// ============================================================================
// FileName: SetTeamNumCmdGroup.cpp
//
// Description:
// Implementation for the SetTeamNumCmdGroup class.
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

#include <Commands/SetTeamNumCmdGroup.h>

SetTeamNumCmdGroup::SetTeamNumCmdGroup(ushort teamNumber) :
	_teamNumber(teamNumber)
{
	AddSequential(new SetDigitCommand(DigitSelectEnum::First));
	AddSequential(new SetDigitCommand(DigitSelectEnum::Second));
	AddSequential(new SetDigitCommand(DigitSelectEnum::Third));
	AddSequential(new SetDigitCommand(DigitSelectEnum::Fourth));
}

void SetTeamNumCmdGroup::Execute()
{
	//std::cout << "SetTeamNumCmdGroup::Execute" << std::endl;
}
