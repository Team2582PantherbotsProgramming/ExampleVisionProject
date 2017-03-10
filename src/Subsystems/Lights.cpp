#include "Lights.h"
#include "../RobotMap.h"

#include <SmartDashboard/SmartDashboard.h>

Lights::Lights() :
	frc::Subsystem("Lights"),
	m_color(OFF)
{
}

Lights::~Lights()
{
	delete m_red;
	delete m_green;
	delete m_blue;
}

void Lights::InitDefaultCommand()
{
}

void Lights::Initialize(frc::Preferences* prefs)
{
	m_alliance = frc::DriverStation::GetInstance().GetAlliance();
	m_position = frc::DriverStation::GetInstance().GetLocation();

	m_pegCamLight = new frc::Solenoid(LIGHT_PEG_PORT);
	m_shootCamLight = new frc::Solenoid(LIGHT_BOILER_PORT);

	m_red = new frc::Solenoid(LIGHT_RED_PORT);
	m_green = new frc::Solenoid(LIGHT_GREEN_PORT);
	m_blue = new frc::Solenoid(LIGHT_BLUE_PORT);

	SetPegCamLight(true);
}

void Lights::DashboardOutput(bool verbose)
{
	frc::SmartDashboard::PutString("Light Color", m_color.name);
	frc::SmartDashboard::PutBoolean("Peg Light", m_pegCamLight->Get());
	frc::SmartDashboard::PutBoolean("Shoot Light", m_shootCamLight->Get());

	if (verbose)
	{

	}
}

void Lights::SetPegCamLight(bool on)
{
	m_pegCamLight->Set(on);
}

void Lights::SetShootCamLight(bool on)
{
	m_shootCamLight->Set(on);
}

void Lights::SetColor(const Color& color)
{
	m_red->Set(color.red);
	m_green->Set(color.green);
	m_blue->Set(color.blue);
	m_color = color;
}
