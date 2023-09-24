/*
 * Stm32_F1103C6_USART_driver.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Bahaa
 */

#ifndef INC_STM32_F103C6_USART_DRIVER_H_
#define INC_STM32_F103C6_USART_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "Stm32_F103C6_RCC_driver.h"

//--------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------

typedef struct
{
	uint8_t		USART_MODE;				//@ref UART_MODE_DEFINE
	uint32_t	BAUDRATE;				//@ref UART_BaudRate_DEFINE
	uint8_t		Payload_Length;			//@ref UART_PayloadLength_DEFINE
	uint8_t		Parity;					//@ref UART_Parity_DEFINE
	uint8_t		StopBits;				//@ref UART_StopBits_DEFINE
	uint8_t		FlowCTRL;				//@ref UART_FlowCTRL_DEFINE
	uint8_t		IRQ_En;					//@ref UART_IRQ_EN_DEFINE
	void		(* P_IRQ_CallBack)(void);
}UART_Config_t;


//---------------------------------------------------------
//Macros Configuration References
//------------------------------------------------------------
//@ref UART_MODE_DEFINE
#define UART_MODE_TX		(uint32_t)(1<<3)
#define UART_MODE_RX		(uint32_t)(1<<2)
#define UART_MODE_TX_RX		(uint32_t)(1<<3 | 1<<2)

//@ref UART_BaudRate_DEFINE
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_2250000		2250000
#define UART_BaudRate_4500000		4500000

//@ref UART_PayloadLength_DEFINE
#define UART_PayloadLength_8b		(uint32_t)(0)
#define UART_PayloadLength_9b		(uint32_t)(1<<12)

//@ref UART_Parity_DEFINE
#define UART_Parity_Disable			(uint32_t)(0)
#define UART_Parity_Even			(uint32_t)(1<<10)
#define UART_Parity_Odd				(uint32_t)(1<<10 | 1<<9)

//@ref UART_StopBits_DEFINE
//Bits 13:12 STOP: STOP bits
//These bits are used for programming the stop bits.
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
#define UART_StopBits_1b		(uint32_t)(0)
#define UART_StopBits_half		(uint32_t)(1<<12)
#define UART_StopBits_2b		(uint32_t)(2<<12)
#define UART_StopBits_1_half	(uint32_t)(3<<12)

//@ref UART_FlowCTRL_DEFINE
#define UART_FlowCTRL_None		(uint32_t)(0)
#define UART_FlowCTRL_RTS		(uint32_t)(1<<8)
#define UART_FlowCTRL_CTS		(uint32_t)(1<<9)
#define UART_FlowCTRL_RTS_CTS	(uint32_t)(1<<8 | 1<<9)

//@ref UART_IRQ_EN_DEFINE
#define UART_IRQ_EN_None		(uint32_t)(0)
#define UART_IRQ_EN_TXE			(uint32_t)(1<<7)
#define UART_IRQ_EN_TC			(uint32_t)(1<<6)
#define UART_IRQ_EN_RXNEIE		(uint32_t)(1<<5)
#define UART_IRQ_EN_PE			(uint32_t)(1<<8)


enum Polling_Mechanism {Enable,Disable};

#define USARTDIV(PCLK,BAUD)				(uint32_t)(PCLK / (16 * BAUD))
#define USARTDIV_MUL100(PCLK,BAUD)		(uint32_t)((25*PCLK) / (4 * BAUD))
#define Mantissa_MUL100(PCLK,BAUD)		(uint32_t)(USARTDIV(PCLK,BAUD) * 100)
#define DIV_MANTISSA(PCLK,BAUD)			(uint32_t)(USARTDIV(PCLK,BAUD))
#define DIV_FRACTION(PCLK,BAUD)			(uint32_t)(( (USARTDIV_MUL100(PCLK,BAUD) - Mantissa_MUL100(PCLK,BAUD) ) * 16) / 100)
#define UART_BRR_REG(PCLK,BAUD)			((DIV_MANTISSA(PCLK,BAUD) << 4) | ((DIV_FRACTION(PCLK,BAUD)) & 0xF))

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_UART_Init 		(USART_TypeDef *USARTx, UART_Config_t *UART_Config);
void MCAL_UART_DeInit 		(USART_TypeDef *USARTx);
void MCAL_UART_GPIO_SetPins (USART_TypeDef *USARTx);
void MCAL_UART_SendData 	(USART_TypeDef *USARTx, uint16_t *pTxBuffer, enum Polling_Mechanism PollingEn);
void MCAL_UART_ReceiveData 	(USART_TypeDef *USARTx, uint16_t *pTxBuffer, enum Polling_Mechanism PollingEn);
void MCAL_UART_WAIT_TC 		(USART_TypeDef *USARTx);



#endif /* INC_STM32_F103C6_USART_DRIVER_H_ */
