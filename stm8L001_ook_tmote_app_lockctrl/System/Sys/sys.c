/**
  *********************************************************************************************************
  * @file    sys.c
  * @author  Movebroad -- KK
  * @version V1.0
  * @date    2019-08-22
  * @brief   
  *********************************************************************************************************
  * @attention
  *			
  *
  *
  *********************************************************************************************************
  */

#include "sys.h"

/**********************************************************************************************************
 @Function			void Stm8_HSIClock_Init(CLK_SYSCLKDiv_TypeDef CLK_SYSCLKDiv)
 @Description			Stm8_HSIClock_Init
 @Input				CLK_SYSCLKDiv
 @Return				void
**********************************************************************************************************/
void Stm8_HSIClock_Init(CLK_SYSCLKDiv_TypeDef CLK_SYSCLKDiv)
{
     /* ʹ��HSI */
     CLK_HSICmd(ENABLE);
     
     /* ʹ��ϵͳʱ��Դѡ�� */
     CLK_SYSCLKSourceSwitchCmd(ENABLE);
     
     /* ϵͳʱ��Դѡ��HSI */
     CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);
     
     /* ����ϵͳ��Ƶϵ�� */
     CLK_SYSCLKDivConfig(CLK_SYSCLKDiv);
}

/**********************************************************************************************************
 @Function			void Stm8_LSIClock_Init(CLK_SYSCLKDiv_TypeDef CLK_SYSCLKDiv)
 @Description			Stm8_LSIClock_Init
 @Input				CLK_SYSCLKDiv
 @Return				void
**********************************************************************************************************/
void Stm8_LSIClock_Init(CLK_SYSCLKDiv_TypeDef CLK_SYSCLKDiv)
{
     /* ʹ��LSI */
     CLK_LSICmd(ENABLE);
     
     /* ʹ��ϵͳʱ��Դѡ�� */
     CLK_SYSCLKSourceSwitchCmd(ENABLE);
     
     /* ϵͳʱ��Դѡ��LSI */
     CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_LSI);
     
     /* ����ϵͳ��Ƶϵ�� */
     CLK_SYSCLKDivConfig(CLK_SYSCLKDiv);
}

/********************************************** END OF FLEE **********************************************/
