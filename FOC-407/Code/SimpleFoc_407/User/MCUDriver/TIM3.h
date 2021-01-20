#ifndef TIM3_h
#define TIM3_h

#include "stdint.h"


void TIM3_Init(void);
void SetTIM3Channel1HighLeaveTime_us(float time);
void SetTIM3Channel2HighLeaveTime_us(float time);
void SetTIM3Channel3HighLeaveTime_us(float time);
#endif /* TIM3_h */
