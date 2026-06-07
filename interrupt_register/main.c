#include "stdint.h"
#include "stm32f10x.h"
#include "Key.h"
uint8_t ison=0;
uint16_t leds[]={LED1,LED2,LED3};
int8_t n=3;
int main(void)
{
	//初始化
	main_Init();
	Key_Init();
	while(1){
		if(ison==255)
		{
		for(uint16_t i=0;i<n;i++)
		{
			led_on(leds[i]);
			Delay_ms(500);
			led_off(leds[i]);
			Delay_ms(500);
		}
		}
		else 
		{
			led_Groupoff(leds,n);
		}
	}
}
