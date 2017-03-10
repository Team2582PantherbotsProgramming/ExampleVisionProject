#include "Shoot.h"

Shoot::Shoot(double speedProp)
{
	Requires(shooter.get());
	Requires(fuelCollector.get());
	Requires(drive.get());

	m_isAligned = false;
	m_speedProportion = speedProp;
}

void Shoot::Initialize()
{
	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_shoot_end");
	m_abortBtn = new frc::JoystickButton(oi.get()->GetStick(2), 9);

	code = oi.get()->GetPrefs()->GetString("joy_btn_shoot_meter");
	m_meterBtn = new frc::JoystickButton(oi.get()->GetStick(1), 1);

	drive.get()->Disable();
	m_isAligned = false; // Get alignment
}

void Shoot::Execute()
{
	shooter.get()->Set(m_speedProportion);
	if (m_meterBtn->Get())
		fuelCollector.get()->Index(.5);
	else fuelCollector.get()->Index(0);
}

bool Shoot::IsFinished()
{
	// When no more balls are present or not aligned or abort pressed
	return m_abortBtn->Get(); //!isAligned
}

void Shoot::End()
{
	shooter.get()->Set(0);
	fuelCollector.get()->Index(0);
	drive.get()->Enable();
}

void Shoot::Interrupted()
{
}
