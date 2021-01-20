#ifndef TLE5012B_h
#define TLE5012B_h

#include "stdint.h"



struct STLE5012B_Struct
{
    /* data */
    float angleOffect;
    void (*SetCSLeave)(uint8_t leave);
    void (*SPIWrite)(uint16_t data);
    uint16_t (*SPIRead)(void);
	void (*Delay_us)(uint32_t us);
};

typedef struct STLE5012B_Struct TLE5012B_Struct;
typedef TLE5012B_Struct *PTLE5012B_Struct;




/*************************************************************
** Function name:       TLE5012B_EXPORT
** Descriptions:        声明一个TLE5012B磁编码器对象
** Input parameters:    x:名字
**                      xSetCSLeave：设置片选引脚电平
**                      xSPIWrite：SPI写函数
**                      xSPIRead: SPI读函数
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
#define TLE5012B_EXPORT(x,xAngleOffect,xSetCSLeave,xSPIWrite,xSPIRead,xDelay_us)       	\
TLE5012B_Struct x = {                                          				\
    .angleOffect = xAngleOffect,                            \
    .SetCSLeave = xSetCSLeave,                              \
    .SPIWrite = xSPIWrite,                                  \
    .SPIRead = xSPIRead,                                    \
	.Delay_us = xDelay_us,									\
};


float ReadTLE5012BAngle(PTLE5012B_Struct pTLE5012B);

#endif /* TLE5012B_h */
