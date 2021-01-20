#include "TLE5012B.h"
#include "main.h"

#include "SEGGER_RTT_Conf.h"
#include "SEGGER_RTT.h"
#include "stdio.h"
/*************************************************************
** Function name:       ReadTLE5012BAngle
** Descriptions:        获取MS730角度值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
float ReadTLE5012BAngle(PTLE5012B_Struct pTLE5012B)
{
	uint16_t data = 0xffff;
	float angle;

	pTLE5012B->SetCSLeave(0);
	pTLE5012B->Delay_us(1);
	pTLE5012B->SPIWrite(0x8021);
	data = pTLE5012B->SPIRead();
	pTLE5012B->SetCSLeave(1);
	pTLE5012B->Delay_us(1);

	data &= 0x7fff;
	angle = data / 32767.0f * 360.0f;
	//printf("pre:%f\r\n",angle);
	angle = angle - pTLE5012B->angleOffect;
	if (angle < 0) {
		angle = angle + 360.0f;
	}
	//printf("calibration:%f\r\n",angle);
	//printf("8:%f\r\n",angle);
    return  angle;
}




