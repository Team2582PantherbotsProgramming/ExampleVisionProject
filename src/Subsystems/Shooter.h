#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <Wpilib.h>
//#include <CANTalon.h>
#include <Preferences.h>

#include "../ExtSubsystem.h"

// Summary:
//	Class for managing the fuel launcher
class Shooter : public frc::Subsystem, public ExtSubsystem
{
private:
	enum ShootState
	{
		kStopped,
		kShooting,
		kRecovering
	} m_state;

	//CANTalon* m_shooter;

	double m_targetSpeed;

	std::string state_to_string(uint32_t state);

public:
	Shooter();
	~Shooter();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	// Sets the speed of the shooter motor
	void Set(double speed);

	// Returns whether the motor is at the target speed
	bool IsAtSpeed();
};

#endif // SHOOTER_H
