#include "AutonomousBreakObstacle.h"
#include "../Commands/DriveForTime.h"
#include "../Commands/DriveUntilInterrupt.h"
#include "../Commands/RunShooter.h"

AutonomousBreakObstacle::AutonomousBreakObstacle() {
	AddSequential(new DriveForTime(3, 1, 1));
	AddSequential(new DriveUntilInterrupt(0));
}
