
#pragma once
#include "Arp/System/Core/Arp.h"

namespace UnitCtrl
{
	using namespace Arp;

	struct busStringConfigType {
		float32 f32SmallCurr = 1;
		uint16 nShutDownTimeout = { 2 };
		uint16 nStartupTimeout = { 2 };
		uint16 nSwitchTimeout = { 2 };
	};

	struct busPCSConfigType {
		uint16 nShutDownTimeout = { 2 };
		uint16 nStartupTimeout = { 2 };
	};

	struct busSysConfigType {
		boolean bEnableUser = { false };
		float32 f32UserLimKWIn = { 0.0 };
		float32 f32UserLimKWOut = { 0.0 };
		float32 f32UserLimKVarIn = { 0.0 };
		float32 f32UserLimKVarOut = { 0.0 };
		uint16 nG2ITimeout = { 2 };
		uint16 nI2GTimeout = { 2 };
	};

	struct busSOCConfigType {
		float32  f32HighLimit = { 95 };
		float32  f32LowLimit = { 5 };
	};

	struct busConfigType {
		busStringConfigType busStringConfig;
		busPCSConfigType busPCSConfig;
		busSysConfigType busSysConfig;
		busSOCConfigType busSOCConfig;
	};
}


