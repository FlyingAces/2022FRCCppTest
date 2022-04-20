#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ProfiledPIDCommand.h>

#include "subsystems/WestCoastDrive.h"

class TurnToAnglePID: public frc2::CommandHelper<frc2::ProfiledPIDCommand<units::radians>, TurnToAnglePID> {
 
 public:
  TurnToAnglePID(WestCoastDrive* p_drive, units::degree_t targetAngleDegrees);

  bool IsFinished() override;
};