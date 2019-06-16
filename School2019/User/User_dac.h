/*
* User_dac.h
* 本文件用在DAC分支内 用于支持DAC输出
* 由于屏幕转接板的奇葩接线方式 我们要用屏幕就没有DAC可以用
* 因此搞出这个文件 以支持DAC输出
* 
* 校赛DAC应该是用双MCU方案的了，如果有双机通讯需求的话 可以用UART解决
*/
#ifndef USER_DAC_H_
#define USER_DAC_H_

#include "stm32f4xx_hal.h"
#include "tim.h"
#include "dac.h"

#include "string.h"

#define Dac_Status_Idle 0
#define Dac_Status_Busy 1

#define Dac_Plotting_Bank0 0
#define Dac_Plotting_Bank1 1

#define Dac_Plot_Freq_256  0
#define Dac_Plot_Freq_448  1
#define Dac_Plot_Freq_500  2
#define Dac_Plot_Freq_640  3
#define Dac_Plot_Freq_832  4
#define Dac_Plot_Freq_1000 5
#define Dac_Plot_Freq_1216 6
#define Dac_Plot_Freq_1408 7
#define Dac_Plot_Freq_1600 8
#define Dac_Plot_Freq_1792 9

#define Dac_Plot_Freq_50 10


#define Dac_Plot_Freq_Null 255
#define Dac_Plot_Mid_Position 254



typedef struct 
{
	uint8_t  Dac_Status;
	uint8_t  Dac_Plotting_Bank;
	
	int16_t  Dac_Plot_Bank0[250];
	int16_t  Dac_Plot_Bank1[250];
	
	uint32_t Dac_Plot_Counter;
	
	uint8_t  Dac_PlotFreq0;
	uint8_t  Dac_PlotFreq1;
	
}DACStatus_Typedef;




void Dac_init(void);
void Dac_Deinit(void);
void Dac_Run(void);
void Dac_Stop(void);

void Dac_SetOutputFreq(uint8_t Freq0,uint8_t Freq1,DACStatus_Typedef* Status);



#endif