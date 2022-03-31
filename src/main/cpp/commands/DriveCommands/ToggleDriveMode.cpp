#include "commands/DriveCommands/ToggleDriveMode.h"

ToggleDriveMode::ToggleDriveMode(WestCoastDrive* p_WestCoastDrive) : mp_WestCoastDrive {p_WestCoastDrive} {
    SetName("ToggleDriveMode");
    AddRequirements(mp_WestCoastDrive);
}

void ToggleDriveMode::Execute() {
    mp_WestCoastDrive->toggleDriveMode();
}

bool ToggleDriveMode::IsFinished() {
    return true;
}