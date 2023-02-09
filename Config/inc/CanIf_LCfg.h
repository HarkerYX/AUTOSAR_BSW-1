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

extern CanIf_Hth_Can_Controller_Config CanIf_Hth_Can_Controler_Config_Group_1[];

extern CanIf_Hrh_Can_Controller_Config CanIf_Hrh_Can_Controler_Config_Group_1[];
#endif //AUTOSAR_LIB_CANIF_LCFG_H
