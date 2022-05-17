#include "commands/DriveCommands/DriveDistPID.h"

#include <frc/controller/ProfiledPIDController.h>

DriveDistPID::DriveDistPID(WestCoastDrive* mp_drive, units::meter_t target) : CommandHelper(
          frc::ProfiledPIDController<units::meters>(DrivePIDConst::kDriveP, DrivePIDConst::kDriveI, DrivePIDConst::kDriveD, {DrivePIDConst::kMaxSpeed, DrivePIDConst::kMaxAccel}),
          // Close loop on heading
          [mp_drive] { return ((mp_drive->getRightDist()+mp_drive->getLeftDist())/2); },
          // Set reference to target
          target,
          // Pipe output to turn robot
          [mp_drive](double output, auto setpointState) {
            mp_drive->arcadeDrive(output, 0);
          },
          // Require the drive
          {mp_drive}) {
  GetController().SetTolerance(DrivePIDConst::kDistTolerance, DrivePIDConst::kAccelTolerance);
  AddRequirements({mp_drive});
  mp_WestCoastDrive->zeroDrivetrain();
  GetController().Reset(0_m);
}
void DriveDistPID::Initialize() {
  mp_WestCoastDrive->zeroDrivetrain();
  GetController().Reset(0_m);
}
bool DriveDistPID::IsFinished() {
  return GetController().AtGoal();
}