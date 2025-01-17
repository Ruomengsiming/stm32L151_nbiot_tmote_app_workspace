/**
  *********************************************************************************************************
  * @file    net_mqttsn_message_operate.c
  * @author  Movebroad -- KK
  * @version V1.0
  * @date    2018-03-02
  * @brief   
  *********************************************************************************************************
  * @attention
  *
  *
  *
  *********************************************************************************************************
  */

#include "net_mqttsn_message_operate.h"
#include "inspectmessageoperate.h"
#include "platform_config.h"
#include "platform_map.h"
#include "stm32l1xx_config.h"
#include "fifomessage.h"
#include "hal_rtc.h"
#include "radar_api.h"
#include "tmesh_algorithm.h"
#include "string.h"

#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
MQTTSN_SwapSendDataTypeDef		NETMqttSNMessageSendPark;
#endif

#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
#define MESSAGEMQTTSNFIFO_SENDPARKNUM_MAX		NETFIFO_MQTTSNSENDPARKNUM_MAX
#define MESSAGEMQTTSNFIFO_SENDPARKSIZE_MAX		NETFIFO_MQTTSNSENDPARKSIZE_MAX

MessageFifoTypeDef			NETMqttSNFifoMessageSendPark;

unsigned char				MqttSNFifoMessageSendBuf[MESSAGEMQTTSNFIFO_SENDPARKSIZE_MAX];
#endif

/**********************************************************************************************************
 @Function			int NET_MQTTSN_Message_Operate_Creat_Json_Work_Info(char* outBuffer)
 @Description			NET_MQTTSN_Message_Operate_Creat_Json_Work_Info
 @Input				outBuffer
 @Return				Length
 @attention			!!<<< MaxLength 450Byte >>>!!
**********************************************************************************************************/
int NET_MQTTSN_Message_Operate_Creat_Json_Work_Info(char* outBuffer)
{
	TCFG_EEPROM_GetMagTempCoef(&TCFG_SystemData.MagCoefX, &TCFG_SystemData.MagCoefY, &TCFG_SystemData.MagCoefZ);
	
	sprintf(outBuffer, 
		"{"
			"\"SN\":\"%08x\","
			"\"WorkInfo\":"
			"{"
				"\"Sense\":%d,"
				"\"Mode\":\"%s\","
				"\"Channel\":%d,"
				"\"Range\":%d,"
				"\"Earfcn\":%d,"
				"\"Tac\":\"%X\","
				"\"Ci\":\"%X\","
				"\"Cmdcnt\":\"%d.%d\","
				"\"Nbruntime\":\"%d.%d\","
				"\"APN\":\"%s\","
				"\"PCP\":\"%d.%d-%d.%d.V%d.%d\","
				"\"Coef\":\"%d.%d.%d\","
				"\"OOK\":[\"%X\",\"%X\",\"%X\",\"%X\",\"%X\"],"
				"\"RadioRv\":%d"
			"}"
		"}",
		
		TCFG_EEPROM_Get_MAC_SN(),
		TCFG_EEPROM_GetSavedSensitivity(),
		TCFG_EEPROM_Get_WorkMode_String(),
		TCFG_EEPROM_GetRfChannel(),
		TCFG_Utility_Get_DistanceRange(),
		TCFG_Utility_Get_Nbiot_RadioEARFCN(),
		TCFG_Utility_Get_Nbiot_NetworkRegStatusTac(),
		TCFG_Utility_Get_Nbiot_NetworkRegStatusCellID(),
		TCFG_EEPROM_GetRFCmdCnt(), TCFG_EEPROM_GetNBCmdCnt(),
		TCFG_Utility_GetCoapConnectTime(), TCFG_Utility_GetCoapIdleTime(),
		TCFG_Utility_Get_Nbiot_PDPContext_APN(),
		TCFG_Utility_Get_Nbiot_PCPUpgradeStartTimes(), TCFG_Utility_Get_Nbiot_PCPUpgradePackSliceIndex(), TCFG_Utility_Get_Nbiot_PCPUpgradePackSliceNum(),
		TCFG_Utility_Get_Nbiot_PCPUpgradePackSliceSize(), TCFG_Utility_Get_Nbiot_PCPPlatformSoftVersionMajor(), TCFG_Utility_Get_Nbiot_PCPPlatformSoftVersionSub(),
		TCFG_SystemData.MagCoefX, TCFG_SystemData.MagCoefY, TCFG_SystemData.MagCoefZ,
		TCFG_EEPROM_GetOOKKEYEncoded(0) >> 12, TCFG_EEPROM_GetOOKKEYEncoded(1) >> 12, TCFG_EEPROM_GetOOKKEYEncoded(2) >> 12, TCFG_EEPROM_GetOOKKEYEncoded(3) >> 12, TCFG_EEPROM_GetOOKKEYEncoded(4) >> 12,
		TCFG_Utility_Get_RadioGatewayNearby()
	);
	
	return strlen(outBuffer);
}

/**********************************************************************************************************
 @Function			int NET_MQTTSN_Message_Operate_Creat_Json_Basic_Info(char* outBuffer)
 @Description			NET_MQTTSN_Message_Operate_Creat_Json_Basic_Info
 @Input				outBuffer
 @Return				Length
 @attention			!!<<< MaxLength 450Byte >>>!!
**********************************************************************************************************/
int NET_MQTTSN_Message_Operate_Creat_Json_Basic_Info(char* outBuffer)
{
	sprintf(outBuffer, 
		"{"
			"\"SN\":\"%08x\","
			"\"TMoteInfo\":"
			"{"
				"\"Type\":\"%d.1\","
				"\"Vender\":\"%s\","
				"\"Hard\":\"%s\","
				"\"Soft\":\"%d:%d.%d\","
				"\"Sim\":\"%s\","
				"\"Imei\":\"%s\","
				"\"Imsi\":\"%s\","
				"\"Nbvender\":\"%s\","
				"\"Nbmode\":\"%s\","
				"\"Boot\":\"%d.%d.%d\","
				"\"Ver\":\"%s\","
				"\"Rmold\":%d,"
				"\"Rvcc\":%d"
			"}"
		"}",
		
		TCFG_EEPROM_Get_MAC_SN(),
		TCFG_Utility_Get_Mvb_ModelType(),
		TCFG_EEPROM_Get_Vender_String(),
		TCFG_Utility_Get_Hardwear_Version_String(),
		TCFG_EEPROM_GetBootVersion(), TCFG_Utility_Get_Major_Softnumber(), TCFG_Utility_Get_Sub_Softnumber(),
		TCFG_Utility_Get_Nbiot_Iccid_String(),
		TCFG_Utility_Get_Nbiot_Imei_String(),
		TCFG_Utility_Get_Nbiot_Imsi_String(),
		TCFG_Utility_Get_Nbiot_Manufacturer(),
		TCFG_Utility_Get_Nbiot_Manufacturermode(),
		TCFG_Utility_Get_SoftResetFlag(), TCFG_Utility_Get_Device_BootCount(), TCFG_EEPROM_GetDeviceRbtMode(),
		TCFG_Utility_Get_Nbiot_ModelVersion(),
		Radar_GetModel(),
		Radar_Get_RadarVcc()
	);
	
	return strlen(outBuffer);
}

/**********************************************************************************************************
 @Function			int NET_MQTTSN_Message_Operate_Creat_Json_Dynamic_Info(char* outBuffer)
 @Description			NET_MQTTSN_Message_Operate_Creat_Json_Dynamic_Info
 @Input				outBuffer
 @Return				Length
 @attention			!!<<< MaxLength 450Byte >>>!!
**********************************************************************************************************/
int NET_MQTTSN_Message_Operate_Creat_Json_Dynamic_Info(char* outBuffer)
{
	sprintf(outBuffer, 
		"{"
			"\"SN\":\"%08x\","
			"\"TMoteInfo\":"
			"{"
				"\"RT\":%d,"
				"\"Batt\":%d,"
				"\"RAlib\":[%d,%d],"
				"\"Rcnt\":%d,"
				"\"Temp\":%d,"
				"\"Qmcrbt\":%d,"
				"\"Nbrun\":[%d,%d,%d,%d,%d],"
				"\"Indelay\":%d,"
				"\"Gain\":[%d,%d],"
				"\"Smode\":%d,"
				"\"Sinter\":%d,"
				"\"hpass\":%d,"
				"\"x\":[%d,%d,%d,%d,%d],"
				"\"y\":[%d,%d,%d,%d,%d],"
				"\"z\":[%d,%d,%d,%d,%d]"
			"}"
		"}",
		
		TCFG_EEPROM_Get_MAC_SN(),
		TCFG_Utility_Get_Run_Time() / 60 / 60,
		TCFG_Utility_Get_Device_Batt_ShortVal(),
		TCFG_Utility_Get_RadarLibNum(),
		TCFG_Utility_Get_AlgoLibNum(),
		TCFG_GetRadarCount(),
		TCFG_Utility_Get_Device_Temperature(),
		TCFG_Utility_Get_ReInitModuleCount(),
		TCFG_Utility_Get_Nbiot_BootCount(), TCFG_Utility_Get_Nbiot_SentCount(), TCFG_Utility_Get_Nbiot_RecvCount(), TCFG_Utility_Get_NBIot_SentCountLimit(), (TCFG_EEPROM_GetNbiotHeart() * 15),
		TCFG_EEPROM_GetCarInDelay(),
		TCFG_Utility_Get_GainCover(), TCFG_EEPROM_GetRadarGain(),
		TCFG_EEPROM_GetSenseMode(),
		Radar_Get_SampleInterval(),
		tradar_get_highpass(),
		TCFG_EEPROM_GetMagManualBack(0, TCFG_X_AXIS),
		TCFG_EEPROM_GetMagManualBack(1, TCFG_X_AXIS),
		TCFG_EEPROM_GetMagManualBack(2, TCFG_X_AXIS),
		TCFG_EEPROM_GetMagManualBack(3, TCFG_X_AXIS),
		TCFG_EEPROM_GetMagManualBack(4, TCFG_X_AXIS),
		TCFG_EEPROM_GetMagManualBack(0, TCFG_Y_AXIS),
		TCFG_EEPROM_GetMagManualBack(1, TCFG_Y_AXIS),
		TCFG_EEPROM_GetMagManualBack(2, TCFG_Y_AXIS),
		TCFG_EEPROM_GetMagManualBack(3, TCFG_Y_AXIS),
		TCFG_EEPROM_GetMagManualBack(4, TCFG_Y_AXIS),
		Qmc5883lHistoryBack.Z_Back[0],
		Qmc5883lHistoryBack.Z_Back[1],
		Qmc5883lHistoryBack.Z_Back[2],
		Qmc5883lHistoryBack.Z_Back[3],
		Qmc5883lHistoryBack.Z_Back[4]
#if 0
		TCFG_EEPROM_GetMagManualBack(0, TCFG_Z_AXIS),
		TCFG_EEPROM_GetMagManualBack(1, TCFG_Z_AXIS),
		TCFG_EEPROM_GetMagManualBack(2, TCFG_Z_AXIS),
		TCFG_EEPROM_GetMagManualBack(3, TCFG_Z_AXIS),
		TCFG_EEPROM_GetMagManualBack(4, TCFG_Z_AXIS)
#endif
	);
	
	return strlen(outBuffer);
}

/**********************************************************************************************************
 @Function			int NET_MQTTSN_Message_Operate_Creat_Json_Response_Info(char* outBuffer, u16 errcode, char msgId)
 @Description			NET_MQTTSN_Message_Operate_Creat_Json_Response_Info
 @Input				outBuffer
					errcode
 @Return				Length
 @attention			!!<<< MaxLength 450Byte >>>!!
**********************************************************************************************************/
int NET_MQTTSN_Message_Operate_Creat_Json_Response_Info(char* outBuffer, u16 errcode, char msgId)
{
	sprintf(outBuffer, 
		"{"
			"\"SN\":\"%08x\","
			"\"ResponseInfo\":"
			"{"
				"\"ret\":%d,"
				"\"msgid\":\"%c\""
			"}"
		"}",
		
		TCFG_EEPROM_Get_MAC_SN(),
		errcode,
		msgId
	);
	
	return strlen(outBuffer);
}

/**********************************************************************************************************
 @Function			void NET_MqttSN_FifoSendMessageInit(void)
 @Description			NET_MqttSN_FifoSendMessageInit	: 发送数据Fifo初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
void NET_MqttSN_FifoSendMessageInit(void)
{
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
	netMessageFifoInit(&NETMqttSNFifoMessageSendPark, MqttSNFifoMessageSendBuf, sizeof(MqttSNFifoMessageSendBuf), MESSAGEMQTTSNFIFO_SENDPARKNUM_MAX);
#endif
}

#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
/**********************************************************************************************************
 @Function			bool NET_MqttSN_Message_SendDataisFull(void)
 @Description			NET_MqttSN_Message_SendDataisFull	: 检查发送队列是否已满
 @Input				void
 @Return				true							: 已满
					false						: 未满
**********************************************************************************************************/
bool NET_MqttSN_Message_SendDataisFull(void)
{
	bool MessageState;
	
	if ((NETMqttSNMessageSendPark.Rear + 1) % MQTTSN_SEND_PARK_NUM == NETMqttSNMessageSendPark.Front) {
		MessageState = true;
	}
	else {
		MessageState = false;
	}
	
	return MessageState;
}
#endif

/**********************************************************************************************************
 @Function			bool NET_MqttSN_Message_SendDataisEmpty(void)
 @Description			NET_MqttSN_Message_SendDataisEmpty	: 检查发送队列是否已空
 @Input				void
 @Return				true							: 已空
					false						: 未空
**********************************************************************************************************/
bool NET_MqttSN_Message_SendDataisEmpty(void)
{
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
	bool MessageState;
	
	if (NETMqttSNMessageSendPark.Front == NETMqttSNMessageSendPark.Rear) {
		MessageState = true;
	}
	else {
		MessageState = false;
	}
	
	return MessageState;
#endif
	
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
	return netMessageFifoisEmpty(&NETMqttSNFifoMessageSendPark);
#endif
}

/**********************************************************************************************************
 @Function			void NET_MqttSN_Message_SendDataEnqueue(unsigned char* dataBuf, unsigned short dataLength)
 @Description			NET_MqttSN_Message_SendDataEnqueue	: 发送数据写入队列
 @Input				dataBuf	 		 			: 需写入数据
					dataLength					: 需写入数据长度
 @Return				void
**********************************************************************************************************/
void NET_MqttSN_Message_SendDataEnqueue(unsigned char* dataBuf, unsigned short dataLength)
{
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
	if ((dataBuf == NULL) || (dataLength > MQTTSN_SEND_BUFFER_SIZE)) {
		return;
	}
	
	NETMqttSNMessageSendPark.Rear = (NETMqttSNMessageSendPark.Rear + 1) % MQTTSN_SEND_PARK_NUM;				//队尾偏移1
	memset((u8 *)&NETMqttSNMessageSendPark.Park[NETMqttSNMessageSendPark.Rear], 0x0, sizeof(NETMqttSNMessageSendPark.Park[NETMqttSNMessageSendPark.Rear]));
	memcpy(NETMqttSNMessageSendPark.Park[NETMqttSNMessageSendPark.Rear].Buffer, dataBuf, dataLength);
	NETMqttSNMessageSendPark.Park[NETMqttSNMessageSendPark.Rear].Length = dataLength;
	
	if (NET_MqttSN_Message_SendDataisFull() == true) {												//队列已满
		NETMqttSNMessageSendPark.Front = (NETMqttSNMessageSendPark.Front + 1) % MQTTSN_SEND_PARK_NUM;			//队头偏移1
	}
#endif
	
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
	netMessageFifoEnqueue(&NETMqttSNFifoMessageSendPark, dataBuf, dataLength);
#endif
}

/**********************************************************************************************************
 @Function			bool NET_MqttSN_Message_SendDataDequeue(unsigned char* dataBuf, unsigned short* dataLength)
 @Description			NET_MqttSN_Message_SendDataDequeue	: 发送数据读出队列
 @Input				dataBuf	 		 			: 需读出数据地址
					dataLength					: 需读出数据长度地址
 @Return				true							: 未空
					false						: 已空
**********************************************************************************************************/
bool NET_MqttSN_Message_SendDataDequeue(unsigned char* dataBuf, unsigned short* dataLength)
{
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
	bool MessageState;
	unsigned char front;
	
	if (NET_MqttSN_Message_SendDataisEmpty() == true) {												//队列已空
		MessageState = false;
	}
	else {																					//队列未空
		front = (NETMqttSNMessageSendPark.Front + 1) % MQTTSN_SEND_PARK_NUM;								//队头偏移1
		memcpy(dataBuf, NETMqttSNMessageSendPark.Park[front].Buffer, NETMqttSNMessageSendPark.Park[front].Length);
		*dataLength = NETMqttSNMessageSendPark.Park[front].Length;
		MessageState = true;
	}
	
	return MessageState;
#endif
	
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
	return netMessageFifoDequeue(&NETMqttSNFifoMessageSendPark, dataBuf, dataLength);
#endif
}

/**********************************************************************************************************
 @Function			bool NET_MqttSN_Message_SendDataOffSet(void)
 @Description			NET_MqttSN_Message_SendDataOffSet	: 发送数据队列(队列头偏移1)
 @Input				void
 @Return				true							: 未空
					false						: 已空
**********************************************************************************************************/
bool NET_MqttSN_Message_SendDataOffSet(void)
{
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
	bool MessageState;
	
	if (NET_MqttSN_Message_SendDataisEmpty() == true) {												//队列已空
		MessageState = false;
	}
	else {																					//队列未空
		NETMqttSNMessageSendPark.Front = (NETMqttSNMessageSendPark.Front + 1) % MQTTSN_SEND_PARK_NUM;
		MessageState = true;
	}
	
	return MessageState;
#endif
	
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
	return netMessageFifoDiscard(&NETMqttSNFifoMessageSendPark);
#endif
}

/**********************************************************************************************************
 @Function			unsigned char NET_MqttSN_Message_SendDataRear(void)
 @Description			NET_MqttSN_Message_SendDataRear	: 发送数据队尾值
 @Input				void
 @Return				发送数据队尾值
**********************************************************************************************************/
unsigned char NET_MqttSN_Message_SendDataRear(void)
{
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEDISABLE
	return NETMqttSNMessageSendPark.Rear;
#endif
	
#if NETFIFOMESSAGETYPE == NETFIFOMESSAGEENABLE
	return netMessageFifoRear(&NETMqttSNFifoMessageSendPark);
#endif
}

/********************************************** END OF FLEE **********************************************/
