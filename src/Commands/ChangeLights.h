#ifndef CHANGE_LIGHTS_H
#define CHANGE_LIGHTS_H

#include "Commands/InstantCommand.h"

#include "../CommandBase.h"

// Summary:
//
class ChangeLights : public frc::InstantCommand
{
private:
	bool m_peg, m_shoot;
	Color m_color;

public:
	ChangeLights(Color color, bool peg, bool shoot);
	void Initialize();
};

#endif // CHANGE_LIGHTS_H
