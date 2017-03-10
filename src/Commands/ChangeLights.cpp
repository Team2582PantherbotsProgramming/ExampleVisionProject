#include "ChangeLights.h"

ChangeLights::ChangeLights(Color color, bool peg, bool shoot) :
	m_color(color), m_peg(peg), m_shoot(shoot)
{
	Requires(CommandBase::lights.get());
}

void ChangeLights::Initialize()
{
	CommandBase::lights.get()->SetColor(m_color);
	CommandBase::lights.get()->SetPegCamLight(m_peg);
	CommandBase::lights.get()->SetShootCamLight(m_shoot);
}
