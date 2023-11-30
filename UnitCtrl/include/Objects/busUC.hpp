#pragma once

#include "busBMS.hpp"
#include "busPCS.hpp"
#include "busMBMU.hpp"
#include "busConfig.hpp"
#include "busGenOper.hpp"


namespace UnitCtrl
{
	//const int nStringNum = 1;
	//const int nPCSNum = 1;
	//const int nContainerNum = 1;
				//TMS: thermal management system
//	
//#ifdef TMS_CATL
//	struct busTMSMeasType {
//		uint32 u32Alarms = { 0 };
//	};
//#elif TMS_Ampace
//	struct busTMSMeasType {
//		uint32 u32Warnings = { 0 };
//	};
//#else
//	struct busTMSMeasType {
//		uint32 u32Alarms = { 0 };
//		uint32 u32Warnings = { 0 };
//	};
//#endif
				struct busTMSMeasType {
				//#ifdef TMS_CATL
					uint32 u32Alarms = { 0 };
					uint32 u32Warnings = { 0 };
					uint32 u32TMSMode = { 0 };  //0:power off, 1:cooling, 2:heating, 3:self-circulation
					float32 f32TMSEnvTemp = { 0.0 };
					uint32 u32TMSFaultCode = { 0 };
				//#elif TMS_Ampace_Envicool
					//uint32 u32Alarms = { 0 };   //bitwise
					//uint32 u32Warnings = { 0 };    //bitwise
					//uint16 u16DeviceStatus = { 2 }; //1:standby, 2:operation, 3:fault
					//int16 i16AirTemp = { 0 };
					//uint16 u16AirHUmidity = { 0 };					
					//uint16 u16HighTempWarning = { 0 }; //0:normal operation, 1:ALarm  //warning bit0
					//uint16 u16InFansFaultWarning = { 0 };   //warning bit1
					//uint16 u16OutFansFaultWarning = { 0 };  //warning bit2
					//uint16 u16CompFaultWarning = { 0 };     //warning bit3
					//uint16 u16AirTempSenAlarm = { 0 };      //alarm bit0
					//uint16 u16HighSysPresWarning = { 0 };   //warning  bit4
					//uint16 u16LowTempWarning = { 0 };       //warning bit5
					//uint16 u16HighDCVWarning = { 0 };       //warning bit6
					//uint16 u16LowDCVWarning = { 0 };        //warning  bit7
					//uint16 u16HighACVWarning = { 0 };       //warning bit8
					//uint16 u16LowACVWarning = { 0 };        //warning bit9
					//uint16 u16ACPowerFailWarning = { 0 };   //warning bit10
					//uint16 u16EvaTempSenAlarm = { 0 };      //alarm bit1
					//uint16 u16CondTempSenAlarm = { 0 };     //alarm bit2
					//uint16 u16EnvTempSenAlarm = { 0 };      //alarm bit3
					//uint16 u16EvaFreezeWarning = { 0 };     //warning bit11
					//uint16 u16FreqHighPreWarning = { 0 };   //warning bit12
					//uint16 u161TemporHumAlarm = { 0 };      //alarm bit4
					//uint16 u162TemporHumAlarm = { 0 };      //alarm bit5
				//#elif TMS_Ampace_BlackShields
					//uint32 u32Alarms = { 0 }; //bitwise
					//uint32 u32Warnings = { 0 };//bitwise
					//uint16 u16DeviceStatus = { 1 }; //0:stop, 1:operation
					//int16 i16InnerTemp = { 0 };
					//int16 i16Humidity = { 0 };					
					//uint16 u16HighTempWarning = { 0 }; //0:Normal, 1:Warning warning bit0
					//uint16 u16LowTempWarning = { 0 };    //warning bit1
					//uint16 u16HighHmdWarning = { 0 };    //warning bit2
					//uint16 u16CoilAntiFZWarning = { 0 }; //warning bit3
					//uint16 u16HighACVWarning = { 0 };    //warning bit4
					//uint16 u16LowACVWarning = { 0 };     //warning bit5
				//#endif
				};

				struct busTMSInfoType {
				//#ifdef TMS_CATL
					uint32 u32Alarms = { 0 };
					uint32 u32Warnings = { 0 };
					uint32 u32TMSMode = { 0 };
					float32 f32TMSEnvTemp = { 0.0 };
					boolean bTMSFault = { false };
				//#elif TMS_Ampace_Envicool
					/*uint32 u32Alarms = { 0 };
					uint32 u32Warnings = { 0 };
					uint16 u16DeviceStatus = { 2 };
					int16 i16AirTemp = { 0 };
					uint16 u16AirHUmidity = { 0 };*/
				//#elif TMS_Ampace_BlackShields
					/*uint32 u32Alarms = { 0 };
					uint32 u32Warnings = { 0 };
					uint16 u16DeviceStatus = { 2 };
					int16 i16InnerTemp = { 0 };
					uint16 u16Humidity = { 0 };*/
				//#endif
				};

				//FSS: Fire Supression System
				struct busFSSMeasType {
					uint32 u32FSSAlarms = { 0 };
					uint32 u32FSSWarnings = { 0 };

				};

				struct busFSSInfoType {
					uint32 u32FSSAlarms = { 0 };
					uint32 u32FSSWarnings = { 0 };
				};

				//for Ampace BMS
				//BCP:Battery connection panel, also called combiner
				struct busBCPMeasType {
					uint32 u32BCPAlarms = { 0 };
					uint32 u32BCPWarnings = { 0 };

				};

				struct busBCPInfoType {
					uint32 u32BCPAlarms = { 0 };
					uint32 u32BCPWarnings = { 0 };
				};

			struct busCtrlPanelMeasType {
				uint32 u32Alarms = { 0 };
				uint32 u32Warnings = { 0 };
			};

		struct busContainerMeasType {
			busStringMeasType busStringMeas[nStringNum];
			busTMSMeasType busTMSMeas[nTMSNum];	
			busFSSMeasType busFSSMeas[nFSSNum];
			uint32 u32Alarms = { 0 };
			uint32 u32Warnings = { 0 };
		};

		struct busContainerCtrlType {
			busStringCtrlType busStringCtrl[nStringNum];
		};

		struct busContainerInfoType {
			busStringInfoType busStringInfo[nStringNum];
			busTMSInfoType busTMSInfo[nTMSNum];
			busFSSInfoType busFSSInfo[nFSSNum];
			uint32 u32Alarms = { 0 };
			uint32 u32Warnings = { 0 };
		};

		//#ifdef TMS_CATL
		//	struct busUCMeasType {
		//		busContainerMeasType busContainer[nContainerNum];
		//		busPCSMeasType busPCSMeas[nPCSNum];
		//		busCtrlPanelMeasType busCtrlPanel;
		//	};
		//#elif TMS_Ampace
		//	struct busUCMeasType {
		//		busContainerMeasType busContainer[nContainerNum];
		//		busPCSMeasType busPCSMeas[nPCSNum];
		//		busCtrlPanelMeasType busCtrlPanel;
		//	};
		//#else
		//	struct busUCMeasType {
		//		busContainerMeasType busContainer[nContainerNum];
		//		busPCSMeasType busPCSMeas[nPCSNum];
		//		busCtrlPanelMeasType busCtrlPanel;
		//	};
		//#endif

		//struct MyStructA {
		//	uint32 u32Alarms = { 0 };
		//	uint32 u32Warnings = { 0 };
		//};
		//struct MyStructB {
		//	uint32 u32Alarms = { 0 };
		//};
		//template<typename Tx>
		//struct MyStruct {
		//	Tx myValx;
		//};

		struct busMetersType {
			int32 u32Alarms = { 0 };
			int32 u32Warnings = { 0 };
		};

		struct busCommLossMeasType {
			uint16 u16BMS[nCommLossBMSNum] = { 0 };
			uint16 u16PCS[nCommLossPCSNum] = { 0 };
			uint16 u16Meter = { 0 };
			uint16 u16HMI = { 0 };
			uint16 u16EtherSwitch = { 0 };
			uint16 u16MGuard = { 0 };
			uint16 u16TimeServer = { 0 };
			uint16 u16PLC = { 0 };
		};

		struct busUCMeasType {
			busContainerMeasType busContainer[nContainerNum];
			busMBMUMeasType busMBMUMeas[nMBMUNum];
			busBCPMeasType busBCPMeas[nBCPNum];
			busPCSMeasType busPCSMeas[nPCSNum];
			busCtrlPanelMeasType busCtrlPanel;
			busMetersType busMeter;
			busCommLossMeasType busCommLoss;
			uint16 u16InterSwitchPos = { 0 };
		};

		struct busUCCtrlType {
			busContainerCtrlType busContainerCtrl[nContainerNum];
			busPCSCtrlType busPCSCtrl[nPCSNum];
		};

		struct busUCCoreType {
			uint16 u16UCState = { 0 };
			boolean bUCRun = { false };
			boolean bBMSOn = { false };
			boolean bPCSOn = { false };
			boolean bAutoForming = { false };
			int32 u32Alarms = { 0 };
			int32 u32Warnings = { 0 };
		};

		struct busPowerInfoType {
			float32 f32SysSOC = { 0 };
			uint16 u16BattVDC = { 0 };
			uint32 u32MaxChgPower = { 0 };
			uint32 u32MaxDcgPower = { 0 };
			uint16 u16BESSRunning = { 0 };
			uint16 u16InterSwitchPos = { 0 };
			uint32 u32Alarms = { 0 };
			uint32 u32Warnings = { 0 };
		};

		struct busCommLossInfoType {
			uint16 u16BMS[nCommLossBMSNum] = { 0 };
			uint16 u16PCS[nCommLossPCSNum] = { 0 };
			uint16 u16Meter = { 0 };
			uint16 u16HMI = { 0 };
			uint16 u16EtherSwitch = { 0 };
			uint16 u16MGuard = { 0 };
			uint16 u16TimeServer = { 0 };
			uint16 u16PLC = { 0 };
		};

		struct busUCInfoType {
			busContainerInfoType busContainerInfo[nContainerNum];
			busPCSInfoType busPCSInfo[nPCSNum];
			busMBMUInfoType busMBMUInfo[nMBMUNum];
			busBCPInfoType busBCPInfo[nBCPNum];
			busUCCoreType busUCCore;
			busPowerInfoType busPowerInfo;
			busCommLossInfoType busCommLossInfo;
		};


		struct busUCType {
			busUCMeasType busUCMeas;
			busUCCtrlType busUCCtrl;
			busUCInfoType busUCInfo;
			busGenOperType busGenOper;
			busConfigType busConfig;
		};
}
