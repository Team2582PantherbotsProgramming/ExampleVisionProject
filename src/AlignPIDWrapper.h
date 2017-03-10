///////////////////////////////////////////////////////////////////////////////
// AlignPIDWrapper.h
//
//  Created on: Feb 16, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ALIGN_PID_WRAPPER_H
#define ALIGN_PID_WRAPPER_H

#include <PIDOutput.h>
#include <PIDSource.h>

class AlignPIDWrapper : public frc::PIDSource, public frc::PIDOutput
{
public:
	AlignPIDWrapper();
	double PIDGet() override;
	void PIDWrite(double output) override;
};

#endif // ALIGN_PID_WRAPPER_H
