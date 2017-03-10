///////////////////////////////////////////////////////////////////////////////
//
// MotionControl.cpp
//
//  Created on: Feb 18, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "MotionControl.h"

#include <iostream>

void MotionControl::periodic_tasks()
{
	//m_driveLeft->ProcessMotionProfileBuffer();
	//m_driveRight->ProcessMotionProfileBuffer();
}

MotionControl::MotionControl(std::shared_ptr<DriveTrain> drive, std::list<Profile*>& sequence) :
	m_notifier(new frc::Notifier(&MotionControl::periodic_tasks, this)),
	//m_driveLeft(drive->m_lb), m_driveRight(drive->m_rb), m_drive(drive),
	m_sequence(sequence)
{
}

MotionControl::~MotionControl()
{
	delete m_notifier;
}
/*
Point MotionControl::create_point(double position, double velocity, double duration, int slot, bool first, bool last, bool velOnly)
{
	Point point;
	point.position = position;
	point.velocity = velocity;
	point.timeDurMs = duration;
	point.profileSlotSelect = slot;
	point.zeroPos = first;
	point.isLastPoint = last;
	point.velocityOnly = velOnly;
	return point;
}


Point MotionControl::invert_point(Point& point)
{
	point.position = -point.position;
	point.velocity = -point.velocity;
	return point;
}
*/
void MotionControl::Fill(int start, int end, Profile& profile, bool split)
{
	if (!split)
	{
		//m_driveLeft->ClearMotionProfileTrajectories();
		//m_driveRight->ClearMotionProfileTrajectories();
	}

	//Point pt;

	//if (m_leftStatus.hasUnderrun)
	//	m_driveLeft->ClearMotionProfileHasUnderrun();
	//if (m_rightStatus.hasUnderrun)
	//	m_driveRight->ClearMotionProfileHasUnderrun();

	for (int i = start; i < end; i++)
	{
		//pt = create_point(profile.profile[i][0], profile.profile[i][1], profile.profile[i][2], 1, i == 0, i == profile.size - 1);
		if (profile.turn == LEFT)
		{
			//m_driveLeft->PushMotionProfileTrajectory(invert_point(pt));
			//m_driveRight->PushMotionProfileTrajectory(pt);
		}
		else if (profile.turn == RIGHT)
		{
			//m_driveLeft->PushMotionProfileTrajectory(pt);
			//m_driveRight->PushMotionProfileTrajectory(pt);
		}
		else if (profile.turn == NOT_REVERSE)
		{
			//m_driveLeft->PushMotionProfileTrajectory(pt);
			//m_driveRight->PushMotionProfileTrajectory(invert_point(pt));
		}
		else if (profile.turn == REVERSE)
		{
			//m_driveLeft->PushMotionProfileTrajectory(invert_point(pt));
			//m_driveRight->PushMotionProfileTrajectory(invert_point(pt));
		}
	}
}

void MotionControl::Initialize()
{
	m_currentPr = m_sequence.begin();
	if (m_currentPr != m_sequence.end()) m_state = 0;

	//m_drive->SetTalonMode(frc::CANSpeedController::kMotionProfile);

	//m_driveLeft->ChangeMotionControlFramePeriod(5);
	//m_driveRight->ChangeMotionControlFramePeriod(5);

	m_notifier->StartPeriodic(.01); // 10ms

	m_drive->Disable();

	//m_driveRight->Enable();
}

void MotionControl::Update()
{
	//m_driveLeft->GetMotionProfileStatus(m_leftStatus);
	//m_driveRight->GetMotionProfileStatus(m_rightStatus);

	if (m_loopTimeout < 0); // nothing
	else
	{
		if (m_loopTimeout == 0)
			std::cout << "HILFE!!" << std::endl;// error
		else
			--m_loopTimeout;
	}

	//if (m_driveLeft->GetControlMode() != CANSpeedController::kMotionProfile ||
	//	m_driveRight->GetControlMode() != CANSpeedController::kMotionProfile)
	//{
	//	return;
	//}
	/*
	switch (m_state)
	{
	case -1:
		m_isFinished = true;
		break;
	case 0:
		//m_leftSetValue = CANTalon::SetValueMotionProfileDisable;
		//m_rightSetValue = CANTalon::SetValueMotionProfileDisable;

		//m_driveLeft->SetEncPosition(0);
		//m_driveRight->SetEncPosition(0);

		Fill(0, (*m_currentPr)->size, *(*m_currentPr), (*m_currentPr)->split);

		m_state = 1;
		m_loopTimeout = TIMEOUT_LOOPS;
		break;
	case 1:

		//if (m_leftStatus.btmBufferCnt > MIN_POINTS && m_rightStatus.btmBufferCnt > MIN_POINTS)
		//{
		//	m_state = 2;
		//	m_loopTimeout = TIMEOUT_LOOPS;
		//	m_rightSetValue = CANTalon::SetValueMotionProfileEnable;
	//		m_leftSetValue = CANTalon::SetValueMotionProfileEnable;
	//	}
		break;
	case 2:
		//if (!m_leftStatus.isUnderrun || !m_rightStatus.isUnderrun)
		//	m_loopTimeout = TIMEOUT_LOOPS;

		//if (m_leftStatus.activePointValid && m_leftStatus.activePoint.isLastPoint &&
		//	m_rightStatus.activePointValid && m_rightStatus.activePoint.isLastPoint)
		//{
		//	m_state = 0;
		//	m_loopTimeout = -1;

		//	m_leftSetValue = CANTalon::SetValueMotionProfileHold;
		//	m_rightSetValue = CANTalon::SetValueMotionProfileHold;

		//	m_currentPr++;
		//	if (m_currentPr == m_sequence.end())
		//		m_state = -1;
		//}
		//break;
	}
//	m_driveLeft->Set(m_leftSetValue);
//	m_driveRight->Set(m_rightSetValue);

	std::cout << m_state << std::endl;*/
}

void MotionControl::Finish()
{
	m_drive->Enable();
	//m_drive->SetTalonMode(CANSpeedController::kPercentVbus);
}
