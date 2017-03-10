#ifndef SHIFT_H
#define SHIFT_H

#include "../CommandBase.h"

// Summary:
//	Toggles between low and high gear on the drive train
class Shift : public CommandBase
{
public:
	Shift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // SHIFT_H
