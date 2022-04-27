#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(WestCoastDrive* p_Drive) : mp_Drive{p_Drive} {
    // SAFE ISH
    AddCommands(frc2::PrintCommand("Drive"), 
    DriveStraight(mp_Drive, 12, 0.3), 
    frc2::PrintCommand("Turn"), 
    TurnToAnglePID{mp_Drive, 180_deg}, 
    frc2::PrintCommand("Drive"), 
    DriveStraight(mp_Drive, 12, 0.3));
}