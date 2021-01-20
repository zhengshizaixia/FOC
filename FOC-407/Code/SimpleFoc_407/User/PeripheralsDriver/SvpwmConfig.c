#include "SvpwmConfig.h"
#include "Svpwm.h"
#include "TIM3.h"
#include "TIM4.h"
#include "ADC1.h"
#include "math.h"
#include "main.h"
#include "arm_math.h"

#include "TLE5012BConfig.h"
#include "MotorGPIO.h"
#include "Timer.h"


#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"


float motor1Angle;
float motor2Angle;

#define U 1.0f
float GetMotor1Uα(void)
{
	float Uα;
    static float angle = 0.0f;
    angle = motor1Angle;
    //return 1 * sqrt(3) / 3 * -arm_sin_f32(angle / 180 * 3.1415926 );
	Uα = U* 0.577f * arm_sin_f32(angle * 0.01745f);
	return Uα;
}

float GetMotor1Uβ(void)
{
	float Uβ;
    static float angle = 0.0f;
	angle = motor1Angle;
    //return 1 * sqrt(3) / 3 * arm_cos_f32(angle / 180 * 3.1415926 );
	Uβ = U* 0.577f * -arm_cos_f32(angle * 0.01745f);
	return Uβ;
}


//声明一个SVPWM对象
SVPWM_EXPORT(gMotor1,100,12.0,
                SetTIM3Channel1HighLeaveTime_us,
                SetTIM3Channel2HighLeaveTime_us,
                SetTIM3Channel3HighLeaveTime_us)

float GetMotor2Uα(void)
{
    float Uα;
    static float angle = 0.0f;
    angle = motor2Angle;
    //return 1 * sqrt(3) / 3 * -arm_sin_f32(angle / 180 * 3.1415926 );
	Uα = U* 0.577f * arm_sin_f32(angle * 0.01745f);
	return Uα;
}

float GetMotor2Uβ(void)
{
    float Uβ;
    static float angle = 0.0f;
	angle = motor2Angle;
    //return 1 * sqrt(3) / 3 * arm_cos_f32(angle / 180 * 3.1415926 );
	Uβ = U* 0.577f * -arm_cos_f32(angle * 0.01745f);
	return Uβ;
}
SVPWM_EXPORT(gMotor2,50.0f,12.0f,
                SetTIM4Channel1HighLeaveTime_us,
                SetTIM4Channel2HighLeaveTime_us,
                SetTIM4Channel3HighLeaveTime_us)





/*************************************************************
** Function name:       Motor1SvpwmGenerate
** Descriptions:        电机一SVPWM生成
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SvpwmGenerate(float uα,float uβ)
{
    SvpwmContorol(&gMotor1,uα,uβ);
}
/*************************************************************
** Function name:       Motor1SvpwmGenerate
** Descriptions:        电机一SVPWM生成
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SvpwmGenerate(float uα,float uβ)
{
    SvpwmContorol(&gMotor2,uα,uβ);
}
/*************************************************************
** Function name:       GetMotor1SVPWMSector
** Descriptions:        获取电机1的扇区
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t GetMotor1SVPWMSector(void)
{
    return GetSVPWMSector(&gMotor1);
}
/*************************************************************
** Function name:       GetMotor2SVPWMSector
** Descriptions:        获取电机2的扇区
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t GetMotor2SVPWMSector(void)
{
    return GetSVPWMSector(&gMotor2);
}



void SvpwmConfig_Loop(void)
{
	SetMotor2Enable(1);
	motor2Angle = ReadMotor2Angel() * 7.0f;
	Motor2SvpwmGenerate(GetMotor2Uα(),GetMotor2Uβ());


//	SetMotor1Enable(1);
//	motor1Angle = ReadMotor1Angel() * 7.0f;
//	Motor1SvpwmGenerate(GetMotor1Uα(),GetMotor1Uβ());
}


