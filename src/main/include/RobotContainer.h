// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/Command.h>
#include <frc2/command/button/Button.h>
#include <frc2/command/PrintCommand.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <iostream>

#include "commands/AutoCommands/MainAuto.h"
#include "commands/DriveWithController.h"
#include "commands/DriveCommands/ToggleDriveMode.h"
#include "subsystems/WestCoastDrive.h"

class RobotContainer {
 public:
  static RobotContainer* mp_RobotContainer;
  static RobotContainer* GetInstance() {
    if(mp_RobotContainer == NULL) mp_RobotContainer = new RobotContainer();
    return mp_RobotContainer;
  }

  frc2::Command* GetAutonomousCommand();
  void RobotInit();

 private:
  RobotContainer();

  void ConfigureButtonBindings();

  //Choose Auto
  frc::SendableChooser<frc2::Command*> m_AutoMode;

  // Subsystems and Commands
  WestCoastDrive m_WestCoastDrive{&m_DriverController};
  DriveWithController m_RunDriveWithController{&m_WestCoastDrive};
  ToggleDriveMode m_ToggleDriveMode{&m_WestCoastDrive};

  // Controllers
  frc::XboxController m_DriverController{0};
  frc2::Button m_DriverButtonY { [&] { return m_DriverController.GetYButton(); }};
};
