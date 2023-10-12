typedef volatile unsigned int vuint32_t;

#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIO_PORTA_BASE 0x40010800
#define RCC_APB2EBR *(vuint32_t*)(RCC_BASE+0x18)
#define GPIO_PA_CRH *(vuint32_t*)(GPIO_PORTA_BASE+0x04)
#define GPIO_PA_ODR *(vuint32_t*)(GPIO_PORTA_BASE+0x0C)

#define RCC_IOPAEN 	(1<<2)
#define GPIOA13		(1UL<<13)

typedef union {
	vuint32_t	all_fields;
	struct {
		vuint32_t	reserved:13;
		vuint32_t	P_13:1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_PORTA_BASE + 0x0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};

int main(void){
	RCC_APB2EBR |= RCC_IOPAEN;
	GPIO_PA_CRH &= 0xff0fffff;
	GPIO_PA_CRH |= 0x00200000;

	while(1){
		R_ODR->Pin.P_13 = 1;
		for(int i=0;i<5000;i++);
		R_ODR->Pin.P_13 = 0;
		for(int i=0;i<5000;i++);
	}

	return 0;
}
