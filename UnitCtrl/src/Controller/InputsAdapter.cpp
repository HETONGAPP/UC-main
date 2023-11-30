
#include "InputsAdapter.hpp"
#include <algorithm>
#include <vector>
//#include "../Util/CAlarms.h"
//#include "../Objects/StructAlarm.hpp"

using namespace std;

namespace UnitCtrl {

busUCStdType InputsAdapter::RunInputsAdapter(busUCType busUC) {
  busUCStdType busUCStd;

  for (int nContNum = 0; nContNum < nContainerNum; nContNum++) {
    for (int i = 0; i < nStringNum; i++) {
      int nIndex = nContNum * nStringNum + i;
      busUCStd.busUCMeasStd.busContainer[nContNum].busStringMeas[i] =
          BMSAdapter(busUC.busUCMeas.busContainer[nContNum].busStringMeas[i]);
      // bmsCore_[nIndex].GetAlarmPtr()->ConvertBitsToMap(busUC.busUCMeas.busContainer[nContNum].busStringMeas[i].u32StrAlarms,true);
      // // to input alarms
    }
    for (int k = 0; k < nTMSNum; k++) {
      busUCStd.busUCMeasStd.busContainer[nContNum].busTMSMeas[k] =
          TMSAdapter(busUC.busUCMeas.busContainer[nContNum].busTMSMeas[k]);
    }
    for (int j = 0; j < nFSSNum; j++) {
      busUCStd.busUCMeasStd.busContainer[nContNum].busFSSMeas[j] =
          FSSAdapter(busUC.busUCMeas.busContainer[nContNum].busFSSMeas[j]);
    }
  }

  for (int k = 0; k < nBCPNum; k++) {
    busUCStd.busUCMeasStd.busBCPMeas[k] =
        BCPAdapter(busUC.busUCMeas.busBCPMeas[k]);
  }

  for (int i = 0; i < nMBMUNum; i++) {
    busUCStd.busUCMeasStd.busMBMUMeas[i] =
        MBMUAdapter(busUC.busUCMeas.busMBMUMeas[i]);
  }

  for (int j = 0; j < nPCSNum; j++) {
    busUCStd.busUCMeasStd.busPCSMeas[j] =
        PCSAdapter(busUC.busUCMeas.busPCSMeas[j], busUC.busUCMeas);
  }
  busUCStd.busUCMeasStd.u16InterSwitchPos = busUC.busUCMeas.u16InterSwitchPos;
  busUCStd.busUCMeasStd.busCommLoss =
      CommLossAdapter(busUC.busUCMeas.busCommLoss);

  busUCStd.busGenOperStd = GenOperAdapter(busUC.busGenOper);
  busUCStd.busConfigStd = ConfigAdapter(busUC.busConfig);

  return busUCStd;
}

busCommLossMeasStdType
InputsAdapter::CommLossAdapter(busCommLossMeasType busCommLoss) {
  busCommLossMeasStdType busCommLossMeasStd;

  for (int i = 0; i < nCommLossBMSNum; i++) {
    busCommLossMeasStd.u16BMS[i] = busCommLoss.u16BMS[i];
  }
  for (int j = 0; j < nCommLossPCSNum; j++) {
    busCommLossMeasStd.u16PCS[j] = busCommLoss.u16PCS[j];
  }
  busCommLossMeasStd.u16EtherSwitch = busCommLoss.u16EtherSwitch;
  busCommLossMeasStd.u16HMI = busCommLoss.u16HMI;
  busCommLossMeasStd.u16Meter = busCommLoss.u16Meter;
  busCommLossMeasStd.u16MGuard = busCommLoss.u16MGuard;
  busCommLossMeasStd.u16PLC = busCommLoss.u16PLC;
  busCommLossMeasStd.u16TimeServer = busCommLoss.u16TimeServer;

  return busCommLossMeasStd;
}

busBMSMeasStdType InputsAdapter::BMSAdapter(busStringMeasType busStringMeas) {
  busBMSMeasStdType busBMSMeasStd;

#ifdef BMS_CATL
  busBMSMeasStd.bStrSwitchPos = static_cast<bool>(busStringMeas.bStrSwitchPos);
  busBMSMeasStd.u16StrVoltage = static_cast<int>(busStringMeas.u16StrVoltage);
  busBMSMeasStd.i16StrCurrent = static_cast<int>(busStringMeas.i16StrCurrent);
  busBMSMeasStd.bStrCommLoss = static_cast<bool>(busStringMeas.bStrCommLoss);
  busBMSMeasStd.u16StrChgCurrLim =
      static_cast<int>(busStringMeas.u16StrChgCurrLim);
  busBMSMeasStd.u16StrDcgCurrLim =
      static_cast<int>(busStringMeas.u16StrDcgCurrLim);
  busBMSMeasStd.u32StrAlarms = static_cast<int>(busStringMeas.u32StrAlarms);
  busBMSMeasStd.u32StrWarnings = static_cast<int>(busStringMeas.u32StrWarnings);

  // busBMSMeasStd.alarms.SetAlarms(busBMSMeasStd.alarms.convertBitsToMap(static_cast<int>(busStringMeas.u32StrWarnings)));
#elif BMS_Ampace
  // busBMSMeasStd.bStartupOK =
  // static_cast<bool>(busStringMeas.bPrechargeRelay);
  busBMSMeasStd.bStrSwitchPos = static_cast<bool>(busStringMeas.bStrSwitchPos);
  busBMSMeasStd.u16StrVoltage = static_cast<int>(busStringMeas.u16StrVoltage);
  busBMSMeasStd.i16StrCurrent = static_cast<int>(busStringMeas.i16StrCurrent);
  busBMSMeasStd.bStrCommLoss = static_cast<bool>(busStringMeas.bStrCommLoss);
  busBMSMeasStd.u16StrChgCurrLim =
      static_cast<int>(busStringMeas.u16StrChgCurrLim);
  busBMSMeasStd.u16StrDcgCurrLim =
      static_cast<int>(busStringMeas.u16StrDcgCurrLim);
  busBMSMeasStd.u32StrAlarms = static_cast<int>(busStringMeas.u32StrAlarms);
  busBMSMeasStd.u32StrWarnings = static_cast<int>(busStringMeas.u32StrWarnings);
#else
  busBMSMeasStd.bStrSwitchPos = static_cast<bool>(busStringMeas.bStrSwitchPos);
  busBMSMeasStd.u16StrVoltage = static_cast<int>(busStringMeas.u16StrVoltage);
  busBMSMeasStd.i16StrCurrent = static_cast<int>(busStringMeas.i16StrCurrent);
  busBMSMeasStd.bStrCommLoss = static_cast<bool>(busStringMeas.bStrCommLoss);
  busBMSMeasStd.u16StrChgCurrLim =
      static_cast<int>(busStringMeas.u16StrChgCurrLim);
  busBMSMeasStd.u16StrDcgCurrLim =
      static_cast<int>(busStringMeas.u16StrDcgCurrLim);
  busBMSMeasStd.u32StrAlarms = static_cast<int>(busStringMeas.u32StrAlarms);
  busBMSMeasStd.u32StrWarnings = static_cast<int>(busStringMeas.u32StrWarnings);
#endif
  // int nSize = sizeof(busStringMeas.vi16StrCurrent) /
  // sizeof(busStringMeas.vi16StrCurrent[0]); copy(busStringMeas.vi16StrCurrent,
  // busStringMeas.vi16StrCurrent + nSize, busBMSMeasStd.vi16StrCurrent);
  // copy(busStringMeas.vi16StrVoltage, busStringMeas.vi16StrVoltage + nSize,
  // busBMSMeasStd.vi16StrVoltage); copy(busStringMeas.vu16StrSOC,
  // busStringMeas.vu16StrSOC + nSize, busBMSMeasStd.vu16StrSOC);
  // copy(busStringMeas.vu16StrSOH, busStringMeas.vu16StrSOH + nSize,
  // busBMSMeasStd.vu16StrSOH); copy(busStringMeas.vu16StrChgCurrLim,
  // busStringMeas.vu16StrChgCurrLim + nSize, busBMSMeasStd.vu16StrChgCurrLim);
  // copy(busStringMeas.vu16StrDcgCurrLim, busStringMeas.vu16StrDcgCurrLim +
  // nSize, busBMSMeasStd.vu16StrDcgCurrLim);
  // copy(busStringMeas.vu16MaxCellVoltage, busStringMeas.vu16MaxCellVoltage +
  // nSize, busBMSMeasStd.vu16MaxCellVoltage);
  // copy(busStringMeas.vu16MinCellVoltage, busStringMeas.vu16MinCellVoltage +
  // nSize, busBMSMeasStd.vu16MinCellVoltage);
  // copy(busStringMeas.vi16MaxCellTemp, busStringMeas.vi16MaxCellTemp + nSize,
  // busBMSMeasStd.vi16MaxCellTemp); copy(busStringMeas.vi16MinCellTemp,
  // busStringMeas.vi16MinCellTemp + nSize, busBMSMeasStd.vi16MinCellTemp);
  // copy(busStringMeas.vbStrSwitchPos, busStringMeas.vbStrSwitchPos + nSize,
  // busBMSMeasStd.vbStrSwitchPos); copy(busStringMeas.vu16CellBalance,
  // busStringMeas.vu16CellBalance + nSize, busBMSMeasStd.vu16CellBalance);
  // nSize = sizeof(busStringMeas.vbStrAlarms) /
  // sizeof(busStringMeas.vbStrAlarms[0]); copy(busStringMeas.vbStrAlarms,
  // busStringMeas.vbStrAlarms + nSize, busBMSMeasStd.vbStrAlarms); nSize =
  // sizeof(busStringMeas.vbStrWarnings) /
  // sizeof(busStringMeas.vbStrWarnings[0]); copy(busStringMeas.vbStrWarnings,
  // busStringMeas.vbStrWarnings + nSize, busBMSMeasStd.vbStrWarnings); nSize =
  // sizeof(busStringMeas.vbStrCommLoss) /
  // sizeof(busStringMeas.vbStrCommLoss[0]); copy(busStringMeas.vbStrCommLoss,
  // busStringMeas.vbStrCommLoss + nSize, busBMSMeasStd.vbStrCommLoss); Trigger
  // alarms/warnings: from busStringMeas.vi32StrAlarms and
  // busStringMeas.vi32StrWarnings to busBMSMeasStd.vbStrAlarms and
  // busBMSMeasStd.vbStrWarnings

  // if (busBMSMeasStd.bStrSwitchPos)
  //{
  //	//busBMSMeasStd.alarms.ResetAlarms();
  //	busBMSMeasStd.u32StrAlarms = 666;
  //}
  // else
  //{
  //	busBMSMeasStd.u32StrAlarms = 111;
  //}

  return busBMSMeasStd;
}

busPCSMeasStdType InputsAdapter::PCSAdapter(busPCSMeasType busPCSMeas,
                                            busUCMeasType busUCMeas) {
  busPCSMeasStdType busPCSMeasStd;

#ifdef PCS_EPC
  busPCSMeasStd.u32Alarms = static_cast<int>(busPCSMeas.u32Alarms);
  busPCSMeasStd.u32Warnings = static_cast<int>(busPCSMeas.u32Warnings);
  busPCSMeasStd.bStartupTimeout =
      false; // static_cast<bool>(busPCSMeas.bStartupTimeout);
  busPCSMeasStd.u16OperMode = static_cast<PMState>(busPCSMeas.u16OperMode);
  busPCSMeasStd.bCommLoss = static_cast<bool>(busPCSMeas.bCommLoss);
  busPCSMeasStd.u16VDC = static_cast<int>(busPCSMeas.u16VDC);
  busPCSMeasStd.f32PACFreq = static_cast<float>(busPCSMeas.f32PACFreq);
  busPCSMeasStd.f32Q = static_cast<float>(busPCSMeas.f32Q) * 1000;
  busPCSMeasStd.i16PAC = static_cast<int>(busPCSMeas.i16PAC) * 1000;
  busPCSMeasStd.bPCCPos = static_cast<bool>(busUCMeas.u16InterSwitchPos != 0);
  // busPCSMeasStd.f32PCSChgLimitP =
  // static_cast<float>(busPCSMeas.f32PCSChgLimitP) * 1000;
  // busPCSMeasStd.f32PCSDcgLimitP =
  // static_cast<float>(busPCSMeas.f32PCSDcgLimitP) * 1000;
  // busPCSMeasStd.f32PCSGenerateLimitQ =
  // static_cast<float>(busPCSMeas.f32PCSGenerateLimitQ) * 1000;
  // busPCSMeasStd.f32PCSAbsorbLimitQ =
  // static_cast<float>(busPCSMeas.f32PCSAbsorbLimitQ) * 1000;
#else
  busPCSMeasStd.u32Alarms = static_cast<int>(busPCSMeas.u32Alarms);
  busPCSMeasStd.u32Warnings = static_cast<int>(busPCSMeas.u32Warnings);
  busPCSMeasStd.bStartupTimeout =
      false; // static_cast<bool>(busPCSMeas.bStartupTimeout);
  busPCSMeasStd.u16OperMode = static_cast<PMState>(busPCSMeas.u16OperMode);
  busPCSMeasStd.bCommLoss = static_cast<bool>(busPCSMeas.bCommLoss);
  busPCSMeasStd.u16VDC = static_cast<int>(busPCSMeas.u16VDC);
  busPCSMeasStd.f32PACFreq = static_cast<float>(busPCSMeas.f32PACFreq);
  busPCSMeasStd.f32Q = static_cast<float>(busPCSMeas.f32Q) * 1000;
  busPCSMeasStd.i16PAC = static_cast<int>(busPCSMeas.i16PAC) * 1000;
  busPCSMeasStd.bPCCPos = static_cast<bool>(busUCMeas.u16InterSwitchPos != 0);
  // busPCSMeasStd.f32PCSChgLimitP =
  // static_cast<float>(busPCSMeas.f32PCSChgLimitP) * 1000;
  // busPCSMeasStd.f32PCSDcgLimitP =
  // static_cast<float>(busPCSMeas.f32PCSDcgLimitP) * 1000;
  // busPCSMeasStd.f32PCSGenerateLimitQ =
  // static_cast<float>(busPCSMeas.f32PCSGenerateLimitQ) * 1000;
  // busPCSMeasStd.f32PCSAbsorbLimitQ =
  // static_cast<float>(busPCSMeas.f32PCSAbsorbLimitQ) * 1000;
#endif

  // busPCSMeasStd.u32Alarms = static_cast<bool>(busPCSMeas.u32Alarms>0);
  // busPCSMeasStd.u32Warnings = static_cast<bool>(busPCSMeas.u32Warnings > 0);
  // int nSize = sizeof(busPCSMeas.vbPCSOn) / sizeof(busPCSMeas.vbPCSOn[0]);
  // copy(busPCSMeas.vbPCSOn, busPCSMeas.vbPCSOn + nSize,
  // busPCSMeasStd.vbPCSOn); nSize = sizeof(busPCSMeasStd.u32Alarms) /
  // sizeof(busPCSMeasStd.u32Alarms[0]); fill(busPCSMeasStd.u32Alarms,
  // busPCSMeasStd.u32Alarms + nSize, busPCSMeas.u32Alarms > 0); nSize =
  // sizeof(busPCSMeasStd.u32Alarms) / sizeof(busPCSMeasStd.u32Alarms[0]);
  // fill(busPCSMeasStd.u32Warnings, busPCSMeasStd.u32Warnings + nSize,
  // busPCSMeas.u32Warnings > 0); nSize = sizeof(busPCSMeas.u32Warnings) /
  // sizeof(busPCSMeas.u32Warnings[0]); copy(busPCSMeas.u32Warnings,
  // busPCSMeas.u32Warnings + nSize, busPCSMeasStd.u32Warnings); nSize =
  // sizeof(busPCSMeas.bCommLoss) / sizeof(busPCSMeas.bCommLoss[0]);
  // copy(busPCSMeas.bCommLoss, busPCSMeas.bCommLoss + nSize,
  // busPCSMeasStd.bCommLoss);

  return busPCSMeasStd;
}

busMBMUMeasStdType InputsAdapter::MBMUAdapter(busMBMUMeasType busMBMUMeas) {
  busMBMUMeasStdType busMBMUMeasStd;
  busMBMUMeasStd.u32MBMUWarnings =
      static_cast<int>(busMBMUMeas.u32MBMUWarnings);
  busMBMUMeasStd.u32MBMUAlarms = static_cast<int>(busMBMUMeas.u32MBMUAlarms);
  busMBMUMeasStd.f32SysSOC =
      static_cast<float>(busMBMUMeas.u16SysSOC) / 10.0; // covert unit to 1%
  busMBMUMeasStd.u16SysSOH = static_cast<short>(busMBMUMeas.u16SysSOH) / 10;
#ifdef BMS_CATL
  busMBMUMeasStd.u16SysStatus = static_cast<short>(busMBMUMeas.u16SysStatus);
  busMBMUMeasStd.u16SysVol =
      static_cast<unsigned short>(busMBMUMeas.u16SysVol) / 10;
  busMBMUMeasStd.i16SysCurrent = static_cast<short>(busMBMUMeas.i16SysCurrent);
  busMBMUMeasStd.u16SysChgCurrLim =
      static_cast<unsigned short>(busMBMUMeas.u16SysChgCurrLim);
  busMBMUMeasStd.u16SysDischgCurrLim =
      static_cast<unsigned short>(busMBMUMeas.u16SysDischgCurrLim);

#elif BMS_Ampace
  busMBMUMeasStd.u32SysVol =
      static_cast<unsigned int>(busMBMUMeas.u32SysVol) / 10; // covert unit to V
  busMBMUMeasStd.i32SysCurrent =
      static_cast<int>(busMBMUMeas.i32SysCurrent) / 10; // covert unit to A
  busMBMUMeasStd.i32SysPower =
      static_cast<int>(busMBMUMeas.i32SysPower) / 10; // covert unit to kw
  busMBMUMeasStd.u32SysChgPwLim =
      static_cast<unsigned int>(busMBMUMeas.u32SysChgPwLim) /
      10; // covert unit to kw
  busMBMUMeasStd.u32SysDischgPwLim =
      static_cast<unsigned int>(busMBMUMeas.u32SysDischgPwLim) /
      10; // covert unit to kw
  busMBMUMeasStd.i32SysChgCurrLim =
      static_cast<int>(busMBMUMeas.i32SysChgCurrLim) / 10; // covert unit to A
  busMBMUMeasStd.i32SysDischgCurrLim =
      static_cast<int>(busMBMUMeas.i32SysDischgCurrLim) /
      10; // covert unit to A
#else

#endif
  return busMBMUMeasStd;
}

busTMSMeasStdType InputsAdapter::TMSAdapter(busTMSMeasType busTMSMeas) {
  busTMSMeasStdType busTMSMeasStd;

#ifdef TMS_CATL

  busTMSMeasStd.u32Alarms = static_cast<int>(busTMSMeas.u32Alarms);
  busTMSMeasStd.u32Warnings = static_cast<int>(busTMSMeas.u32Warnings);
  busTMSMeasStd.u32TMSMode = static_cast<int>(busTMSMeas.u32TMSMode);
  busTMSMeasStd.f32TMSEnvTemp = static_cast<float>(busTMSMeas.f32TMSEnvTemp);
  busTMSMeasStd.u32TMSFaultCode = static_cast<int>(busTMSMeas.u32TMSFaultCode);

#elif TMS_Ampace_Envicool
  busTMSMeasStd.u32Alarms = static_cast<int>(busTMSMeas.u32Alarms);
  busTMSMeasStd.u32Warnings = static_cast<int>(busTMSMeas.u32Warnings);
  busTMSMeasStd.u16DeviceStatus =
      static_cast<unsigned short int>(busTMSMeas.u16DeviceStatus);
  busTMSMeasStd.i16AirTemp =
      static_cast<signed short int>(busTMSMeas.i16AirTemp);
  busTMSMeasStd.u16AirHUmidity =
      static_cast<unsigned short int>(busTMSMeas.u16AirHUmidity);
  /*busTMSMeasStd.u16HighTempWarning = static_cast<unsigned short
  int>(busTMSMeas.u16HighTempWarning); busTMSMeasStd.u16InFansFaultWarning =
  static_cast<unsigned short int>(busTMSMeas.u16InFansFaultWarning);
  busTMSMeasStd.u16OutFansFaultWarning = static_cast<unsigned short
  int>(busTMSMeas.u16OutFansFaultWarning); busTMSMeasStd.u16CompFaultWarning =
  static_cast<unsigned short int>(busTMSMeas.u16CompFaultWarning);
  busTMSMeasStd.u16AirTempSenAlarm = static_cast<unsigned short
  int>(busTMSMeas.u16AirTempSenAlarm); busTMSMeasStd.u16HighSysPresWarning =
  static_cast<unsigned short int>(busTMSMeas.u16HighSysPresWarning);
  busTMSMeasStd.u16LowTempWarning = static_cast<unsigned short
  int>(busTMSMeas.u16LowTempWarning); busTMSMeasStd.u16HighDCVWarning =
  static_cast<unsigned short int>(busTMSMeas.u16HighDCVWarning);
  busTMSMeasStd.u16LowDCVWarning = static_cast<unsigned short
  int>(busTMSMeas.u16LowDCVWarning); busTMSMeasStd.u16HighACVWarning =
  static_cast<unsigned short int>(busTMSMeas.u16HighACVWarning);
  busTMSMeasStd.u16LowACVWarning = static_cast<unsigned short
  int>(busTMSMeas.u16LowACVWarning); busTMSMeasStd.u16ACPowerFailWarning =
  static_cast<unsigned short int>(busTMSMeas.u16ACPowerFailWarning);
  busTMSMeasStd.u16EvaTempSenAlarm = static_cast<unsigned short
  int>(busTMSMeas.u16EvaTempSenAlarm); busTMSMeasStd.u16CondTempSenAlarm =
  static_cast<unsigned short int>(busTMSMeas.u16CondTempSenAlarm);
  busTMSMeasStd.u16EnvTempSenAlarm = static_cast<unsigned short
  int>(busTMSMeas.u16EnvTempSenAlarm); busTMSMeasStd.u16EvaFreezeWarning =
  static_cast<unsigned short int>(busTMSMeas.u16EvaFreezeWarning);
  busTMSMeasStd.u16FreqHighPreWarning = static_cast<unsigned short
  int>(busTMSMeas.u16FreqHighPreWarning); busTMSMeasStd.u161TemporHumAlarm =
  static_cast<unsigned short int>(busTMSMeas.u161TemporHumAlarm);
  busTMSMeasStd.u162TemporHumAlarm = static_cast<unsigned short
  int>(busTMSMeas.u162TemporHumAlarm);*/

#elif TMS_Ampace_BlackShields
  busTMSMeasStd.u32Alarms = static_cast<int>(busTMSMeas.u32Alarms);
  busTMSMeasStd.u32Warnings = static_cast<int>(busTMSMeas.u32Warnings);
  busTMSMeasStd.u16DeviceStatus =
      static_cast<unsigned short int>(busTMSMeas.u16DeviceStatus);
  busTMSMeasStd.i16InnerTemp =
      static_cast<signed short int>(busTMSMeas.i16InnerTemp);
  busTMSMeasStd.u16Humidity =
      static_cast<unsigned short int>(busTMSMeas.i16Humidity);
  // busTMSMeasStd.u16HighTempWarning = static_cast<unsigned short
  // int>(busTMSMeas.u16HighTempWarning); busTMSMeasStd.u16LowTempWarning =
  // static_cast<unsigned short int>(busTMSMeas.u16LowTempWarning);
  // busTMSMeasStd.u16HighHmdWarning = static_cast<unsigned short
  // int>(busTMSMeas.u16HighHmdWarning); busTMSMeasStd.u16CoilAntiFZWarning =
  // static_cast<unsigned short int>(busTMSMeas.u16CoilAntiFZWarning);
  // busTMSMeasStd.u16HighACVWarning = static_cast<unsigned short
  // int>(busTMSMeas.u16HighACVWarning); busTMSMeasStd.u16LowACVWarning =
  // static_cast<unsigned short int>(busTMSMeas.u16LowACVWarning);

#else
  busTMSMeasStd.u32Alarms = static_cast<int>(busTMSMeas.u32Alarms);
  busTMSMeasStd.u32Warnings = static_cast<int>(busTMSMeas.u32Warnings);
  busTMSMeasStd.u16DeviceStatus =
      static_cast<unsigned short int>(busTMSMeas.u16DeviceStatus);
  busTMSMeasStd.i16AirTemp =
      static_cast<signed short int>(busTMSMeas.i16AirTemp);
  busTMSMeasStd.u16AirHUmidity =
      static_cast<unsigned short int>(busTMSMeas.u16AirHUmidity);
#endif

  return busTMSMeasStd;
}

busBCPMeasStdType InputsAdapter::BCPAdapter(busBCPMeasType busBCPMeas) {
  busBCPMeasStdType busBCPMeasStd;

  busBCPMeasStd.u32BCPAlarms = static_cast<int>(busBCPMeas.u32BCPAlarms);
  busBCPMeasStd.u32BCPWarnings = static_cast<int>(busBCPMeas.u32BCPWarnings);

  return busBCPMeasStd;
}

busFSSMeasStdType InputsAdapter::FSSAdapter(busFSSMeasType busFSSMeas) {
  busFSSMeasStdType busFSSMeasStd;

  busFSSMeasStd.u32FSSAlarms = static_cast<int>(busFSSMeas.u32FSSAlarms);
  busFSSMeasStd.u32FSSWarnings = static_cast<int>(busFSSMeas.u32FSSWarnings);

  return busFSSMeasStd;
}

busGenOperStdType InputsAdapter::GenOperAdapter(busGenOperType busGenOper) {
  busGenOperStdType busGenOperStd;

  busGenOperStd.bTurnOn = static_cast<bool>(busGenOper.bTurnOn);
  busGenOperStd.bAlarmReset = static_cast<bool>(busGenOper.bAlarmReset);
  busGenOperStd.u16SetOperation = static_cast<int>(busGenOper.u16SetOperation);
  busGenOperStd.u16StartupMode =
      static_cast<PCSState>(busGenOper.u16StartupMode);
  busGenOperStd.u16Transition = static_cast<bool>(busGenOper.u16Transition);
  busGenOperStd.bAllowFollowing = static_cast<bool>(busGenOper.bAllowFollowing);
  busGenOperStd.bAllowForming = static_cast<bool>(busGenOper.bAllowForming);
  // busGenOperStd.bAllowAutoForming =
  // static_cast<bool>(busGenOper.bAllowAutoForming);
  busGenOperStd.bAllowG2I = static_cast<bool>(busGenOper.bAllowG2I);
  busGenOperStd.bAllowI2G = static_cast<bool>(busGenOper.bAllowI2G);

  busGenOperStd.busGenOperManStd.u16PFlowDir =
      static_cast<PFDir>(busGenOper.busGenOperMan.u16PFlowDir);
  // busGenOperStd.busGenOperManStd.u16QFlowDir =
  // static_cast<PFDir>(busGenOper.busGenOperMan.u16QFlowDir);
  busGenOperStd.busGenOperManStd.u16SetpointType =
      static_cast<SetPT>(busGenOper.busGenOperMan.u16SetpointType);
  busGenOperStd.busGenOperManStd.f32FreqSetpoint =
      static_cast<float>(busGenOper.busGenOperMan.f32FreqSetpoint);
  busGenOperStd.busGenOperManStd.f32PSetpoint =
      static_cast<float>(busGenOper.busGenOperMan.f32PSetpoint) * 1000;
  busGenOperStd.busGenOperManStd.f32QSetpoint =
      static_cast<float>(busGenOper.busGenOperMan.f32QSetpoint) * 1000;
  busGenOperStd.busGenOperManStd.f32VACSetpoint =
      static_cast<float>(busGenOper.busGenOperMan.f32VACSetpoint);
  busGenOperStd.busGenOperManStd.f32UFSetpoint =
      static_cast<float>(busGenOper.busGenOperMan.f32UFSetpoint);
  busGenOperStd.busGenOperManStd.f32ISetpoint =
      static_cast<float>(busGenOper.busGenOperMan.f32ISetpoint);

  for (int nContNum = 0; nContNum < nContainerNum; nContNum++) {
    for (int i = 0; i < nStringNum; i++) {
      busGenOperStd.busContainerGenOper[nContNum].busStringGenOper[i].vbStrSel =
          static_cast<bool>(busGenOper.busContainerGenOper[nContNum]
                                .busStringGenOper[i]
                                .vbStrSel);
      busGenOperStd.busContainerGenOper[nContNum]
          .busStringGenOper[i]
          .bTurnOn = static_cast<bool>(
          busGenOper.busContainerGenOper[nContNum].busStringGenOper[i].bTurnOn);
      busGenOperStd.busContainerGenOper[nContNum]
          .busStringGenOper[i]
          .bAlarmReset =
          static_cast<bool>(busGenOper.busContainerGenOper[nContNum]
                                .busStringGenOper[i]
                                .bAlarmReset);
    }
  }
  for (int j = 0; j < nPCSNum; j++) {
    busGenOperStd.busPCSGenOperStd[j].bTurnOn =
        static_cast<bool>(busGenOper.busPCSGenOper[j].bTurnOn);
    busGenOperStd.busPCSGenOperStd[j].bAlarmReset =
        static_cast<bool>(busGenOper.busPCSGenOper[j].bAlarmReset);
  }

  return busGenOperStd;
}

busConfigStdType InputsAdapter::ConfigAdapter(busConfigType busConfig) {
  busConfigStdType busConfigStd;

  busConfigStd.busStringConfig.f32SmallCurr =
      static_cast<float>(busConfig.busStringConfig.f32SmallCurr);
  busConfigStd.busStringConfig.nStartupTimeout =
      static_cast<int>(busConfig.busStringConfig.nStartupTimeout);
  busConfigStd.busStringConfig.nShutDownTimeout =
      static_cast<int>(busConfig.busStringConfig.nShutDownTimeout);
  busConfigStd.busStringConfig.nSwitchTimeout =
      static_cast<int>(busConfig.busStringConfig.nSwitchTimeout);

  busConfigStd.busPCSConfig.nStartupTimeout =
      static_cast<int>(busConfig.busPCSConfig.nStartupTimeout);
  busConfigStd.busPCSConfig.nShutDownTimeout =
      static_cast<int>(busConfig.busPCSConfig.nShutDownTimeout);

  busConfigStd.busSysConfig.bEnableUser =
      static_cast<bool>(busConfig.busSysConfig.bEnableUser);
  busConfigStd.busSysConfig.f32UserLimKWIn =
      static_cast<float>(busConfig.busSysConfig.f32UserLimKWIn) * 1000;
  busConfigStd.busSysConfig.f32UserLimKWOut =
      static_cast<float>(busConfig.busSysConfig.f32UserLimKWOut) * 1000;
  busConfigStd.busSysConfig.f32UserLimKVarIn =
      static_cast<float>(busConfig.busSysConfig.f32UserLimKVarIn) * 1000;
  busConfigStd.busSysConfig.f32UserLimKVarOut =
      static_cast<float>(busConfig.busSysConfig.f32UserLimKVarOut) * 1000;

  busConfigStd.busSysConfig.nG2ITimeout =
      static_cast<int>(busConfig.busSysConfig.nG2ITimeout);
  busConfigStd.busSysConfig.nI2GTimeout =
      static_cast<int>(busConfig.busSysConfig.nI2GTimeout);
  // busConfigStd.busSysConfig.nStartupTimeout =
  // static_cast<int>(busConfig.busSysConfig.nStartupTimeout);
  // busConfigStd.busSysConfig.nShutDownTimeout =
  // static_cast<int>(busConfig.busSysConfig.nShutDownTimeout);

  busConfigStd.busSOCConfig.f32HighLimit =
      static_cast<float>(busConfig.busSOCConfig.f32HighLimit);
  busConfigStd.busSOCConfig.f32LowLimit =
      static_cast<float>(busConfig.busSOCConfig.f32LowLimit);

  return busConfigStd;
}

} // namespace UnitCtrl
