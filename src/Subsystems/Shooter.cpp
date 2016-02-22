#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter(): Subsystem("Shooter") {
	lMotor = new Talon(RobotMap::LEFT_SHOOTER_MOTOR);
	rMotor = new Talon(RobotMap::RIGHT_SHOOTER_MOTOR);
}

void Shooter::InitDefaultCommand() {

}

void Shooter::run_shooter(float speed) {
	//spins up the motors to shoot the ball
	lMotor->SetSpeed(speed);
	rMotor->SetSpeed(speed * -1);
	//will need to stop the motors a few seconds after they're turned on
}

Shooter::~Shooter() {
	delete lMotor;
	delete rMotor;
}
