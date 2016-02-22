#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem {
private:
	const int LEFT_SYNC_GROUP = 0;
	const int RIGHT_SYNC_GROUP = 1;

	const float DISTANCE_THRESHOLD = 5.0;

	float target_distance = 0;
	float target_distance_speed = 0;

public:
	std::shared_ptr<CANTalon> left_primary_motor;
	std::shared_ptr<CANJaguar> left_secondary_motor;

	std::shared_ptr<CANTalon> right_primary_motor;
	std::shared_ptr<CANJaguar> right_secondary_motor;

	std::shared_ptr<RobotDrive> robot_drive;

	Drivetrain();
	void InitDefaultCommand();
	void TankDrive(float lSpeed, float rSpeed);
	void ArcadeDrive(float magnitude, float rotate);

	void SetTargetDistance(float distance, float speed);
	void MoveToDistance();
	void ResetDistance();
	bool IsAtDistance();
};

#endif
