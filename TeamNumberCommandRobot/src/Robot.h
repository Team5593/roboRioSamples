// ============================================================================
// FileName: Robot.h
//
// Description:
// Header file for the main robot program.
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

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Commands/SetDigitCommand.h"
#include "Commands/SetTeamNumCmdGroup.h"
#include "WPILib.h"
#include "Subsystems/DigitPwmSubsystem.h"

class Robot: public IterativeRobot {
public:
	//create static objects of the subsystems
	//static OI * oi;

private:
	//LiveWindow * lw;

	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void TeleopInit();
	void TestInit();

	void DisabledPeriodic();
	void AutonomousPeriodic();
	void TeleopPeriodic();
	void TestPeriodic();

	std::unique_ptr<SetTeamNumCmdGroup> _setTeamNumCmdGroup{ nullptr };

	Command * autonomousCommand { nullptr };
	SendableChooser *chooser { nullptr };
};

#endif /* ROBOT_H_ */
