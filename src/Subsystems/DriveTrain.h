#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand();

	void Drive(float left, float right);

private:
	std::unique_ptr<RobotDrive> robot_drive;

	std::shared_ptr<CANTalon> left_primary_motor;
	std::shared_ptr<CANJaguar> left_secondary_motor;
	std::shared_ptr<CANTalon> right_primary_motor;
	std::shared_ptr<CANJaguar> right_secondary_motor;
};

#endif
