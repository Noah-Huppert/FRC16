#include "BallCollector.h"
#include "../RobotMap.h"

BallCollector::BallCollector(): Subsystem("BallCollector") {
	motor = std::unique_ptr<Talon>(new Talon(RobotMap::INTAKE_MOTOR));
}

void BallCollector::Run(float speed) {
	motor->Set(speed);
}

BallCollector::~BallCollector(){

}
