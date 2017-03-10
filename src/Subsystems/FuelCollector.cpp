#include "FuelCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectFuel.h"

FuelCollector::FuelCollector() :
	Subsystem("Fuel Collector")
{
}

FuelCollector::~FuelCollector()
{
	//delete m_meter;
	//delete m_intake;
}

std::string FuelCollector::state_to_string(uint32_t state)
{
	switch (state)
	{
	case 0:
		return "Stopped";
		break;
	case 1:
		return "Collecting";
		break;
	case 2:
		return "Ejecting";
		break;
	default:
		return "Error";
		break;
	}
}

void FuelCollector::InitDefaultCommand()
{
}

void FuelCollector::Initialize(frc::Preferences* prefs)
{
	/*
	m_meter = new CANTalon(FUEL_METER_PORT);
	m_meter->SetControlMode(CANSpeedController::kPercentVbus);

	//m_meter->Reset();
	m_currentMeterPos = 0;

	m_intake = new CANTalon(FUEL_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_state = CollectState::kStopped;
	*/
}

void FuelCollector::DashboardOutput(bool verbose)
{
	/*
	frc::SmartDashboard::PutString("Fuel Collector State", state_to_string(m_state));
	frc::SmartDashboard::PutBoolean("Fuel Intake On", m_intake->Get() > 0.0);
	frc::SmartDashboard::PutBoolean("Meter On", !!m_meter->Get());

	if (verbose)
	{
		frc::SmartDashboard::PutNumber("Meter Count", m_meter->GetEncPosition());
		frc::SmartDashboard::PutNumber("Balls Indexed to Shooter", m_currentMeterPos / (FUEL_METER_CPR / FUEL_BALL_PER_TURN));
	}
	*/
}

void FuelCollector::IndexOne()
{
	/*
	m_currentMeterPos = m_meter->GetEncPosition();
	m_currentMeterPos += -(1 / FUEL_BALL_PER_TURN) * FUEL_METER_CPR;
	m_meter->Set(m_currentMeterPos);
	*/
}

void FuelCollector::SetIntake(double speed)
{
	//m_intake->Set(speed);
}

void FuelCollector::Index(double speed)
{
	//m_meter->Set(-speed);
}
