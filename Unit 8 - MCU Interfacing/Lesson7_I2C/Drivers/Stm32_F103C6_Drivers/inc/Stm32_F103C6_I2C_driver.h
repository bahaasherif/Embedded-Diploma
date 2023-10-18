/*
 * Stm32_F103C6_I2C_driver.h
 *
 *  Created on: Sep 26, 2023
 *      Author: Bahaa
 */

#ifndef INC_STM32_F103C6_I2C_DRIVER_H_
#define INC_STM32_F103C6_I2C_DRIVER_H_


//-----------------------------
//Includes
//-----------------------------
#include <stm32f103x6.h>
#include <Stm32_F103C6_gpio_driver.h>
#include <Stm32_F103C6_RCC_driver.h>


//--------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------

typedef struct
{
	uint32_t	Enable_DUAL_ADD;
	uint8_t		Slave_First_ADD;
	uint8_t		Slave_Second_ADD;
	uint32_t	Slave_ADD_Mode;		//@ref I2C_SLAVE_ADD_Mode_DEFINE
}I2C_slave_address_t;

typedef enum
{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADD_MATCHED,
	I2C_EV_DATA_REQ,
	I2C_EV_DATA_RCV
}Slave_State;

typedef struct
{
	uint32_t				I2C_ClockSpeed;		//@ref I2C_CLOCK_SPEED_DEFINE

	uint32_t				I2C_StretchMode;	//@ref I2C_StretchMode_DEFINE

	uint32_t				I2C_Mode;			//@ref I2C_Mode_DEFINE

	I2C_slave_address_t		Slave_ADD;

	uint32_t 				I2C_ACK_Control;	//@ref I2C_ACK_Control_DEFINE

	uint32_t				I2C_General_Call;	//@ref I2C_General_Call_DEFINE

	void(* P_Slave_CallBack)(Slave_State state);

}I2C_Config_t;

//---------------------------------------------------------
//Macros Configuration References
//------------------------------------------------------------
//@ref I2C_CLOCK_SPEED_DEFINE
/*Supports different communication speeds:
	– Standard Speed (up to 100 kHz)
	– Fast Speed (up to 400 kHz)
 	* The CCR register must be configured only when the I2C is disabled (PE = 0)
 	* Bits 5:0 FREQ[5:0]: Peripheral clock frequency
	The FREQ bits must be configured with the APB clock frequency value (I2C peripheral connected to APB). The FREQ field is used by the peripheral to generate data setup and
	hold times compliant with the I2C specifications. The minimum allowed frequency is 2 MHz,
	the maximum frequency is limited by the maximum APB frequency and cannot exceed
	50 MHz (peripheral intrinsic maximum limit).
	0b000000: Not allowed
	0b000001: Not allowed
	0b000010: 2 MHz
	...
	0b110010: 50 MHz
	Higher than 0b100100: Not allowed
 */
#define I2C_CLOCK_SPEED_50KHZ		(50000U)
#define I2C_CLOCK_SPEED_100KHZ		(100000U)


//@ref I2C_StretchMode_DEFINE
#define I2C_StretchMode_Enable		(uint32_t)(0)
#define I2C_StretchMode_Disable		(uint32_t)(1<<7)

//@ref I2C_Mode_DEFINE
#define I2C_Mode_I2C				(uint32_t)(0)
#define I2C_Mode_SMBus				(uint32_t)(1<<1)

//@ref I2C_SLAVE_ADD_Mode_DEFINE: I2C_OAR1
#define I2C_SLAVE_ADD_Mode_7Bit		(uint32_t)(0)
#define I2C_SLAVE_ADD_Mode_10Bit	(uint32_t)(1<<15)

//@ref I2C_ACK_Control_DEFINE
#define I2C_ACK_Control_Enable		(uint32_t)(1<<10)
#define I2C_ACK_Control_Disable		(uint32_t)(0)

//@ref I2C_General_Call_DEFINE
#define I2C_General_Call_Enable		(uint32_t)(1<<6)
#define I2C_General_Call_Disable	(uint32_t)(0)


typedef enum
{
	With_Stop,
	Without_Stop
}STOP_Condition;

typedef enum
{
	START,
	Repeated_START
}START_Condition;

typedef enum
{
	RESET,
	SET
}I2C_Flagstatus;

typedef enum
{
	BUS_BUSY,												/* BUSY: Bus busy 1: Communication ongoing on the bus */
	SB,														/* SB: Start bit (Master mode) 1: Start condition generated. */
	ADDR,													/* ADDR: Address sent (master mode)/matched (slave mode) */
	TXE,													/* TxE: Data register empty (transmitters) */
	RXNE,													/* RxNE: Data register not empty (receivers) */
	Master_Transmitter_Event = ((uint32_t)(0x00070080))		/* Check if BUSY ,TRA ,MSL W,TXE flags are all set */
}Status;

typedef enum
{
	Disable,
	Enable
}Functional_State;

typedef enum
{
	I2C_Direction_Transmitter = 0,
	I2C_Direction_Receiver = 1
}I2C_Direction;

/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_I2C_Init(I2C_TypeDef* I2Cx, I2C_Config_t* I2C_Config);
void MCAL_I2C_DeInit(I2C_TypeDef* I2Cx);

void MCAL_I2C_GPIO_Set_Pins		(I2C_TypeDef* I2Cx);

//Master polling Mechanism
void MCAL_I2C_Master_Tx(I2C_TypeDef* I2Cx, uint16_t Dev_Add, uint8_t* pTxData, uint8_t Data_Len, STOP_Condition Stop, START_Condition Start);
void MCAL_I2C_Master_Rx(I2C_TypeDef* I2Cx, uint16_t Dev_Add, uint8_t* pTxData, uint8_t Data_Len, STOP_Condition Stop, START_Condition Start);

//SLave interrupt mechanism
void MCAL_I2C_Slave_TX(I2C_TypeDef *I2Cx, uint8_t TxData);
uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef *I2Cx);

/*
 * ===============================================
 * Generic APIs
 * ===============================================
 */

I2C_Flagstatus I2C_Get_FlagStatus(I2C_TypeDef *I2Cx, Status Flag);

void I2C_GenerateStart(I2C_TypeDef *I2Cx,START_Condition Start, Functional_State State);
void I2C_SendADD(I2C_TypeDef* I2Cx, uint16_t ADD, I2C_Direction Direction);
void I2C_GenerateStop(I2C_TypeDef* I2Cx, Functional_State State);
void I2C_ACKConfig(I2C_TypeDef *I2Cx, Functional_State State);




#endif /* INC_STM32_F103C6_I2C_DRIVER_H_ */
