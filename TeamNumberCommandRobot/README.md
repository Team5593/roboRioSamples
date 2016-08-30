# Team Number Command Robot

This is a simple and contrived example of a command based robot targetting the roboRio and using
WPILib's command based programming paradigm. See http://wpilib.screenstepslive.com/s/4485/m/13810/c/88685.

The program writes the team number to a 4 character LED segment display that has been placed on a breadboard
and has the control pins attached to 4 of the roboRio's DIO pins and the 8 pins that set the character segments
attached to the roboRio's PWM pins. Setting each of the 4 characters is treated as a separate command.

Of course this is definitely NOT how to write to a character display with the roboRio. It's an experiment to 
get an understanding of how the command based programming works and not useful for an practical purposes.