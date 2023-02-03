/***********************************************************************************************************************
 *
 * Module:       CanIf
 *
 * File Name:    CanIf_CanTrcv.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/
#ifndef AUTOSAR_LIB_CANIF_CANTRCV_H
#define AUTOSAR_LIB_CANIF_CANTRCV_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "CanIf.h"

/***********************************************************************************************************************
*                                                Callback Functions                                                    *
***********************************************************************************************************************/
void CanIf_ConfirmPnAvailability(uint8 TransceiverId);

void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);

void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);

void CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

#endif //AUTOSAR_LIB_CANIF_CANTRCV_H
