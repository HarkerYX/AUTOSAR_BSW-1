/***********************************************************************************************************************
 *
 * Module:       CanIf
 *
 * File Name:    CanIf.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANIF_H
#define AUTOSAR_LIB_CANIF_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {

} CanIf_ConfigType;

typedef enum {
     CANIF_OFFLINE           = 0x00,
     CANIF_TX_OFFLINE        = 0x01,
     CANIF_TX_OFFLINE_ACTIVE = 0x02,
     CANIF_ONLINE            = 0x03,
} CanIf_PduModeType;

typedef enum {
     CANIF_NO_NOTIFICATION    = 0x00,
     CANIF_TX_RX_NOTIFICATION = 0x01,
} CanIf_NotifStatusType;

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
extern void CanIf_Init(const CanIf_ConfigType *ConfigPtr);

extern void CanIf_DeInit(void);

Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId, Can_ControllerStateType ControllerMode);

Std_ReturnType CanIf_GetControllerMode(uint8 ControllerId, Can_ControllerStateType *ControllerModePtr);

Std_ReturnType CanIf_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType *ErrorStatePtr);

Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr);

Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType *CanIfRxInfoPtr);

CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);

CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduInfoType CanIfRxSduId);




#endif //AUTOSAR_LIB_CANIF_H
