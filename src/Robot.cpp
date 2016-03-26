#include <Commands/DriveForTime.h>
#include "Robot.h"

#include "RobotMap.h"
#include "CommandGroups/AutonomousBreakObstacle.h"

std::shared_ptr<DriveTrain> Robot::drive_train;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<BallRetriever> Robot::ball_retriever;

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	drive_train.reset(new DriveTrain());
	shooter.reset(new Shooter());
	ball_retriever.reset(new BallRetriever());

	oi.reset(new OI());

	last_inverted_time = GetTime();

	gyro = std::unique_ptr<Gyro>(new AnalogGyro(1));


	CameraServer::GetInstance()->SetQuality(0.25);
	//the camera name (ex "cam0") can be found through the roborio web interface
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset(new AutonomousBreakObstacle());

	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand != NULL) autonomousCommand->Cancel();

	oi->xbox_controller->Calibrate();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	SmartDashboard::PutNumber("Gyro", gyro->GetAngle());

	if(oi->xbox_controller->GetButton(XBoxController::BUTTON_START)) {
		oi->xbox_controller->Calibrate();
	}
}

void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)

