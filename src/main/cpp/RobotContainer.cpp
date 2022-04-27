// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer* RobotContainer::mp_RobotContainer = NULL;

RobotContainer::RobotContainer() {
  std::cout << "Set Default Command" << std::endl;
  m_WestCoastDrive.SetDefaultCommand(std::move(m_RunDriveWithController));
  // Set Auto State False for testing
  std::cout << "Auto State False" << std::endl;
  m_WestCoastDrive.setAutoState(false);
  
  ConfigureButtonBindings();

  // Auto
  m_AutoMode.SetDefaultOption("Main Auto", new MainAuto(&m_WestCoastDrive));
  m_AutoMode.AddOption("None", new frc2::PrintCommand("No Auto"));

  frc::Shuffleboard::GetTab("Drive").Add("AutoMode", m_AutoMode).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_DriverButtonY.WhenPressed(m_ToggleDriveMode);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //std::cout << "Starting Auto";
  
  // Zero Gyro (For Auto Testing)
  m_WestCoastDrive.zeroGyro();

  return m_AutoMode.GetSelected();
}