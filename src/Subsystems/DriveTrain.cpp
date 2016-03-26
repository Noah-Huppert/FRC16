#include "DriveTrain.h"

#include "../RobotMap.h"
#include "../Commands/TankDriveWithXBoxController.h"

DriveTrain::DriveTrain(): Subsystem("DriveTrain") {
	left_primary_motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::LEFT_PRIMARY_MOTOR));
	left_secondary_motor = std::shared_ptr<CANJaguar>(new CANJaguar(RobotMap::LEFT_SECONDARY_MOTOR));

	right_primary_motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::RIGHT_PRIMARY_MOTOR));
	right_secondary_motor = std::shared_ptr<CANJaguar>(new CANJaguar(RobotMap::RIGHT_SECONDARY_MOTOR));

	robot_drive = std::unique_ptr<RobotDrive>(
			new RobotDrive(left_primary_motor, left_secondary_motor,
							right_primary_motor, right_secondary_motor)
	);

	left_primary_motor->Set(0, 0);
	left_secondary_motor->Set(0, 0);

	right_primary_motor->Set(0, 1);
	right_secondary_motor->Set(0, 1);

	robot_drive->SetSafetyEnabled(true);
	robot_drive->SetExpiration(0.3);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new TankDriveWithXBoxController());
}

void DriveTrain::Drive(float left, float right) {
	left *= -1;
	right *= -1;

	if(left < -1) {
		left = -1;
	} else if(left > 1) {
		left = 1;
	}

	if(right < -1) {
		right = -1;
	} else if(right > 1) {
		right = 1;
	}

	robot_drive->TankDrive(left, right, false);
}
