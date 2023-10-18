/*
 * Stm32_F1103C6_USART_driver.c
 *
 *  Created on: Sep 21, 2023
 *      Author: Bahaa
 */


#include <Stm32_F103C6_USART_driver.h>

//-------------------------------------------------
// GENERIC VARIABLES
//-------------------------------------------------

UART_Config_t *Global_UART_Config = NULL;


//-------------------------------------------------
// GENERIC FUNCTIONS
//-------------------------------------------------
void MCAL_UART_Init 		(USART_TypeDef *USARTx, UART_Config_t *UART_Config)
{
	uint32_t pclk , BRR ;
	Global_UART_Config = UART_Config;

	//enable clock
	if(USARTx == USART1)
		RCC_USART1_CLK_EN();
	else if(USARTx == USART2)
		RCC_USART2_CLK_EN();
	else if(USARTx == USART3)
		RCC_USART3_CLK_EN();

	//enable USART Module
	USARTx->CR1 |= 1<<13 ;

	//enable TX and Rx: USART_MODE
	USARTx->CR1 |= UART_Config->USART_MODE;

	//Payload
	USARTx->CR1 |= UART_Config->Payload_Length;

	//Parity
	USARTx->CR1 |= UART_Config->Parity;

	//Stop Bits
	USARTx->CR2 |= UART_Config->StopBits;

	//Flow Control
	USARTx->CR3 |= UART_Config->FlowCTRL;

	//Baud Rate
	//PCLK1 for USART 2 ,3
	//PCLK2 for USART 1

	if(USARTx == USART1)
		pclk = MCAL_RCC_Get_PCLK2_FREQ();
	else
		pclk = MCAL_RCC_Get_PCLK1_FREQ();

	BRR = UART_BRR_REG(pclk , UART_Config->BAUDRATE);
	USARTx->BRR = BRR;


	//enable Interrupt
	if(UART_Config->IRQ_En != UART_IRQ_EN_None)
	{
		USARTx->CR1 |= (UART_Config->IRQ_En);

		//enable NVIC for USARTx IRQ
		if(USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;
		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;
		else if (USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}

}


void MCAL_UART_DeInit 		(USART_TypeDef *USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_RESET();
		NVIC_IRQ37_USART1_Disable;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_RESET();
		NVIC_IRQ38_USART2_Disable;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_RESET();
		NVIC_IRQ39_USART3_Disable;
	}
}


void MCAL_UART_GPIO_SetPins (USART_TypeDef *USARTx)
{
	GPIO_PinConfig_t PinCfg ;
	//USART1
	if(USARTx == USART1)
	{
		//PA9  	TX  MODE:Alternate function PushPull
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		//PA10	RX	MODE:Input floating pull up
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		//PA11	CTS	Mode:Input floating pull up
		if((Global_UART_Config->FlowCTRL == UART_FlowCTRL_CTS) || (Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS_CTS))
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

		//PA12	RTS	Mode:alternate function pushpull
		if((Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS) || (Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS_CTS))
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

	}

	//USART2
	if(USARTx == USART1)
	{
		//PA2  	TX  MODE:Alternate function PushPull
		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		//PA3	RX	MODE:Input floating pull up
		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		//PA0	CTS	Mode:Input floating pull up
		if((Global_UART_Config->FlowCTRL == UART_FlowCTRL_CTS) || (Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS_CTS))
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_0;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

		//PA1	RTS	Mode:alternate function pushpull
		if((Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS) || (Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS_CTS))
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_1;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

	}

	//USART3
	if(USARTx == USART1)
	{
		//PB10  	TX  MODE:Alternate function PushPull
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		//PB11	RX	MODE:Input floating pull up
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		PinCfg.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		//PB13	CTS	Mode:Input floating pull up
		if((Global_UART_Config->FlowCTRL == UART_FlowCTRL_CTS) || (Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS_CTS))
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}

		//PB14	RTS	Mode:alternate function pushpull
		if((Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS) || (Global_UART_Config->FlowCTRL == UART_FlowCTRL_RTS_CTS))
		{
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}

	}
}


void MCAL_UART_SendData 	(USART_TypeDef *USARTx, uint16_t *pTxBuffer, enum Polling_Mechanism PollingEn)
{
	if(PollingEn == ENABLE)
		while (!(USARTx->SR & (1<<7)));

	if(Global_UART_Config->Payload_Length == UART_PayloadLength_9b)
		USARTx->DR |= (*pTxBuffer & (uint16_t)0x01FF);
	else if(Global_UART_Config->Payload_Length == UART_PayloadLength_8b)
		USARTx->DR |= (*pTxBuffer & (uint8_t)0xFF);

}


void MCAL_UART_ReceiveData 	(USART_TypeDef *USARTx, uint16_t *pTxBuffer, enum Polling_Mechanism PollingEn)
{
	if(PollingEn == ENABLE)
		while(!(USARTx->SR & (1<<5)));

	if(Global_UART_Config->Payload_Length == UART_PayloadLength_9b)
	{
		if(Global_UART_Config->Payload_Length == UART_Parity_Disable)
			*((uint16_t *)pTxBuffer) = USARTx->DR;
		else
			*((uint16_t *)pTxBuffer) = (USARTx->DR & (uint8_t)0xFF);
	}

	else
	{
		if(Global_UART_Config->Payload_Length == UART_Parity_Disable)
			*((uint16_t *)pTxBuffer) = (USARTx->DR & (uint8_t)0xFF);
		else
			*((uint16_t *)pTxBuffer) = (USARTx->DR & (uint8_t)0x7F);
	}
}


void MCAL_UART_WAIT_TC 		(USART_TypeDef *USARTx)
{
	while(!(USARTx->SR & (1<<6)));
}


//ISR
void USART1_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART2_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART3_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}



