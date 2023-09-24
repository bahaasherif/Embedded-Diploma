/*
 * Stm32_F103C6_SPI_driver.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Bahaa
 */


#include <Stm32_F103C6_SPI_driver.h>

//-------------------------------------------------
// GENERIC VARIABLES
//-------------------------------------------------
SPI_Config_t* Global_SPI_Config[2] = {NULL,NULL};

//-------------------------------------------------
// GENERIC MACROS
//-------------------------------------------------
#define SPI1_Index		0
#define SPI2_Index		1

#define   SPI_SR_RXNE            ((uint8_t)0x01)         //Bit 0 RXNE: Receive buffer not empty
#define   SPI_SR_TXE             ((uint8_t)0x02)         //Bit 1 TXE: Transmit buffer empty

//-------------------------------------------------
// GENERIC FUNCTIONS
//-------------------------------------------------

void MCAL_SPI_Init				(SPI_TypeDef* SPIx, SPI_Config_t* SPI_Config)
{
	uint16_t tmpreg_CR1=0;
	uint16_t tmpreg_CR2=0;

	if(SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_Index] = SPI_Config;
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		Global_SPI_Config[SPI2_Index] = SPI_Config;
		RCC_SPI2_CLK_EN();
	}
	//SPI enable
	tmpreg_CR1 = (0x1U<<6);

	//Master or slave
	tmpreg_CR1 |= SPI_Config->Device_Mode;

	//communication mode
	tmpreg_CR1 |= SPI_Config->Communication_MODE;

	//SPI frame format
	tmpreg_CR1 |= SPI_Config->Frame_Format;

	//data size
	tmpreg_CR1 |= SPI_Config->Data_Size;

	//polarity
	tmpreg_CR1 |= SPI_Config->CLK_Polarity;

	//phase
	tmpreg_CR1 |= SPI_Config->CLK_Phase;

	//NSS
	if(SPI_Config->NSS == SPI_NSS_HW_MASTER_SS_Output_Enable)
		tmpreg_CR2 |= SPI_Config->NSS;
	else if((SPI_Config->NSS == SPI_NSS_HW_MASTER_SS_Output_Disable) || (SPI_Config->NSS == SPI_NSS_HW_SLAVE))
		tmpreg_CR2 &= SPI_Config->NSS;
	else
		tmpreg_CR1 |= SPI_Config->NSS;

	//baudrate
	tmpreg_CR1 |= SPI_Config->SPI_Baudrate_Prescalar;

	//interrupt
	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_None)
	{
		tmpreg_CR2 |= SPI_Config->IRQ_Enable;

		if(SPIx == SPI1)
			NVIC_IRQ35_SPI1_Enable;
		else if (SPIx == SPI2)
			NVIC_IRQ36_SPI2_Enable;
	}

	SPIx->SPI_CR1 = tmpreg_CR1;
	SPIx->SPI_CR2 = tmpreg_CR2;
}

void MCAL_SPI_DeInit			(SPI_TypeDef* SPIx)
{
	if(SPIx == SPI1)
	{
		RCC_SPI1_RESET();
		NVIC_IRQ35_SPI1_Disable;
	}
	else if(SPIx == SPI2)
	{
		RCC_SPI2_RESET();
		NVIC_IRQ36_SPI2_Disable;
	}
}

void MCAL_SPI_GPIO_Set_Pins		(SPI_TypeDef* SPIx)
{
	GPIO_PinConfig_t PinCfg ;

	if(SPIx == SPI1)
	{
		//PA4: SPI1_NSS
		//PA5: SPI1_SCK
		//PA6: SPI_MISO
		//PA7: SPI_MOSI

		if(Global_SPI_Config[SPI1_Index]->Device_Mode == SPI_DEVICE_MODE_MASTER)
		{
			//PA4: SPI1_NSS
			switch (Global_SPI_Config[SPI1_Index]->NSS)
			{
			case SPI_NSS_HW_MASTER_SS_Output_Enable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			case SPI_NSS_HW_MASTER_SS_Output_Disable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			default:
				break;
			}

			//PA5: SPI1_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA6: SPI_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA7: SPI_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		else if(Global_SPI_Config[SPI1_Index]->Device_Mode == SPI_DEVICE_MODE_SLAVE)
		{
			//PA4: SPI1_NSS
			if(Global_SPI_Config[SPI1_Index]->NSS == SPI_NSS_HW_SLAVE)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}

			//PA5: SPI1_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA6: SPI_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA7: SPI_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}
	else if(SPIx == SPI2)
	{
		//PB12: SPI2_NSS
		//PB13: SPI2_SCK
		//PB14: SPI2_MISO
		//PB15: SPI2_MOSI
		if(Global_SPI_Config[SPI2_Index]->Device_Mode == SPI_DEVICE_MODE_MASTER)
		{
			//PB12: SPI2_NSS
			switch (Global_SPI_Config[SPI2_Index]->NSS)
			{
			case SPI_NSS_HW_MASTER_SS_Output_Enable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			case SPI_NSS_HW_MASTER_SS_Output_Disable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			default:
				break;
			}

			//PB13: SPI2_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB14: SPI2_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB15: SPI2_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
		else if(Global_SPI_Config[SPI2_Index]->Device_Mode == SPI_DEVICE_MODE_SLAVE)
		{
			//PB12: SPI2_NSS
			if(Global_SPI_Config[SPI2_Index]->NSS == SPI_NSS_HW_SLAVE)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
			}

			//PB13: SPI2_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB14: SPI2_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB15: SPI2_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
	}
}

void MCAL_SPI_SendData			(SPI_TypeDef* SPIx, uint16_t* pTxBuffer, Polling_Mechanism PollingEn)
{
	if(PollingEn == polling_Enable)
		while(!((SPIx->SPI_SR) & SPI_SR_TXE));

	SPIx->SPI_DR = *pTxBuffer;
}

void MCAL_SPI_ReceiveData		(SPI_TypeDef* SPIx, uint16_t* pTxBuffer, Polling_Mechanism PollingEn)
{
	if(PollingEn == polling_Enable)
		while(!((SPIx->SPI_SR) & SPI_SR_RXNE) );

	*pTxBuffer = SPIx->SPI_DR;
}

void MCAL_SPI_Tx_Rx				(SPI_TypeDef* SPIx, uint16_t* pTxBuffer, Polling_Mechanism PollingEn)
{
	if(PollingEn == polling_Enable)
		while(!((SPIx->SPI_SR) & SPI_SR_TXE));
	SPIx->SPI_DR = *pTxBuffer;

	if(PollingEn == polling_Enable)
		while(!((SPIx->SPI_SR) & SPI_SR_RXNE) );
	*pTxBuffer = SPIx->SPI_DR;
}


//----------------------------------------------
//ISR
//---------------------------------------------

void SPI_IRQHandler(void)
{
	S_IRQ_SRC irq_src;
	irq_src.TXE =  (SPI1->SPI_SR & (1<<1) >> 1 );
	irq_src.RXNE =  (SPI1->SPI_SR & (1<<0) >> 0 );
	irq_src.ERRI =  (SPI1->SPI_SR & (1<<4) >> 4 );
	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}

void SPI2_IRQHandler(void)
{
	S_IRQ_SRC irq_src;
	irq_src.TXE = (SPI2->SPI_SR & (1<<1) >> 1 );
	irq_src.RXNE = (SPI2->SPI_SR & (1<<0) >> 0 );
	irq_src.ERRI = (SPI2->SPI_SR & (1<<4) >> 4 );
	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);
}

