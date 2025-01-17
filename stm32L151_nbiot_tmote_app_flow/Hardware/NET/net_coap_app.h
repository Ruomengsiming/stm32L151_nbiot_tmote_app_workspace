#ifndef __NET_COAP_APP_H
#define   __NET_COAP_APP_H

#include "sys.h"
#include "nbiotconfig.h"
#include "nbiotfunc.h"
#include "nbiottransport.h"
#include "net_coap_message_operate.h"
#include "net_pcp_message_operate.h"
#include "platform_map.h"

#define COAP_DEBUG_LOG_RF_PRINT											//定义开启RF输出DEBUG信息
#define COAP_DEBUG_LOG_PRINTF				Radio_Trf_Debug_Printf_Level2			//定义开启RF输出DEBUG信息函数

void NET_COAP_APP_PollExecution(NBIOT_ClientsTypeDef* pClient);					//COAP逻辑处理
void NET_COAP_NBIOT_Event_StopMode(NBIOT_ClientsTypeDef* pClient);				//停止模式
void NET_COAP_NBIOT_Event_HardwareReboot(NBIOT_ClientsTypeDef* pClient);			//硬件重启
void NET_COAP_NBIOT_Event_ReportError(NBIOT_ClientsTypeDef* pClient);				//错误码输出
void NET_COAP_NBIOT_Event_ModuleCheck(NBIOT_ClientsTypeDef* pClient);				//模块检测
void NET_COAP_NBIOT_Event_ParameterConfig(NBIOT_ClientsTypeDef* pClient);			//参数配置
void NET_COAP_NBIOT_Event_SimICCIDCheck(NBIOT_ClientsTypeDef* pClient);			//Sim卡检测
void NET_COAP_NBIOT_Event_FullFunctionality(NBIOT_ClientsTypeDef* pClient);		//完整功能
void NET_COAP_NBIOT_Event_MinimumFunctionality(NBIOT_ClientsTypeDef* pClient);		//最小功能
void NET_COAP_NBIOT_Event_CDPServerCheck(NBIOT_ClientsTypeDef* pClient);			//CDP服务器查询
void NET_COAP_NBIOT_Event_CDPServerConfig(NBIOT_ClientsTypeDef* pClient);			//CDP服务器配置
void NET_COAP_NBIOT_Event_NbandModeCheck(NBIOT_ClientsTypeDef* pClient);			//NBAND模式查询
void NET_COAP_NBIOT_Event_NbandModeConfig(NBIOT_ClientsTypeDef* pClient);			//NBAND模式配置
void NET_COAP_NBIOT_Event_MiscEquipConfig(NBIOT_ClientsTypeDef* pClient);			//其他配置
void NET_COAP_NBIOT_Event_AttachCheck(NBIOT_ClientsTypeDef* pClient);				//注网检查
void NET_COAP_NBIOT_Event_AttachExecute(NBIOT_ClientsTypeDef* pClient);			//注网进行
void NET_COAP_NBIOT_Event_AttachInquire(NBIOT_ClientsTypeDef* pClient);			//注网查询
void NET_COAP_NBIOT_Event_ParameterCheckOut(NBIOT_ClientsTypeDef* pClient);		//参数检出
void NET_COAP_NBIOT_Event_SendData(NBIOT_ClientsTypeDef* pClient);				//发送数据
void NET_COAP_NBIOT_Event_RecvData(NBIOT_ClientsTypeDef* pClient);				//接收数据
void NET_COAP_NBIOT_Event_SendDataRANormal(NBIOT_ClientsTypeDef* pClient);			//发送数据RANormal
void NET_COAP_NBIOT_Event_RecvDataRANormal(NBIOT_ClientsTypeDef* pClient);			//接收数据RANormal
void NET_COAP_NBIOT_Event_ExecutDownlinkData(NBIOT_ClientsTypeDef* pClient);		//下行数据处理

void NET_COAP_Listen_PollExecution(NBIOT_ClientsTypeDef* pClient);				//COAP监听器处理
void NET_COAP_NBIOT_Listen_Event_EnterNone(NBIOT_ClientsTypeDef* pClient);			//事件(进入None模式)监听
#if NBCOAP_LISTEN_PARAMETER_TYPE == NBCOAP_LISTEN_PARAMETER_ENABLE
void NET_COAP_NBIOT_Listen_Enable_EnterParameter(NBIOT_ClientsTypeDef* pClient);	//使能(进入NBIOT运行信息)监听
void NET_COAP_NBIOT_Listen_Event_EnterParameter(NBIOT_ClientsTypeDef* pClient);		//事件(进入NBIOT运行信息)监听
#endif

#endif /* __NET_COAP_APP_H */
