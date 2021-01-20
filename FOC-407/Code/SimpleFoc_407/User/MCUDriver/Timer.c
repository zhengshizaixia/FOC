#include "Timer.h"
#include "main.h"
uint32_t gMS_TimeCNT;

//us must < 1000!!!
void rt_hw_us_delay(uint32_t us)
{
    uint32_t delta;

    us = us * (SysTick->LOAD / (1000 / HAL_GetTickFreq()));
    delta = SysTick->VAL;

    while (delta - SysTick->VAL < us) continue;
}
