// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommands/DriveStraight.h"
#include "RobotContainer.h"

//  Drive distance in inches at speed multiplier between 0 and 1;
DriveStraight::DriveStraight(WestCoastDrive* p_WestCoastDrive, double distance, double speed) : mp_WestCoastDrive{p_WestCoastDrive}, m_Distance{distance}, m_Speed{speed} {
    SetName("DriveStraight");
    AddRequirements(p_WestCoastDrive);
}

void DriveStraight::Initialize() {
        
    // Changes sign based on direction
    m_OutputSpeed = (m_Distance / std::abs(m_Distance)) * m_Speed;

    //Converts distance to encoder pulses
    // (Distance / Wheel Circ) * encoder pulses * 4
    m_OutputDistance = std::abs(((m_Distance / (WestCoastConstants::kWheelDiameter * WestCoastConstants::kPI)) * WestCoastConstants::kPulsesPerRev) * 4);
    mp_WestCoastDrive->zeroDrivetrain();
}

void DriveStraight::Execute() {
    mp_WestCoastDrive->arcadeDrive(m_OutputSpeed, 0);
    //std::cout << "Encoder Pos: " << mp_WestCoastDrive->getAvgEncoderPosition() << " Requested Pos: " << m_Distance << std::endl;
}

bool DriveStraight::IsFinished() {
    return (std::abs(mp_WestCoastDrive->getAvgEncoderPosition()) >= std::abs(m_OutputDistance));
}

void DriveStraight::End(bool interupted) {
    mp_WestCoastDrive->zeroDrivetrain();
}