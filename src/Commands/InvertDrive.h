#ifndef INVERT_DRIVE_H
#define INVERT_DRIVE_H

#include "Commands/InstantCommand.h"
#include "../CommandBase.h"

// Summary:
//
class InvertDrive : public frc::InstantCommand
{
public:
	InvertDrive();
	void Initialize();
};

#endif // INVERT_DRIVE_H
