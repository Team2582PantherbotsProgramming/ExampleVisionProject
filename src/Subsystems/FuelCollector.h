#ifndef FUEL_COLLECTOR_H
#define FUEL_COLLECTOR_H

#include <Commands/Subsystem.h>
#include <Servo.h>
#include <Ultrasonic.h>
//#include <CANTalon.h>
#include <Preferences.h>
#include <Timer.h>

#include "../ExtSubsystem.h"

// Summary:
// 	Fuel collector and container (magazine for shooter)
class FuelCollector : public frc::Subsystem, public ExtSubsystem
{
private:
	enum CollectState
	{
		kStopped = 0,
		kCollecting = 1,
		kEjecting = 2
	} m_state;

	//CANTalon* m_meter;
	//CANTalon* m_intake;

	int m_currentMeterPos;

	std::string state_to_string(uint32_t state);

public:
	FuelCollector();
	~FuelCollector();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void IndexOne();

	// Set the motor that collects balls
	void SetIntake(double speed);

	void Index(double speed);
};

#endif // FUEL_COLLECTOR_H
