/***********************************************************************************************************************
 *
 * Module:       CanTP
 *
 * File Name:    CanTP.c
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/
#include "../inc/CanTp.h"
#include "../../Config/inc/CanTp_PbCfg.h"

/***********************************************************************************************************************
*                                            Global Flag definitions                                                   *
***********************************************************************************************************************/
uint8 CanTp_InitState;

/***********************************************************************************************************************
*                                               Static Functions                                                        *
***********************************************************************************************************************/
static uint16 CanTp_Get_TX_N_CS(PduIdType TX_SDU_ID) {

}

static CanTp_TX_State_Type CanTp_Get_TX_Channel_State(PduIdType TX_SDU_ID) {

}

static void CanTp_TX_Error_Handler(uint8 Error, CanTp_TX_State_Type TX_State, Std_ReturnType result) {

}

static void CanTp_TX_Transmit_Handler(CanTp_TX_State_Type TX_Channel_State) {
    Std_ReturnType Error_Flag;

    switch (TX_Channel_State.Channel_State) {
        case CanTp_TX_Prepare_Transmit_SF: {
            Error_Flag = E_OK;
            break;
        }

        case CanTp_TX_Prepare_Transmit_FF: {
            Error_Flag = E_OK;
            break;
        }

        case CanTp_TX_Prepare_Transmit_CF: {
            Error_Flag = E_OK;
            break;
        }
        default: {
            Error_Flag = E_NOT_OK;
            break;
        }
    }
}

static void CanTp_TX_Start_Connection(PduIdType TX_SDU_ID, const PduInfoType *PduInfoPtr) {
    CanTp_TX_State_Type TX_Channel_State;

    TX_Channel_State = CanTp_Get_TX_Channel_State(TX_SDU_ID);

    /* Single or Multi? */
    if (PduInfoPtr->SduLength > CANTP_TX_MAX_PAYLOAD_SF) {
        TX_Channel_State.Channel_State = CanTp_TX_Prepare_Transmit_FF;
    }
    else {
        TX_Channel_State.Channel_State = CanTp_TX_Prepare_Transmit_SF;
    }

    /* Set channel */
    TX_Channel_State.Data_Index  = 0;
    TX_Channel_State.Data_Length = PduInfoPtr->SduLength;
    TX_Channel_State.Timer       = CanTp_Get_TX_N_CS(TX_SDU_ID);

    /* Trigger next stage */
}

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/

void CanTp_TX_MainFunction(void) {

    CanTp_TX_State_Type TX_Channel_State;
    uint8 channel_Id;

    if (CanTp_InitState == CANTP_STATE_INITIALIZED) {
        for (channel_Id = 0; channel_Id < CANTP_CHANNEL_NUMS; channel_Id++) {

            TX_Channel_State = CanTp_TX_State[channel_Id];

            /* Update and check stmin */
            if (TX_Channel_State.STmin > 0) {
                TX_Channel_State.STmin--;

                /* STmin = 0, waiting for CF */
                if (TX_Channel_State.STmin == 0) {
                    TX_Channel_State.Channel_State = CanTp_TX_Prepare_Transmit_CF;
                }
            }

            /* Update channel Timer */
            TX_Channel_State.Timer--;

            /* Timeer is expired, start actions */
            if (TX_Channel_State.Timer == 0) {
                switch (TX_Channel_State.Channel_State) {
                    /* N_AS timeout. But the transmission did not end.
                     * Handle Error */
                    case CanTp_TX_Transmit_CF:
                    case CanTp_TX_Transmit_FF:
                    case CanTp_TX_Transmit_SF:
                    case CanTp_TX_Wait_Confirm_CF:
                    case CanTp_TX_Wait_Confirm_FF:
                    case CanTp_TX_Wait_Confirm_SF: {
                        CanTp_TX_Error_Handler(CANTP_E_TX_TIMEOUT_AS, TX_Channel_State, E_NOT_OK);
                        break;
                    }

                    /* N_BS timeout. But no FC received.
                     * Handle Error. */
                    case CanTp_TX_Wait_FC: {
                        CanTp_TX_Error_Handler(CANTP_E_TX_TIMEOUT_BS, TX_Channel_State, E_NOT_OK);
                        break;
                    }

                    /* N_CS timeout. But STmin is not expired.
                     * Reset STmin, prepare to transmit CF.  */
                    case CanTp_TX_Wait_STmin: {
                        TX_Channel_State.STmin = 0;
                        TX_Channel_State.Channel_State = CanTp_TX_Prepare_Transmit_CF;
                        break;
                    }

                    /* Something wrong */
                    case CanTp_TX_Prepare_Transmit_SF:
                    case CanTp_TX_Prepare_Transmit_FF:
                    case CanTp_TX_Prepare_Transmit_CF: {
                        CanTp_TX_Error_Handler(CANTP_E_TX_TIMEOUT_CS, TX_Channel_State, E_NOT_OK);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
    }
}

Std_ReturnType CanTp_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr) {
    Std_ReturnType return_value = E_NOT_OK;
    uint8          error_ID     = CANTP_E_NO_ERROR;

    /* check cantp init status */
    if (CanTp_InitState == CANTP_STATE_NOT_INITIALIZED) {
        error_ID = CANTP_E_UNINIT;
    }

    /* check whether sdu length is valid*/
    if (PduInfoPtr->SduLength > 0) {
        return_value = E_OK;
    }

    /* TX Start Connection */
    if (return_value == E_OK) {
        return_value = CanTp_TX_Start_Connection(TxPduId, PduInfoPtr);
    }

    return return_value;
}
