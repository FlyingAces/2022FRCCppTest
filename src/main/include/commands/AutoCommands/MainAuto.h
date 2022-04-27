#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/PrintCommand.h>

#include "commands/DriveCommands/DriveStraight.h"
#include "commands/DriveCommands/TurnFor.h"
#include "commands/DriveCommands/TurnToAnglePID.h"
#include "subsystems/WestCoastDrive.h"

class MainAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, MainAuto> {
    public:
        MainAuto(WestCoastDrive* p_Drive);
    
    private:
    WestCoastDrive* mp_Drive;
};
