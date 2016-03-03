#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;
class RobotMap {
public:
	//declare all talons, encoders, solenoids, etc.
	static std::shared_ptr<CANTalon> drivetrainFrontLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainRearLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainFrontRightMotor;
	static std::shared_ptr<CANTalon> drivetrainRearRightMotor;
	static std::shared_ptr<RobotDrive> drivetrainchassis;
	static std::shared_ptr<Encoder> drivetrainLeftEncoder;
	static std::shared_ptr<Encoder> drivetrainRightEncoder;
	static std::shared_ptr<DoubleSolenoid> shooterSolenoid;
	static std::shared_ptr<CANTalon> shooterMotor;
	static std::shared_ptr<DigitalInput> shooterPhotoeye;
	static std::shared_ptr<DoubleSolenoid> intakeSolenoid;
	static std::shared_ptr<CANTalon> intakeMotor;
	static std::shared_ptr<CANTalon> climberHookMotor;
	static std::shared_ptr<CANTalon> climberLeftWinchMotor;
	static std::shared_ptr<CANTalon> climberRightWinchMotor;
	static std::shared_ptr<Encoder> climberHookEncoder;
	static std::shared_ptr<Relay> compressorSpike;
	static std::shared_ptr<DigitalInput> compressorPressureSwitch;

	static void init();
};

#endif
