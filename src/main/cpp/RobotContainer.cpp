// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer* RobotContainer::m_RobotContainer = NULL;

RobotContainer::RobotContainer() {
  
  // Configure the button bindings
  ConfigureButtonBindings();
  
}

RobotContainer* RobotContainer::GetInstance() {
  if (m_RobotContainer == NULL) {
    m_RobotContainer = new RobotContainer();
  }
  return (m_RobotContainer);
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  std::cout << "Starting Auto";
  return new MainAuto(&m_WestCoastDrive);
}
