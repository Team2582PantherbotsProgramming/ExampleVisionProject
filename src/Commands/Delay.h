#ifndef DELAY_H
#define DELAY_H

#include "../CommandBase.h"

// Summary:
// Disables the Robot for a period of time
class Delay : public CommandBase
{
private:
	double m_delay;

	frc::Timer* m_delayTimer;

public:
	Delay(double delay);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // DELAY_H
