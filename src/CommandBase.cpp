///////////////////////////////////////////////////////////////////////////////
//
// CommandBase.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "CommandBase.h"

#include <Commands/Scheduler.h>


std::shared_ptr<DriveTrain> CommandBase::drive =
		std::make_shared<DriveTrain>();
std::shared_ptr<Shooter> CommandBase::shooter =
		std::make_shared<Shooter>();
std::shared_ptr<GearCollector> CommandBase::gearCollector =
		std::make_shared<GearCollector>();
std::shared_ptr<Climber> CommandBase::climber =
		std::make_shared<Climber>();
std::shared_ptr<FuelCollector> CommandBase::fuelCollector =
		std::make_shared<FuelCollector>();
std::shared_ptr<VisionManager> CommandBase::visionManager =
		std::make_shared<VisionManager>();
std::shared_ptr<Lights> CommandBase::lights =
		std::make_shared<Lights>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

// Add Subsystems

CommandBase::CommandBase(const std::string& name) :
	frc::Command(name)
{

}
