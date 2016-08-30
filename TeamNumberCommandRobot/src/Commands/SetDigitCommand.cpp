// ============================================================================
// FileName: SetDigitCommand.cpp
//
// Description:
// Implementation for the SetDigitCommand class.
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

#include <Commands/SetDigitCommand.h>

SetDigitCommand::SetDigitCommand(DigitSelectEnum selectedDigit) :
	_selectedDigit(selectedDigit)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(TeamNumDigitPwmSubsystem.get());
	Requires(TeamNumDigitSelectSubsystem.get());

	SetInterruptible(true);

	std::cout << "SetDigitCommand::Constructor " << _selectedDigit << std::endl;
}

// Called just before this Command runs the first time
void SetDigitCommand::Initialize()
{
	std::cout << "SetDigitCommand::Initialize " << _selectedDigit << std::endl;
	CommandBase::TeamNumDigitPwmSubsystem->TurnOff();
}

// Called repeatedly when this Command is scheduled to run
void SetDigitCommand::Execute()
{
	std::cout << "SetDigitCommand::Execute " << _selectedDigit << std::endl;
	CommandBase::TeamNumDigitSelectSubsystem->Display(_selectedDigit);

	switch(_selectedDigit)
	{
		case DigitSelectEnum::First:
			CommandBase::TeamNumDigitPwmSubsystem->DisplayDigit(TEAM_NUMBER / 1000);
			break;
		case DigitSelectEnum::Second:
			CommandBase::TeamNumDigitPwmSubsystem->DisplayDigit(TEAM_NUMBER % 1000 / 100);
			break;
		case DigitSelectEnum::Third:
			CommandBase::TeamNumDigitPwmSubsystem->DisplayDigit(TEAM_NUMBER % 100 / 10);
			break;
		case DigitSelectEnum::Fourth:
			CommandBase::TeamNumDigitPwmSubsystem->DisplayDigit(TEAM_NUMBER % 10);
			break;
	}

	Wait(SET_DIGIT_WAIT_SECONDS);
}

// Make this return true when this Command no longer needs to run execute()
bool SetDigitCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetDigitCommand::End()
{
	CommandBase::TeamNumDigitPwmSubsystem->TurnOff();
	std::cout << "SetDigitCommand::End " << _selectedDigit << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetDigitCommand::Interrupted()
{
	std::cout << "SetDigitCommand::Interrupted" << std::endl;
}
