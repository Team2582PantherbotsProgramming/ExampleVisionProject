#include "CollectGear.h"

CollectGear::CollectGear(bool direction)
{
	Requires(gearCollector.get());

	m_direction = direction;
}

void CollectGear::Initialize()
{
	std::string code = oi.get()->GetPrefs()->GetString("joy_btn_gear_end_collect");
	m_endBtn = new frc::JoystickButton(oi.get()->GetStick(2), 9);
}

void CollectGear::Execute()
{
	gearCollector.get()->SetIntake(m_direction ? FORWARD : BACKWARD);
}

bool CollectGear::IsFinished()
{
	return m_endBtn->Get();
}

void CollectGear::End()
{
	gearCollector.get()->Stop();
}

void CollectGear::Interrupted()
{
}
