#ifndef WAIT_FOR_PEG_H
#define WAIT_FOR_PEG_H

#include "../CommandBase.h"

// Summary:
//
class WaitForPeg : public CommandBase
{
private:
	frc::JoystickButton* m_abortBtn;

	frc::Timer* m_gearGoneTimer;
	frc::Timer* m_lightFlashTimer;

	bool m_toggle = false;

public:
	WaitForPeg();
	~WaitForPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // WAIT_FOR_PEG_H
