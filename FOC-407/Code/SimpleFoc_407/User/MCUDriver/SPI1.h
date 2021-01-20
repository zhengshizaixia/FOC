#ifndef SPI1_h
#define SPI1_h

#include "stdint.h"


void WriteSPI1Data(uint16_t data);
uint16_t ReadSPI1Data(void);
void SetSPI1CS1(uint8_t leave);


#endif /* SPI1_h */
