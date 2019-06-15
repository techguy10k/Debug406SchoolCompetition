#include "main.h"
#include "spi.h"
#include "gpio.h"


#include "User_adc.h"
#include "User_Uart.h"
#include "User_FFT.h"
#include "gui.h"


//TIM3 触发输出事件连接到ADC1 PA1端口控制采样速率 ADC1 PA1使用DMA2S0

/* Test Only */
float Adc_table[2048];


void Systeminit(void); //初始化都放这里

//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	Systeminit();
	while(1)
	{
		User_FastRfft2048BlokingMode(Adc_table);
		while(1);
	}
	
}




void Systeminit(void)
{
	//用户ADC1+TIM3+DMA初始化
	User_AdcInit();
}

