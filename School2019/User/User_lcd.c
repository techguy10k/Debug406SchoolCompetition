#include "spi.h"
#include "User_lcd.h"


//void LCD_SPI_Init()
//{
//	uint8_t temp=0xFF;
//	//HAL_SPI_Init(&hspi1);
//	LCD_RST_SET;
//	HAL_Delay(50);
//	HAL_SPI_Transmit(&hspi1,&temp,1,3);
//}

///****************************************************************************
//* ��    �ƣ�Lcd_WriteIndex(u8 Index)
//* ��    �ܣ���Һ����дһ��8λָ��
//* ��ڲ�����Index   �Ĵ�����ַ
//* ���ڲ�������
//* ˵    ��������ǰ����ѡ�п��������ڲ�����
//****************************************************************************/
//void Lcd_WriteIndex(uint8_t Index)
//{
//   LCD_CS_CLR;
//   LCD_DC_CLR; 
//   SPI_WriteByte(Index);
//   LCD_CS_SET;
//}

///****************************************************************************
//* ��    �ƣ�Lcd_WriteData(u8 Data)
//* ��    �ܣ���Һ����дһ��8λ����
//* ��ڲ�����dat     �Ĵ�������
//* ���ڲ�������
//* ˵    �����������ָ����ַд�����ݣ��ڲ�����
//****************************************************************************/
//void Lcd_WriteData(uint8_t Data)
//{
//   LCD_CS_CLR;
//   LCD_DC_SET; 
//   SPI_WriteByte(Data);
//   LCD_CS_SET;
//}

///****************************************************************************
//* ��    �ƣ�void LCD_WriteReg(u8 Index,u16 Data)
//* ��    �ܣ�д�Ĵ�������
//* ��ڲ�����Index,Data
//* ���ڲ�������
//* ˵    ����������Ϊ��Ϻ�������Index��ַ�ļĴ���д��Dataֵ
//****************************************************************************/
//void LCD_WriteReg(uint8_t Index,uint16_t Data)
//{
//	Lcd_WriteIndex(Index);
//	Lcd_WriteData_16Bit(Data);
//}

///****************************************************************************
//* ��    �ƣ�void Lcd_WriteData_16Bit(u16 Data)
//* ��    �ܣ���Һ����дһ��16λ����
//* ��ڲ�����Data
//* ���ڲ�������
//* ˵    �����������ָ����ַд��һ��16λ����
//****************************************************************************/
//void Lcd_WriteData_16Bit(uint16_t Data)
//{	
//	Lcd_WriteData(Data>>8);
//	Lcd_WriteData(Data);	
//}

///****************************************************************************
//* ��    �ƣ�void Lcd_Reset(void)
//* ��    �ܣ�Һ��Ӳ��λ����
//* ��ڲ�������
//* ���ڲ�������
//* ˵    ����Һ����ʼ��ǰ��ִ��һ�θ�λ����
//****************************************************************************/
//void Lcd_Reset(void)
//{
//	LCD_RST_CLR;
//	HAL_Delay(100);
//	LCD_RST_SET;
//	HAL_Delay(50);
//}
///****************************************************************************
//* ��    �ƣ�void Lcd_Init(void)
//* ��    �ܣ�Һ����ʼ������
//* ��ڲ�������
//* ���ڲ�������
//* ˵    ����Һ����ʼ��_ILI9225_176X220
//****************************************************************************/
//void Lcd_Init(void)
//{	
//	LCD_SPI_Init();	
//	Lcd_Reset(); 							//Reset before LCD Init.
//	Lcd_WriteIndex(0xCB);  
//	Lcd_WriteData(0x39); 
//	Lcd_WriteData(0x2C); 
//	Lcd_WriteData(0x00); 
//	Lcd_WriteData(0x34); 
//	Lcd_WriteData(0x02); 

//	Lcd_WriteIndex(0xCF);  
//	Lcd_WriteData(0x00); 
//	Lcd_WriteData(0XC1); 
//	Lcd_WriteData(0X30); 
// 
//	Lcd_WriteIndex(0xE8);  
//	Lcd_WriteData(0x85); 
//	Lcd_WriteData(0x00); 
//	Lcd_WriteData(0x78); 
// 
//	Lcd_WriteIndex(0xEA);  
//	Lcd_WriteData(0x00); 
//	Lcd_WriteData(0x00); 
// 
//	Lcd_WriteIndex(0xED);  
//	Lcd_WriteData(0x64); 
//	Lcd_WriteData(0x03); 
//	Lcd_WriteData(0X12); 
//	Lcd_WriteData(0X81); 

//	Lcd_WriteIndex(0xF7);  
//	Lcd_WriteData(0x20); 
//  
//	Lcd_WriteIndex(0xC0);			//Power control 
//	Lcd_WriteData(0x23);			//VRH[5:0] 
// 
//	Lcd_WriteIndex(0xC1);    	//Power control 
//	Lcd_WriteData(0x10);   		//SAP[2:0];BT[3:0] 
// 
//	Lcd_WriteIndex(0xC5);    	//VCM control 
//	Lcd_WriteData(0x3e); 			//�Աȶȵ���
//	Lcd_WriteData(0x28); 
// 
//	Lcd_WriteIndex(0xC7);    	//VCM control2 
//	Lcd_WriteData(0x86);  		//--
// 
//	Lcd_WriteIndex(0x36);    	// Memory Access Control 
//#ifdef USE_HORIZONTAL
//	Lcd_WriteData(0xE8); 			//C8	   //48 68����//28 E8 ����
//#else
//	Lcd_WriteData(0x48); 
//#endif

//	Lcd_WriteIndex(0x3A);    
//	Lcd_WriteData(0x55); 

//	Lcd_WriteIndex(0xB1);    
//	Lcd_WriteData(0x00);  
//	Lcd_WriteData(0x18); 
// 
//	Lcd_WriteIndex(0xB6);    // Display Function Control 
//	Lcd_WriteData(0x08); 
//	Lcd_WriteData(0x82);
//	Lcd_WriteData(0x27);  
// 
//	Lcd_WriteIndex(0xF2);    // 3Gamma Function Disable 
//	Lcd_WriteData(0x00); 
// 
//	Lcd_WriteIndex(0x26);    //Gamma curve selected 
//	Lcd_WriteData(0x01); 
// 
//	Lcd_WriteIndex(0xE0);    //Set Gamma 
//	Lcd_WriteData(0x0F); 
//	Lcd_WriteData(0x31); 
//	Lcd_WriteData(0x2B); 
//	Lcd_WriteData(0x0C); 
//	Lcd_WriteData(0x0E); 
//	Lcd_WriteData(0x08); 
//	Lcd_WriteData(0x4E); 
//	Lcd_WriteData(0xF1); 
//	Lcd_WriteData(0x37); 
//	Lcd_WriteData(0x07); 
//	Lcd_WriteData(0x10); 
//	Lcd_WriteData(0x03); 
//	Lcd_WriteData(0x0E); 
//	Lcd_WriteData(0x09); 
//	Lcd_WriteData(0x00); 
//	
//	Lcd_WriteIndex(0XE1);    //Set Gamma 
//	Lcd_WriteData(0x00); 
//	Lcd_WriteData(0x0E); 
//	Lcd_WriteData(0x14); 
//	Lcd_WriteData(0x03); 
//	Lcd_WriteData(0x11); 
//	Lcd_WriteData(0x07); 
//	Lcd_WriteData(0x31); 
//	Lcd_WriteData(0xC1); 
//	Lcd_WriteData(0x48); 
//	Lcd_WriteData(0x08); 
//	Lcd_WriteData(0x0F); 
//	Lcd_WriteData(0x0C); 
//	Lcd_WriteData(0x31); 
//	Lcd_WriteData(0x36); 
//	Lcd_WriteData(0x0F); 
// 
//	Lcd_WriteIndex(0x11);    //Exit Sleep 
//	HAL_Delay(120); 
//				
//	Lcd_WriteIndex(0x29);    //Display on 
//	Lcd_WriteIndex(0x2c); 
//	
//}

///*************************************************
//��������LCD_Set_XY
//���ܣ�����lcd��ʾ��ʼ��
//��ڲ�����xy����
//����ֵ����
//*************************************************/
//void Lcd_SetXY(uint16_t Xpos, uint16_t Ypos)
//{	
//	Lcd_WriteIndex(0x2a);
//	Lcd_WriteData_16Bit(Xpos);
//	Lcd_WriteIndex(0x2b);
//	Lcd_WriteData_16Bit(Ypos);
//	Lcd_WriteIndex(0x2c);	
//} 
///*************************************************
//��������LCD_Set_Region
//���ܣ�����lcd��ʾ�����ڴ�����д�������Զ�����
//��ڲ�����xy�����յ�
//����ֵ����
//*************************************************/
////������ʾ����
//void Lcd_SetRegion(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd)
//{
//	Lcd_WriteIndex(0x2a);
//	Lcd_WriteData_16Bit(xStar);
//	Lcd_WriteData_16Bit(xEnd);
//	Lcd_WriteIndex(0x2b);
//	Lcd_WriteData_16Bit(yStar);
//	Lcd_WriteData_16Bit(yEnd);
//	Lcd_WriteIndex(0x2c);
//}

//	
///*************************************************
//��������LCD_DrawPoint
//���ܣ���һ����
//��ڲ�����xy�������ɫ����
//����ֵ����
//*************************************************/
//void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data)
//{
//	Lcd_SetXY(x,y);
//	Lcd_WriteData_16Bit(Data);

//}    

///*************************************************
//��������Lcd_Clear
//���ܣ�ȫ����������
//��ڲ����������ɫCOLOR
//����ֵ����
//*************************************************/
//void Lcd_Clear(uint16_t Color)               
//{	
//   int32_t i,m;
//   Lcd_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
//   for(i=0;i<X_MAX_PIXEL;i++)
//    for(m=0;m<Y_MAX_PIXEL;m++)
//    {	
//	  	Lcd_WriteData_16Bit(Color);
//    }   
//}
/* USER CODE END 1 */