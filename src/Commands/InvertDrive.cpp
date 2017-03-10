#include "InvertDrive.h"

InvertDrive::InvertDrive()
{
	Requires(CommandBase::drive.get());
}

void InvertDrive::Initialize()
{
	CommandBase::drive.get()->Reverse();
}
