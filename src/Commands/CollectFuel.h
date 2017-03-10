#ifndef COLLECT_FUEL_H
#define COLLECT_FUEL_H

#include "../CommandBase.h"
#include "../OI.h"

// Summary:
//
class CollectFuel : public CommandBase
{
private:
	frc::JoystickButton* m_endBtn;

	double m_speed;

public:
	CollectFuel();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // COLLECT_FUEL_H
