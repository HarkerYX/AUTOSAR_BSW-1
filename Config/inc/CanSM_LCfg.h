/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanSM_LCfg.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANSM_LCFG_H
#define AUTOSAR_LIB_CANSM_LCFG_H
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
typedef struct
{
    uint8 Controller_Id_Of_Channel;
    uint8 Network_Handle_Of_Channel;
    uint8 Transceiver_Id_Of_Channel;
} CanSM_Controller_Network_Tranceiver_Config_Type;


#endif //AUTOSAR_LIB_CANSM_LCFG_H
