#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/WestCoastDrive.h"

class DriveWithController : public frc2::CommandHelper<frc2::CommandBase, DriveWithController> {
    public:
        explicit DriveWithController(WestCoastDrive *p_WestCoastDrive);

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interupted) override;

    private:
        WestCoastDrive* mp_WestCoastDrive;
};