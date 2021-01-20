#include "MCUDriverMain.h"
#include "TIM3.h"
#include "TIM4.h"
#include "ADC1.h"
/*************************************************************
** Function name:      MCUDriverMain_Init
** Descriptions:       芯片初始化
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void MCUDriverMain_Init(void)
{
    TIM3_Init();
    TIM4_Init();
	ADC1_Init();
}

/*************************************************************
** Function name:      MCUDriverMain_Loop
** Descriptions:       芯片循环
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void MCUDriverMain_Loop(void)
{
	
}

