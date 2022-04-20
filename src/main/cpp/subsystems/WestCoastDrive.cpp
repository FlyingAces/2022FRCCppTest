// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/WestCoastDrive.h"

WestCoastDrive::WestCoastDrive(frc::XboxController* p_Controller) : mp_Controller{p_Controller} {
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

  m_gyro.Reset();

  m_RightLeader.SetInverted(true);
  m_RightFollower.SetInverted(true);
 
  m_DifferntialDrive.SetSafetyEnabled(false);

  m_DriveMode = true;
  m_DriveSpeedMult = WestCoastConstants::kFullSpeedMult;
  m_RotationSpeedMult = WestCoastConstants::kFullRotationMult;
}

void WestCoastDrive::arcadeDrive(double speed, double rotation) {
  m_DifferntialDrive.ArcadeDrive(speed, rotation, false);
}

void WestCoastDrive::tankDrive(double left, double right) {
  m_DifferntialDrive.TankDrive(left, right);
}

void WestCoastDrive::controllerDrive() {
  m_ControllerDriveSpeed = (mp_Controller->GetLeftTriggerAxis() - mp_Controller->GetRightTriggerAxis()) * m_DriveSpeedMult;
  m_ControllerDriveRotation = mp_Controller->GetLeftX() * m_RotationSpeedMult;
  m_DifferntialDrive.ArcadeDrive(m_ControllerDriveSpeed, m_ControllerDriveRotation);
}

void WestCoastDrive::toggleDriveMode() {
  m_DriveMode = !m_DriveMode;
  if(m_DriveMode) {
    m_DriveSpeedMult = WestCoastConstants::kFullSpeedMult;
    m_RotationSpeedMult = WestCoastConstants::kFullRotationMult;
  } else {
    m_DriveSpeedMult = WestCoastConstants::kHalfSpeedMult;
    m_RotationSpeedMult = WestCoastConstants::kHalfRotationMult;
  }
}

void WestCoastDrive::zeroDrivetrain() {
  m_LeftLeader.SetSelectedSensorPosition(0.0);
  m_RightLeader.SetSelectedSensorPosition(0.0);
}

double WestCoastDrive::getAvgEncoderPosition() {
  return (m_LeftLeader.GetSelectedSensorPosition(0) + m_RightLeader.GetSelectedSensorPosition(0)) / 2;
}

void WestCoastDrive::zeroGyro() {
  m_gyro.Reset();
}

units::degree_t WestCoastDrive::getGyro() {
  return units::degree_t(std::remainder(m_gyro.GetAngle(), 360) *(WestCoastConstants::kGyroReversed ? -1.0 : 1.0));
}

void WestCoastDrive::Periodic() {
  // Implementation of subsystem periodic method goes here.
}