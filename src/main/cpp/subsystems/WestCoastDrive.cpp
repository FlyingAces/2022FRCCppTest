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

  m_differentialDrive.SetSafetyEnabled(false);

  //Odemetry Setup
  frc::SmartDashboard::PutData("Field", &m_field);
}

void WestCoastDrive::arcadeDrive(double speed, double rotation) {
  m_differentialDrive.ArcadeDrive(speed, rotation, false);
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

//Odometry Set up
void WestCoastDrive::UpdateOdometry() {
  m_Odometry.Update(m_gyro.GetRotation2d(), units::meter_t(m_LeftLeader.GetSelectedSensorPosition(0)), units::meter_t(m_RightLeader.GetSelectedSensorPosition(0)));
}

void WestCoastDrive::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void WestCoastDrive::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
  WestCoastDrive::UpdateOdometry();
  m_field.SetRobotPose(m_Odometry.GetPose());
}
