#include "SPI1.h"
#include "main.h"

extern SPI_HandleTypeDef hspi1;





/*************************************************************
** Function name:       WriteSPI1Data
** Descriptions:        SPI1写数据
** Input parameters:    data：要发送的数据
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WriteSPI1Data(uint16_t data)
{
    HAL_SPI_Transmit(&hspi1,(uint8_t *)&data,1,1000);
}
/*************************************************************
** Function name:       ReadSPI1Data
** Descriptions:        SPI1读数据
** Input parameters:    None
** Output parameters:   None
** Returned value:      读取到的数据
** Remarks:             None
*************************************************************/
uint16_t ReadSPI1Data(void)
{
    uint16_t data;
    HAL_SPI_Receive(&hspi1,(uint8_t *)&data,1,1000);
    return data;
}
/*************************************************************
** Function name:       SetSPI1CS1
** Descriptions:        设置SPI1 片选1引脚电平
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetSPI1CS1(uint8_t leave)
{
    HAL_GPIO_WritePin(M1_CS_GPIO_Port,M1_CS_Pin, (GPIO_PinState)leave);
}

