/***********************************************************************************************************************
 *
 * Module:       Can State Manager
 *
 * File Name:    CanSM.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANSM_H
#define AUTOSAR_LIB_CANSM_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"
#include "../../CanIf/inc/CanIf.h"
#include "../../CanSM/inc/CanSm_CanIf.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
/* SWS_CanSM_00596 */
typedef enum {
    CANSM_INITED   = 0x00,
    CANSM_UNINITED = 0x01,
} CanSM_StateType;

/* SWS_CanSM_00597 */
typedef struct {

} CanSM_ConfigType;

/* SWS_CanSM_00598 */
typedef enum {
    CANSM_BSWM_NO_COMMUNICATION     = 0x00,
    CANSM_BSWM_SILENT_COMMUNICATION = 0x01,
    CANSM_BSWM_BUS_OFF              = 0x02,
    CANSM_BSWM_FULL_COMMUNICATION   = 0x03,
    CANSM_BSWM_CHANGE_BAUDRATE      = 0x04,
} CanSM_BswMCurrentStateType;

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
/* SWS_CanSM_00023 */
void CanSM_Init(const CanSM_ConfigType *ConfigPtr);

/* SWS_CanSM_91001 */
void CanSM_DeInit(void);

/* SWS_CanSM_00062 */
Std_ReturnType CanSM_RequestComMode(NetworkHandleType network, ComM_ModeType ComM_Mode);

/* SWS_CanSM_00063 */
Std_ReturnType CanSM_GetCurrentComMode(NetworkHandleType network, ComM_ModeType ComM_ModePtr);

/* SWS_CanSM_00069 */
Std_ReturnType CanSM_StartWakeupSource(NetworkHandleType network);

/* SWS_CanSM_00610 */
Std_ReturnType CanSM_StopWakeupSource(NetworkHandleType network);

/* SWS_CanSM_00587 */
void CanSM_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);

void CanSM_Get_Channel_Config_By_Controller_Id(uint8 *Controller_Id, uint8 *Network, uint8 Transceiver_Id);


#endif //AUTOSAR_LIB_CANSM_H
