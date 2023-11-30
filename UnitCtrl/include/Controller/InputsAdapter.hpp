#pragma once

#include "busBMS.hpp"
#include "busBMSStd.hpp"
#include "busConfig.hpp"
#include "busConfigStd.hpp"
#include "busGenOper.hpp"
#include "busGenOperStd.hpp"
#include "busMBMU.hpp"
#include "busMBMUStd.hpp"
#include "busPCS.hpp"
#include "busPCSStd.hpp"
#include "busUC.hpp"
#include "busUCStd.hpp"

namespace UnitCtrl {
class InputsAdapter {
public:
  static busUCStdType RunInputsAdapter(busUCType busUC);

  // void MapGenOper(busGenOperType busGenOper, busGenOperStdType busGenOperStd)
  // { busGenOperStd = dynamic_cast<busGenOperStdType>(busGenOper); }
  static busBMSMeasStdType BMSAdapter(busStringMeasType busStringMeas);

  static busPCSMeasStdType PCSAdapter(busPCSMeasType busPCSMeas,
                                      busUCMeasType busUCMeas);

  static busTMSMeasStdType TMSAdapter(busTMSMeasType busTMSMeas);

  static busFSSMeasStdType FSSAdapter(busFSSMeasType busFSSMeas);

  static busGenOperStdType GenOperAdapter(busGenOperType busGenOper);

  static busConfigStdType ConfigAdapter(busConfigType busConfig);

  static busMBMUMeasStdType MBMUAdapter(busMBMUMeasType busMBMUMeas);

  static busBCPMeasStdType BCPAdapter(busBCPMeasType busBCPMeas);

  static busCommLossMeasStdType
  CommLossAdapter(busCommLossMeasType busCommLoss);
};
} // namespace UnitCtrl
