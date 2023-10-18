/*
 * Stm32_F1103C6_RCC_driver.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Bahaa
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

//-------------------------------------------------
// INCLUDES
//-------------------------------------------------
#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"

//-------------------------------------------------
// MACROS
//-------------------------------------------------

#define  HSE_CLK			(uint32_t)16000000
#define  HSI_CLK			(uint32_t)8000000

//-------------------------------------------------
// APIs supported by "MCAL RCC DRIVER"
//-------------------------------------------------
uint32_t MCAL_RCC_Get_SYSCLK_FREQ(void);
uint32_t MCAL_RCC_Get_HCLK_FREQ(void);
uint32_t MCAL_RCC_Get_PCLK1_FREQ(void);
uint32_t MCAL_RCC_Get_PCLK2_FREQ(void);

#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
