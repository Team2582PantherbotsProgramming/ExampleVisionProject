#include "AlignWithBoiler.h"
#include "../AlignPIDWrapper.h"

AlignWithBoiler::AlignWithBoiler(frc::JoystickButton* abortBtn)
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

AlignWithBoiler::~AlignWithBoiler()
{
	delete m_pid;
}

void AlignWithBoiler::Initialize()
{
	m_pid->SetTolerance(ALIGN_BOILER_TOLERANCE);
	//drive.get()->SetTalonMode(CANSpeedController::kPosition);
}

void AlignWithBoiler::Execute()
{
	m_pid->SetSetpoint(0);
}

bool AlignWithBoiler::IsFinished()
{
	return m_pid->OnTarget();
}

void AlignWithBoiler::End()
{

}

void AlignWithBoiler::Interrupted()
{

}
