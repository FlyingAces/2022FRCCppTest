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
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/AnalogGyro.h>
#include <units/length.h>

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
  const units::length::meter_t  kTrackWidth(0.5715);

}
class WestCoastDrive : public frc2::SubsystemBase {
 public:
  WestCoastDrive();

  void arcadeDrive(double speed, double rotation);
  void zeroDrivetrain();
  
  double getLeftCurrentPosition();
  double getRightCurrentPosition();

  void Periodic() override;

  void SimulationPeriodic() override;

  //Odometry Set Up
  void UpdateOdometry();
  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX m_LeftLeader{WestCoastConstants::kLeftLeader};
  WPI_TalonFX m_RightLeader{WestCoastConstants::kRightLeader};
  WPI_TalonFX m_LeftFollower{WestCoastConstants::kLeftFollower};
  WPI_TalonFX m_RightFollower{WestCoastConstants::kRightFollower};

  frc::MotorControllerGroup m_LeftGroup{m_LeftLeader, m_LeftFollower};
  frc::MotorControllerGroup m_RightGroup{m_RightLeader, m_RightFollower};

  frc::DifferentialDrive m_differentialDrive{m_LeftGroup, m_RightGroup};

  frc::AnalogGyro m_gyro{0};

  //Odometry Set up
  frc::DifferentialDriveKinematics m_Kinematics{WestCoastConstants::kTrackWidth};
  frc::DifferentialDriveOdometry m_Odometry{m_gyro.GetRotation2d()};

  frc::Field2d m_field;

};
