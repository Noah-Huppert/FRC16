#include "TankDriveWithXBoxController.h"

#include "../Robot.h"
#include "../Models/Vector.h"

TankDriveWithXBoxController::TankDriveWithXBoxController(): Command("TankDriveWithXBoxController") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drive_train.get());
}

// Called just before this Command runs the first time
void TankDriveWithXBoxController::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDriveWithXBoxController::Execute() {
	Vector lVector = Robot::oi->xbox_controller->GetLeftStick();
	Vector rVector = Robot::oi->xbox_controller->GetRightStick();

	SmartDashboard::PutNumber("LV", lVector.GetMagnitude(true));
	SmartDashboard::PutNumber("RV", rVector.GetMagnitude(true));

	Robot::drive_train->Drive(lVector.GetMagnitude(true), rVector.GetMagnitude(true));
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveWithXBoxController::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDriveWithXBoxController::End() {
	Robot::drive_train->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveWithXBoxController::Interrupted() {
	End();
}
