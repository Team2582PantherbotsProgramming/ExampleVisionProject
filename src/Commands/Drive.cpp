///////////////////////////////////////////////////////////////////////////////
//
// Drive.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "Drive.h"

Drive::Drive() :
	CommandBase("Drive")
{
	Requires(drive.get());
}

void Drive::Initialize()
{
	//drive.get()->SetTalonMode(CANSpeedController::kPercentVbus); // WARNING: This causes MP to be unusable

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_drive_mode");
	m_atSwitch = new frc::JoystickButton(oi.get()->GetStick(2), 1);
}

void Drive::Execute()
{
	if (m_atSwitch->Get())
	{
		drive.get()->TankDrive(oi.get()->GetYAxis(JOY_DRIVER_PORT), -oi.get()->GetYAxis(JOY_CODRIVER_PORT));
		drive.get()->PowerCompressor(false);
	}
	else
	{
		drive.get()->ArcadeDrive(-oi.get()->GetXAxis(JOY_CODRIVER_PORT), -oi.get()->GetYAxis(JOY_CODRIVER_PORT));
		drive.get()->PowerCompressor(true);
	}
}

bool Drive::IsFinished()
{
	return false;
}

void Drive::End()
{
	drive.get()->TankDrive(0, 0);
}

void Drive::Interrupted()
{
	End();
}
