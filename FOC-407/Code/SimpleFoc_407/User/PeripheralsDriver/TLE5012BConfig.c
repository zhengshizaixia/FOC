#include "TLE5012BConfig.h"
#include "TLE5012B.h"
#include "SPI1.h"
#include "SPI2.h"
#include "Timer.h"



TLE5012B_EXPORT(gMorot1Encoder,49.549850f,SetSPI1CS1,WriteSPI2Data,ReadSPI2Data,rt_hw_us_delay)
TLE5012B_EXPORT(gMorot2Encoder,10.580157f,SetSPI2CS1,WriteSPI1Data,ReadSPI1Data,rt_hw_us_delay)




/*************************************************************
** Function name:       ReadMotor1Angel
** Descriptions:        获取电机1角度值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
float ReadMotor1Angel(void)
{
    return ReadTLE5012BAngle(&gMorot1Encoder);
}
/*************************************************************
** Function name:       ReadMotor2Angel
** Descriptions:        获取电机2角度值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
float ReadMotor2Angel(void)
{
    return ReadTLE5012BAngle(&gMorot2Encoder);
}



