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
	SmartDashboard::PutData(Scheduler::GetInstance());

	// Choose autonomous command from the SmartDashboard.
	// http://wpilib.screenstepslive.com/s/4485/m/26401/l/255419-choosing-an-autonomous-program-from-smartdashboard
	chooser = new SendableChooser();
	chooser->AddDefault("Default Auto", new SetDigitCommand(DigitSelectEnum::First));
	chooser->AddObject("Second Digit", new SetDigitCommand(DigitSelectEnum::Second));
	chooser->AddObject("Third Digit", new SetDigitCommand(DigitSelectEnum::Third));
	SmartDashboard::PutData("Autonomous modes", chooser);

	// Test commands from the SmartDashboard.
	// http://wpilib.screenstepslive.com/s/4485/m/26401/l/255418-testing-commands
	// Note: Have verified this works for Teleoperated and Practice modes but having a problem with Test mode.
	SmartDashboard::PutData("Set First Digit", new SetDigitCommand());
}

/**
 * This function is called once each time the robot enters Disabled mode.
 * You can use it to reset any subsystem information you want to clear when
 * the robot is disabled.
 */
void Robot::DisabledInit()
{
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
	//if (autonomousCommand != NULL)
	//	autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TestInit()
{
	//_setTeamNumCmdGroup.reset(new SetTeamNumCmdGroup(TEAM_NUMBER));
	//_setTeamNumCmdGroup->Start();

	//Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	//std::cout << "Robot::TestPeriodic" << std::endl;

	Scheduler::GetInstance()->Run();
	//LiveWindow::GetInstance()->Run();

	//_setTeamNumCmdGroup->Run();
}

// Macro (yuck, yuck, yuck) that supplies the main function entry point for the robot program.
START_ROBOT_CLASS(Robot)
