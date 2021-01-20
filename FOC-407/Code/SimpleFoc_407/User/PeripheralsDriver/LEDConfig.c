#include "LEDConfig.h"

#include "LEDControl.h"
#include "LEDGPIO.h"


LED_EXPORT(gSysLed,1,SetLedLeave);



/*************************************************************
** Function name:       LEDConfigSetYellowLedStatus
** Descriptions:        设置绿色LED状态
** Input parameters:    status：LED状态 0：熄灭 1：常亮 2：闪烁
**                      cycle：周期单位秒
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDConfigSetSysLedStatus(uint8_t status, float cycle)
{
    SetLedStatus(&gSysLed,status,cycle);
}
/*************************************************************
** Function name:       LEDConfig_Init
** Descriptions:        led初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDConfig_Init(void)
{
    LEDConfigSetSysLedStatus(LEDConfig_Toggle,1);
}
/*************************************************************
** Function name:       LEDConfig_Loop
** Descriptions:        led周期循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDConfig_Loop(void)
{
    LEDRunCycle(&gSysLed);
}

