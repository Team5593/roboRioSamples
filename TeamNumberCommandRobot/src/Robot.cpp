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
	CommandBase::init();

	//chooser = new SendableChooser();
	//chooser->AddDefault("Default Auto", new ExampleCommand());
	//chooser->AddObject("My Auto", new TestCommand());
	//SmartDashboard::PutData("Auto Modes", chooser);
	//SmartDashboard::PutData("Chooser", chooser);

	//SmartDashboard::PutData(_setTeamNumCmdGroup);
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

/**
 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
 * below the Gyro
 *
 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
 * or additional comparisons to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
	// std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
	//if(autoSelected == "My Auto") {
	//	autonomousCommand.reset(new TestCommand());
	//} else {
	//	autonomousCommand.reset(new ExampleCommand());
	//}

	/*autonomousCommand.reset((Command *)chooser->GetSelected());

	if (autonomousCommand != NULL)
		autonomousCommand->Start();*/
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
	_setTeamNumCmdGroup.reset(new SetTeamNumCmdGroup(TEAM_NUMBER));
	_setTeamNumCmdGroup->Start();
	//TestCommandGroup testCmdGroup{};
	//testCmdGroup.Start();
	//Scheduler::GetInstance()->Run();
	//_testCommandGroup->Start();

}

void Robot::TestPeriodic()
{
	//std::cout << "Robot::TestPeriodic" << std::endl;

	//Scheduler::GetInstance()->Run();
	//LiveWindow::GetInstance()->Run();

	//if(IsEnabled()) {
		//_setDigitOneCommand->Execute();
		//_setDigitTwoCommand->Execute();
		//_testCommandGroup->Run();
	//}

	_setTeamNumCmdGroup->Run();
}

// Macro (yuck, yuck, yuck) that produces the main function entry point for the robot program.
START_ROBOT_CLASS(Robot)
