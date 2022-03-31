#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    AddCommands(DriveStraight(mp_Drive, 40, 0.5), DriveStraight(mp_Drive, -40, 0.25));
}