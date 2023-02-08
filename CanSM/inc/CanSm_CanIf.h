/***********************************************************************************************************************
 *
 * Module:       Can State Manager
 *
 * File Name:    CanSM_CanIf.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANSM_CANIF_H
#define AUTOSAR_LIB_CANSM_CANIF_H

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
*                                                  Functions                                                           *
***********************************************************************************************************************/
/* SWS_CanSM_00064 */
void CanSM_ControllerBusOff(uint8 ControllerId);

/* SWS_CanSM_00369 */
void CanSM_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);

/* SWS_CanSM_00610 */
void CanSM_TransceiverModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

/* SWS_CanSM_00410 */
void CanSM_TxTimeoutException(NetworkHandleType Channel);

/* SWS_CanSM_00413 */
void CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver);

/* SWS_CanSM_00416 */
void CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver);

/* SWS_CanSM_00419 */
void CanSM_ConfirmPnAvailability(uint8 Transceiver);



#endif //AUTOSAR_LIB_CANSM_CANIF_H
