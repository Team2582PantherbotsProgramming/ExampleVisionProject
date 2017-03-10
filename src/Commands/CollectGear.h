#ifndef COLLECT_GEAR_H
#define COLLECT_GEAR_H

#include "../CommandBase.h"
#include "../OI.h"

// Summary:
//
class CollectGear : public CommandBase
{
private:
	frc::JoystickButton* m_endBtn;

	bool m_direction;

public:
	CollectGear(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // COLLECT_GEAR_H
