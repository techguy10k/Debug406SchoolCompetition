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
	int i=0;
	int LastX=0,LastY=100;
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
			{
				int temp;
				temp=counter/6;
				if((3.3*Adc_table[counter]/4095)<1.72)
				Gui_DrawLine(LastX,LastY,temp,(107*(3.3*Adc_table[counter]/4095)-100) ,RED);
		   	//Gui_DrawPoint(temp,107*(3.3*Adc_table[counter]/4095)-100,RED);
				else
				Gui_DrawLine(LastX,LastY,temp,(107*(3.3*Adc_table[counter]/4095)-100) ,RED);
				LastX=temp;
				LastY=(107*(3.3*Adc_table[counter]/4095)-100);
			}
			//LCD_OUTPUT_Float(0,20,"time",time);
			//HAL_Delay(10);
		}
		//Gui_DrawLine(0,0,320,240,RED);
//		for(i=0;i<=320;i++)
//		{
//			Gui_DrawPoint(i,0,RED);
//		}
		while(1);
		//Lcd_Clear(WHITE);
	}
	
}




void Systeminit(void)
{
	//用户ADC1+TIM3+DMA初始化
	User_AdcInit();
}

