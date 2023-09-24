/*
 * Stm32_F1103C6_gpio_driver.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Bahaa
 */

#ifndef INC_STM32_F1103C6_GPIO_DRIVER_H_
#define INC_STM32_F1103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include <stm32f103x6.h>

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint16_t GPIO_PinNumber ; 	//set at @ref GPIO_PINS_define
	uint8_t GPIO_Mode ;			//set at @ref GPIO_Mode_define
	uint8_t GPIO_Output_Speed ; //set at @ref GPIO_Speed_define
}GPIO_PinConfig_t;

//@ref GPIO_PIN_state
#define GPIO_PIN_set 	1
#define GPIO_PIN_reset 	0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_EN		1
#define GPIO_RETURN_LOCK_ERROR 	0

//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref GPIO_PINS_define
#define GPIO_PIN_0		((uint16_t)0x0001) //Pin 0 selected
#define GPIO_PIN_1		((uint16_t)0x0002) //Pin 1 selected
#define GPIO_PIN_2		((uint16_t)0x0004) //Pin 2 selected
#define GPIO_PIN_3		((uint16_t)0x0008) //Pin 3 selected
#define GPIO_PIN_4		((uint16_t)0x0010) //Pin 4 selected
#define GPIO_PIN_5		((uint16_t)0x0020) //Pin 5 selected
#define GPIO_PIN_6		((uint16_t)0x0040) //Pin 6 selected
#define GPIO_PIN_7		((uint16_t)0x0080) //Pin 7 selected
#define GPIO_PIN_8		((uint16_t)0x0100) //Pin 8 selected
#define GPIO_PIN_9		((uint16_t)0x0200) //Pin 9 selected
#define GPIO_PIN_10		((uint16_t)0x0400) //Pin 10 selected
#define GPIO_PIN_11		((uint16_t)0x0800) //Pin 11 selected
#define GPIO_PIN_12		((uint16_t)0x1000) //Pin 12 selected
#define GPIO_PIN_13 	((uint16_t)0x2000) //Pin 13 selected
#define GPIO_PIN_14		((uint16_t)0x4000) //Pin 14 selected
#define GPIO_PIN_15		((uint16_t)0x8000) //Pin 15 selected
#define GPIO_PIN_ALL	((uint16_t)0xFFFF) //All Pins selected

#define GPIO_PIN_MASK		0x0000FFFFu

//@ref GPIO_Mode_define
#define GPIO_MODE_ANALOG			0x00000000u
#define GPIO_MODE_INPUT_FLO			0x00000001u
#define GPIO_MODE_INPUT_PU			0x00000002u
#define GPIO_MODE_INPUT_PD			0x00000003u
#define GPIO_MODE_OUTPUT_PP			0x00000004u
#define GPIO_MODE_OUTPUT_OD			0x00000005u
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006u
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007u
#define GPIO_MODE_AF_INPUT			0x00000008u

//@ref GPIO_Speed_define
#define GPIO_SPEED_10M			0x00000001u
#define GPIO_SPEED_2M			0x00000002u
#define GPIO_SPEED_50M			0x00000003u



/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init 	(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit	(GPIO_TypeDef *GPIOx);

//Read APIs
uint8_t MCAL_GPIO_ReadPin	(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort	(GPIO_TypeDef *GPIOx);

//Write APIs
void MCAL_GPIO_WritePin	(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort	(GPIO_TypeDef *GPIOx, uint16_t Value);

void MCAL_GPIO_TooglePin	(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin	(GPIO_TypeDef *GPIOx, uint16_t PinNumber);


#endif /* INC_STM32_F1103C6_GPIO_DRIVER_H_ */
