/**
  *********************************************************************************************************
  * @file    hal_beep.c
  * @author  Movebroad -- KK
  * @version V1.0
  * @date    2017-12-16
  * @brief   
  *********************************************************************************************************
  * @attention
  *
  *
  *
  *********************************************************************************************************
  */

#include "hal_beep.h"
#include "platform_config.h"
#include "platform_map.h"
#include "delay.h"

/**********************************************************************************************************
 @Function			void BEEP_Ctrl(u8 beepEnable)
 @Description			蜂鸣器控制
 @Input				ON or OFF
 @Return				void
**********************************************************************************************************/
void BEEP_Ctrl(u8 beepEnable)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	BEEP_RCC_GPIO_CLK_ENABLE();
	
	GPIO_Initure.Pin = BEEP_PIN;
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Initure.Pull = GPIO_NOPULL;
	GPIO_Initure.Speed = GPIO_SPEED_HIGH;									//高速
	HAL_GPIO_Init(BEEP_GPIOx, &GPIO_Initure);								//初始化GPIO
	
	if (beepEnable == ON) {
		HAL_GPIO_WritePin(BEEP_GPIOx, BEEP_PIN, GPIO_PIN_SET);
	}
	else if (beepEnable == OFF) {
		HAL_GPIO_WritePin(BEEP_GPIOx, BEEP_PIN, GPIO_PIN_RESET);
	}
	
	GPIO_Initure.Pin = BEEP_PIN;
	GPIO_Initure.Speed = GPIO_SPEED_VERY_LOW;
	HAL_GPIO_Init(BEEP_GPIOx, &GPIO_Initure);								//初始化GPIO
}

/**********************************************************************************************************
 @Function			void BEEP_CtrlRepeat(u16 nCount, u16 nMs)
 @Description			蜂鸣器控制重复响
 @Input				nCount	: 次数
					nMs		: 间隔
 @Return				void
**********************************************************************************************************/
void BEEP_CtrlRepeat(u16 nCount, u16 nMs)
{
	u16 index = 0;
	
	for (index = 0; index < nCount; index++) {
		BEEP(ON);
		Delay_MS(nMs);
		BEEP(OFF);
		Delay_MS(nMs);
	}
}

/**********************************************************************************************************
 @Function			void BEEP_PassiveCtrl(u16 speak_nMs)
 @Description			蜂鸣器无源响(内部使用)
 @Input				speak_nMs	: BEEP时间MS
 @Return				void
**********************************************************************************************************/
void BEEP_PassiveCtrl(u16 speak_nMs)
{
	for (u16 nCount = 0; nCount < speak_nMs * 2; nCount++) {
		HAL_GPIO_WritePin(BEEP_GPIOx, BEEP_PIN, GPIO_PIN_SET);
		Delay_US(BEEP_ON_US);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
		Delay_US(BEEP_OFF_US);
	}
}

/**********************************************************************************************************
 @Function			void BEEP_CtrlRepeat_Extend(u16 nCount, u16 speak_nMs, u16 shut_nMs)
 @Description			蜂鸣器控制重复响
 @Input				nCount	: 次数
					speak_nMs	: 间隔鸣
					shut_nMs	: 间隔闭
 @Return				void
**********************************************************************************************************/
void BEEP_CtrlRepeat_Extend(u16 nCount, u16 speak_nMs, u16 shut_nMs)
{
	GPIO_InitTypeDef GPIO_Initure;
	u16 index = 0;
	
	BEEP_RCC_GPIO_CLK_ENABLE();
	
	GPIO_Initure.Pin = BEEP_PIN;
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Initure.Pull = GPIO_NOPULL;
	GPIO_Initure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(BEEP_GPIOx, &GPIO_Initure);
	
	if (TCFG_EEPROM_GetBeepOff() != 2) {
		for (index = 0; index < nCount; index++) {
		#if BEEP_MODEL_TYPE
			BEEP_PassiveCtrl(speak_nMs);
			BEEP(OFF);
			Delay_MS(shut_nMs);
		#else
			BEEP(ON);
			Delay_MS(speak_nMs);
			BEEP(OFF);
			Delay_MS(shut_nMs);
		#endif
		}
	}
	
	GPIO_Initure.Pin = BEEP_PIN;
	GPIO_Initure.Speed = GPIO_SPEED_VERY_LOW;
	HAL_GPIO_Init(BEEP_GPIOx, &GPIO_Initure);
}

/********************************************** END OF FLEE **********************************************/
