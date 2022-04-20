#include "commands/DriveCommands/TurnToAnglePID.h"

#include <frc/controller/ProfiledPIDController.h>

TurnToAnglePID::TurnToAnglePID(WestCoastDrive* mp_drive, units::degree_t target) : CommandHelper(
          frc::ProfiledPIDController<units::radians>(WestCoastConstants::kTurnP, WestCoastConstants::kTurnI, WestCoastConstants::kTurnD, {WestCoastConstants::kMaxTurnRate, WestCoastConstants::kMaxTurnAcceleration}),
          // Close loop on heading
          [mp_drive] { return mp_drive->getGyro(); },
          // Set reference to target
          target,
          // Pipe output to turn robot
          [mp_drive](double output, auto setpointState) {
            mp_drive->arcadeDrive(0, output);
          },
          // Require the drive
          {mp_drive}) {
  // Set the controller to be continuous (because it is an angle controller)
  GetController().EnableContinuousInput(-180_deg, 180_deg);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  GetController().SetTolerance(WestCoastConstants::kTurnTolerance, WestCoastConstants::kTurnRateTolerance);

  AddRequirements({mp_drive});
}

bool TurnToAnglePID::IsFinished() {
  return GetController().AtGoal();
}