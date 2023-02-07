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
#include "../../Config/inc/CanTrcv_PbCfg.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/


typedef struct {
    uint8          CanIf_Ctrl_Id;
    boolean        CanIf_Ctrl_Wakeup_Support;
    Can_Controller CanIf_Ctrl_Can_Ctrl_Ref;
} CanIf_Ctrl_Cfg;

typedef struct {
    uint32 CanIf_Hrh_Range_Base_Id;
    uint32 CanIf_Hrh_Range_Mask;
    uint32 CanIf_Hrh_Range_Rx_Pdu_Lower_CanId;
    Can_Id_Type_Enum CanIf_Hrh_Range_Rx_Pdu_Range_CanId_Type;
    uint32 CanIf_Hrh_Range_Rx_Pdu_Upper_CanId;
} CanIf_Hrh_Range_Cfg;

typedef struct {
    void (*CanIfDispatchUserCheckTrcvWakeFlagIndicationName)(void);
    void (*CanIfDispatchUserCheckTrcvWakeFlagIndicationUL)(void);
    void (*CanIfDispatchUserClearTrcvWufFlagIndicationName)(void);
    void (*CanIfDispatchUserClearTrcvWufFlagIndicationUL)(void);
    void (*CanIfDispatchUserConfirmPnAvailabilityName)(void);
    void (*CanIfDispatchUserConfirmPnAvailabilityUL)(void);
    void (*CanIfDispatchUserCtrlBusOffName)(void);
    void (*CanIfDispatchUserCtrlBusOffUL)(void);
    void (*CanIfDispatchUserCtrlModeIndicationName)(void);
    void (*CanIfDispatchUserCtrlModeIndicationUL)(void);
    void (*CanIfDispatchUserTrcvModeIndicationUL)(void);
    void (*CanIfDispatchUserValidateWakeupEventName)(void);
    void (*CanIfDispatchUserValidateWakeupEventUL)(void);
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
    uint8            CanIf_Trcv_Id;
    boolean          CanIf_Trcv_Wakeup_Support;
    CanTrcv_Channel Can_Trcv_Channel_Ref;
} CanIf_Trcv_Cfg;

typedef struct {
    CanIf_Trcv_Cfg CanIf_Trcv_Cfg_Ref;
} CanIf_Trcv_Drv_Cfg;

typedef struct {
    boolean             CanIf_Hrh_Software_Filter;
    CanIf_Ctrl_Cfg      CanIf_Hrh_Can_Ctrl_Id_Ref;
    Can_Hardware_Object CanIf_Hrh_Id_Sym_Ref;
} CanIf_Hrh_Cfg;

typedef struct {
    CanIf_Ctrl_Cfg      CanIf_Hth_Can_Ctrl_Id_Ref;
    Can_Hardware_Object CanIf_Hth_Id_Sym_Ref;
} CanIf_Hth_Cfg;

typedef struct {
    CanIf_Hrh_Cfg  CanIf_Hrh_Cfg_Ref;
    CanIf_Hth_Cfg  CanIf_Hth_Cfg_Ref;
} CanIf_Init_Hoh_Cfg;

typedef struct {
    uint8         CanIfBufferSize;
    CanIf_Hth_Cfg CanIf_Buffer_Hth_Ref;
} CanIf_Buffer_Cfg;

typedef struct {
    uint32 CanIf_Rx_Pdu_CanId_Range_Lower_CanId;
    uint32 CanIf_Rx_Pdu_CanId_Range_Upper_CanId;
} CanIf_Rx_Pdu_CanId_Range;

typedef struct {
    uint32                     CanIf_Rx_Pdu_CanId;
    uint32                     CanIf_Rx_Pdu_CanId_Mask;
    uint8                      CanIf_Rx_Pdu_Data_Length;
    boolean                    CanIf_Rx_Pdu_Data_Length_Check;
    uint32                     CanIf_Rx_Pdu_Id;
    boolean                    CanIf_Rx_Pdu_Read_Data;
    boolean                    CanIf_Rx_Pdu_Read_Notify_Status;
    void(*CanIfRxPduUserRxIndicationName)(void);
    void(*CanIfRxPduUserRxIndicationUL)(void);
    CanIf_Hrh_Cfg              Can_If_Rx_Pdu_Hrh_Id_Ref;
    uint32                     Can_If_Rx_Pdu_Ref;
    CanIf_Rx_Pdu_CanId_Range   CanIf_Rx_Pdu_CanId_Range_Ref;
    uint32                     CanIf_TT_Rx_Frame_Triggering_Ref;
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
    void(*CanIfTxPduUserTriggerTransmitName)(void);
    void(*CanIfTxPduUserTxConfirmationName)(void);
    void(*CanIfTxPduUserTxConfirmationUL)(void);
    CanIf_Buffer_Cfg       CanIf_Buffer_Cfg;
    uint32                 Can_If_Tx_Pdu_Ref;
} CanIf_Tx_Pdu_Cfg;

typedef struct {
    CanIf_Init_Hoh_Cfg     CanIf_Ctrl_Drv_Init_Hoh_Config_Ref;
    Can_General            CanIf_Ctrl_Drv_Name_Ref;
    CanIf_Ctrl_Cfg         CanIf_Ctrl_Cfg_Ref;
} CanIf_Ctrl_Drv_Cfg;

typedef struct {
    uint8                 CanIf_Init_Config_Set;
    uint64                CanIf_Max_Buffer_Size;
    uint64                CanIf_Max_Rx_Pdu_Cfg;
    uint64                CanIf_Max_Tx_Pdu_Cfg;
    CanIf_Buffer_Cfg      CanIf_Buffer_Cfg_Ref;
    CanIf_Init_Hoh_Cfg    CanIf_Init_Hoh_Config_Ref;
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
