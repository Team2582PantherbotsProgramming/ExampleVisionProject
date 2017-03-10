///////////////////////////////////////////////////////////////////////////////
//
// DistancePIDWrapper.h
//
//  Created on: Feb 16, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DISTANCE_PID_WRAPPER_H
#define DISTANCE_PID_WRAPPER_H

#include <PIDOutput.h>
#include <PIDSource.h>

class DistancePIDWrapper: public frc::PIDSource, public frc::PIDOutput
{
public:
	DistancePIDWrapper();
	double PIDGet() override;
	void PIDWrite(double output) override;
};

#endif // DISTANCE_PID_WRAPPER_H
