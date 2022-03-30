#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/WestCoastDrive.h"

class ToggleDriveMode : public frc2::CommandHelper<frc2::CommandBase, ToggleDriveMode> {
    public:
    explicit ToggleDriveMode(WestCoastDrive *p_WestCoastDrive);

        void Execute() override;
        bool IsFinished() override;

    private:
        WestCoastDrive* mp_WestCoastDrive;
};