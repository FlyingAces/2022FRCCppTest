// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <iostream>

#include "commands/AutoCommands/MainAuto.h"
#include "subsystems/WestCoastDrive.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  static RobotContainer* GetInstance();
  void RobotInit();

 private:
  // The robot's subsystems and commands are defined here...

  static RobotContainer* m_RobotContainer;

  WestCoastDrive m_WestCoastDrive;

  void ConfigureButtonBindings();
};
