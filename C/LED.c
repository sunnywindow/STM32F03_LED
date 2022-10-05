#include "stm32f10x.h"
//----------------APB2使能时钟寄存器 ---------------------
#define RCC_APB2ENR		*((unsigned volatile int*)0x40021018)
//----------------GPIOA配置寄存器 -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB配置寄存器 -----------------------
#define GPIOB_CRL		*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ODR		*((unsigned volatile int*)0x40010C0C)
//----------------GPIOC配置寄存器 -----------------------
#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR		*((unsigned volatile int*)0x4001100C)


//延时函数
 void Delay()
 {
   u32 i=0;
   for(;i<5000000;i++);
 }

 int main(void)
{	
	RCC_APB2ENR|=1<<2|1<<3|1<<4;			//APB2-GPIOA、GPIOB、GPIOC外设时钟使能	
	
	GPIOA_CRL&=0xFF0FFFFF;		//设置位 清零	
	GPIOA_CRL|=0x00200000;		//PA5推挽输出
  GPIOA_ODR|=1<<5;
	
	
	GPIOB_CRL&=0xFFFFFF0F;		//设置位 清零	
	GPIOB_CRL|=0x00000020;		//PB9推挽输出
	GPIOB_ODR|=1<<9;
	 
	GPIOC_CRH&=0xFF0FFFFF;		//设置位 清零	
	GPIOC_CRH|=0x00200000;		//PC13推挽输出
	GPIOC_ODR|=1<<13;
	 

	while(100){
		GPIOA_ODR&=~(1<<5);		//PA5低电平,因为是置0，所以用按位与
	 	Delay();
		GPIOA_ODR|=1<<5;		//PA5高电平

		
		//B灯
		GPIOB_ODR&=~(1<<9);		//PB9低电平,因为是置0，所以用按位与
	 	Delay();
		GPIOB_ODR|=1<<9;		//PB9高电平


		
		
		//C灯
		GPIOC_ODR&=~(1<<13);		//PC13低电平,因为是置0，所以用按位与
	 	Delay();
		GPIOC_ODR|=1<<13;		//PC13高电平
	}

	
}
