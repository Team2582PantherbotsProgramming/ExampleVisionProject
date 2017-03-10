#ifndef AUTO_CROSS_LINE_H
#define AUTO_CROSS_LINE_H

#include <Commands/CommandGroup.h>
#include "../../Profiles.h"

// Summary:
//
class AutoCrossLine : public frc::CommandGroup
{
public:
	AutoCrossLine(double delay, std::list<Profile*>* seq);
};

#endif  // AUTO_CROSS_LINE_H
