#include "User_main.h"
#include "stm32f4xx_hal.h"
#include "adc.h"
#include "usart.h"
#include "stdio.h"
#include "stdlib.h"

uint16_t table[2048];
uint32_t time = 0;

//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	HAL_TIM_Base_Init(&htim3);
	HAL_TIM_Base_Start(&htim3);
	HAL_ADC_Init(&hadc1);
	
	while(1)
	{
		HAL_Delay(1000);
		HAL_ADC_Start_DMA(&hadc1,(uint32_t*)table,2048);
		time = HAL_GetTick();
		HAL_Delay(3000);
		
		for(uint16_t counter = 0;counter < 2048;counter ++)
		{
			printf("%d\r\n",table[counter]);
		}
		
		printf("Time %d \r\n",time);
		
		while(1);
		
	}
	
}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	time = HAL_GetTick() - time;
		HAL_ADC_Stop_DMA(&hadc1);
}

/* Retargeting printf() output to Usart1 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif 

int fputc(int ch,FILE *f)
{
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart1,temp,1,10);        //UartHandle是串口的句柄
		return ch;
}


PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart1,(uint8_t*)&ch,1,10);
	return ch;
}


