#ifndef AUTO_PEG_GEAR_H
#define AUTO_PEG_GEAR_H

#include <Commands/CommandGroup.h>

#include "../../Profiles.h"

// Summary:
//
class AutoPegGear : public frc::CommandGroup
{
public:
	AutoPegGear(double delay, std::list<Profile*>* prePegSeq, std::list<Profile*>* postPegSeq);
};

#endif // AUTO_PEG_GEAR_H
