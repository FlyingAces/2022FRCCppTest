#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    AddCommands(DriveStraight(mp_Drive, 12, 0.5));
}