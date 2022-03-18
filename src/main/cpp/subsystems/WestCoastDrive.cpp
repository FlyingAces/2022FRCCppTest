// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/WestCoastDrive.h"

WestCoastDrive::WestCoastDrive() {
  SetName("WestCoastDrive");
  SetSubsystem("WestCoastDrive");

  //Config
  m_LeftLeader.SetNeutralMode(Brake);
  m_RightLeader.SetNeutralMode(Brake);
  m_LeftFollower.SetNeutralMode(Brake);
  m_RightFollower.SetNeutralMode(Brake);

  m_LeftLeader.ConfigOpenloopRamp(0.2);
  m_RightLeader.ConfigOpenloopRamp(0.2);
  m_LeftFollower.ConfigOpenloopRamp(0.2);
  m_RightFollower.ConfigOpenloopRamp(0.2);

  m_RightLeader.SetInverted(true);
  m_RightFollower.SetInverted(true);

  m_differntialDrive.SetSafetyEnabled(false);
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
