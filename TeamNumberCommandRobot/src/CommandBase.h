// ============================================================================
// FileName: CommandBase.h
//
// Description:
// The central place to instantiate all subsystems used by the robot commands.
// Todo: Any other purpose?
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

#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/DigitSelectSubsystem.h>
#include <string>
#include "Commands/Command.h"
#include "Subsystems/DigitPwmSubsystem.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DigitPwmSubsystem> TeamNumDigitPwmSubsystem;
	static std::unique_ptr<DigitSelectSubsystem> TeamNumDigitSelectSubsystem;
	static std::unique_ptr<OI> oi;
};

#endif
