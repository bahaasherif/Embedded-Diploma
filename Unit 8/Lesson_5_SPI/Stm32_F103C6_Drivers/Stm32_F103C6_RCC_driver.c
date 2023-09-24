/*
 * Stm32_F1103C6_RCC_driver.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Bahaa
 */


#include <Stm32_F103C6_RCC_driver.h>

//Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB low-speed clock
//(PCLK1).
//Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
const uint8_t APB_Prescalar[8u] = {0,0,0,0,1,2,3,4};

//Bits 7:4 HPRE: AHB prescaler
//Set and cleared by software to control the division factor of the AHB clock.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
const uint8_t AHB_Prescalar[16u] = {0,0,0,0,0,0,0,1,2,3,4,6,7,8};

uint32_t MCAL_RCC_Get_SYSCLK_FREQ(void)
{
	/*Bits 3:2 SWS: System clock switch status
	Set and cleared by hardware to indicate which clock source is used as system clock.
	00: HSI oscillator used as system clock
	01: HSE oscillator used as system clock
	10: PLL used as system clock
	11: not applicable*/

	switch ((RCC->CFGR >> 2 ) & 0b11)
	{
		case 0:
			return HSI_CLK;
			break;
		case 1:
			return HSE_CLK;
			break;
		case 2:
			return 16000000;

			break;

		default:
			return 0;
			break;

		}
		return 0;
}

uint32_t MCAL_RCC_Get_HCLK_FREQ(void)
{
	return MCAL_RCC_Get_SYSCLK_FREQ() >> AHB_Prescalar[(RCC->CFGR >> 4) & 0b1111];
}

uint32_t MCAL_RCC_Get_PCLK1_FREQ(void)
{
	return MCAL_RCC_Get_HCLK_FREQ()	>> APB_Prescalar[(RCC->CFGR >> 8) & 0b111];
}

uint32_t MCAL_RCC_Get_PCLK2_FREQ(void)
{
	return MCAL_RCC_Get_HCLK_FREQ()	>> APB_Prescalar[(RCC->CFGR >> 11) & 0b111];
}
