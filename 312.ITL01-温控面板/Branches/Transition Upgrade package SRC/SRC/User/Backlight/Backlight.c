/*****************************************************************************
	文件： Backlight.c
	说明： 背光控制源文件
	编译： Keil uVision4 V4.54.0.0
	版本： v2.0
	编写： Unarty
	日期： 2014-11-14
*****************************************************************************/
#include "Backlight.h"
#include "GPIO.h"
#include "Thread.h"

/*******************************************************************
函 数 名：	Backlight_Init
功能说明： 	背光初始化
参	  数： 	无
返 回 值：	无
*******************************************************************/
void Backlight_Init(void)
{	  
	GPIOx_Cfg(BACKLIGHT_PORT, BACKLIGHT_PIN, OUT_PP_2M);
	Backlight_Run();
}	

/*******************************************************************
函 数 名：	Backlight_Off
功能说明： 	背光灯关闭
参	  数： 	无
返 回 值：	无
*******************************************************************/
void Backlight_Off(void)
{	  
	BACKLIGHT_OFF;
}

/*******************************************************************
函 数 名：	Backlight_On
功能说明： 	背光灯开
参	  数： 	无
返 回 值：	无
*******************************************************************/
void Backlight_On(void)
{	  
	BACKLIGHT_ON;
}

/*******************************************************************
函 数 名：	Backlight_Run
功能说明： 	背光灯运行
参	  数： 	无
返 回 值：	无
*******************************************************************/
void Backlight_Run(void)
{	  
	Backlight_On();
	Thread_Login(ONCEDELAY, 0, BACKLIGHT_ON_TIME, &Backlight_Off);
}

/*******************************************************************
函 数 名：	Backlight_Instruct
功能说明： 	背光灯指示
参	  数： 	无
返 回 值：	无
*******************************************************************/
void Backlight_Instruct(void)
{	  
	Backlight_On();
	Thread_Login(ONCEDELAY, 0, 80, &Backlight_Off);
}


/**************************Copyright BestFu 2014-05-14*************************/	

