#pragma once

#include "Arp/System/Core/Arp.h"

namespace UnitCtrl
{
	using namespace Arp;

	struct busStringMeasType {
		int16 i16StrCurrent = { 0 };
		uint16 u16StrVoltage = { 0 };
		uint16 u16StrSOC = { 0 };
		uint16 u16StrSOH = { 0 };
		uint16 u16StrChgCurrLim = { 0 };
		uint16 u16StrDcgCurrLim = { 0 };
		uint16 u16MaxCellVoltage = { 0 };
		uint16 u16MinCellVoltage = { 0 };
		int16 i16MaxCellTemp = { 0 };
		int16 i16MinCellTemp = { 0 };
		uint32 u32StrAlarms = { 0 };
		uint32 u32StrWarnings = { 0 };
		boolean bStrCommLoss = { false };
		uint16 u16CellBalance = { 0 };
		boolean bStrSwitchPos = { false };
		//boolean bPrechargeRelay = { false };
	};

	struct busStringCtrlType {
		boolean bAlarmReset = false;
		boolean bSwCtrl = false;
	};

	struct busStringInfoType {
		boolean bChgOK = { false };
		boolean bDcgOK = { false };
		boolean bBMSRun = false;
		uint16 u16BMSState = 0;
		uint16 u16SMState = 0;
		uint32 u32StrAlarms = { 0 };
		uint32 u32StrWarnings = { 0 };
	};
}

