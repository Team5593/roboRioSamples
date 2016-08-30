// ============================================================================
// FileName: DigitPwmSubsystem.cpp
//
// Description:
// Implementation for the DigitPwmSubsystem class.
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

#include "DigitPwmSubsystem.h"

DigitPwmSubsystem::DigitPwmSubsystem() :
		Subsystem("DigitPwmSubsystem"),
		_pwmA { PWM_PIN_SEGMENT_A },
		_pwmB { PWM_PIN_SEGMENT_B },
		_pwmC { PWM_PIN_SEGMENT_C },
		_pwmD { PWM_PIN_SEGMENT_D },
		_pwmE { PWM_PIN_SEGMENT_E },
		_pwmF { PWM_PIN_SEGMENT_F },
		_pwmG { PWM_PIN_SEGMENT_G },
		_pwmDecimalPoint { PWM_PIN_SEGMENT_DECIMAL_POINT }
{
	TurnOff();
}

void DigitPwmSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Writes to the PWM pins to set the segments on the character display the desired character.
void DigitPwmSubsystem::DisplayDigit(short digit)
{
	//std::cout << "DigitPwmSubsystem::DisplayDigit" << std::endl;

	switch(digit)
	{
		case 3:
			_pwmA.SetSpeed(MOTOR_SPEED);
			_pwmB.SetSpeed(MOTOR_SPEED);
			_pwmC.SetSpeed(MOTOR_SPEED);
			_pwmD.SetSpeed(MOTOR_SPEED);
			_pwmE.StopMotor();
			_pwmF.StopMotor();
			_pwmG.SetSpeed(MOTOR_SPEED);
			_pwmDecimalPoint.StopMotor();
			break;
		case 5:
			_pwmA.SetSpeed(MOTOR_SPEED);
			_pwmB.StopMotor();
			_pwmC.SetSpeed(MOTOR_SPEED);
			_pwmD.SetSpeed(MOTOR_SPEED);
			_pwmE.StopMotor();
			_pwmF.SetSpeed(MOTOR_SPEED);
			_pwmG.SetSpeed(MOTOR_SPEED);
			_pwmDecimalPoint.StopMotor();
			break;
		case 9:
			_pwmA.SetSpeed(MOTOR_SPEED);
			_pwmB.SetSpeed(MOTOR_SPEED);
			_pwmC.SetSpeed(MOTOR_SPEED);
			_pwmD.StopMotor();
			_pwmE.StopMotor();
			_pwmF.SetSpeed(MOTOR_SPEED);
			_pwmG.SetSpeed(MOTOR_SPEED);
			_pwmDecimalPoint.StopMotor();
			break;
		default:
			std::cout << "Sorry the output for this digit has not yet been implemented." << std::endl;
			break;
	}
}

// Ensures all the PWM outputs are set to ground.
void DigitPwmSubsystem::TurnOff()
{
	_pwmA.StopMotor();
	_pwmB.StopMotor();
	_pwmC.StopMotor();
	_pwmD.StopMotor();
	_pwmE.StopMotor();
	_pwmF.StopMotor();
	_pwmG.StopMotor();
	_pwmDecimalPoint.StopMotor();
}
