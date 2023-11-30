#pragma once

namespace UnitCtrl
{
	//bus definition for power limit manager
	struct busPLimitManagerType {
		float f32BaseSpP; 
        float f32BaseSpQ;
        float f32PSetpoint;
        float f32QSetpoint;	
		float f32VACSetpoint;
		float f32FreqSetpoint;
		float f32ChgLimitP;
		float f32DcgLimitP;
		float f32AbsorbLimitQ;
		float f32GenerateLimitQ;
		float f32SysSOC;
		unsigned int u32Warnings;
		};
}
