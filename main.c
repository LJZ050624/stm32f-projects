#include "stdint.h"
#include "stm32f10x.h"
int main(void)
{
	//先开启时钟
	//*(uint32_t *)(0x40021000+0x18)=16;
	//第一次优化
	//RCC->APB2ENR=16;
	//第二次优化
	//RCC->APB2ENR|=1<<4;
	//第三次优化
	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
	
	//设置引脚GPIO工作模式
	//*(uint32_t*)(0x40011000+0x04)=0x300000;
	//第一次优化
	//GPIOC->CRH=0x300000;
	//第二次优化
	//GPIOC->CRH&=~(0xf<<20);
	//GPIOC->CRH|=0x03<<20;
	//第三次优化
	GPIOA->CRH&=~(GPIO_CRH_CNF12|GPIO_CRH_MODE12);
	GPIOA->CRH|=(GPIO_CRH_MODE12_0|GPIO_CRH_MODE12_1);
	
	
	//引脚GPIO输出输入模式
	//*(uint32_t*)(0x40011000+0x0c)=0xdfff;
	//第一次优化
	//GPIOC->ODR=0xdfff;
	//第二次优化
	//GPIOC->ODR&=~(1<<13);
  //第三次优化
	GPIOA->ODR&=~GPIO_ODR_ODR12;
	
	//死循环
	while(1)
	{
	}
}
