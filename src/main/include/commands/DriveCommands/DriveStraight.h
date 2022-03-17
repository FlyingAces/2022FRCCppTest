// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/WestCoastDrive.h"

#include <cmath>

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveStraight
    : public frc2::CommandHelper<frc2::CommandBase, DriveStraight> {
 public:
    explicit DriveStraight(WestCoastDrive* p_WestCoastDrive, double distance, double speed);

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;


 private:
  WestCoastDrive* mp_WestCoastDrive;
  double m_Distance;
  double m_Speed;
  double m_OutputSpeed;
  double m_OutputDistance;

};
