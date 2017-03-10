#include "AutoCrossLine.h"

#include "../Delay.h"
#include "../DriveProfile.h"

AutoCrossLine::AutoCrossLine(double delay, std::list<Profile*>* seq)
{
	AddSequential(new Delay(delay));
	AddSequential(new DriveProfile(*seq));
}
