#ifndef LIGHTS_H
#define LIGHTS_H

#include <Commands/Subsystem.h>
#include <DriverStation.h>
#include <Preferences.h>
#include <Solenoid.h>

#include "../ExtSubsystem.h"

// Summary:
//  Structure that contains color data
struct Color
{
	char* name;
	bool red;
	bool green;
	bool blue;

	Color(bool r, bool g, bool b, char* n = nullptr)
	{
		red = r;
		green = g;
		blue = b;
		name = n;
	}

	Color(const Color& color)
	{
		red = color.red;
		blue = color.blue;
		green = color.green;
		name = color.name;
	}
};

#define OFF     Color(0, 0, 0, "OFF")
#define WHITE   Color(1, 1, 1, "WHITE")
#define RED     Color(1, 0, 0, "RED")
#define GREEN   Color(0, 1, 0, "GREEN")
#define BLUE    Color(0, 0, 1, "BLUE")
#define YELLOW  Color(1, 1, 0, "YELLOW")
#define	VIOLET  Color(1, 0, 1, "VIOLET")
#define CYAN    Color(0, 1, 1, "CYAN")

// Summary:
//	Controls indicators (mainly lights) for robot feedback
class Lights : public frc::Subsystem, public ExtSubsystem
{
private:
	frc::DriverStation::Alliance m_alliance;
	int m_position;

	frc::Solenoid* m_pegCamLight;
	frc::Solenoid* m_shootCamLight;

	frc::Solenoid* m_red;
	frc::Solenoid* m_green;
	frc::Solenoid* m_blue;

	Color m_color;

public:
	Lights();
	~Lights();
	void InitDefaultCommand();

	void Initialize(frc::Preferences* prefs) override;
	void DashboardOutput(bool verbose = false) override;

	void SetPegCamLight(bool on);
	void SetShootCamLight(bool on);

	void SetColor(const Color& color);

	inline bool IsBlue() { return m_alliance == frc::DriverStation::Alliance::kBlue; }
	inline bool IsRed() { return m_alliance == frc::DriverStation::Alliance::kRed; }
	inline int GetLocation() { return m_position; }
};

#endif // LIGHTS_H
