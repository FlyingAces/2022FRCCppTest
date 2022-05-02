#include "commands/DriveCommands/DriveDistanceProfiled.h"

DriveDistanceProfiled::DriveDistanceProfiled(WestCoastDrive* m_drive, units::meter_t m_distance) : CommandHelper(
          frc::TrapezoidProfile<units::meters>(
              // Limit the max acceleration and velocity
              {WestCoastConstants::k_MaxSpeed, WestCoastConstants::k_MaxAcceleration},
              // End at desired position in meters; implicitly starts at 0
              {m_distance, 0_mps}),
          // Pipe the profile state to the drive
          [m_drive](auto setpointState) {
            m_drive->SetDriveStates(setpointState, setpointState);
          },
          // Require the drive
          {m_drive}) {
  // Reset drive encoders since we're starting at 0
  m_drive->zeroDrivetrain();
}