#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    // SAFE ISH
    AddCommands(frc2::PrintCommand("Drive"), 
    DriveStraight(mp_Drive, 3, 0.35), 
    frc2::PrintCommand("END"));
}