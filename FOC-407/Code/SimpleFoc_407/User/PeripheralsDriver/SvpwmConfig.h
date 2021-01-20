#ifndef SvpwmConfig_h
#define SvpwmConfig_h

#include "stdint.h"


void SvpwmConfig_Loop(void);

uint8_t GetMotor1SVPWMSector(void);
uint8_t GetMotor2SVPWMSector(void);
void Motor1SvpwmGenerate(float uα,float uβ);
void Motor2SvpwmGenerate(float uα,float uβ);
#endif /* SvpwmConfig_h */
