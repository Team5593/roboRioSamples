// ============================================================================
// FileName: Robot.cpp
//
// Description:
// Implementation file for the main robot program. The functions employed in this
// class are tightly coupled to the FRC Driver Station. The program does nothing useful
// until the "Enable" button for one of the modes (TeleOperated, Autonomous, Practice
// or Test) on the Driver Station is pressed.
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

#include "Robot.h"
#include "RobotMap.h"

void Robot::RobotInit()
{
	// For SmartDashboard see http://wpilib.screenstepslive.com/s/4485/m/26401/l/255407-getting-started-with-the-smartdashboard.

	CommandBase::init();

	// Display the Scheduler status on the SmartDashboard.
	// http://wpilib.screenstepslive.com/s/4485/m/26401/l/255422-displaying-the-status-of-commands-and-subsystems
	//SmartDashboard::PutData(Scheduler::GetInstance());

	// Test commands from the SmartDashboard.
	// http://wpilib.screenstepslive.com/s/4485/m/26401/l/255418-testing-commands
	_setTeamNumCmdGroup = std::make_unique<SetTeamNumCmdGroup>(TEAM_NUMBER);
	_testSetFirstDigitCommand = std::make_unique<SetDigitCommand>(DigitSelectEnum::First);
	_testSetSecondDigitCommand = std::make_unique<SetDigitCommand>(DigitSelectEnum::Second);
	_testSetThirdDigitCommand = std::make_unique<SetDigitCommand>(DigitSelectEnum::Third);
	_testSetFourthDigitCommand = std::make_unique<SetDigitCommand>(DigitSelectEnum::Fourth);

	// Choose autonomous command from the SmartDashboard.
	// http://wpilib.screenstepslive.com/s/4485/m/26401/l/255419-choosing-an-autonomous-program-from-smartdashboard
	chooser = new SendableChooser();
	chooser->AddDefault("Default Auto", _setTeamNumCmdGroup.get());
	chooser->AddObject("First Digit", _testSetFirstDigitCommand.get());
	chooser->AddObject("Second Digit", _testSetSecondDigitCommand.get());
	chooser->AddObject("Third Digit", _testSetThirdDigitCommand.get());
	chooser->AddObject("Fourth Digit", _testSetFourthDigitCommand.get());
	SmartDashboard::PutData("Autonomous modes", chooser);

	SmartDashboard::PutData("Team Number", _setTeamNumCmdGroup.get());
	SmartDashboard::PutData("First Digit", _testSetFirstDigitCommand.get());
	SmartDashboard::PutData("Second Digit", _testSetSecondDigitCommand.get());
	SmartDashboard::PutData("Third Digit", _testSetThirdDigitCommand.get());
	SmartDashboard::PutData("Fourth Digit", _testSetFourthDigitCommand.get());
}

/**
 * This function is called once each time the robot enters Disabled mode.
 * You can use it to reset any subsystem information you want to clear when
 * the robot is disabled.
 */
void Robot::DisabledInit()
{
	// Turn off the LED's.
	CommandBase::TeamNumDigitPwmSubsystem->TurnOff();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TestInit()
{
	// Turn off the LED's in case the previous mode left them on.
	CommandBase::TeamNumDigitPwmSubsystem->TurnOff();

	// Scheduler doesn't get enabled by default in Test mode so if you want to test commands enable it.
	Scheduler::GetInstance()->SetEnabled(true);
}

void Robot::TestPeriodic()
{
	//std::cout << "Robot::TestPeriodic" << std::endl;

	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->Run();
}

// Macro that supplies the main function entry point for the robot program (note macros aren't cool
// don't write them).
START_ROBOT_CLASS(Robot)
