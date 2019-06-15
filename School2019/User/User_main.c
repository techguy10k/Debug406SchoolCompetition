#include "main.h"
#include "spi.h"
#include "gpio.h"


#include "User_adc.h"
#include "User_Uart.h"


//TIM3 触发输出事件连接到ADC1 PA1端口控制采样速率 ADC1 PA1使用DMA2S0

/* Test Only */
uint16_t Adc_table[2048];


void Systeminit(void); //初始化都放这里

//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	Systeminit();
	HAL_Delay(500);
	Lcd_Clear(RED);
	while(1)
	{
		uint32_t time = HAL_GetTick();
		User_AdcStartBlokingMode(Adc_table,2048);
		time = HAL_GetTick() - time;
		for(uint16_t counter = 0;counter < 2048;counter ++)
		{
			printf("%d\r\n",Adc_table[counter]);
		}
		printf("%d\r\n",time);
	}
	
}




void Systeminit(void)
{
	//用户ADC1+TIM3+DMA初始化
	User_AdcInit();
}

