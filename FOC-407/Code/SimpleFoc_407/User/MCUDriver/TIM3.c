#include "TIM3.h"
#include "main.h"



#include "SEGGER_RTT_Conf.h"
#include "SEGGER_RTT.h"
#include "stdio.h"


extern TIM_HandleTypeDef htim3;

/*************************************************************
** Function name:       TIM3_Init
** Descriptions:        定时器3初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void TIM3_Init(void)
{
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,0);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,0);

    SetTIM3Channel1HighLeaveTime_us(0);
    SetTIM3Channel2HighLeaveTime_us(0);
    SetTIM3Channel3HighLeaveTime_us(0);
}
/*************************************************************
** Function name:       SetTIM3Channel1HighLeaveTime_us
** Descriptions:        设置定时器3通道1高电平时间（中央对齐模式一）
** Input parameters:    time：高电平时间 单位us 范围 0-100
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetTIM3Channel1HighLeaveTime_us(float time)
{
    uint32_t ccr;
    if (time < 0) {
        time = 0;
    }
    if (time > 50) {
        time = 50;
    }
    ccr = 2100 - 42 * time;
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, ccr);
}
/*************************************************************
** Function name:       SetTIM3Channel2HighLeaveTime_us
** Descriptions:        设置定时器3通道2高电平时间（中央对齐模式一）
** Input parameters:    time：高电平时间 单位us 范围 0-100
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetTIM3Channel2HighLeaveTime_us(float time)
{
    uint32_t ccr;
    if (time < 0) {
        time = 0;
    }
    if (time > 50) {
        time = 50;
    }
    ccr = 2100 - 42 * time;
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, ccr);
}
/*************************************************************
** Function name:       SetTIM3Channel3HighLeaveTime_us
** Descriptions:        设置定时器3通道3高电平时间（中央对齐模式一）
** Input parameters:    time：高电平时间 单位us 范围 0-100
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetTIM3Channel3HighLeaveTime_us(float time)
{
    uint32_t ccr;
    if (time < 0) {
        time = 0;
    }
    if (time > 50) {
        time = 50;
    }
    ccr = 2100 - 42 * time;
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3, ccr);
}





