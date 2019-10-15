#ifndef __CTWING_CONFIG_H
#define   __CTWING_CONFIG_H

#include "sys.h"
#include "nbiotconfig.h"
#include "net_nbiot_app.h"




/* CTWING 协议栈开辟缓存大小 */
#define CTWING_BUFFER_SIZE				512
#define CTWING_DATASTACK_SIZE				1100











typedef struct CTWING_ClientsTypeDef		CTWING_ClientsTypeDef;

/* CTWING Status */
typedef enum
{
	CTWING_OK       					= 0x00,
	CTWING_ERROR    					= 0x01,
	CTWING_CMD_TIMEOUT					= 0x02,
	
	/* -General Errors- */
	CTWING_Operation_not_allowed			= 3,
	CTWING_Operation_not_supported		= 4,
	CTWING_Need_to_enter_PIN				= 5,
	CTWING_Memory_failure				= 23,
	CTWING_No_Network_Service			= 30,
	CTWING_Incorrect_parameters			= 50,
	CTWING_Command_implemented_but		= 51,
	CTWING_Command_aborted_by_user		= 52,
	CTWING_Uplink_Busy_Flow_Control		= 159,
	CTWING_ME_failure					= 300,
	CTWING_SMS_service_of_ME_reserved		= 301,
	CTWING_operation_not_allowed			= 302,
	CTWING_operation_not_supported		= 303,
	CTWING_invalid_PDU_mode_parameter		= 304,
	CTWING_invalid_text_mode_parameter		= 305,
	CTWING_SIM_not_inserted				= 310,
	CTWING_SIM_PIN_required				= 311,
	CTWING_PH_SIM_PIN_required			= 312,
	CTWING_SIM_failure					= 313,
	CTWING_SIM_busy					= 314,
	CTWING_SIM_wrong					= 315,
	CTWING_SIM_PUK_required				= 316,
	CTWING_SIM_PIN2_required				= 317,
	CTWING_SIM_PUK2_required				= 318,
	CTWING_memory_failure				= 320,
	CTWING_invalid_memory_index			= 321,
	CTWING_memory_full					= 322,
	CTWING_SMSC_address_unknown			= 330,
	CTWING_no_network_service			= 331,
	CTWING_network_timeout				= 332,
	CTWING_acknowledgement_expected		= 340,
	CTWING_unknown_error				= 500,
	
	/* -HISI specific error codes- */
	CTWING_Required_parameter_not_configured= 512,
	CTWING_TUP_not_registered			= 513,
	CTWING_AT_Internal_Error				= 514,
	CTWING_CID_is_active				= 515,
	CTWING_Incorrect_State_for_Command		= 516,
	CTWING_Cid_is_invalid				= 517,
	CTWING_CID_is_not_active				= 518,
	CTWING_Deactive_last_active_cid		= 520,
	CTWING_Cid_is_not_defined			= 521,
	CTWING_Uart_parity_error				= 522,
	CTWING_Uart_frame_error				= 523,
	CTWING_Mt_not_power_on				= 524,
	CTWING_sent_data_sequence_repeat_error	= 525,
	CTWING_at_command_abort_error			= 526,
	CTWING_command_interrupted			= 527,
	CTWING_Configuration_conflicts		= 528,
	CTWING_FOTA_is_updating				= 529,
	CTWING_Not_the_at_allocated_socket		= 530
}CTWING_StatusTypeDef;








/* CTWING Transport */
struct CTWING_LWM2MTransportTypeDef
{
	NBIOT_ClientsTypeDef*				NBIotStack;
	
	//CTWING_StatusTypeDef				(*Write)(CTWING_ClientsTypeDef*, const char*, u16);
	//CTWING_StatusTypeDef				(*Read)(CTWING_ClientsTypeDef*, char*, u16*);
};

/* CTWING Clients */
struct CTWING_ClientsTypeDef
{
	unsigned char*						Sendbuf;
	unsigned char*						Recvbuf;
	size_t							Sendbuf_size;
	size_t							Recvbuf_size;
	short							Sendlen;
	short							Recvlen;
	unsigned char*						DataProcessStack;
	size_t							DataProcessStack_size;
	
	
	
	
	
	
	
};

/* Application Programming Interface */











#endif /* __CTWING_CONFIG_H */
