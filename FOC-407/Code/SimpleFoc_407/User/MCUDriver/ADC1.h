#ifndef ADC1_h
#define ADC1_h

#include "stdint.h"

void ADC1_Init(void);
int32_t GetADC1ChannelXValue(uint8_t channel);
void GetMotor1ADCValue(void);
void GetMotor2ADCValue(void);

#endif /* ADC1_h */
