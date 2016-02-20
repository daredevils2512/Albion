// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "VisionTracking.h"
#include "../RobotMap.h"
#include <algorithm>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

VisionTracking::VisionTracking() : Subsystem("VisionTracking") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	table = NetworkTable::GetTable("GRIP/myContoursReport");
	camera.reset(new AxisCamera("10.25.12.11"));
}

void VisionTracking::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

Nullable<double> VisionTracking::GetTargetX() {
	std::vector<double> xCoor = table->GetNumberArray("centerX", llvm::ArrayRef<double>());
	SmartDashboard::PutNumber("Target data length", xCoor.size());
	auto lowestTarget = std::min_element(xCoor.begin(), xCoor.end());
	if(xCoor.size() == 1) {
		return Nullable<double>(*lowestTarget);
	}else{
		return Nullable<double>();
	}
}

void VisionTracking::cameraAuton() {
	camera->WriteBrightness(10);
	camera->WriteColorLevel(30);
}

void VisionTracking::cameraTeleop() {
	camera->WriteBrightness(50);
	camera->WriteColorLevel(50);
}



// Put methods for controlling this subsystem
// here. Call these from Commands.

