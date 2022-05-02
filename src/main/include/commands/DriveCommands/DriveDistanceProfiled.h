#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/TrapezoidProfileCommand.h>

#include "subsystems/WestCoastDrive.h"

class DriveDistanceProfiled : public frc2::CommandHelper<frc2::TrapezoidProfileCommand<units::meters>, DriveDistanceProfiled> {
 public:
  DriveDistanceProfiled(WestCoastDrive* m_drive, units::meter_t m_distance);
};
