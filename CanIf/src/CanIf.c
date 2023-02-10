/***********************************************************************************************************************
 *
 * Module:       CanIf
 *
 * File Name:    CanIf.c
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Can/inc/Can.h"
#include "../inc/CanIf.h"
#include "../inc/CanIf_Can.h"
#include "../inc/CanIf_CanTrcv.h"
#include "../../Config/inc/Can_Types.h"
#include "../../Config/inc/CanIf_PbCfg.h"
#include "../../Config/inc/CanIf_LCfg.h"
/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
static Std_ReturnType  CanIf_BufferTransmitMessage(PduIdType TxPduId, Can_PduType Can_Pdu) {
    ;
}

Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr)
{
    Can_ReturnType          Can_Return;
    Can_ReturnType          Can_Write_Return = CAN_NOT_OK;
    Can_PduType             Can_Pdu;
    uint8                   Can_Controller_Id;
    uint8                   Can_Object_Id;
    CanIf_PduModeType       Pdu_Mode;
    Can_ControllerStateType Controller_Mode;
    boolean                 Do_Transmit = FALSE;
    boolean                 Can_FD_BIT;

    Can_Controller_Id = CanIf_Tx_Pdu_Cfg_Group_1[TxPduId]
        .CanIf_Buffer_Cfg_Ref
        ->CanIf_Buffer_Hth_Ref
        ->CanIf_Hth_Id_Sym_Ref
        ->Can_Object_Id;

    Can_Return = CanIf_GetPduMode(Can_Controller_Id, &Pdu_Mode);

    /* SWS_CANIF_00317 */
    if (Can_Return == E_OK) {
        Can_Return = CanIf_GetControllerMode(Can_Controller_Id, &Controller_Mode);

        if (Controller_Mode == CAN_CS_STARTED) {
            switch (Pdu_Mode) {
                case CANIF_OFFLINE: {
                    /* SWS_CANIF_00382 */
                    /* DET will report error */
                    Can_Return = E_NOT_OK;
                    Do_Transmit = FALSE;
                    break;
                }

                case CANIF_TX_OFFLINE_ACTIVE: {
                    /* SWS_CANIF_00072 */
                    if (CanIf_Group_1[0].CanIf_Public_Cfg_Ref->CanIf_Tx_Offline_Active_Support == TRUE) {
                        CanIf_TxConfirmation(TxPduId);
                        Do_Transmit = TRUE;
                    }
                    else {
                        Can_Return = E_NOT_OK;
                    }

                    break;
                }
                case CANIF_ONLINE: {
                    /* SWS_CANIF_00747, SWS_CANIF_00750*/
                    if (CanIf_Group_1[0].CanIf_Public_Cfg_Ref->CanIf_Public_Pn_Support == STD_ON) {
                        if (CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_Pn_Filter_Pdu != STD_ON) {
                            Do_Transmit = FALSE;
                        }
                    }
                    else {
                        Do_Transmit = TRUE;
                    }
                    break;
                }
                case CANIF_TX_OFFLINE:
                    break;
                default: {
                    Can_Return = E_NOT_OK;
                    break;
                }
            }
        }

        /* SWS_CANIF_00317 */
        if (Controller_Mode == CAN_CS_SLEEP) Can_Return = E_NOT_OK;

        if (Controller_Mode == CAN_CS_UNINIT) Can_Return = E_NOT_OK;

        if (Controller_Mode == CAN_CS_STOPPED) {
            /* SWS_CANIF_00677 */
            Can_Return = E_NOT_OK;
        }
    }

    /* SWS_CANIF_00844 */
    if (CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_Type == DYNAMIC) {
        if ((CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_CanId == 0x00000000)
         && (CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_CanId_Mask == 0x00000000)) {
            Can_Pdu.id = *(Can_IdType*)PduInfoPtr->MetaDataPtr;
        }
        else {
            Can_Pdu.id = CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_CanId
                       & CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_CanId_Mask;
        }
    }
    else {
        Can_Pdu.id = CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_CanId;
    }


    if ((Can_Return == E_OK) && (Do_Transmit == TRUE)) {

        Can_FD_BIT = Can_Pdu.id & 0x40000000;

        if (CanIf_Tx_Pdu_Cfg_Group_1[TxPduId].CanIf_Tx_Pdu_Truncation == STD_ON) {
            /* SWS_CANIF_00893 */
            if (((PduInfoPtr->SduLength > 64) && (Can_FD_BIT == TRUE))
            || ((PduInfoPtr->SduLength > 8) && (Can_FD_BIT != TRUE))   )
            {
                Can_Return = E_NOT_OK;
                /* Report to DET */
            }
            else {
                /* SWS_CANIF_00894 */
                Can_Pdu.sdu = PduInfoPtr->SduDataPtr;
            }
        }
        else {
            /* SWS_CANIF_00900 */
            if ((PduInfoPtr->SduLength > 8) && (Can_FD_BIT != TRUE)) {
                Can_Return = E_NOT_OK;
            }
            Can_Pdu.sdu = PduInfoPtr->SduDataPtr;
        }

        Can_Pdu.length = PduInfoPtr->SduLength;
        Can_Pdu.swPduHandle = TxPduId;

        /* SWS_CANIF_00023, SWS_CANIF_00318, SWS_CANIF_00040*/
        Can_Write_Return = Can_Write(CanIf_Hth_Can_Controler_Config_Group_1[TxPduId].CanIf_Hth_HW_Id,
                               (const Can_PduType*) &Can_Pdu);
    }

        /* SWS_CANIF_00162, SWS_CANIF_00381 */
    switch (Can_Write_Return) {
        case CAN_OK:
            Can_Return = E_OK;
            break;
        case CAN_NOT_OK:
            Can_Return = E_NOT_OK;
            break;
        case CAN_BUSY:
            if (CanIf_Group_1[0].CanIf_Public_Cfg_Ref->CanIf_Public_Tx_Buffering == TRUE) {
                CanIf_BufferTransmitMessage(TxPduId, Can_Pdu);
            }
            else {
                Can_Return = E_NOT_OK;
            }
            break;
        default: {
            Can_Return = E_NOT_OK;
            break;
        }
    }


    return Can_Return;

}

