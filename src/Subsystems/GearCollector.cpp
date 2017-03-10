#include "GearCollector.h"
#include "../RobotMap.h"

#include "../Commands/CollectGear.h"

GearCollector::GearCollector() :
	Subsystem("Gear Collector")
{
}

GearCollector::~GearCollector()
{
	//delete m_intake;
	//delete m_transportFront;
	//delete m_transportBack;
	delete m_gearSensor;
}

void GearCollector::InitDefaultCommand()
{
}

std::string GearCollector::state_to_string(uint32_t state)
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

void GearCollector::Initialize(frc::Preferences* prefs)
{
	/*
	m_intake = new CANTalon(GEAR_INTAKE_PORT);
	m_intake->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_transportBack = new CANTalon(GEAR_TRANS_BACK_PORT);
	m_transportBack->SetControlMode(CANTalon::ControlMode::kPercentVbus);

	m_transportFront = new CANTalon(GEAR_TRANS_FRONT_PORT);
	m_transportFront->SetControlMode(CANTalon::ControlMode::kFollower);
	m_transportFront->Set(m_transportBack->GetDeviceID());
	 */
	m_intakeSpeed = frc::SmartDashboard::GetNumber("gear_intake_speed", GEAR_INTAKE_SPEED);
	m_transSpeed = frc::SmartDashboard::GetNumber("gear_trans_speed", GEAR_TRANS_SPEED);

	m_gearSensor = new frc::DigitalInput(GEAR_SENSOR_PORT);
}

void GearCollector::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Gear Collector State", state_to_string(m_state));
	frc::SmartDashboard::PutBoolean("Gear Present", IsGearPresent());
	//frc::SmartDashboard::PutBoolean("Gear Intake On", m_intake->Get() > 0.0);

	if (verbose)
	{

	}
}

bool GearCollector::IsGearPresent()
{
	return m_gearSensor->Get(); // Defaults to on (true = gear)
}

void GearCollector::SetIntake(int direction)
{
	m_state = CollectState::kCollecting;
	//m_intake->Set(m_intakeSpeed * direction);
	//m_transportBack->Set(m_transSpeed * direction);
}

void GearCollector::Stop()
{
	m_state = CollectState::kStopped;
	//m_intake->Set(0);
	//m_transportBack->Set(0);
}
