#include "CollectFuel.h"

CollectFuel::CollectFuel()
{
	Requires(fuelCollector.get());
}

void CollectFuel::Initialize()
{
	m_speed = -.85; //oi.get()->GetPrefs()->GetDouble("fuel_intake_speed", FUEL_INTAKE_SPEED);

	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_fuel_end_intake");
	m_endBtn = new frc::JoystickButton(oi.get()->GetStick(2), 2);
}

void CollectFuel::Execute()
{
	fuelCollector.get()->SetIntake(m_speed);
}

bool CollectFuel::IsFinished()
{
	return m_endBtn->Get();
}

void CollectFuel::End()
{
	fuelCollector.get()->SetIntake(0);
}

void CollectFuel::Interrupted()
{
}
