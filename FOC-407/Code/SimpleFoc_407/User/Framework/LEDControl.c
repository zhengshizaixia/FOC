#include "LEDControl.h"

volatile uint32_t gLED_TimeCNT;

/*************************************************************
** Function name:       LEDON
** Descriptions:        LED常亮
** Input parameters:    gLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLEDON(PLEDControl_Struct gLED)
{
    gLED->state = LEDState_ON;
    gLED->SetLEDLeave(gLED->onLeave);
}
/*************************************************************
** Function name:       LEDFF
** Descriptions:        LED常灭
** Input parameters:    gLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLEDOFF(PLEDControl_Struct gLED)
{
    gLED->state = LEDState_OFF;
    gLED->SetLEDLeave(!(gLED->onLeave));
}
/*************************************************************
** Function name:       LEDToggle
** Descriptions:        LED闪烁
** Input parameters:    gLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDToggle(PLEDControl_Struct gLED)
{
    gLED->onoff = !gLED->onoff;
    gLED->SetLEDLeave(gLED->onoff);
}
/*************************************************************
** Function name:       LEdRunCycle
** Descriptions:        LED周期执行函数
** Input parameters:    gLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDRunCycle(PLEDControl_Struct gLED)
{
    if(LED_TIMEOUT(gLED->cycle * 1000,gLED->startTime)) {
        gLED->startTime = LED_GETTIME();
        if(gLED->state == LEDState_Toggle) {
            LEDToggle(gLED);
        }
    }
}
/*************************************************************
** Function name:       LEDFlashing
** Descriptions:        LED闪烁
** Input parameters:    gLED:SLEDControl_Struct结构体指针
**                      cycle:闪烁周期(单位ms)
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLEDFlashing(PLEDControl_Struct gLED,float cycle)
{
    gLED->state = LEDState_Toggle;
    gLED->cycle = cycle;
}

/*************************************************************
** Function name:       SetLedStatus
** Descriptions:        设置LEDz状态
** Input parameters:    gLED:SLEDControl_Struct结构体指针
**                      status:LED状态
**                      cycle:闪烁周期(单位ms)
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLedStatus(PLEDControl_Struct gLED,uint8_t status,float cycle)
{
    switch(status) {
        case LEDState_OFF:
            SetLEDOFF(gLED);
            break;
        case LEDState_ON:
            SetLEDON(gLED);
            break;
        case LEDState_Toggle:
            SetLEDFlashing(gLED,cycle);
            break;
    }
}















