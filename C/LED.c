#include "stm32f10x.h"
//----------------APB2ʹ��ʱ�ӼĴ��� ---------------------
#define RCC_APB2ENR		*((unsigned volatile int*)0x40021018)
//----------------GPIOA���üĴ��� -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB���üĴ��� -----------------------
#define GPIOB_CRL		*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ODR		*((unsigned volatile int*)0x40010C0C)
//----------------GPIOC���üĴ��� -----------------------
#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR		*((unsigned volatile int*)0x4001100C)


//��ʱ����
 void Delay()
 {
   u32 i=0;
   for(;i<5000000;i++);
 }

 int main(void)
{	
	RCC_APB2ENR|=1<<2|1<<3|1<<4;			//APB2-GPIOA��GPIOB��GPIOC����ʱ��ʹ��	
	
	GPIOA_CRL&=0xFF0FFFFF;		//����λ ����	
	GPIOA_CRL|=0x00200000;		//PA5�������
  GPIOA_ODR|=1<<5;
	
	
	GPIOB_CRL&=0xFFFFFF0F;		//����λ ����	
	GPIOB_CRL|=0x00000020;		//PB9�������
	GPIOB_ODR|=1<<9;
	 
	GPIOC_CRH&=0xFF0FFFFF;		//����λ ����	
	GPIOC_CRH|=0x00200000;		//PC13�������
	GPIOC_ODR|=1<<13;
	 

	while(100){
		GPIOA_ODR&=~(1<<5);		//PA5�͵�ƽ,��Ϊ����0�������ð�λ��
	 	Delay();
		GPIOA_ODR|=1<<5;		//PA5�ߵ�ƽ

		
		//B��
		GPIOB_ODR&=~(1<<9);		//PB9�͵�ƽ,��Ϊ����0�������ð�λ��
	 	Delay();
		GPIOB_ODR|=1<<9;		//PB9�ߵ�ƽ


		
		
		//C��
		GPIOC_ODR&=~(1<<13);		//PC13�͵�ƽ,��Ϊ����0�������ð�λ��
	 	Delay();
		GPIOC_ODR|=1<<13;		//PC13�ߵ�ƽ
	}

	
}
