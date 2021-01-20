#include "FOCConfig.h"
#include "MotorGPIO.h"

#include "Foc.h"
#include "SvpwmConfig.h"
#include "TLE5012BConfig.h"
#include "ADC1.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

#include "Timer.h"

#define M1_TAR_IQ  -50.0f
#define M1_TAR_ID  0.0f
#define M1_OUTMAX  12.0f * 0.577f
#define M1_KP  0.0002f
#define M1_KI  0.0003f
#define M1_KD  0.0f


#define M2_TAR_IQ  000.0f
#define M2_TAR_ID  0.0f
#define M2_OUTMAX  12.0f * 0.577f
#define M2_KP  0.0002f
#define M2_KI  0.0003f
#define M2_KD  0.0f
/*************************************************************
** Function name:       GetMotor1PreCurrent
** Descriptions:        获取电机1 3相电流值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GetMotor1PreCurrent(float *ua,float *ub,float *uc)
{
	*ua = (float)GetADC1ChannelXValue(5);
	*ub = (float)GetADC1ChannelXValue(4);
	*uc = (float)GetADC1ChannelXValue(3);

}
/*************************************************************
** Function name:       GetMotor2PreCurrent
** Descriptions:        获取电机2 3相电流值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GetMotor2PreCurrent(float *ua,float *ub,float *uc)
{
	*ua = (float)GetADC1ChannelXValue(0);
	*ub = (float)GetADC1ChannelXValue(1);
	*uc = (float)GetADC1ChannelXValue(2);

}
//声明两个FOC对象
FOC_EXPORT(gMotor1FOC,0.0002f,7.0f,SetMotor1Enable,ReadMotor1Angel,GetMotor1SVPWMSector,GetMotor1PreCurrent,Motor1SvpwmGenerate)
FOC_EXPORT(gMotor2FOC,0.0002f,7.0f,SetMotor2Enable,ReadMotor2Angel,GetMotor2SVPWMSector,GetMotor2PreCurrent,Motor2SvpwmGenerate)



/*************************************************************
** Function name:       FOCConfig_Init
** Descriptions:        FOC初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void FOCConfig_Init(void)
{

    SetFocEnable(&gMotor1FOC,1);
    SetCurrentPIDTar(&gMotor1FOC,M1_TAR_ID,M1_TAR_IQ);
    SetCurrentPIDParams(&gMotor1FOC,M1_KP,M1_KI,M1_KD,M1_OUTMAX);

    SetFocEnable(&gMotor2FOC,1);
    SetCurrentPIDTar(&gMotor2FOC,M2_TAR_ID,M2_TAR_IQ);
    SetCurrentPIDParams(&gMotor2FOC,M2_KP,M2_KI,M2_KD,M2_OUTMAX);
}
/*************************************************************
** Function name:       FOCConfig_Loop
** Descriptions:        FOC周期循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void FOCConfig_Loop(void)
{
    FOCCycle(&gMotor1FOC);
	RUN_BY_LIMIT_BLOCK(1000,
		SetCurrentPIDTar(&gMotor2FOC,0,250);
		SetCurrentPIDTar(&gMotor1FOC,0,100);
		)
	RUN_BY_LIMIT_BLOCK(2000,
		SetCurrentPIDTar(&gMotor2FOC,0,-250);
		SetCurrentPIDTar(&gMotor1FOC,0,-100);
		)
    FOCCycle(&gMotor2FOC);
}


