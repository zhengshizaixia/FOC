#include "AngleCalibrationFunc.h"


#include "MotorGPIO.h"
#include "TIM3.h"
#include "TIM4.h"
#include "main.h"
#include "TLE5012BConfig.h"


/*************************************************************
** Function name:       Motor1AngleCalibration
** Descriptions:        电机一角度校准
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1AngleCalibration(void)
{
	float angle;
	//1.使能电机
	SetMotor1Enable(1);
	//2.电机旋转至a轴
	SetTIM4Channel1HighLeaveTime_us(50);
	SetTIM4Channel2HighLeaveTime_us(40);
	SetTIM4Channel3HighLeaveTime_us(40);
	HAL_Delay(500);
	//3.读取角度
	angle = ReadMotor1Angel();

	//4.电机失能
	SetTIM4Channel1HighLeaveTime_us(0);
	SetTIM4Channel2HighLeaveTime_us(0);
	SetTIM4Channel3HighLeaveTime_us(0);
	SetMotor1Enable(0);
    while(1);
}
/*************************************************************
** Function name:       Motor2AngleCalibration
** Descriptions:        电机2角度校准
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2AngleCalibration(void)
{
	float angle;
	//1.使能电机
	SetMotor2Enable(1);
	//2.电机旋转至a轴
	SetTIM3Channel1HighLeaveTime_us(50);
	SetTIM3Channel2HighLeaveTime_us(40);
	SetTIM3Channel3HighLeaveTime_us(40);
	HAL_Delay(500);
	//3.读取角度
	angle = ReadMotor2Angel();

	//4.电机失能
	SetTIM3Channel1HighLeaveTime_us(0);
	SetTIM3Channel2HighLeaveTime_us(0);
	SetTIM3Channel3HighLeaveTime_us(0);
	SetMotor2Enable(0);
    while(1);
}
/*************************************************************
** Function name:      AngleCalibrationFunc_Init
** Descriptions:       编码器角度校准
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void AngleCalibrationFunc_Init(void)
{
    //Motor1AngleCalibration();
    //Motor2AngleCalibration();
}




