/**
  *********************************************************************************************************
  * @file    inspectflowparameter.c
  * @author  Movebroad -- KK
  * @version V1.0
  * @date    2018-11-05
  * @brief   
  *********************************************************************************************************
  * @attention
  *
  *
  *
  *********************************************************************************************************
  */

#include "inspectflowparameter.h"
#include "platform_config.h"
#include "platform_map.h"

/**********************************************************************************************************
 @Function			void INSPECT_FLOW_Para_SetMagMeasureFreq(unsigned char magFreq)
 @Description			INSPECT_FLOW_Para_SetMagMeasureFreq			: 设置magFreq地磁扫描频率
 @Input				magFreq
 @Return				void
**********************************************************************************************************/
void INSPECT_FLOW_Para_SetMagMeasureFreq(unsigned char magFreq)
{
	magFreq = (magFreq > MEASURE_FREQ_200HZ) ? MEASURE_FREQ_200HZ : magFreq;
	
	InspectFlowClientHandler.Configuration.magMeasureFreq = (INSPECT_FlowMeasureFreqTypeDef)magFreq;
	
	switch (InspectFlowClientHandler.Configuration.magMeasureFreq)
	{
	case MEASURE_FREQ_10HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 600 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	
	case MEASURE_FREQ_50HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 3000 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	
	case MEASURE_FREQ_100HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 6000 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	
	case MEASURE_FREQ_200HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 12000 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	}
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_GetMagMeasureFreq(void)
 @Description			INSPECT_FLOW_Para_GetMagMeasureFreq			: 读取magFreq地磁扫描频率
 @Input				void
 @Return				magFreq
**********************************************************************************************************/
unsigned char INSPECT_FLOW_Para_GetMagMeasureFreq(void)
{
	return InspectFlowClientHandler.Configuration.magMeasureFreq;
}

/**********************************************************************************************************
 @Function			void INSPECT_FLOW_Para_SetCarinThreshhold(unsigned char carinThreshhold)
 @Description			INSPECT_FLOW_Para_SetCarinThreshhold			: 设置carinThreshhold车辆触发灵敏度
 @Input				carinThreshhold
 @Return				void
**********************************************************************************************************/
void INSPECT_FLOW_Para_SetCarinThreshhold(unsigned char carinThreshhold)
{
	InspectFlowClientHandler.Configuration.carinThreshhold = carinThreshhold;
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_GetCarinThreshhold(void)
 @Description			INSPECT_FLOW_Para_GetCarinThreshhold			: 读取carinThreshhold车辆触发灵敏度
 @Input				void
 @Return				carinThreshhold
**********************************************************************************************************/
unsigned char INSPECT_FLOW_Para_GetCarinThreshhold(void)
{
	return InspectFlowClientHandler.Configuration.carinThreshhold;
}

/**********************************************************************************************************
 @Function			void INSPECT_FLOW_Para_SetCaroutThreshhold(unsigned char caroutThreshhold)
 @Description			INSPECT_FLOW_Para_SetCaroutThreshhold			: 设置caroutThreshhold车辆离开参数
 @Input				caroutThreshhold
 @Return				void
**********************************************************************************************************/
void INSPECT_FLOW_Para_SetCaroutThreshhold(unsigned char caroutThreshhold)
{
	InspectFlowClientHandler.Configuration.caroutThreshhold = caroutThreshhold;
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_GetCaroutThreshhold(void)
 @Description			INSPECT_FLOW_Para_GetCaroutThreshhold			: 读取caroutThreshhold车辆离开参数
 @Input				void
 @Return				caroutThreshhold
**********************************************************************************************************/
unsigned char INSPECT_FLOW_Para_GetCaroutThreshhold(void)
{
	return InspectFlowClientHandler.Configuration.caroutThreshhold;
}

/**********************************************************************************************************
 @Function			void INSPECT_FLOW_Para_SetRecalibrationOvernum(unsigned char recalibrationOvernum)
 @Description			INSPECT_FLOW_Para_SetRecalibrationOvernum		: 设置recalibrationOvernum基准值更新阈值
 @Input				recalibrationOvernum
 @Return				void
**********************************************************************************************************/
void INSPECT_FLOW_Para_SetRecalibrationOvernum(unsigned char recalibrationOvernum)
{
	recalibrationOvernum = (recalibrationOvernum > 15) ? 15 : recalibrationOvernum;
	
	InspectFlowClientHandler.Configuration.recalibrationOvernum = recalibrationOvernum;
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_GetRecalibrationOvernum(void)
 @Description			INSPECT_FLOW_Para_GetRecalibrationOvernum		: 读取recalibrationOvernum基准值更新阈值
 @Input				void
 @Return				recalibrationOvernum
**********************************************************************************************************/
unsigned char INSPECT_FLOW_Para_GetRecalibrationOvernum(void)
{
	return InspectFlowClientHandler.Configuration.recalibrationOvernum;
}

/**********************************************************************************************************
 @Function			void INSPECT_FLOW_Para_SetRecalibrationOvertime(unsigned char recalibrationOvertime)
 @Description			INSPECT_FLOW_Para_SetRecalibrationOvertime		: 设置recalibrationOvertime背景值重新计算时间
 @Input				recalibrationOvertime
 @Return				void
**********************************************************************************************************/
void INSPECT_FLOW_Para_SetRecalibrationOvertime(unsigned char recalibrationOvertime)
{
	recalibrationOvertime = (recalibrationOvertime > 15) ? 15 : recalibrationOvertime;
	
	InspectFlowClientHandler.Configuration.recalibrationOvertime = recalibrationOvertime;
	
	switch (InspectFlowClientHandler.Configuration.magMeasureFreq)
	{
	case MEASURE_FREQ_10HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 600 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	
	case MEASURE_FREQ_50HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 3000 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	
	case MEASURE_FREQ_100HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 6000 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	
	case MEASURE_FREQ_200HZ:
		InspectFlowClientHandler.Configuration.recalibrationOvertimeCnt = 12000 * InspectFlowClientHandler.Configuration.recalibrationOvertime;
		break;
	}
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_GetRecalibrationOvertime(void)
 @Description			INSPECT_FLOW_Para_GetRecalibrationOvertime		: 读取recalibrationOvertime背景值重新计算时间
 @Input				void
 @Return				recalibrationOvertime
**********************************************************************************************************/
unsigned char INSPECT_FLOW_Para_GetRecalibrationOvertime(void)
{
	return InspectFlowClientHandler.Configuration.recalibrationOvertime;
}


/**********************************************************************************************************
 @Function			unsigned int INSPECT_FLOW_Para_ObtainMagnetismScanCnt(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismScanCnt		: 获取MagnetismScanCnt地磁扫描次数
 @Input				void
 @Return				MagnetismScanCnt
**********************************************************************************************************/
unsigned int INSPECT_FLOW_Para_ObtainMagnetismScanCnt(void)
{
	return InspectFlowClientHandler.DetectCtrl.detectCnt;
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_ObtainCarFlowStatus(void)
 @Description			INSPECT_FLOW_Para_ObtainCarFlowStatus			: 获取CarFlowStatus车辆状态值
 @Input				void
 @Return				CarFlowStatus
**********************************************************************************************************/
unsigned char INSPECT_FLOW_Para_ObtainCarFlowStatus(void)
{
	return InspectFlowClientHandler.DetectCtrl.bInStatus;
}

/**********************************************************************************************************
 @Function			unsigned short INSPECT_FLOW_Para_ObtainCarFlowNumber(void)
 @Description			INSPECT_FLOW_Para_ObtainCarFlowNumber			: 获取CarFlowNumber车辆数
 @Input				void
 @Return				CarFlowNumber
**********************************************************************************************************/
unsigned short INSPECT_FLOW_Para_ObtainCarFlowNumber(void)
{
	return InspectFlowClientHandler.Parameter.carNumber;
}

/**********************************************************************************************************
 @Function			unsigned char INSPECT_FLOW_Para_ObtainMagnetismDiff(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismDiff			: 获取MagnetismDiff地磁变化值
 @Input				void
 @Return				MagnetismDiff
**********************************************************************************************************/
unsigned short INSPECT_FLOW_Para_ObtainMagnetismDiff(void)
{
	return InspectFlowClientHandler.Parameter.magnetismDiff;
}

/**********************************************************************************************************
 @Function			signed short INSPECT_FLOW_Para_ObtainMagnetismX(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismX				: 获取MagnetismX地磁X轴值
 @Input				void
 @Return				MagnetismX
**********************************************************************************************************/
signed short INSPECT_FLOW_Para_ObtainMagnetismX(void)
{
	return InspectFlowClientHandler.magnetismX;
}

/**********************************************************************************************************
 @Function			signed short INSPECT_FLOW_Para_ObtainMagnetismY(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismY				: 获取MagnetismY地磁Y轴值
 @Input				void
 @Return				MagnetismY
**********************************************************************************************************/
signed short INSPECT_FLOW_Para_ObtainMagnetismY(void)
{
	return InspectFlowClientHandler.magnetismY;
}

/**********************************************************************************************************
 @Function			signed short INSPECT_FLOW_Para_ObtainMagnetismZ(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismZ				: 获取MagnetismZ地磁Z轴值
 @Input				void
 @Return				MagnetismZ
**********************************************************************************************************/
signed short INSPECT_FLOW_Para_ObtainMagnetismZ(void)
{
	return InspectFlowClientHandler.magnetismZ;
}

/**********************************************************************************************************
 @Function			signed short INSPECT_FLOW_Para_ObtainMagnetismBackX(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismBackX			: 获取MagnetismBackX地磁X轴背景值
 @Input				void
 @Return				MagnetismBackX
**********************************************************************************************************/
signed short INSPECT_FLOW_Para_ObtainMagnetismBackX(void)
{
	return InspectFlowClientHandler.Parameter.magnetismBackX;
}

/**********************************************************************************************************
 @Function			signed short INSPECT_FLOW_Para_ObtainMagnetismBackY(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismBackY			: 获取MagnetismBackY地磁Y轴背景值
 @Input				void
 @Return				MagnetismBackY
**********************************************************************************************************/
signed short INSPECT_FLOW_Para_ObtainMagnetismBackY(void)
{
	return InspectFlowClientHandler.Parameter.magnetismBackY;
}

/**********************************************************************************************************
 @Function			signed short INSPECT_FLOW_Para_ObtainMagnetismBackZ(void)
 @Description			INSPECT_FLOW_Para_ObtainMagnetismBackZ			: 获取MagnetismBackZ地磁Z轴背景值
 @Input				void
 @Return				MagnetismBackZ
**********************************************************************************************************/
signed short INSPECT_FLOW_Para_ObtainMagnetismBackZ(void)
{
	return InspectFlowClientHandler.Parameter.magnetismBackZ;
}


























/********************************************** END OF FLEE **********************************************/
