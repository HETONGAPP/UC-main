
#pragma once

#include "Arp/System/Core/Arp.h"
#include "EnumUC.hpp"

namespace UnitCtrl {
struct busStringGenOperType {
  boolean vbStrSel = false;
  boolean bTurnOn = false;
  boolean bAlarmReset = false;
};

struct busPCSGenOperType {
  boolean bTurnOn = false;
  boolean bAlarmReset = false;
};

struct busGenOperManType {
  uint16 u16PFlowDir = {0};
  // uint16 u16QFlowDir;
  uint16 u16SetpointType = {0};

  float32 f32PSetpoint = 0.0;
  float32 f32QSetpoint = 0.0;
  float32 f32VACSetpoint = 0.0;
  float32 f32FreqSetpoint = 0.0;
  float32 f32UFSetpoint = 0.0; // Unbalance factor
  float32 f32ISetpoint = 0.0;
};

struct busContainerGenOperType {
  busStringGenOperType busStringGenOper[nStringNum];
};

struct busGenOperType {
  boolean bTurnOn = false;
  boolean bAlarmReset = false;
  uint16 u16SetOperation = 0; // Run, Standby
  uint16 u16StartupMode = 0;  // Start up in Grid, Island, Auto Start
  uint16 u16Transition = 0;   // No transition, Grid to Island, Island to Grid
  boolean bAllowFollowing = false;
  boolean bAllowForming = false;
  // boolean bAllowAutoForming = false;
  boolean bAllowG2I = false; // Pulse rising trigger signal
  boolean bAllowI2G = false; // Pulse rising trigger signal
  busGenOperManType busGenOperMan;
  busContainerGenOperType busContainerGenOper[nContainerNum];
  busPCSGenOperType busPCSGenOper[nPCSNum];
};

} // namespace UnitCtrl