#include "WPILib.h"
#include <Subsystems/Drivetrain.h>

#include "Vector.h"
#include "XboxController.h"

#include "Subsystems/Shooter.h"
#include "Subsystems/BallCollector.h"
#include "Commands/DriveDistanceCommand.h"

class Robot: public IterativeRobot {
private:
	// Input devices
	std::unique_ptr<XboxController> controller;

	// Subsystems
	std::shared_ptr<Drivetrain> drive_train;
	std::shared_ptr<Shooter> shooter;
	std::shared_ptr<BallCollector> ball_collector;

	void RobotInit() {
		// Input devices
		controller = std::unique_ptr<XboxController>(new XboxController(0));

		// Subsystems
		drive_train = std::unique_ptr<Drivetrain> (new Drivetrain());
		shooter = std::unique_ptr<Shooter> (new Shooter());
		ball_collector = std::unique_ptr<BallCollector> (new BallCollector());
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit() {
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() {
		/*
		drive_train->SetTargetDistance(100, 0.2);

		while(!drive_train->IsAtDistance()) {
			drive_train->MoveToDistance();
		}

		drive_train->ResetDistance();
		*/
		DriveDistanceCommand cmd(drive_train, 100, 0.2);
		cmd.Start();
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		controller->Calibrate();
	}

	void TeleopPeriodic() {
		SmartDashboard::PutNumber("Left Distance", drive_train->left_primary_motor->GetPosition());
		// Calibrate
		if(controller->GetButton(controller->ButtonRightJoystickPress)) {
			controller->Calibrate();
		}

		// Chases drive
		std::unique_ptr<Vector> left_stick_vector = std::unique_ptr<Vector>(controller->GetLeftStickVector());
		std::unique_ptr<Vector> right_stick_vector = std::unique_ptr<Vector>(controller->GetRightStickVector());

		drive_train->TankDrive(left_stick_vector->GetMagnitude(true),
							right_stick_vector->GetMagnitude(true));

		// Shooter control
		if (controller->GetRightTrigger() >= 0.5) {
			shooter->run_shooter(1);
		} else if (controller->GetButton(controller->ButtonRB)) {
			shooter->run_shooter(1);
		} else {
			shooter->run_shooter(0);
		}

		// Ball Collector control
		if (controller->GetLeftTrigger() >= 0.5) {
			ball_collector->Run(1.0);
		} else if(controller->GetButton(controller->ButtonLB)) {
			ball_collector->Run(-1.0);
		} else {
			ball_collector->Run(0);
		}
	}

	void TestPeriodic() {
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

