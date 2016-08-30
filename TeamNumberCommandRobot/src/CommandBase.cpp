// ============================================================================
// FileName: CommandBase.cpp
//
// Description:
// Implemenation for CommandBase class.
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

#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL.
std::unique_ptr<DigitPwmSubsystem> CommandBase::TeamNumDigitPwmSubsystem { nullptr };
std::unique_ptr<DigitSelectSubsystem> CommandBase::TeamNumDigitSelectSubsystem { nullptr };
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{ }

CommandBase::CommandBase() :
		Command()
{ }

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems.
	TeamNumDigitPwmSubsystem.reset(new DigitPwmSubsystem());
	TeamNumDigitSelectSubsystem.reset(new DigitSelectSubsystem());

	oi.reset(new OI());
}
