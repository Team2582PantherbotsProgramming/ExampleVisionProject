///////////////////////////////////////////////////////////////////////////////
//
// Robot.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "CommandBase.h"

#include "Commands/Autonomous/AutoShoot.h"
#include "Commands/Autonomous/AutoCrossLine.h"
#include "Commands/Autonomous/AutoPegGear.h"
#include "Commands/Autonomous/AutoPickupAndPeg.h"
#include "Commands/Autonomous/AutoPickupGear.h"
#include "MotionControl.h"

class Robot: public frc::IterativeRobot
{
private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> autoModes;

	frc::LiveWindow* lw;

	std::list<Profile*> rp1PreSeq, rp2PreSeq, rp3PreSeq, bp1PreSeq, bp2PreSeq, bp3PreSeq, lineSeq1;
	std::list<Profile*> rp1PostSeq, rp2PostSeq, rp3PostSeq, bp1PostSeq, bp2PostSeq, bp3PostSeq;

	double autonDelay;

public:
	void InitializeSubsystems(frc::Preferences* prefs)
	{
		CommandBase::drive.get()->Initialize(prefs);
		CommandBase::shooter.get()->Initialize(prefs);
		CommandBase::gearCollector.get()->Initialize(prefs);
		CommandBase::climber.get()->Initialize(prefs);
		CommandBase::fuelCollector.get()->Initialize(prefs);
		CommandBase::lights.get()->Initialize(prefs);
		CommandBase::visionManager.get()->Initialize(prefs);

		CommandBase::oi.get()->Initialize();
		//CommandBase::visionManager->vision_thread();
		CommandBase::visionManager->StartProc();
	}

	void UpdateDashboard(bool verbose = false)
	{
		CommandBase::drive.get()->DashboardOutput(verbose);
		CommandBase::shooter.get()->DashboardOutput(verbose);
		CommandBase::gearCollector.get()->DashboardOutput(verbose);
		CommandBase::climber.get()->DashboardOutput(verbose);
		CommandBase::fuelCollector.get()->DashboardOutput(verbose);
		CommandBase::lights.get()->DashboardOutput(verbose);
		CommandBase::visionManager.get()->DashboardOutput(verbose);
	}

	void RobotInit() override
	{
		InitializeSubsystems(CommandBase::oi.get()->GetPrefs());

		// Default Cross baseline
		//autoModes.Add("Cross Line", new AutoCrossLine(0, &lineSeq1));
		// Peg 1 to 1
		rp1PreSeq.push_back(new Profile(REVERSE, Mp81p5Size, Mp81p5, false));
		rp1PreSeq.push_back(new Profile(RIGHT, Mp45TurnSize, Mp45Turn, false));
		rp1PreSeq.push_back(new Profile(REVERSE, Mp28p5Size, Mp28p5, false));
		rp1PostSeq.push_back(new Profile(NOT_REVERSE, Mp28p5Size, Mp28p5, false));
		rp1PostSeq.push_back(new Profile(LEFT, Mp45TurnSize, Mp45Turn, false));
		rp1PostSeq.push_back(new Profile(LEFT, Mp180TurnSize, Mp180Turn, false));
		rp1PostSeq.push_back(new Profile(NOT_REVERSE, MpPeg85Size, MpPeg85, false));
		autoModes.AddObject("Blue Peg Pos 1", new AutoPegGear(0, &rp1PreSeq, nullptr));

		// Peg 2 to 2
		rp2PreSeq.push_back(new Profile(REVERSE, Mp81p5Size, Mp81p5, false));
		autoModes.AddObject("Blue Peg Pos 2", new AutoPegGear(0, &rp2PreSeq, nullptr));

		// Peg 3 to 3
		rp3PreSeq.push_back(new Profile(REVERSE, Mp88Size, Mp88, false));
		rp3PreSeq.push_back(new Profile(LEFT, Mp45TurnSize, Mp45Turn, false));
		rp3PreSeq.push_back(new Profile(REVERSE, Mp35p125Size, Mp35p125, false));
		rp3PostSeq.push_back(new Profile(NOT_REVERSE, Mp35p125Size, Mp35p125, false));
		rp3PostSeq.push_back(new Profile(RIGHT, Mp45TurnSize, Mp45Turn, false));
		rp3PostSeq.push_back(new Profile(RIGHT, Mp180TurnSize, Mp180Turn, false));
		rp3PostSeq.push_back(new Profile(NOT_REVERSE, MpPeg92Size, MpPeg92, false));
		autoModes.AddObject("Blue Peg Pos 3", new AutoPegGear(0, &rp3PreSeq, nullptr));

		// Peg 1 to 1
		bp1PreSeq.push_back(new Profile(REVERSE, MpPeg85Size, MpPeg85, false));
		bp1PreSeq.push_back(new Profile(RIGHT, Mp45TurnSize, Mp45Turn, false));
		bp1PreSeq.push_back(new Profile(REVERSE, Mp28p5Size, Mp28p5, false));
		bp1PostSeq.push_back(new Profile(NOT_REVERSE, Mp35p125Size, Mp35p125, false));
		bp1PostSeq.push_back(new Profile(LEFT, Mp45TurnSize, Mp45Turn, false));
		bp1PostSeq.push_back(new Profile(LEFT, Mp180TurnSize, Mp180Turn, false));
		bp1PostSeq.push_back(new Profile(NOT_REVERSE, MpPeg92Size, MpPeg92, false));
		autoModes.AddObject("Red Peg Pos 1", new AutoPegGear(0, &bp1PreSeq, nullptr));

		// Peg 2 to 2
		bp2PreSeq.push_back(new Profile(REVERSE, Mp81p5Size, Mp81p5, false));
		autoModes.AddObject("Red Peg Pos 2", new AutoPegGear(0, &bp2PreSeq, nullptr));

		// Peg 3 to 3
		bp3PreSeq.push_back(new Profile(REVERSE, Mp88Size, Mp88, false));
		bp3PreSeq.push_back(new Profile(LEFT, Mp45TurnSize, Mp45Turn, false));
		bp3PreSeq.push_back(new Profile(REVERSE, Mp35p125Size, Mp35p125, false));
		bp3PostSeq.push_back(new Profile(NOT_REVERSE, Mp35p125Size, Mp35p125, false));
		bp3PostSeq.push_back(new Profile(RIGHT, Mp45TurnSize, Mp45Turn, false));
		bp3PostSeq.push_back(new Profile(RIGHT, Mp180TurnSize, Mp180Turn, false));
		bp3PostSeq.push_back(new Profile(NOT_REVERSE, MpPeg85Size, MpPeg85, false));
		autoModes.AddObject("Red Peg Pos 3", new AutoPegGear(0, &bp3PreSeq, nullptr));

		// Maybe add non post autos

		// Nothing
		autoModes.AddDefault("Nothing", nullptr);

		frc::SmartDashboard::Delete("Auto Modes"); // Attempt to fix no show chooser
		frc::SmartDashboard::PutData("Auto Modes", &autoModes);
	}

	void RobotPeriodic() override
	{
		UpdateDashboard();
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override
	{
	}

	void DisabledPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override
	{
		autonomousCommand.reset(autoModes.GetSelected());

		if (autonomousCommand.get() != nullptr)
		{
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override
	{
		CommandBase::drive.get()->Enable(); // In case that auto was stopped unexpectedly
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Cancel();
		}
	}

	void TeleopPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override
	{
		frc::LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)
