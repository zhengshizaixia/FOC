#ifndef SPI2_h
#define SPI2_h

#include "stdint.h"


void WriteSPI2Data(uint16_t data);
uint16_t ReadSPI2Data(void);
void SetSPI2CS1(uint8_t leave);

#endif /* SPI2_h */
