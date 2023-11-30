#pragma once

#include "Arp/System/Core/Arp.h"

namespace UnitCtrl
{
	using namespace Arp;

	struct busMBMUMeasType {
		uint32 u32MBMUWarnings = { 0 };  //bitwise
		uint32 u32MBMUAlarms = { 0 };    //bitwise
		uint16 u16SysSOC = { 0 };
		uint16 u16SysSOH = { 0 };
//#ifdef BMS_CATL		
		uint16 u16SysStatus = { 0 };     //0:Initialize 1:Normal 2:Full charge 3:Full discharge 4:Warning 5:Fault
		uint16 u16SysVol = { 0 };
		int16 i16SysCurrent = { 0 };
		uint16 u16SysChgCurrLim = { 0 };
		uint16 u16SysDischgCurrLim = { 0 };
//#elif BMS_Ampace
//		uint32 u32SysVol = { 0 };
//		int32 i32SysCurrent = { 0 };
//		int32 i32SysPower = { 0 };
//		uint32 u32SysChgPwLim = { 0 };
//		uint32 u32SysDischgPwLim = { 0 };
//		int32 i32SysChgCurrLim = { 0 };
//		int32 i32SysDischgCurrLim = { 0 };
//#endif
	};

	//struct busMBMUCtrlType {
	//	
	//	
	//};

	struct busMBMUInfoType {
		uint32 u32MBMUWarnings = { 0 };  //bitwise
		uint32 u32MBMUAlarms = { 0 };    //bitwise
		float32 f32SysSOC = { 0 };
		uint16 u16SysSOH = { 0 };
//#ifdef BMS_CATL
		uint16 u16SysStatus = { 0 };     //0:Initialize 1:Normal 2:Full charge 3:Full discharge 4:Warning 5:Fault
		uint16 u16SysVol = { 0 };
		int16 i16SysCurrent = { 0 };
		uint16 u16SysChgCurrLim = { 0 };
		uint16 u16SysDischgCurrLim = { 0 };
//#elif BMS_Ampace
		//uint32 u32SysVol = { 0 };
		//int32 i32SysCurrent = { 0 };
		//int32 i32SysPower = { 0 };
		//uint32 u32SysChgPwLim = { 0 };
		//uint32 u32SysDischgPwLim = { 0 };
		//int32 i32SysChgCurrLim = { 0 };
		//int32 i32SysDischgCurrLim = { 0 };
//#endif		
	};
}