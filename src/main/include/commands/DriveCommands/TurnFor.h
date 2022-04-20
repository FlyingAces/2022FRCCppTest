/*#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/WestCoastDrive.h"

class TurnFor : public frc2::CommandHelper<frc2::CommandBase, TurnFor> {
    public:
    explicit TurnFor(WestCoastDrive *p_WestCoastDrive, double degrees);
    
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interupted);

    private:
    WestCoastDrive* mp_WestCoastDrive;
    double m_Degrees;
    double m_TurnDir;
    double m_TurnErr;
};*/