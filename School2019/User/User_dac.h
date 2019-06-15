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


#endif