///////////////////////////////////////////////////////////////////////////////
//
// DistancePIDWrapper.cpp
//
//  Created on: Feb 16, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include <DistancePIDWrapper.h>
#include <SmartDashboard/SmartDashboard.h>
#include "CommandBase.h"

DistancePIDWrapper::DistancePIDWrapper()
{
	// Uses DriveTrain
}

double DistancePIDWrapper::PIDGet()
{
	return frc::SmartDashboard::GetNumber("Distance", -1);
}

void DistancePIDWrapper::PIDWrite(double output)
{
	CommandBase::drive.get()->ArcadeDrive(output, 0);
}
