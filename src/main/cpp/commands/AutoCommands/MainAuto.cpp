#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    // SAFE ISH
    mp_Drive->zeroDrivetrain();
    AddCommands(frc2::PrintCommand("Drive"), 
    DriveDistPID(mp_Drive, 1_m), 
    frc2::PrintCommand("END"));
}