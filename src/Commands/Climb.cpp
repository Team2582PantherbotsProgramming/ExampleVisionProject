#include "Climb.h"

Climb::Climb(frc::JoystickButton* thisBtn, double speed)
{
	Requires(climber.get());

	m_thisBtn = thisBtn;
	m_speed = speed;
}

Climb::~Climb()
{
}

void Climb::Initialize()
{
}

void Climb::Execute()
{
	climber.get()->SetSpeed(-m_speed);
}

bool Climb::IsFinished()
{
	return !m_thisBtn->Get();
}

void Climb::End()
{
	climber.get()->SetSpeed(0);
}

void Climb::Interrupted()
{
}
