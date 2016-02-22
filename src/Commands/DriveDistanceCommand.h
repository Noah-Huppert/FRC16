/*
 * DriveDistanceCommand.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Noah-Huppert
 */

#ifndef SRC_COMMANDS_DRIVEDISTANCECOMMAND_H_
#define SRC_COMMANDS_DRIVEDISTANCECOMMAND_H_

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/Drivetrain.h"

class DriveDistanceCommand: public CommandBase {
private:
	std::shared_ptr<Drivetrain> drive_train;
	float distance;
	float speed;
public:
	DriveDistanceCommand(std::shared_ptr<Drivetrain> drive_train, float distance, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_DRIVEDISTANCECOMMAND_H_ */
