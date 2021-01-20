#include "SPI2.h"
#include "main.h"

extern SPI_HandleTypeDef hspi2;





/*************************************************************
** Function name:       WriteSPI2Data
** Descriptions:        SPI2写数据
** Input parameters:    data：要发送的数据
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WriteSPI2Data(uint16_t data)
{
    HAL_SPI_Transmit(&hspi2,(uint8_t *)&data,1,1000);
}
/*************************************************************
** Function name:       ReadSPI2Data
** Descriptions:        SPI2读数据
** Input parameters:    None
** Output parameters:   None
** Returned value:      读取到的数据
** Remarks:             None
*************************************************************/
uint16_t ReadSPI2Data(void)
{
    uint16_t data;
    HAL_SPI_Receive(&hspi2,(uint8_t *)&data,1,1000);
    return data;
}
/*************************************************************
** Function name:       SetSPI2CS2
** Descriptions:        设置SPI2 片选2引脚电平
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetSPI2CS1(uint8_t leave)
{
    HAL_GPIO_WritePin(M2_CS_GPIO_Port,M2_CS_Pin, (GPIO_PinState)leave);
}

