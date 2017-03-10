#ifndef ALIGN_WITH_PEG_H
#define ALIGN_WITH_PEG_H

#include "../CommandBase.h"

#include <PIDController.h>

// Summary:
//
class AlignWithPeg : public CommandBase
{
private:
	frc::PIDController* m_pid;

	frc::JoystickButton* m_abortBtn;

public:
	AlignWithPeg(frc::JoystickButton*);
	~AlignWithPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // ALIGN_WITH_PEG_H
