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
#include "../../EcuM/EcuM.h"

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
void CanIf_Init(const CanIf_ConfigType *ConfigPtr);

void CanIf_DeInit(void);

Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId, Can_ControllerStateType ControllerMode);

Std_ReturnType CanIf_GetControllerMode(uint8 ControllerId, Can_ControllerStateType *ControllerModePtr);

Std_ReturnType CanIf_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType *ErrorStatePtr);

Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr);

Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType *CanIfRxInfoPtr);

CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);

CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduInfoType CanIfRxSduId);

Std_ReturnType CanIf_SetPduMode(uint8 ControllerId, CanIf_PduModeType *PduModeRequest);

Std_ReturnType CanIf_GetPduMode(uint8 ControllerId, CanIf_PduModeType *PduModePtr);

void CanIf_SetDynamicTxId(PduInfoType CanIfTxSduId, Can_IdType CanId);

Std_ReturnType CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

Std_ReturnType CanIf_GetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType *TransceiverModePtr);

Std_ReturnType CanIf_GetTrcvWakeupReason(uint8 TransceiverId, CanTrcv_TrcvWakeupReasonType *TrcvWuReasonPtr);

Std_ReturnType CanIf_SetTrcvWakeupMode(uint8 TransceiverId, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

Std_ReturnType CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);

CanIf_NotifStatusType CanIf_GetTxConfirmationState(uint8 ControllerId);

Std_ReturnType CanIf_ClearTrcvWuFlag(uint8 TransceiverId);

Std_ReturnType CanIf_CheckTrcvWakeFlag(uint8 TransceiverId);

Std_ReturnType CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID);

Std_ReturnType CanIf_SetIcomConfiguration(uint8 ControllerId, IcomConfigIdType ComfigurationId);

Std_ReturnType GetControllerRxErrorCounter(uint8 ControllerId, uint8 *RxErrorCounterPtr);

Std_ReturnType GetControllerTxErrorCounter(uint8 ControllerId, uint8 *TxErrorCounterPtr);

Std_ReturnType CanIf_EnableBusMirroring(uint8 ControllerId, boolean MirroringActive);


/***********************************************************************************************************************
*                                                Callback Functions                                                    *
***********************************************************************************************************************/
Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr);


#endif //AUTOSAR_LIB_CANIF_H
