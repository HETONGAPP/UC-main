#include "OutputsAdapter.hpp"


namespace UnitCtrl
{
	busUCType OutputsAdapter::RunOutputsAdapter(busUCCtrlStdType busUCCtrlStd, busUCInfoStdType busUCInfoStd, busUCCoreStdType busUCCore, busPLimitManagerType busPLimitManager, busUCStdType busUCStd)
	{
		busUCType busUC;
		//busUC = outputsAdapter_.UCAdapter(busUCCtrl, busUCInfoStd);
		for (int nContNum = 0; nContNum < nContainerNum; nContNum++)
		{
			for (int i = 0; i < nStringNum; i++)
			{
				busUC.busUCCtrl.busContainerCtrl[nContNum].busStringCtrl[i] = BMSCtrlAdapter(busUCCtrlStd.busContainerCtrl[nContNum].busStringCtrl[i]);
				busUC.busUCInfo.busContainerInfo[nContNum].busStringInfo[i] = BMSInfoAdapter(busUCInfoStd.busContainerInfo[nContNum].busStringInfo[i]);
			}
			for (int nTMSn = 0; nTMSn < nTMSNum; nTMSn++)
			{
				busUC.busUCInfo.busContainerInfo[nContNum].busTMSInfo[nTMSn] = TMSInfoAdapter(busUCInfoStd.busContainerInfo[nContNum].busTMSInfo[nTMSn]);
			}
			for (int nFSSn = 0; nFSSn < nFSSNum; nFSSn++)
			{
				busUC.busUCInfo.busContainerInfo[nContNum].busFSSInfo[nFSSn] = FSSInfoAdapter(busUCInfoStd.busContainerInfo[nContNum].busFSSInfo[nFSSn]);
			}
		}				   
		for (int k = 0; k < nPCSNum; k++)
		{
			busUCCtrlStd.busPCSCtrl[k].f32PSetpoint = busPLimitManager.f32PSetpoint;
			busUCCtrlStd.busPCSCtrl[k].f32QSetpoint = busPLimitManager.f32QSetpoint;
			busUCCtrlStd.busPCSCtrl[k].f32VACSetpoint = busPLimitManager.f32VACSetpoint;
			busUCCtrlStd.busPCSCtrl[k].f32FreqSetpoint = busPLimitManager.f32FreqSetpoint;
			busUCInfoStd.busPCSInfo[k].f32ChgLimitP = busPLimitManager.f32ChgLimitP;
			busUCInfoStd.busPCSInfo[k].f32DcgLimitP = busPLimitManager.f32DcgLimitP;
			busUCInfoStd.busPCSInfo[k].f32AbsorbLimitQ = busPLimitManager.f32AbsorbLimitQ;
			busUCInfoStd.busPCSInfo[k].f32GenerateLimitQ = busPLimitManager.f32GenerateLimitQ;
			busUC.busUCCtrl.busPCSCtrl[k] = PCSCtrlAdapter(busUCCtrlStd.busPCSCtrl[k]);
			busUC.busUCInfo.busPCSInfo[k] = PCSInfoAdapter(busUCInfoStd.busPCSInfo[k]);
		}
		for (int j = 0; j < nMBMUNum; j++)
		{
			busUC.busUCInfo.busMBMUInfo[j] = MBMUInfoAdapter(busUCInfoStd.busMBMUInfo[j]);
		}
		for (int n = 0; n < nBCPNum; n++)
		{
			busUC.busUCInfo.busBCPInfo[n] = BCPInfoAdapter(busUCInfoStd.busBCPInfoStd[n]);
		}
		busUC.busUCInfo.busUCCore = UCCoreAdapter(busUCCore);
		busUC.busUCInfo.busPowerInfo.f32SysSOC = static_cast<float>(busPLimitManager.f32SysSOC);
		busUC.busUCInfo.busPowerInfo.u32Warnings = busPLimitManager.u32Warnings;
		busUC.busUCInfo.busPowerInfo.u16BattVDC = busUCInfoStd.busMBMUInfo[0].u16SysVol;
		busUC.busUCInfo.busPowerInfo.u32MaxChgPower = busUCInfoStd.busMBMUInfo[0].u16SysChgCurrLim * busUCInfoStd.busMBMUInfo[0].u16SysVol;
		busUC.busUCInfo.busPowerInfo.u32MaxDcgPower = busUCInfoStd.busMBMUInfo[0].u16SysDischgCurrLim * busUCInfoStd.busMBMUInfo[0].u16SysVol;
		busUC.busUCInfo.busPowerInfo.u16BESSRunning = busUCInfoStd.busUCCore.bUCRun ? 1 : 0;
		busUC.busUCInfo.busPowerInfo.u16InterSwitchPos = busUCStd.busUCMeasStd.u16InterSwitchPos;

		busUC.busUCInfo.busCommLossInfo = CommLossAdapter(busUCInfoStd.busCommLossInfo);
		
		return busUC;
	}

	busCommLossInfoType OutputsAdapter::CommLossAdapter(busCommLossInfoStdType busCommLoss)
	{
		busCommLossInfoType busCommLossInfo;

		for (int i = 0; i < nCommLossBMSNum; i++)
		{
			busCommLossInfo.u16BMS[i] = busCommLoss.u16BMS[i];
		}
		for (int j = 0; j < nCommLossPCSNum; j++)
		{
			busCommLossInfo.u16PCS[j] = busCommLoss.u16PCS[j];
		}
		busCommLossInfo.u16EtherSwitch = busCommLoss.u16EtherSwitch;
		busCommLossInfo.u16HMI = busCommLoss.u16HMI;
		busCommLossInfo.u16Meter = busCommLoss.u16Meter;
		busCommLossInfo.u16MGuard = busCommLoss.u16MGuard;
		busCommLossInfo.u16PLC = busCommLoss.u16PLC;
		busCommLossInfo.u16TimeServer = busCommLoss.u16TimeServer;

		return busCommLossInfo;
	}

	busStringCtrlType OutputsAdapter::BMSCtrlAdapter(busBMSCtrlStdType busBMSCtrlStd)
	{
		busStringCtrlType busStringCtrl;

#ifdef BMS_CATL
		busStringCtrl.bAlarmReset = static_cast<boolean>(busBMSCtrlStd.bAlarmReset);
		busStringCtrl.bSwCtrl = static_cast<boolean>(busBMSCtrlStd.bSwCtrl);
#elif BMS_Ampace
		busStringCtrl.bAlarmReset = static_cast<boolean>(busBMSCtrlStd.bAlarmReset);
		busStringCtrl.bSwCtrl = static_cast<boolean>(busBMSCtrlStd.bSwCtrl);
#else
		busStringCtrl.bAlarmReset = static_cast<boolean>(busBMSCtrlStd.bAlarmReset);
		busStringCtrl.bSwCtrl = static_cast<boolean>(busBMSCtrlStd.bSwCtrl);
#endif	

		return busStringCtrl;
	}

	busStringInfoType OutputsAdapter::BMSInfoAdapter(busStringInfoStdType busBMSInfoStd)
	{
		busStringInfoType busStringInfo;

#ifdef BMS_CATL
		busStringInfo.u16BMSState = static_cast<uint16>(busBMSInfoStd.u16BMSState);
		busStringInfo.bBMSRun = static_cast<boolean>(busBMSInfoStd.bBMSRun);
		busStringInfo.bChgOK = static_cast<boolean>(busBMSInfoStd.bChgOK);
		busStringInfo.bDcgOK = static_cast<boolean>(busBMSInfoStd.bDcgOK);
		busStringInfo.u32StrAlarms = static_cast<uint32>(busBMSInfoStd.u32StrAlarms);
		busStringInfo.u32StrWarnings = static_cast<uint32>(busBMSInfoStd.u32StrWarnings);
#elif BMS_Ampace
		busStringInfo.u16BMSState = static_cast<uint16>(busBMSInfoStd.u16BMSState);
		busStringInfo.bBMSRun = static_cast<boolean>(busBMSInfoStd.bBMSRun);
		busStringInfo.bChgOK = static_cast<boolean>(busBMSInfoStd.bChgOK);
		busStringInfo.bDcgOK = static_cast<boolean>(busBMSInfoStd.bDcgOK);
		busStringInfo.u32StrAlarms = static_cast<uint32>(busBMSInfoStd.u32StrAlarms);
		busStringInfo.u32StrWarnings = static_cast<uint32>(busBMSInfoStd.u32StrWarnings);
#else
		busStringInfo.u16BMSState = static_cast<uint16>(busBMSInfoStd.u16BMSState);
		busStringInfo.bBMSRun = static_cast<boolean>(busBMSInfoStd.bBMSRun);
		busStringInfo.bChgOK = static_cast<boolean>(busBMSInfoStd.bChgOK);
		busStringInfo.bDcgOK = static_cast<boolean>(busBMSInfoStd.bDcgOK);
		busStringInfo.u32StrAlarms = static_cast<uint32>(busBMSInfoStd.u32StrAlarms);
		busStringInfo.u32StrWarnings = static_cast<uint32>(busBMSInfoStd.u32StrWarnings);
#endif	

		return busStringInfo;
	}

	busMBMUInfoType OutputsAdapter::MBMUInfoAdapter(busMBMUInfoStdType busMBMUInfoStd)
	{
		busMBMUInfoType busMBMUInfo;
		busMBMUInfo.u32MBMUWarnings = static_cast<uint32>(busMBMUInfoStd.u32MBMUWarnings);
		busMBMUInfo.u32MBMUAlarms = static_cast<uint32>(busMBMUInfoStd.u32MBMUAlarms);
		busMBMUInfo.f32SysSOC = static_cast<float>(busMBMUInfoStd.f32SysSOC);
		busMBMUInfo.u16SysSOH = static_cast<uint16>(busMBMUInfoStd.u16SysSOH);
#ifdef BMS_CATL
		busMBMUInfo.u16SysStatus = static_cast<uint16>(busMBMUInfoStd.u16SysStatus);
		busMBMUInfo.u16SysVol = static_cast<uint16>(busMBMUInfoStd.u16SysVol);
		busMBMUInfo.i16SysCurrent = static_cast<int16>(busMBMUInfoStd.i16SysCurrent);
		busMBMUInfo.u16SysChgCurrLim = static_cast<uint16>(busMBMUInfoStd.u16SysChgCurrLim);
		busMBMUInfo.u16SysDischgCurrLim = static_cast<uint16>(busMBMUInfoStd.u16SysDischgCurrLim);
#elif BMS_Ampace
		busMBMUInfo.u32SysVol = static_cast<uint32>(busMBMUInfoStd.u32SysVol);
		busMBMUInfo.i32SysCurrent = static_cast<int32>(busMBMUInfoStd.i32SysCurrent);
		busMBMUInfo.i32SysPower = static_cast<int32>(busMBMUInfoStd.i32SysPower);
		busMBMUInfo.u32SysChgPwLim = static_cast<uint32>(busMBMUInfoStd.u32SysChgPwLim);
		busMBMUInfo.u32SysDischgPwLim = static_cast<uint32>(busMBMUInfoStd.u32SysDischgPwLim);
		busMBMUInfo.i32SysChgCurrLim = static_cast<int32>(busMBMUInfoStd.i32SysChgCurrLim);
		busMBMUInfo.i32SysDischgCurrLim = static_cast<int32>(busMBMUInfoStd.i32SysDischgCurrLim);
#endif	
		return busMBMUInfo;
	}
	
	busTMSInfoType OutputsAdapter::TMSInfoAdapter(busTMSInfoStdType busTMSInfoStd)
	{
		busTMSInfoType busTMSInfo;
		busTMSInfo.u32Alarms = static_cast<uint32>(busTMSInfoStd.u32Alarms);
		busTMSInfo.u32Warnings = static_cast<uint32>(busTMSInfoStd.u32Warnings);

#ifdef TMS_CATL
		busTMSInfo.u32TMSMode = static_cast<boolean>(busTMSInfoStd.u32TMSMode);
		busTMSInfo.f32TMSEnvTemp = static_cast<float32>(busTMSInfoStd.f32TMSEnvTemp);
		busTMSInfo.bTMSFault = static_cast<boolean>(busTMSInfoStd.bTMSFault);
#elif TMS_Ampace_Envicool
		busTMSInfo.u16DeviceStatus = static_cast<uint16>(busTMSInfoStd.u16DeviceStatus);
		busTMSInfo.i16AirTemp = static_cast<int16>(busTMSInfoStd.i16AirTemp);
		busTMSInfo.u16AirHUmidity = static_cast<uint16>(busTMSInfoStd.u16AirHUmidity);

#elif TMS_Ampace_BlackShields
		busTMSInfo.u16DeviceStatus = static_cast<uint16>(busTMSInfoStd.u16DeviceStatus);
		busTMSInfo.i16InnerTemp = static_cast<int16>(busTMSInfoStd.i16InnerTemp);
		busTMSInfo.i16Humidity = static_cast<uint16>(busTMSInfoStd.i16Humidity);

#else
		busTMSInfo.u16DeviceStatus = static_cast<uint16>(busTMSInfoStd.u16DeviceStatus);
		busTMSInfo.i16AirTemp = static_cast<int16>(busTMSInfoStd.i16AirTemp);
		busTMSInfo.u16AirHUmidity = static_cast<uint16>(busTMSInfoStd.u16AirHUmidity);
#endif

		return busTMSInfo;
	}

	busFSSInfoType OutputsAdapter::FSSInfoAdapter(busFSSInfoStdType busFSSInfoStd)
	{
		busFSSInfoType busFSSInfo;
		busFSSInfo.u32FSSAlarms = static_cast<uint32>(busFSSInfoStd.u32FSSAlarms);
		busFSSInfo.u32FSSWarnings = static_cast<uint32>(busFSSInfoStd.u32FSSWarnings);

		return busFSSInfo;
	}

	busBCPInfoType OutputsAdapter::BCPInfoAdapter(busBCPInfoStdType busBCPInfoStd)
	{
		busBCPInfoType busBCPInfo;
		busBCPInfo.u32BCPAlarms = static_cast<uint32>(busBCPInfoStd.u32BCPAlarms);
		busBCPInfo.u32BCPWarnings = static_cast<uint32>(busBCPInfoStd.u32BCPWarnings);

		return busBCPInfo;
	}

	busPCSCtrlType OutputsAdapter::PCSCtrlAdapter(busPCSCtrlStdType busPCSCtrlStd)
	{
		busPCSCtrlType busPCSCtrl;

#ifdef PCS_EPC
		busPCSCtrl.f32PSetpoint = static_cast<float32>(busPCSCtrlStd.f32PSetpoint / 1000);
		busPCSCtrl.f32QSetpoint = static_cast<float32>(busPCSCtrlStd.f32QSetpoint / 1000);
		busPCSCtrl.f32VACSetpoint = static_cast<float32>(busPCSCtrlStd.f32VACSetpoint);
		busPCSCtrl.f32FreqSetpoint = static_cast<float32>(busPCSCtrlStd.f32FreqSetpoint);
		busPCSCtrl.bAlarmReset = static_cast<boolean>(busPCSCtrlStd.bAlarmReset);
		busPCSCtrl.bAllowFollowing = static_cast<boolean>(busPCSCtrlStd.bAllowFollowing);
		busPCSCtrl.bAllowForming = static_cast<boolean>(busPCSCtrlStd.bAllowForming);
		busPCSCtrl.bAllowAutoForming = static_cast<boolean>(busPCSCtrlStd.bAllowAutoForming);
		busPCSCtrl.bPCSOn = static_cast<boolean>(busPCSCtrlStd.bPCSOn);
		busPCSCtrl.u16CtrlMode = static_cast<uint16>(busPCSCtrlStd.u16CtrlMode);
		busPCSCtrl.u16CtrlSrc = static_cast<uint16>(busPCSCtrlStd.u16CtrlSrc);
		busPCSCtrl.bSynchronized = static_cast<boolean>(busPCSCtrlStd.bSynchronized);
		busPCSCtrl.bConnected = static_cast<boolean>(busPCSCtrlStd.bConnected);
#else
		busPCSCtrl.f32PSetpoint = static_cast<float32>(busPCSCtrlStd.f32PSetpoint / 1000);
		busPCSCtrl.f32QSetpoint = static_cast<float32>(busPCSCtrlStd.f32QSetpoint / 1000);
		busPCSCtrl.f32VACSetpoint = static_cast<float32>(busPCSCtrlStd.f32VACSetpoint);
		busPCSCtrl.f32FreqSetpoint = static_cast<float32>(busPCSCtrlStd.f32FreqSetpoint);
		busPCSCtrl.bAlarmReset = static_cast<boolean>(busPCSCtrlStd.bAlarmReset);
		busPCSCtrl.bAllowFollowing = static_cast<boolean>(busPCSCtrlStd.bAllowFollowing);
		busPCSCtrl.bAllowForming = static_cast<boolean>(busPCSCtrlStd.bAllowForming);
		busPCSCtrl.bAllowAutoForming = static_cast<boolean>(busPCSCtrlStd.bAllowAutoForming);
		busPCSCtrl.bPCSOn = static_cast<boolean>(busPCSCtrlStd.bPCSOn);
		busPCSCtrl.u16CtrlMode = static_cast<uint16>(busPCSCtrlStd.u16CtrlMode);
		busPCSCtrl.u16CtrlSrc = static_cast<uint16>(busPCSCtrlStd.u16CtrlSrc);
		busPCSCtrl.bSynchronized = static_cast<boolean>(busPCSCtrlStd.bSynchronized);
		busPCSCtrl.bConnected = static_cast<boolean>(busPCSCtrlStd.bConnected);
#endif		

		return busPCSCtrl;
	}

	busPCSInfoType OutputsAdapter::PCSInfoAdapter(busPCSInfoStdType busPCSInfoStd)
	{
		busPCSInfoType busPCSInfo;

#ifdef PCS_EPC
		busPCSInfo.bPCSRun = static_cast<boolean>(busPCSInfoStd.bPCSRun);
		busPCSInfo.u16PCSState = static_cast<uint16>(busPCSInfoStd.u16PCSState);
		busPCSInfo.u32PCSAlarms = static_cast<int32>(busPCSInfoStd.u32PCSAlarms);
		busPCSInfo.u32PCSWarnings = static_cast<int32>(busPCSInfoStd.u32PCSWarnings);
		busPCSInfo.f32ChgLimitP = static_cast<float32>(busPCSInfoStd.f32ChgLimitP / 1000);
		busPCSInfo.f32DcgLimitP = static_cast<float32>(busPCSInfoStd.f32DcgLimitP / 1000);
		busPCSInfo.f32GenerateLimitQ = static_cast<float32>(busPCSInfoStd.f32GenerateLimitQ / 1000);
		busPCSInfo.f32AbsorbLimitQ = static_cast<float32>(busPCSInfoStd.f32AbsorbLimitQ / 1000);
#else
		busPCSInfo.bPCSRun = static_cast<boolean>(busPCSInfoStd.bPCSRun);
		busPCSInfo.u16PCSState = static_cast<uint16>(busPCSInfoStd.u16PCSState);
		busPCSInfo.u32PCSAlarms = static_cast<int32>(busPCSInfoStd.u32PCSAlarms);
		busPCSInfo.u32PCSWarnings = static_cast<int32>(busPCSInfoStd.u32PCSWarnings);
		busPCSInfo.f32ChgLimitP = static_cast<float32>(busPCSInfoStd.f32ChgLimitP / 1000);
		busPCSInfo.f32DcgLimitP = static_cast<float32>(busPCSInfoStd.f32DcgLimitP / 1000);
		busPCSInfo.f32GenerateLimitQ = static_cast<float32>(busPCSInfoStd.f32GenerateLimitQ / 1000);
		busPCSInfo.f32AbsorbLimitQ = static_cast<float32>(busPCSInfoStd.f32AbsorbLimitQ / 1000);
#endif

		return busPCSInfo;
	}


	busUCCoreType OutputsAdapter::UCCoreAdapter(busUCCoreStdType busUCCore)
	{
		busUCCoreType busUCCoreT;

		busUCCoreT.u16UCState = static_cast<uint16>(busUCCore.u16UCState);
		busUCCoreT.bUCRun = static_cast<boolean>(busUCCore.bUCRun);
		busUCCoreT.bBMSOn = static_cast<boolean>(busUCCore.bBMSOn);
		busUCCoreT.bPCSOn = static_cast<boolean>(busUCCore.bPCSOn);
		busUCCoreT.bAutoForming = static_cast<boolean>(busUCCore.bAutoForming);
		busUCCoreT.u32Alarms = static_cast<int32>(busUCCore.u32Alarms);
		busUCCoreT.u32Warnings = static_cast<int32>(busUCCore.u32Warnings);

		return busUCCoreT;
	}

	//busUCType OutputsAdapter::UCAdapter(busUCCtrlStdType busUCCtrlStd, busUCInfoStdType busUCInfoStd)
	//{
	//	busUCType busUC;
	//	busUC.busUCCtrl.busStringCtrl = BMSCtrlAdapter(busUCStd.busUCCtrlStd.busStringCtrl);
	//	busUC.busUCInfo.busStringInfo = BMSInfoAdapter(busUCStd.busUCInfoStd.busStringInfo);
	//	busUC.busUCCtrl.busPCSCtrl = PCSCtrlAdapter(busUCStd.busUCCtrlStd.busPCSCtrl);
	//	busUC.busUCInfo.busPCSInfo = PCSInfoAdapter(busUCStd.busUCInfoStd.busPCSInfo);
	//	busUC.busUCInfo.busUCCore = UCCoreAdapter(busUCStd.busUCCore);

	//	return busUC;
	//}
}
