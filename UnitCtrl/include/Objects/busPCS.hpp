#pragma once

#include "Arp/System/Core/Arp.h"

namespace UnitCtrl
{
	using namespace Arp;

	struct busPCSMeasType {		
		uint32 u32Alarms = 0;
		uint32 u32Warnings = 0;
		boolean bCommLoss = false;
		uint16 u16OperMode = 0;
		uint16 u16VDC = 0;
		float32 f32PACFreq = 0.0;
		int16 i16PAC = 0;
		float32 f32Q = 0.0;
		//float32 f32PCSChgLimitP = 0.0;
		//float32 f32PCSDcgLimitP = 0.0;
		//float32 f32PCSGenerateLimitQ = 0.0;
		//float32 f32PCSAbsorbLimitQ = 0.0;
	};

	struct busPCSCtrlType {
		boolean bAlarmReset = false;
		boolean bPCSOn = false;
		//uint16 u16SetOperation;
		uint16 u16CtrlMode = 0;//Control mode: 0-Grid following; 1-Grid forming
		uint16 u16CtrlSrc = 0;//Control source: 0-Normal; 2-Renewable
		boolean bConnected = false;
		boolean bSynchronized = false;
		float32 f32PSetpoint = 0.0;
		float32 f32QSetpoint = 0.0;
		float32 f32VACSetpoint = 0.0;
		float32 f32FreqSetpoint = 0.0;
		boolean bAllowFollowing = false;
		boolean bAllowForming = false;
		boolean bAllowAutoForming = false;//Only True in G2I
	};

	struct busPCSInfoType {
		boolean bPCSRun = false;
		uint16 u16PCSState = 0;
		uint32 u32PCSAlarms = 0;
		uint32 u32PCSWarnings = 0;
		float32 f32ChgLimitP = 0.0;
		float32 f32DcgLimitP = 0.0;
		float32 f32AbsorbLimitQ = 0.0;
		float32 f32GenerateLimitQ = 0.0;
	};
}

