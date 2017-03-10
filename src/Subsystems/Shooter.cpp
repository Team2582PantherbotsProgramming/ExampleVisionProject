#include "Shooter.h"
#include "../RobotMap.h"

#include "../Commands/Shoot.h"

Shooter::Shooter() :
	frc::Subsystem("Shooter")
{
	m_targetSpeed = 0;
}

Shooter::~Shooter()
{
	//delete m_shooter;
}

void Shooter::InitDefaultCommand()
{
}

std::string Shooter::state_to_string(uint32_t state)
{
	switch (state)
	{
	case 0:
		return "Stopped";
		break;
	case 1:
		return "Shooting";
		break;
	case 2:
		return "Recovering";
		break;
	default:
		return "Error";
		break;
	}
}

void Shooter::Initialize(frc::Preferences* prefs)
{
	/*
	m_shooter = new CANTalon(SHOOT_MOTOR_PORT);
	m_shooter->SetControlMode(CANSpeedController::kPercentVbus);
	m_shooter->SetPID(
			frc::SmartDashboard::GetNumber("shoot_p", SHOOT_P),
			frc::SmartDashboard::GetNumber("shoot_i", SHOOT_I),
			frc::SmartDashboard::GetNumber("shoot_d", SHOOT_D));
	m_shooter->Enable();

	m_shooter->SetSensorDirection(true);
*/
	m_targetSpeed = prefs->GetDouble("shoot_speed", SHOOT_SPEED);
}

void Shooter::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Shooter State", state_to_string(m_state));
	//frc::SmartDashboard::PutNumber("Shooter Speed", m_shooter->Get() * 100);

	if (verbose)
	{

	}
}

void Shooter::Set(double speed)
{
	//m_shooter->Set(speed);
}

bool Shooter::IsAtSpeed()
{
	//return is_about(m_targetSpeed, m_shooter->Get(), 50.0);
}
