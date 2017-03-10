///////////////////////////////////////////////////////////////////////////////
//
// OI.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include "OI.h"
#include "RobotMap.h"

#include "Commands/Shoot.h"
#include "Commands/Shift.h"
#include "Commands/CollectGear.h"
#include "Commands/CollectFuel.h"
#include "Commands/Climb.h"
#include "Commands/InvertDrive.h"
#include "Commands/WaitForPeg.h"

#include <string>

OI::OI() :
	m_driver(new Joystick(JOY_DRIVER_PORT)),
	m_codriver(new Joystick(JOY_CODRIVER_PORT)),
	m_board(new Joystick(JOY_BOARD_PORT)),
	m_board2(new Joystick(JOY_BOARD_PORT2)),
	m_prefs(frc::Preferences::GetInstance())
{

}

OI::~OI()
{
	delete m_driver;
	delete m_codriver;
	delete m_board;
	delete m_shoot;
	delete m_shift;
	delete m_collectGear;
	delete m_ejectGear;
	delete m_collectFuel;
}

void OI::Initialize()
{
	std::string code = m_prefs->GetString("joy_btn_gear_collect");
	m_collectGear = new JoystickButton(GetStick(2), 11);
	m_collectGear->WhenPressed(new CollectGear(false));

	code = m_prefs->GetString("joy_btn_gear_eject");
	m_ejectGear = new JoystickButton(GetStick(2), 10);
	m_ejectGear->WhenPressed(new CollectGear(true));

	code = m_prefs->GetString("joy_btn_fuel_intake");
	m_collectFuel = new JoystickButton(GetStick(2), 3);
	m_collectFuel->WhenPressed(new CollectFuel());

	code = m_prefs->GetString("joy_btn_shoot");
	m_shoot = new JoystickButton(GetStick(2), 6);
	m_shoot->WhenPressed(new Shoot(.85));

	code = m_prefs->GetString("joy_btn_drive_shift");
	m_shift = new JoystickButton(GetStick(1), 2);
	m_shift->WhenPressed(new Shift());

	code = m_prefs->GetString("joy_btn_climb");
	m_climb = new frc::JoystickButton(GetStick(2), 8);
	m_climb->WhenPressed(new Climb(m_climb, .6));

	code = m_prefs->GetString("joy_btn_climb_fast");
	m_climbFast = new frc::JoystickButton(GetStick(3), 6);
	m_climbFast->WhenPressed(new Climb(m_climbFast, .95));

	//code = m_prefs->GetString("joy_btn_invert");
	//m_invertDrive = new frc::JoystickButton(GetStick(InterpretStick(code)), InterpretButton(code));
	//m_invertDrive->WhenPressed(new InvertDrive());
}

int OI::InterpretStick(std::string& code)
{
	if (code.length() <= 0) return 0;
	return code[0] - 48;
}

int OI::InterpretButton(std::string& code)
{
	if (code.length() <= 0) return 0;
	std::string str = "";
	bool b = false;
	for (int i = 0; i < code.length(); i++)
	{
		if (b)
			str += code[i];
		if (code[i] == '-') b = true;
	}
	return std::stoi(str);
}

double OI::Deadband(double input)
{
	return input <= m_deadband && input >= -m_deadband ? 0 : input;
}

frc::Joystick* OI::GetStick(int stick)
{
	switch (stick)
	{
	default:
	case 0:
		return m_driver;
		break;
	case 1:
		return m_codriver;
		break;
	case 2:
		return m_board;
		break;
	case 3:
		return m_board2;
		break;
	}
}

double OI::GetXAxis(int stick)
{
	return GetStick(stick)->GetAxis(frc::Joystick::AxisType::kXAxis);
}

double OI::GetYAxis(int stick)
{
	return GetStick(stick)->GetAxis(frc::Joystick::AxisType::kYAxis);
}

double OI::GetZAxis(int stick)
{
	return GetStick(stick)->GetAxis(frc::Joystick::AxisType::kZAxis);
}

void OI::SetDeadband(double band)
{
	EnableDeadband(true);
	m_deadband = band;
}
