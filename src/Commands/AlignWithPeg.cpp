#include "AlignWithPeg.h"
#include "../AlignPIDWrapper.h"

#include <Preferences.h>

AlignWithPeg::AlignWithPeg(frc::JoystickButton* abortBtn)
{
	Requires(drive.get());
	Requires(visionManager.get());

	frc::Preferences* prefs = oi.get()->GetPrefs();

	AlignPIDWrapper* pidSO = new AlignPIDWrapper();

	m_pid = new frc::PIDController(
			prefs->GetDouble("align_drive_p"),
			prefs->GetDouble("align_drive_i"),
			prefs->GetDouble("align_drive_d"),
			pidSO,
			pidSO);

	m_abortBtn = abortBtn;
}

AlignWithPeg::~AlignWithPeg()
{
	delete m_pid;
}

void AlignWithPeg::Initialize()
{
	m_pid->SetTolerance(ALIGN_PEG_TOLERANCE);
	//drive.get()->SetTalonMode(CANSpeedController::kPosition);
}

void AlignWithPeg::Execute()
{
	m_pid->SetSetpoint(0);
}

bool AlignWithPeg::IsFinished()
{
	return m_pid->OnTarget() && frc::SmartDashboard::GetNumber("Distance", -2);
}

void AlignWithPeg::End()
{
}

void AlignWithPeg::Interrupted()
{
}
