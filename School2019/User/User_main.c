#include "main.h"
#include "gpio.h"
#include "gui.h"

#include "User_adc.h"
#include "User_Uart.h"
#include "User_FFT.h"
#include "User_dac.h"

#include "dac.h"


//TIM3 触发输出事件连接到ADC1 PA1端口控制采样速率 ADC1 PA1使用DMA2S0

/*
* DAC输出专用分支 如果有波形输出题的话采用这个分支
* 本分支可以配合USART使用 以实现单片机机通讯
*/

/*
* DAC 使用TIM6触发 预计DAC采样率 1Mhz 大摆幅 250K
*/

/* Test Only */

void Systeminit(void); //初始化都放这里

//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
  HAL_TIM_Base_Init(&htim6);
  HAL_TIM_Base_Start(&htim6);
  HAL_DAC_Init(&hdac);
	Dac_init();
  while(1)
    {
			Dac_Run();
			while(1);
    }

}




void Systeminit(void)
{
  //用户ADC1+TIM3+DMA初始化 DAC分支就不需要初始化ADC了
  //User_AdcInit();
}

