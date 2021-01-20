#ifndef TIM4_h
#define TIM4_h

#include "stdint.h"


void TIM4_Init(void);
void SetTIM4Channel1HighLeaveTime_us(float time);
void SetTIM4Channel2HighLeaveTime_us(float time);
void SetTIM4Channel3HighLeaveTime_us(float time);
#endif /* TIM4_h */
