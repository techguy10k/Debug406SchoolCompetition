/*
* 本工程FFT相关函数 变量的实现都在这个文件
*/

#include "User_FFT.h"
#include "User_adc.h"
#include "arm_math.h"
#include "arm_const_structs.h"

#include "stdio.h"

/*
* 该函数会从ADC以阻塞模式 2048Hz采样率采2048个点 然后进行rFFT 最终输出每个点的模长
*/
void User_FastRfft2048BlokingMode(float32_t* MagOutPosition)
{
	//ADC采样结果存放在这里
	uint16_t adc_input[2048] = {0};
	//2048个实部的输入数组
	float32_t realval[4096] = {0};
	
	User_AdcStartBlokingMode(adc_input,2048);
	
	
	
	//将ADC采集到的数据从DMA缓冲区取到准备FFT的位置
  for (uint16_t index_fill_input_buffer = 0,index_fill_adc_buffer = 0; index_fill_input_buffer < 4096; index_fill_input_buffer += 2,index_fill_adc_buffer++)
  {
    realval[(uint16_t)index_fill_input_buffer] = 3.3 *(float32_t)adc_input[index_fill_adc_buffer] / (float32_t)4096.0;
    /* Imaginary part */
    realval[(uint16_t)(index_fill_input_buffer + 1)] = 0;
  }	

	
	//FFT运算函数 最后的 0 代表是正fft
	arm_cfft_f32(&arm_cfft_sR_f32_len2048, realval, 0, 1);
	//求模长
	arm_cmplx_mag_f32(realval,MagOutPosition,2048);
	
	for(uint16_t counter = 0;counter < 2048;counter ++)
	{
	//	MagOutPosition[counter] *= (float)1.414213562;
	}
	
}

