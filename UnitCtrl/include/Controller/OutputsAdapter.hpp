#pragma once

#include "busBMS.hpp"
#include "busBMSStd.hpp"
#include "busGenOper.hpp"
#include "busGenOperStd.hpp"
#include "busMBMU.hpp"
#include "busMBMUStd.hpp"
#include "busPCS.hpp"
#include "busPCSStd.hpp"
#include "busPLimitManager.hpp"
#include "busUC.hpp"
#include "busUCStd.hpp"


namespace UnitCtrl {
class OutputsAdapter {
public:
  // busUCType UCAdapter(busUCCtrlStdType busUCCtrlStd, busUCInfoStdType
  // busUCInfoStd);
  static busUCType RunOutputsAdapter(busUCCtrlStdType busUCCtrlStd,
                                     busUCInfoStdType busUCInfoStd,
                                     busUCCoreStdType busUCCore,
                                     busPLimitManagerType busPLimitManager,
                                     busUCStdType busUCStd);

  static busStringCtrlType BMSCtrlAdapter(busBMSCtrlStdType busBMSCtrlStd);
  static busStringInfoType BMSInfoAdapter(busStringInfoStdType busBMSInfoStd);
  static busTMSInfoType TMSInfoAdapter(busTMSInfoStdType busTMSInfoStd);
  static busFSSInfoType FSSInfoAdapter(busFSSInfoStdType busFSSInfoStd);
  static busPCSCtrlType PCSCtrlAdapter(busPCSCtrlStdType busPCSCtrlStd);
  static busPCSInfoType PCSInfoAdapter(busPCSInfoStdType busPCSInfoStd);
  static busMBMUInfoType MBMUInfoAdapter(busMBMUInfoStdType busMBMUInfoStd);
  static busBCPInfoType BCPInfoAdapter(busBCPInfoStdType busBCPInfoStd);

  static busUCCoreType UCCoreAdapter(busUCCoreStdType busUCCore);
  static busCommLossInfoType
  CommLossAdapter(busCommLossInfoStdType busCommLoss);
};
} // namespace UnitCtrl
