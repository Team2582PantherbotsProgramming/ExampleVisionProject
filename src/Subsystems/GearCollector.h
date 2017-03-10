#ifndef GEAR_COLLECTOR_H
#define GEAR_COLLECTOR_H

#include <Commands/Subsystem.h>
//#include <CANTalon.h>
#include <Preferences.h>
#include <DigitalInput.h>

#include "../ExtSubsystem.h"

#define FORWARD 1
#define BACKWARD -1

// Summary:
// 	Gear collector and management system
class GearCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	enum CollectState
	{
		kStopped = 0,
		kCollecting = 1,
		kEjecting = 2
	} m_state;

	//CANTalon* m_intake;
	//CANTalon* m_transportFront;
	//CANTalon* m_transportBack;

	DigitalInput* m_gearSensor;

	double m_intakeSpeed;
	double m_transSpeed;

	void gear_poller();

	std::string state_to_string(uint32_t state);

public:
	GearCollector();
	~GearCollector();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	bool IsGearPresent();

	// Set all of the motors
	void SetIntake(int direction);
	void Stop();
};

#endif // GEAR_COLLECTOR_H
