/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanIf_PbCfg.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANIF_PBCFG_H
#define AUTOSAR_LIB_CANIF_PBCFG_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"
#include "../../Config/inc/CanDrv_PbCfg.h"
#include "../../Config/inc/Can_Types.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/


typedef struct {

} CanIf_Ctrl_Cfg;

typedef struct {
    uint32 CanIf_Hrh_Range_Base_Id;
    uint32 CanIf_Hrh_Range_Mask;
    uint32 CanIf_Hrh_Range_Rx_Pdu_Lower_CanId;
    Can_Id_Type_Enum CanIf_Hrh_Range_Rx_Pdu_Range_CanId_Type;
    uint32 CanIf_Hrh_Range_Rx_Pdu_Upper_CanId;
} CanIf_Hrh_Range_Cfg;

typedef struct {
    boolean             CanIf_Hrh_Software_Filter;
    CanIf_Ctrl_Cfg      CanIf_Hrh_Can_Ctrl_Id_Ref;
    Can_Hardware_Object CanIf_Hrh_Id_Sym_Ref;
    CanIf_Hrh_Range_Cfg CanIf_Hrh_Range_Cfg_Impl;
} CanIf_Hrh_Config;

typedef struct {
    CanIf_Hrh_Config
    CanIf_Hth_Config
} CanIf_Init_Hoh_Config;

typedef struct {

} CanIf_Ctrl_Drv_Cfg;

typedef struct {

} CanIf_Dispatch_Cfg;

typedef struct {
    boolean                   CanIf_Fixed_Buffer;
    boolean                   CanIf_Private_Data_Length_Check;
    Can_SW_Filter_Method_Enum CanIf_Private_Software_Filter_Type;
    boolean                   CanIf_Support_TTCAN;
} CanIf_Private_Cfg;

typedef struct {
    boolean CanIf_Bus_Mirroring_Support;
    boolean CanIf_Dev_Error_Detect;
    boolean CanIf_MetaData_Support;
    char    CanIf_Public_Cdd_Header_File[30];
    Can_HW_Handle_Type_Enum CanIf_Public_HandleType_Enum;
    boolean CanIf_Public_Icom_Support;
    boolean CanIf_Public_Multiple_Drv_Support;
    boolean CanIf_Public_Pn_Support;
    boolean CanIf_Public_Read_Rx_Pdu_Data_Api;
    boolean CanIf_Public_Read_Rx_Pdu_Notify_Status_Api;
    boolean CanIf_Public_Read_Tx_Pdu_Notify_Status_Api;
    boolean CanIf_Public_Set_Dynamic_Tx_Id_Api;
    boolean CanIf_Public_Tx_Buffering;
    boolean CanIf_Public_Tx_Confirm_Polling_Support;
    boolean CanIf_Public_Wakeup_Check_Valid_By_NM;
    boolean CanIf_Public_Wakeup_Check_Valid_Support;
    boolean CanIf_Set_Baudrate_Api;
    boolean CanIf_Trigger_Transmit_Support;
    boolean CanIf_Tx_Offline_Active_Support;
    boolean CanIf_Version_Info_Api;
    boolean CanIf_Wakeup_Support;
} CanIf_Public_Cfg;

typedef struct {

} CanIf_Trcv_Drv_Cfg;

typedef struct {

} CanIf_Buffer_Cfg;

typedef struct {

} CanIf_Rx_Pdu_Cfg;

typedef struct {
    uint32                 CanIf_Tx_Pdu_CanId;
    uint32                 CanIf_Tx_Pdu_CanId_Mask;
    Can_LPdu_ID_Type_Enum  CanIf_Tx_Pdu_CanId_Type;
    uint32                 CanIf_Tx_Pdu_Id;
    boolean                CanIf_Tx_Pdu_Pn_Filter_Pdu;
    boolean                CanIf_Tx_Pdu_Read_Notify_Status;
    boolean                CanIf_Tx_Pdu_Trigger_Transmit;
    boolean                CanIf_Tx_Pdu_Truncation;
    CanIf_Tx_Pdu_Type_Enum CanIf_Tx_Pdu_Type;
} CanIf_Tx_Pdu_Cfg;

typedef struct {
    uint8                 CanIf_Init_Config_Set;
    uint64                CanIf_Max_Buffer_Size;
    uint64                CanIf_Max_Rx_Pdu_Cfg;
    uint64                CanIf_Max_Tx_Pdu_Cfg;
    CanIf_Buffer_Cfg      CanIf_Buffer_Cfg_Ref;
    CanIf_Init_Hoh_Config CanIf_Init_Hoh_Config_Ref;
    CanIf_Rx_Pdu_Cfg      CanIf_Rx_Pdu_Cfg_Ref;
    CanIf_Tx_Pdu_Cfg      CanIf_Tx_Pdu_Cfg_Ref;
} CanIf_Init_Config;

typedef struct {
    CanIf_Ctrl_Drv_Cfg CanIf_Ctrl_Drv_Cfg_Ref;
    CanIf_Dispatch_Cfg CanIf_Dispatch_Cfg_Ref;
    CanIf_Private_Cfg  CanIf_Private_Cfg_Ref;
    CanIf_Trcv_Drv_Cfg CanIf_Trcv_Drv_Cfg_Ref;
} CanIf;

#endif //AUTOSAR_LIB_CANIF_PBCFG_H
