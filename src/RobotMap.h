#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:
	//4 speed controllers for the drivetrain
	static std::shared_ptr<CANTalon> drivetrainFrontLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainRearLeftMotor;
	static std::shared_ptr<CANTalon> drivetrainFrontRightMotor;
	static std::shared_ptr<CANTalon> drivetrainRearRightMotor;
	//robot drivetrain
	static std::shared_ptr<frc::RobotDrive> drivetrainchassis;
	//pneumatic actuator to raise and lower shooter
	static std::shared_ptr<frc::DoubleSolenoid> shooterSolenoid;
	//speed controller to run shooter wheels
	static std::shared_ptr<CANTalon> shooterMotor;
	//boolean sensor input that detects if the ball is in the shooter or not
	static std::shared_ptr<frc::DigitalInput> shooterPhotoeye;
	//pneumatic actuator to raise and lower the intake
	static std::shared_ptr<frc::DoubleSolenoid> intakeSolenoid;
	//speed controler to run intake roller
	static std::shared_ptr<CANTalon> intakeMotor;


	static void init();
};

#endif
