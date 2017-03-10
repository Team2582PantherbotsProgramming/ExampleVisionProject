///////////////////////////////////////////////////////////////////////////////
//
// MotionControl.h
//
//  Created on: Feb 18, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef MOTION_CONTROL_H
#define MOTION_CONTROL_H

#include "Subsystems/DriveTrain.h"
#include "RobotMap.h"
#include "Profiles.h"

#include <Notifier.h>
//#include <CANTalon.h>

#include <list>

//typedef CANTalon::TrajectoryPoint Point;

#define NOT_REVERSE 0
#define REVERSE 1
#define LEFT 2
#define RIGHT 3

// Summary:
//
class MotionControl
{
private:
	std::list<Profile*> m_sequence;
	std::list<Profile*>::iterator m_currentPr;

	//CANTalon::MotionProfileStatus m_leftStatus, m_rightStatus;

	int m_loopTimeout;
	int m_state = -1;

	bool m_isFinished = false;

	//CANTalon::SetValueMotionProfile m_leftSetValue = CANTalon::SetValueMotionProfileDisable,
	//								m_rightSetValue = CANTalon::SetValueMotionProfileDisable;

	std::shared_ptr<DriveTrain> m_drive;

	//CANTalon* m_driveLeft;
	//CANTalon* m_driveRight;

	frc::Notifier* m_notifier;

	void periodic_tasks();
	//Point create_point(double position, double velocity, double duration, int slot, bool first, bool last, bool velOnly = false);
	//Point invert_point(Point& point);

public:
	MotionControl(std::shared_ptr<DriveTrain> drive, std::list<Profile*>& profileSeq);
	~MotionControl();

	void Initialize();

	void Fill(int start, int end, Profile& profile, bool split);

	void Update();

	void Finish();
	bool IsFinished() { return m_isFinished; }
};

#endif // MOTION_CONTROL_H
