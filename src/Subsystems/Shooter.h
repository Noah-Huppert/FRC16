#ifndef SHOOTER_H
#define SHOOTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: Subsystem {

private:
	Talon* lMotor;
	Talon* rMotor;

public:
	Shooter();
	void InitDefaultCommand();
	void run_shooter(float speed);
	~Shooter();

};

#endif
