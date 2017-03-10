#include "Shift.h"

Shift::Shift() :
	CommandBase("Shift")
{
	Requires(drive.get());
}

void Shift::Initialize()
{
}

void Shift::Execute()
{
	drive.get()->Shift();
}

bool Shift::IsFinished()
{
	return true;
}

void Shift::End()
{
}

void Shift::Interrupted()
{
}
