///////////////////////////////////////////////////////////////////////////////
//
// Drive.h
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "../OI.h"
#include "../Subsystems/DriveTrain.h"

#include <Buttons/JoystickButton.h>

// Summary:
//
class Drive : public CommandBase
{
private:
	frc::JoystickButton* m_atSwitch;

public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // DRIVE_H
