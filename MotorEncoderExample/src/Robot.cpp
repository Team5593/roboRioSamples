#include "WPILib.h"

/* Example program showing how to use Quadrature Encoders with a demonstration of a self-correcting robot.
 * Quadrature Encoders are digital sensors which can detect the amount the encoder
 *   has rotated since starting as well as the direction in which the encoder
 *   shaft is rotating. However, encoders can not tell you the absolute
 *   position of the encoder shaft (ie, it considers where it starts to be the
 *   zero position, no matter where it starts), and so can only tell you how
 *   much the encoder has rotated since starting.
 * Depending on the precision of an encoder, it will have fewer or greater
 *   ticks per revolution; the number of ticks per revolution will affect the
 *   conversion between ticks and distance, as specified by DistancePerPulse.
 * One of the most common uses of encoders is in the drivetrain, so that the
 *   distance that the robot drives can be precisely controlled during the
 *   autonomous mode.
 */

class Robot: public IterativeRobot
{
private:
	RobotDrive DriveSystem;
	Encoder EncLeft;
	Encoder EncRight;

public:
	Robot():
		DriveSystem(0,1), 	// Drive Motors on channels 0 and 1

		/**
		 * The Encoder object is constructed with 4 parameters, the last two being optional.
		 * The first two parameters (1, 2 in this case) refer to the ports on the
		 *   roboRIO which the encoder uses. Because a quadrature encoder has
		 *   two signal wires, the signal from two DIO ports on the roboRIO are used.
		 * The third (optional) parameter is a boolean which defaults to false.
		 *   If you set this parameter to true, the direction of the encoder will
		 *   be reversed, in case it makes more sense mechanically.
		 * The final (optional) parameter specifies encoding rate (k1X, k2X, or k4X)
		 *   and defaults to k4X. Faster (k4X) encoding gives greater positional
		 *   precision but more noise in the rate.
		 */
		EncLeft(2, 3, false, Encoder::k4X),		// Left Encoder
		EncRight(4, 5, false, Encoder::k4X)		// Right Encoder
	{
		// Defines the number of samples to average when determining the rate.
		// On a quadrature encoder, values range from 1-255; larger values
		// result in smoother but potentially less accurate rates than lower values.
		EncLeft.SetSamplesToAverage(5);
		EncRight.SetSamplesToAverage(5);

		// Defines how far the mechanism attached to the encoder moves per pulse.
		// In this case, we assume that a 360 count encoder is directly attached
		//   to a 6 inch diameter (3inch radius) wheel, and that we want to
		//   measure distance in inches.
		EncLeft.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * 3);
		EncRight.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * 3);

		// Defines the lowest rate at which the encoder will not be considered
		//   stopped, for the purposes of the GetStopped() method.
		// Units are in distance / second, where distance refers to the units
		//   of distance that you are using, in this case inches.
		EncLeft.SetMinRate(1.0);
		EncRight.SetMinRate(1.0);
	}

	void AutonomousInit()
	{
		// Resets the stored value of the encoders to 0
		// The encoder class will start working from when it is initialized which
		//	  can causes undesired results if the robots wheels are rotated
		//    before enabling the robot.
		EncLeft.Reset();
		EncRight.Reset();
	}

	double heading = 0.0; // Proportional correction heading
	double speed = 0.8; // Target speed

	void AutonomousPeriodic()
	{
		// Display each encoder value to the SmartDashboard
		SmartDashboard::PutNumber("Encoder Left Distance", EncLeft.GetDistance());
		SmartDashboard::PutNumber("Encoder Right Distance", EncRight.GetDistance());

		if((EncLeft.GetDistance()+EncRight.GetDistance())/2 < 50 ){ // Only move for 50 inches (distance estimated as the average of both motors)
			heading=EncLeft.GetDistance()-EncRight.GetDistance(); // Calculate heading
			DriveSystem.TankDrive(speed + heading, speed - heading); // Set motor values
		}
		else {
			DriveSystem.TankDrive(0.0, 0.0); // Stop
		}
	}
};

START_ROBOT_CLASS(Robot)
