///////////////////////////////////////////////////////////////////////////////
//
// DriveTrain.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include <iostream>

DriveTrain::DriveTrain() :
	frc::Subsystem("Drive")
{
	//m_lw = frc::LiveWindow::GetInstance();
}

DriveTrain::~DriveTrain()
{
	delete m_shifter;
	delete m_comp;
	//delete m_lf;
	//delete m_lb;
	//delete m_rf;
	//delete m_rb;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new Drive());
}

void DriveTrain::Initialize(frc::Preferences* prefs)
{
	//m_shifter = new Solenoid(DRIVE_SHIFT_PORT);
	m_comp = new frc::Relay(DRIVE_COMPRESS_PORT);
/*
	m_lb = new CANTalon(DRIVE_LEFT_PORT);
	m_lb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_lb->ConfigEncoderCodesPerRev(100);

	m_lf = new CANTalon(DRIVE_LF_PORT);
	m_lf->SetControlMode(CANTalon::ControlMode::kFollower);
	m_lf->Set(m_lb->GetDeviceID());

	m_rb = new CANTalon(DRIVE_RIGHT_PORT);
	m_rb->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	m_rb->ConfigEncoderCodesPerRev(100);

	m_rf = new CANTalon(DRIVE_RF_PORT);
	m_rf->SetControlMode(CANTalon::ControlMode::kFollower);
	m_rf->Set(m_rb->GetDeviceID());

	SetTalonMode(CANSpeedController::kSpeed);
	set_pid_values();

	//m_rf->SetInverted(true);
	//m_rb->SetInverted(true);
	m_lb->SetInverted(true);

	m_rb->SetSensorDirection(false);
	m_lb->SetSensorDirection(false);

	m_shiftState = m_shifter->Get();
	*/
}

void DriveTrain::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Gear", m_shiftState ? "High" : "Low");
	frc::SmartDashboard::PutBoolean("Compressor On", m_comp->Get() == frc::Relay::Value::kOn);

	if (verbose)
	{
		//frc::SmartDashboard::PutNumber("Count L", m_lb->GetEncVel());
		//frc::SmartDashboard::PutNumber("Count R", m_rb->GetEncVel());

		//frc::SmartDashboard::PutNumber("Left Out", m_lb->Get());
		//frc::SmartDashboard::PutNumber("Right Out", m_rb->Get());
	}
}
/*
CANSpeedController::ControlMode DriveTrain::get_talon_mode()
{
	return (CANSpeedController::ControlMode)(m_lb->GetControlMode() & m_rb->GetControlMode());
}
*/
void DriveTrain::set_pid_values()
{
	for (int i = 0; i < 2; i++)
	{
		//m_lb->SelectProfileSlot(i);
		//m_rb->SelectProfileSlot(i);
		//m_lb->SetPID(
		//		DRIVE_LEFT_POS_P,
		//		DRIVE_LEFT_POS_I,
		//		DRIVE_LEFT_POS_D);
		//m_lb->SetF(DRIVE_LEFT_POS_F);
		//m_rb->SetPID(
		//		DRIVE_RIGHT_POS_P,
		//		DRIVE_RIGHT_POS_I,
		//		DRIVE_RIGHT_POS_D);
		//m_rb->SetF(DRIVE_LEFT_POS_F);
	}
}
/*
void DriveTrain::SetTalonMode(CANSpeedController::ControlMode mode)
{
	m_lb->SetControlMode(mode);
	m_rb->SetControlMode(mode);

	set_pid_values();
}
*/
void DriveTrain::ArcadeDrive(double move, double rotate)
{
	if (m_disabled) return;
	if (m_reverse)
	{
		move = -move;
		rotate = -rotate;
	}

	double leftMotorOutput;
	double rightMotorOutput;

	if (move > 0.0)
	{
		if (rotate > 0.0)
		{
			leftMotorOutput = move - rotate;
			rightMotorOutput = std::max(move, rotate);
		}
		else
		{
			leftMotorOutput = std::max(move, -rotate);
			rightMotorOutput = move + rotate;
		}
	}
	else
	{
		if (rotate > 0.0)
		{
			leftMotorOutput = -std::max(-move, rotate);
		  	rightMotorOutput = move + rotate;
		}
		else
		{
			leftMotorOutput = move - rotate;
			rightMotorOutput = -std::max(-move, -rotate);
		}
	}

	//m_lb->Set(leftMotorOutput);
	//m_rb->Set(-rightMotorOutput);
}

void DriveTrain::TankDrive(double left, double right)
{
	if (m_disabled) return;
	if (m_reverse)
	{
		left = -left;
		right = -right;
	}
	//m_lb->Set(left);
	//m_rb->Set(-right);
}

void DriveTrain::Reverse()
{
	m_reverse = !m_reverse;
	//m_lb->SetInverted(m_reverse);
}

void DriveTrain::Shift()
{
	if (m_disabled) return;
	m_shifter->Set(!m_shiftState);
	m_shiftState = m_shifter->Get();
	//m_scaleFactor = m_shiftState ? 0.5 : 1.0;
}

void DriveTrain::PowerCompressor(bool on)
{
	m_comp->Set(on ? frc::Relay::Value::kOn : frc::Relay::Value::kOff);
}

void DriveTrain::SetScale(double scale)
{
	m_scaleFactor = scale;
}

double DriveTrain::GetScale()
{
	return m_scaleFactor;
}

void DriveTrain::GetPosition(double& lPos, double& rPos)
{
	//lPos = m_lb->GetEncPosition();
	//rPos = m_rb->GetEncPosition();
}

double DriveTrain::GetVelocity()
{
	//return (m_lb->GetEncVel() + m_rb->GetEncVel()) / 2;
}
