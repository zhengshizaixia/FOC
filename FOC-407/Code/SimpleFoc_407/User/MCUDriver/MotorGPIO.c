#include "MotorGPIO.h"
#include "main.h"

/*************************************************************
** Function name:       SetMotor1Enable
** Descriptions:        设置电机1使能标志
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotor1Enable(uint8_t isEnable)
{
    HAL_GPIO_WritePin(M1_Enable_GPIO_Port,M1_Enable_Pin, (GPIO_PinState)isEnable);
}

/*************************************************************
** Function name:       SetMotor2Enable
** Descriptions:        设置电机2使能标志
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotor2Enable(uint8_t isEnable)
{
    HAL_GPIO_WritePin(M2_Enable_GPIO_Port,M2_Enable_Pin, (GPIO_PinState)isEnable);
}

