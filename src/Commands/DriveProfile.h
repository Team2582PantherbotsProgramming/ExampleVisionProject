#ifndef DRIVE_PROFILE_H
#define DRIVE_PROFILE_H

#include "../CommandBase.h"
#include "../MotionControl.h"

// Summary:
//
class DriveProfile : public CommandBase
{
private:
	MotionControl* m_motionControl;

	std::list<Profile*> m_seq;

	frc::JoystickButton* m_abortBtn;

public:
	DriveProfile(std::list<Profile*>& seq);
	~DriveProfile();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif // DRIVE_PROFILE_H
