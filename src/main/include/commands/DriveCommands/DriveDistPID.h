#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ProfiledPIDCommand.h>

#include "subsystems/WestCoastDrive.h"

class DriveDistPID: public frc2::CommandHelper<frc2::ProfiledPIDCommand<units::meters>, DriveDistPID> {
 
 public:
  DriveDistPID(WestCoastDrive* p_drive, units::meter_t);

  void Initialize() override;
  bool IsFinished() override;

  private:
  WestCoastDrive* mp_WestCoastDrive;
};