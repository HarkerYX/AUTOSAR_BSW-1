/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanDrv_Pbfg.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANDRV_PBCFG_H
#define AUTOSAR_LIB_CANDRV_PBCFG_H

/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"
#include "../../Config/inc/Can_Types.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {
    uint32         Can_Controller_BaudRate;
    uint8          Can_Controller_BaudRate_Config_ID;
    uint8          Can_Controller_PropSeg;
    uint8          Can_Controller_Seg_1;
    uint8          Can_Controller_Seg_2;
    uint8          Can_Controller_Sync_Jump_Width;
} Can_Controller_Baudrate_Config;

typedef struct {
    uint32         Can_Controller_Fd_BaudRate;
    uint8          Can_Controller_Fd_BaudRate_Config_ID;
    uint8          Can_Controller_Fd_PropSeg;
    uint8          Can_Controller_Fd_Seg_1;
    uint8          Can_Controller_Fd_Seg_2;
    uint8          Can_Controller_Ssp_Offset;
    uint8          Can_Controller_Sync_Jump_Width;
    boolean        Can_Controller_Tx_Bit_Rate_Switch
} Can_Controller_Fd_Baudrate_Config;

typedef struct {
    Can_Opertaion_Mode_Enum        Can_Busoff_Processing;
    boolean                        Can_Controller_Activation;
    uint32                         Can_Controller_BaseAddress;
    uint8                          Can_Controller_Id;
    Can_Opertaion_Mode_Enum        Can_Rx_Processing;
    Can_Opertaion_Mode_Enum        Can_Tx_Processing;
    boolean                        Can_Wakeup_Functionality_API;
    Can_Opertaion_Mode_Enum        Can_Wakeup_Processing;
    boolean                        Can_Wakeup_Support;
    Can_Controller_Baudrate_Config *Can_Controller_Default_Baudrate_Ref;
} Can_Controller;

typedef struct {
    uint32 Can_MainFunction_Period;
} Can_MainFunction_RW_Period;

typedef struct {
    uint8                          CanFd_Padding_Value;
    Can_Handle_Type_Enum           Can_Handle_Type;
    boolean                        Can_Hardware_Object_Uses_Polling;
    uint16                         Can_Hardware_Object_Count;
    Can_Id_Type_Enum               Can_Id_Type;
    uint8                          Can_Object_Id;
    Can_Object_Type_Enum           Can_Object_Type;
    boolean                        Can_Trigger_Transmit_enable;
    Can_Controller                 *Can_Controller_Ref;
    Can_MainFunction_RW_Period     *Can_MainFunction_RW_Period_Ref;
} Can_Hardware_Object;

typedef struct {
    uint32 Can_Hw_Filter_Code;
    uint32 Can_Hw_Filter_Mask;
} Can_Hw_Filter;

typedef struct {
    boolean         Can_Dev_Error_Detect;
    uint8           Can_Index;
    void            (*Can_LPdu_Receive_Callout_Function)(void);
    uint32          Can_MainFunction_Busoff_Period;
    boolean         Can_Multiplexed_Transmission;
    boolean         Can_Public_Icom_Support;
    boolean         Can_Set_Baudrate_Api;
    float32         Can_Timeout_Duration;
    boolean         CanVersionInfoApi;
} Can_General;

typedef struct {
    uint64           Can_Icom_Signal_Mask;
    Can_Compare_Enum Can_Icom_Signal_Operation;
    uint64           Can_Icom_Rx_Message_Signal_Config;
} Can_Icom_Rx_Message_Signal_Config;

typedef struct {
    uint8   Can_Icom_Counter_Value;
    uint16  Can_Icom_Message_Id;
    uint16  Can_Icom_Message_Id_Mask;
    sint32  Can_Icom_Missing_Message_Timer_Value;
    boolean Can_Icom_Payload_Length_Error;
    Can_Icom_Rx_Message_Signal_Config *Can_Icom_Rx_Message_Signal_Config_Ref;
} Can_Icom_Rx_Message;

typedef struct {
    Can_Icom_Rx_Message *Can_Icom_Rx_Message_Ref;
} Can_Icom_Wakeup_Causes;

typedef struct {
    uint8                  Can_Icom_Config_Id;
    boolean                Can_Icom_WakeOn_BusOff;
    Can_Icom_Wakeup_Causes *Can_Icom_Wakeup_Causes_Ref;
} Can_Icom;

typedef struct {
    Can_Controller      *Can_Controller_Ref;
    Can_Hardware_Object *Can_Hardware_Object_Ref;
    Can_Icom            *Can_Icom_Ref;
} Can_Config_Set;


typedef struct {
    Can_Config_Set  *Can_Config_Set_Ref;
    Can_General     *Can_General_Ref;
} Can;

#endif //AUTOSAR_LIB_CANDRV_PBCFG_H
