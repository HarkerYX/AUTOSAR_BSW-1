/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanIf_LCfg.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANIF_LCFG_H
#define AUTOSAR_LIB_CANIF_LCFG_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"
#include "../../Config/inc/CanIf_PbCfg.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {
    /* This id is for HTH object in Can controller */
    Can_HwHandleType CanIf_Hth_HW_Id;

    /* Actual Can controller Id */
    uint8            CanIf_Can_Controlellr_Id;
} CanIf_Hth_Can_Controller_Config;

typedef struct {
    /* This id is for HrH object in Can controller */
    Can_HwHandleType CanIf_Hrh_HW_Id;

    /* Actual Can controller Id */
    uint8            CanIf_Can_Controller_id;
} CanIf_Hrh_Can_Controller_Config;

typedef struct {
    CanIf_Hth_Cfg   CanIf_Buffering_Hth;
    uint8           CanIf_Buffer_Index_Id;
    PduIdType       Pdu_Handle;
    uint8*          CanIf_Buffer_Data_Ptr;
} CanIf_Buffer_Data_Unit;

 struct CanIf_Buffer {
    CanIf_Buffer_Data_Unit    *Data;
    struct CanIf_Buffer*      front;
    struct CanIf_Buffer*      back;
} CanIf_Buffer;

extern CanIf_Hth_Can_Controller_Config CanIf_Hth_Can_Controler_Config_Group_1[];

extern CanIf_Hrh_Can_Controller_Config CanIf_Hrh_Can_Controler_Config_Group_1[];

extern CanIf_Hth_Cfg CanIf_Hth_Cfg_Group_1[];

#endif //AUTOSAR_LIB_CANIF_LCFG_H
