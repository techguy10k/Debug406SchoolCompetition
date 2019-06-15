#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "gui.h"

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
	while(1)
	{
		uint32_t time = HAL_GetTick();
		User_AdcStartBlokingMode(Adc_table,2048);
		time = HAL_GetTick() - time;
		for(uint16_t counter = 0;counter < 2048;counter ++)
		{
			//LCD_OUTPUT_Float(0,0,"Adc_table",3.3*Adc_table[counter]/4095);
			if(counter%6==0)
			Gui_DrawPoint(240-counter,240-240*(3.3*Adc_table[counter]/4095),RED);
			//LCD_OUTPUT_Float(0,20,"time",time);
			//HAL_Delay(100);
		}
		while(1);
	}
	
}




void Systeminit(void)
{
	//用户ADC1+TIM3+DMA初始化
	User_AdcInit();
}

