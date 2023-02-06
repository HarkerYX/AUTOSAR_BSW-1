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
    CanIf_Init_Config_Set
    CanIf_Init_Hoh_Config
    CanIf_RX_Pdu_Config
    CanIf_TX_Pdu_Config
    CanIf_Buffer_Config
    CanIf_Max_Tx_Pdu_Config
    CanIf_Max_Rx_Pdu_Config
} CanIf_Init_Config;

#endif //AUTOSAR_LIB_CANIF_PBCFG_H
