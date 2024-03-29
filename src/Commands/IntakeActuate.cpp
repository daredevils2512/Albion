#include "IntakeActuate.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

IntakeActuate::IntakeActuate(bool upDirection): Command() {
    m_upDirection = upDirection;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	//Requires(Robot::intake.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void IntakeActuate::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeActuate::Execute() {
	if(m_upDirection) {
		Robot::intake->SetIntakeDirection(frc::DoubleSolenoid::kReverse);
	}else{
		Robot::intake->SetIntakeDirection(frc::DoubleSolenoid::kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeActuate::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void IntakeActuate::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeActuate::Interrupted() {

}
