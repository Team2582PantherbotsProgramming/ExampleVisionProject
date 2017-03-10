#include "AutoPegGear.h"

#include "../DriveProfile.h"
#include "../WaitForPeg.h"
#include "../Delay.h"

AutoPegGear::AutoPegGear(double delay, std::list<Profile*>* prePegSeq, std::list<Profile*>* postPegSeq)
{
	AddSequential(new Delay(delay));
	if (prePegSeq != nullptr)
		AddSequential(new DriveProfile(*prePegSeq));
	// Peg Alignment Code here
	AddSequential(new WaitForPeg());
	if (postPegSeq != nullptr)
		AddSequential(new DriveProfile(*postPegSeq));
}
