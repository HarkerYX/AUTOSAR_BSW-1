/***********************************************************************************************************************
 *
 * Module:       CanIf
 *
 * File Name:    CanIf_Can.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANIF_CAN_H
#define AUTOSAR_LIB_CANIF_CAN_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "CanIf.h"

/***********************************************************************************************************************
*                                                Callback Functions                                                    *
***********************************************************************************************************************/
void CanIf_TxConfirmation(PduIdType CanTxPduId);

void CanIf_RxIndication(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr);

void CanIf_ControllerBusOFF(uint8 ControllerId);

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);

void CanIf_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);

#endif //AUTOSAR_LIB_CANIF_CAN_H
