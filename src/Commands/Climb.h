#ifndef CLIMB_H
#define CLIMB_H

#include "../CommandBase.h"
#include <Buttons/JoystickButton.h>

class Climb : public CommandBase
{
private:
	double m_speed;
	frc::JoystickButton* m_thisBtn;

public:
	Climb(frc::JoystickButton*, double);
	~Climb();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // CLIMB_H
