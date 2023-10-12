typedef volatile unsigned int vuint32_t;

#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIO_PORTA_BASE 0x40010800
#define RCC_APB2ENR (*(vuint32_t*)(RCC_BASE+0x18))
#define GPIO_PA_CRH (*(vuint32_t*)(GPIO_PORTA_BASE+0x04))
#define GPIO_PA_ODR (*(vuint32_t*)(GPIO_PORTA_BASE+0x0C))

#define RCC_IOPAEN 	(1<<2)
#define GPIOA13		(1UL<<13)

extern void NMI_Handler (void)
{

}
extern void Bus_Fault_Handler (void)
{
	
}

typedef union
{
	vuint32_t all_fields;
	struct
	{
		vuint32_t reserved:13 ;
		vuint32_t P_13:1 ;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_PORTA_BASE + 0x0C) ;

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN;

	GPIO_PA_CRH &= 0xFF0FFFFF;
	GPIO_PA_CRH |= 0x00200000;

	while(1){
		R_ODR->Pin.P_13 = 1;
		for(int i=0;i<5000;i++);
		R_ODR->Pin.P_13 = 0;
		for(int i=0;i<5000;i++);
	}

	return 0;
}
