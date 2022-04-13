#include "commands/DriveCommands/TurnFor.h"

TurnFor::TurnFor(WestCoastDrive* p_WestCoastDrive, double degrees) : mp_WestCoastDrive {p_WestCoastDrive}, m_Degrees {degrees} {
    SetName("TurnFor");
    AddRequirements(p_WestCoastDrive);
}

void TurnFor::Initialize() {
    // Zeros Gyro So Turn Is Relative
    mp_WestCoastDrive->zeroGyro();
}

void TurnFor::Execute() {
    // TODO Make PID
    // DOESNT WORK FOR BIG NUMBERS
    m_TurnErr = m_Degrees - mp_WestCoastDrive->getGyro();
    mp_WestCoastDrive->tankDrive((0.03 * m_TurnErr), (-0.03 * m_TurnErr));
}

bool TurnFor::IsFinished() {
    return false;
}

void TurnFor::End(bool interupted) {}