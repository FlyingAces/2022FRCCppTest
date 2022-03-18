// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/WestCoastDrive.h"

WestCoastDrive::WestCoastDrive() {
  SetName("WestCoastDrive");
  SetSubsystem("WestCoastDrive");
}

void WestCoastDrive::arcadeDrive(double speed, double rotation) {
  m_differntialDrive.ArcadeDrive(speed, rotation, false);
}

void WestCoastDrive::zeroDrivetrain() {
  m_LeftLeader.SetSelectedSensorPosition(0.0);
  m_RightLeader.SetSelectedSensorPosition(0.0);
}

double WestCoastDrive::getLeftCurrentPosition() {
  return m_LeftLeader.GetSelectedSensorPosition(0);
}

double WestCoastDrive::getRightCurrentPosition() {
  return m_RightLeader.GetSelectedSensorPosition(0);
}



void WestCoastDrive::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void WestCoastDrive::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
