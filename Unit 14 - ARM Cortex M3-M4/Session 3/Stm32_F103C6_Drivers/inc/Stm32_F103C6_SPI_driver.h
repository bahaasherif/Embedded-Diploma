/*
 * Stm32_F103C6_SPI_driver.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Bahaa
 */

#ifndef INC_STM32_F103C6_SPI_DRIVER_H_
#define INC_STM32_F103C6_SPI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include <stm32f103x6.h>
#include <Stm32_F103C6_gpio_driver.h>


//--------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------

typedef struct
{
	uint8_t TXE:1;			//Tx buffer empty interrupt
	uint8_t RXNE:1;			//Rx buffer not empty interrupt
	uint8_t ERRI:1;			//Error interrupt
	uint8_t RESERVED:5;
}S_IRQ_SRC;

typedef struct
{
	uint16_t	Device_Mode;					//@ref SPI_DEVICE_MODE
	uint16_t	Communication_MODE;				//@ref SPI_Communication_MODE
	uint16_t	Frame_Format;					//@ref SPI_Frame_Format
	uint16_t	Data_Size;						//@ref SPI_Data_Size
	uint16_t	CLK_Polarity;					//@ref SPI_CLK_Polarity
	uint16_t	CLK_Phase;						//@ref SPI_CLK_Phase
	uint16_t	NSS;							//@ref SPI_NSS
	uint16_t	SPI_Baudrate_Prescalar;			//@ref SPI_SPI_Baudrate_Prescalar
	uint16_t	IRQ_Enable;						//@ref SPI_IRQ_Enable
	void		(* P_IRQ_CallBack)(S_IRQ_SRC irq_src);
}SPI_Config_t;


//---------------------------------------------------------
//Macros Configuration References
//------------------------------------------------------------

//@ref SPI_DEVICE_MODE: CR1 Register
#define SPI_DEVICE_MODE_SLAVE					(0x00000000U)
#define SPI_DEVICE_MODE_MASTER					(uint32_t)(0x1U<<2)

//@ref SPI_Communication_MODE: CR1 Register
#define SPI_DIRECTION_2Lines					(0x00000000U)
#define SPI_DIRECTION_2Lines_RX_Only			(0x1U<<10)
#define SPI_DIRECTION_1Line_Receive_Only		(0x1U<<15)
#define SPI_DIRECTION_1Line_Transmit_Only		((0x1U<<15) | (0x1U<<14))

//@ref SPI_Frame_Format: CR1 register
#define SPI_Frame_Format_MSB_First				(0x00000000U)
#define SPI_Frame_Format_LSB_First				(0x1U<<7)

//@ref SPI_Data_Size: CR1 register
#define SPI_Data_Size_8Bit						(0x00000000U)
#define SPI_Data_Size_16Bit						(1<<11)

//@ref SPI_CLK_Polarity: CR1 register
#define SPI_CLK_Polarity_Low_idle				(0x00000000U)
#define SPI_CLK_Polarity_High_idle				(1<<1)

//@ref SPI_CLK_Phase: CR1 register
#define SPI_CLK_Phase_1st_Edge					(0x00000000U)
#define SPI_CLK_Phase_2nd_Edge					(1<<0)

//@ref SPI_NSS
//Hardware
#define SPI_NSS_HW_SLAVE						(0x00000000U)	//CR1
#define SPI_NSS_HW_MASTER_SS_Output_Enable		(1<<2)		//CR2
#define SPI_NSS_HW_MASTER_SS_Output_Disable		~(1<<2)	//CR2
//Software (Master or Slave)
#define SPI_NSS_SW_InternalSoft_Reset			(0x1U<<9)
#define SPI_NSS_SW_InternalSoft_Set				((1<<9) | (1<<8))

//@ref SPI_SPI_Baudrate_Prescalar: CR1
//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256
#define SPI_Baudrate_Prescalar_2				(0x00000000U)
#define SPI_Baudrate_Prescalar_4				(0b001<<3)
#define SPI_Baudrate_Prescalar_8				(uint32_t)(2<<3)
#define SPI_Baudrate_Prescalar_16				(0b011<<3)
#define SPI_Baudrate_Prescalar_32				(0b100<<3)
#define SPI_Baudrate_Prescalar_64				(0b101<<3)
#define SPI_Baudrate_Prescalar_128				(0b110<<3)
#define SPI_Baudrate_Prescalar_256				(0b111<<3)

//@ref SPI_IRQ_Enable: CR2
#define SPI_IRQ_Enable_None						(0x00000000U)
#define SPI_IRQ_Enable_TXEIE					(0x1U<<7)
#define SPI_IRQ_Enable_RXNEIE					(uint32_t)(1<<6)
#define SPI_IRQ_Enable_ERRIE					(0x1U<<5)



typedef enum{
	polling_Enable,
	polling_Disable
}Polling_Mechanism;

/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */
void MCAL_SPI_Init				(SPI_TypeDef* SPIx, SPI_Config_t* SPI_Config);
void MCAL_SPI_DeInit			(SPI_TypeDef* SPIx);
void MCAL_SPI_GPIO_Set_Pins		(SPI_TypeDef* SPIx);
void MCAL_SPI_SendData			(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,  Polling_Mechanism PollingEn);
void MCAL_SPI_ReceiveData		(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,  Polling_Mechanism PollingEn);
void MCAL_SPI_Tx_Rx				(SPI_TypeDef* SPIx, uint16_t* pTxBuffer,  Polling_Mechanism PollingEn);




#endif /* INC_STM32_F103C6_SPI_DRIVER_H_ */
