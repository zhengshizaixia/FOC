#include "PerDriverMain.h"

#include "LEDConfig.h"
#include "SvpwmConfig.h"
#include "FOCConfig.h"

#include "Timer.h"
/*************************************************************
** Function name:      PerDriverMain_Init
** Descriptions:       外设初始化
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void PerDriverMain_Init(void)
{
	LEDConfig_Init();
	FOCConfig_Init();
}

/*************************************************************
** Function name:      PerDriverMain_Loop
** Descriptions:       外设循环
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void PerDriverMain_Loop(void)
{
	LEDConfig_Loop();
	FOCConfig_Loop();
}
