/*
 * DriveDistanceCommand.cpp
 *
 *  Created on: Feb 19, 2016
 *      Author: Noah-Huppert
 */

#include <Commands/DriveDistanceCommand.h>

DriveDistanceCommand::DriveDistanceCommand(std::shared_ptr<Drivetrain> drive_train, float distance, float speed): drive_train(drive_train), distance(distance), speed(speed) {
	// TODO Auto-generated constructor stub

}

// Called just before this Command runs the first time
void DriveDistanceCommand::Initialize() {
	drive_train->SetTargetDistance(distance, speed);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistanceCommand::Execute() {
	drive_train->MoveToDistance();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceCommand::IsFinished() {
	return drive_train->IsAtDistance();
}

// Called once after isFinished returns true
void DriveDistanceCommand::End() {
	drive_train->ResetDistance();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceCommand::Interrupted() {
	drive_train->ResetDistance();
}

