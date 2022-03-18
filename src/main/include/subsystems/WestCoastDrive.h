// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/DriverStation.h>
#include <frc/XboxController.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>

#include <cmath>
#include <iostream>

namespace WestCoastConstants {
  //PI
  const double kPI = 3.14159265358979;
  
  // Motor Ports
  const int kLeftLeader = 1;
  const int kRightLeader = 4;
  const int kLeftFollower = 2;
  const int kRightFollower = 3;
  
  // Calibration Values

  // Motor Max Speeds
  
  // Encoder Values
  const int kPulsesPerRev = 2048;

  // Sizes
  //In Inches
  const double kWheelDiameter = 6.0;
}
class WestCoastDrive : public frc2::SubsystemBase {
 public:
  WestCoastDrive() {
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

  void arcadeDrive(double speed, double rotation);
  void zeroDrivetrain();
  
  double getLeftCurrentPosition();
  double getRightCurrentPosition();

  void Periodic() override;

  void SimulationPeriodic() override;
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX m_LeftLeader{WestCoastConstants::kLeftLeader};
  WPI_TalonFX m_RightLeader{WestCoastConstants::kRightLeader};
  WPI_TalonFX m_LeftFollower{WestCoastConstants::kLeftFollower};
  WPI_TalonFX m_RightFollower{WestCoastConstants::kRightFollower};

  frc::MotorControllerGroup m_LeftGroup{m_LeftLeader, m_LeftFollower};
  frc::MotorControllerGroup m_RightGroup{m_RightLeader, m_RightFollower};

  frc::DifferentialDrive m_differntialDrive{m_LeftGroup, m_RightGroup};
};
