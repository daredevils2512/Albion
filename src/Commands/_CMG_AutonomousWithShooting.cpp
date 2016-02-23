// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Commands/_CMG_AutonomousWithShooting.h"
#include "Commands/WaitCommand.h"
#include "Commands/IntakeActuate.h"
#include "Commands/AutonDrive.h"
#include "Commands/_CMG_ShooterCharge.h"
#include "Commands/_CMG_ShootBall.h"
#include "Commands/AutonVisionTurning.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

_CMG_AutonomousWithShooting::_CMG_AutonomousWithShooting(bool shooting) {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
		AddSequential(new IntakeActuate(false));
        AddSequential(new AutonDrive(1.5, -0.8, 0.0, false));
        AddSequential(new AutonDrive(7.0, -0.4, 0.0, false));
        AddSequential(new AutonDrive(5.5, -0.8, 0.0, true));
        AddSequential(new AutonDrive(2.9, 0.0, 0.8, true));
        //AddSequential(new WaitCommand(0.5);
        //AddSequential(new AutonVisionTurning());
        AddSequential(new AutonDrive(7.0, 0.8, 0.0, true));
        if(shooting) {
			AddSequential(new _CMG_ShooterCharge());
			AddSequential(new WaitCommand(1.0));
			AddSequential(new _CMG_ShootBall());
        }
 }