#ifndef __LCD_H
#define __LCD_H

#include "stm32f4xx_hal.h"
#include "main.h"

//#define LCD_X_SIZE	        240
//#define LCD_Y_SIZE	        320
////�����Ƿ�ʹ�ú��� 		0,��ʹ��.1,ʹ��
//#define USE_HORIZONTAL  		1
//#ifdef USE_HORIZONTAL
//#define X_MAX_PIXEL	        LCD_Y_SIZE
//#define Y_MAX_PIXEL	        LCD_X_SIZE
//#else
//#define X_MAX_PIXEL	        LCD_X_SIZE
//#define Y_MAX_PIXEL	        LCD_Y_SIZE
//#endif

//#define RED			0xF800
//#define GREEN		0x07E0
//#define BLUE 		0x001F
//#define WHITE		0xFFFF
//#define BLACK		0x0000
//#define YELLOW  0xFFE0
//#define GRAY0   0xEF7D   		//��ɫ0  00110 001011 00101
//#define GRAY1   0x8410      //��ɫ1  00000 000000 00000
//#define GRAY2   0x4208      //��ɫ2  11111 111110 11111

////Һ�����ƿ���1�������궨��
//#define	LCD_CS_SET  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);    
//#define	LCD_DC_SET  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);     
//#define	LCD_RST_SET  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);      

////Һ�����ƿ���0�������궨��
//#define	LCD_CS_CLR  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);    
//#define	LCD_DC_CLR  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);      
//#define	LCD_RST_CLR  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET); 

//#define SPI_SPEED_SET(SPIHandle,SPIScale)	do{(SPIHandle.Instance->CR1)&=0xFFC7;(SPIHandle.Instance->CR1)|=SPIScale;}while(0);

//void Lcd_WriteIndex(uint8_t Index);
//void Lcd_WriteData(uint8_t Data);
//void LCD_WriteReg(uint8_t Index,uint16_t Data);
//void Lcd_WriteData_16Bit(uint16_t Data);
//void Lcd_Reset(void);
//void Lcd_Init(void);
//void Lcd_SetXY(uint16_t Xpos, uint16_t Ypos);
//void Lcd_SetRegion(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);
//void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data);
//void Lcd_Clear(uint16_t Color);

#endif