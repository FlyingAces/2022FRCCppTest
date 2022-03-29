#include "commands/DriveCommands/DriveWithController.h"

DriveWithController::DriveWithController(WestCoastDrive* p_WestCoastDrive) : mp_WestCoastDrive {p_WestCoastDrive} {
    SetName("DriveWithController");
    AddRequirements(mp_WestCoastDrive);
}

void DriveWithController::Initialize() {}

void DriveWithController::Execute() {
    if (!(mp_WestCoastDrive->getAutoState())) {
        mp_WestCoastDrive->controllerDrive();
    }
}

bool DriveWithController::IsFinished() {
    return false;
}

void DriveWithController::End(bool interrupted) {
}