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
static void CanTp_Rx_Indication_SF(CanTp_RX_State_Type RX_Channel_State, PduInfoType PDU) {

}

static void CanTp_Rx_Indication_FF(CanTp_RX_State_Type RX_Channel_State, PduInfoType PDU) {

}

static void CanTp_Rx_Indication_CF(CanTp_RX_State_Type RX_Channel_State, PduInfoType PDU) {

}

static void CanTp_Rx_Indication_FC(CanTp_RX_State_Type RX_Channel_State, PduInfoType PDU) {

}

static void CanTp_RX_Indication_Handler(PduIdType SDU, uint8 Frame_Type, PduInfoType payload) {

}

static uint16 CanTp_Get_TX_N_CS(PduIdType TX_SDU_ID) {

}

static uint16 CanTp_Get_TX_N_AS(PduIdType TX_SDU_ID) {

}

static uint16 CanTp_Get_TX_N_BS(PduIdType TX_SDU_ID) {

}

static uint16 CanTp_Get_TX_N_CR(PduIdType RX_SDU_ID) {

}

static uint16 CanTp_Get_TX_N_AR(PduIdType RX_SDU_ID) {

}

static uint16 CanTp_Get_TX_N_BR(PduIdType RX_SDU_ID) {

}

static Std_ReturnType CanTp_CanIf_Transmit_Frame(void){}

static inline void CanTp_Memory_Copy(const uint8 *source, uint8 *destination, uint16 length) {
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
}

static void CanTp_Get_TX_Channel_State(CanTp_TX_State_Type *TX_Channel_State, PduIdType TX_SDU_ID) {

}

static void CanTp_TX_Error_Handler(uint8 Error, CanTp_TX_State_Type *TX_State, Std_ReturnType result) {

}

static void CanTp_RX_Error_Handler(uint8 Error, CanTp_RX_State_Type *RX_State, Std_ReturnType result) {

}

static void CanTp_Rx_Transmit(CanTp_RX_State_Type *RX_Channel_State) {

}

static void CanTp_RX_Store(CanTp_RX_State_Type *RX_Channel_State) {

}

static void CanTp_TX_Transmit(CanTp_TX_State_Type *TX_Channel_State){
    PduInfoType Temp_PDU;
    uint8       Frame_Buffer[8];
    Std_ReturnType return_value = E_OK;

    Temp_PDU.SduDataPtr = &Frame_Buffer[0];
    Temp_PDU.SduLength  = 0;

    /* Assemble Frames */
    switch (TX_Channel_State->Channel_State) {
        case CanTp_TX_Transmit_SF: {
            Temp_PDU.SduDataPtr[0] = CANTP_PCI_TYPE_SF;

            /* CAN FD or CAN CLASSIC? */
            if ((CANTP_PCI_LENGTH_SF + TX_Channel_State->Payload_Length) > CANTP_CAN20_FRAME_LENGTH) {
                Temp_PDU.SduLength = CANTP_PCI_LENGTH_LONG_SF;
                Temp_PDU.SduDataPtr[1] = TX_Channel_State->Data_Length;
            }
            else {
                Temp_PDU.SduLength = CANTP_PCI_LENGTH_SF;
                Temp_PDU.SduDataPtr[1] = TX_Channel_State->Data_Length;
            }

            break;
        }

        case CanTp_TX_Transmit_FF: {

            /* Check whether long FF */
            if (TX_Channel_State->Data_Length > CANTP_LONG_FF_LENGTH) {
                Temp_PDU.SduDataPtr[0] = CANTP_PCI_TYPE_FF;
                Temp_PDU.SduDataPtr[1] = 0;
                Temp_PDU.SduDataPtr[2] = ((TX_Channel_State->Data_Length) >> 24);
                Temp_PDU.SduDataPtr[3] = ((TX_Channel_State->Data_Length) >> 16);
                Temp_PDU.SduDataPtr[4] = ((TX_Channel_State->Data_Length) >> 8);
                Temp_PDU.SduDataPtr[5] = TX_Channel_State->Data_Length;

                Temp_PDU.SduLength = CANTP_PCI_LENGTH_LONG_FF;
            }
            else {
                Temp_PDU.SduDataPtr[0] = CANTP_PCI_TYPE_FF;
                Temp_PDU.SduDataPtr[1] = CANTP_PCI_TYPE_FF | (TX_Channel_State->Data_Length >> 8);
                Temp_PDU.SduDataPtr[2] = (uint8)TX_Channel_State->Data_Length;

                Temp_PDU.SduLength = CANTP_PCI_LENGTH_FF;
            }

            TX_Channel_State->Secquence_Number = 1;
            TX_Channel_State->BS_Counter = 0;
            TX_Channel_State->Data_Index = 0;

            break;
        }

        case CanTp_TX_Transmit_CF: {
            Temp_PDU.SduDataPtr[0] = CANTP_PCI_TYPE_CF | (TX_Channel_State->Secquence_Number);

            Temp_PDU.SduLength = CANTP_PCI_LENGTH_CF;
            break;
        }

        default: {
            return_value = E_NOT_OK;
            /* Report to DET */
            break;
        }
    }

    /* Copy Payload and transmit */
    if (return_value == E_OK) {
        CanTp_Memory_Copy((&Temp_PDU.SduDataPtr[Temp_PDU.SduLength]), &TX_Channel_State->Payload[0],
                          TX_Channel_State->Payload_Length);

        Temp_PDU.SduLength += TX_Channel_State->Payload_Length;

        /* Transmit */
        return_value = CanTp_CanIf_Transmit_Frame();
    }

    if (return_value == E_OK) {
        switch (TX_Channel_State->Channel_State) {
            case CanTp_TX_Transmit_SF: {
                TX_Channel_State->Channel_State = CanTp_TX_Wait_Confirm_SF;
                TX_Channel_State->Data_Index    = TX_Channel_State->Data_Index + TX_Channel_State->Payload_Length;
                break;
            }

            case CanTp_TX_Transmit_FF: {
                TX_Channel_State->Channel_State = CanTp_TX_Wait_Confirm_FF;
                TX_Channel_State->Data_Index    = TX_Channel_State->Data_Index + TX_Channel_State->Payload_Length;
                break;
            }

            case CanTp_TX_Transmit_CF: {
                TX_Channel_State->Channel_State = CanTp_TX_Wait_Confirm_CF;
                TX_Channel_State->Data_Index    = TX_Channel_State->Data_Index + TX_Channel_State->Payload_Length;
                break;
            }
        }
    }
}

static Std_ReturnType CanTp_TX_Transmit_Prepare(CanTp_TX_State_Type *TX_Channel_State) {
    Std_ReturnType Error_Flag;
    PduInfoType    temp_PDU;

    /* Switch State Machine */
    switch (TX_Channel_State->Channel_State) {
        case CanTp_TX_Prepare_Transmit_SF: {
            Error_Flag = E_OK;
            TX_Channel_State->Channel_State = CanTp_TX_Transmit_SF;
            break;
        }

        case CanTp_TX_Prepare_Transmit_FF: {
            TX_Channel_State->Payload_Length = CANTP_TX_MAX_PAYLOAD_FF;
            TX_Channel_State->Channel_State = CanTp_TX_Transmit_FF;
            Error_Flag = E_OK;
            break;
        }

        case CanTp_TX_Prepare_Transmit_CF: {
            TX_Channel_State->Payload_Length = CANTP_TX_MAX_PAYLOAD_CF;
            TX_Channel_State->Channel_State = CanTp_TX_Transmit_CF;

            /* Process last CF */
            if ((TX_Channel_State->Data_Index + TX_Channel_State->Payload_Length) > TX_Channel_State->Data_Length) {
                TX_Channel_State->Payload_Length = TX_Channel_State->Data_Length - TX_Channel_State->Data_Index;
            }

            Error_Flag = E_OK;
            break;
        }
        default: {
            Error_Flag = E_NOT_OK;
            break;
        }
    }

    /* Copy Payload */
    temp_PDU.SduLength  = TX_Channel_State->Payload_Length;
    temp_PDU.SduDataPtr = &TX_Channel_State->Payload[0];

    TX_Channel_State->Buffer_State = CanTp_PduRCopyTxData();


    if (TX_Channel_State->Buffer_State == BUFREQ_OK) {
        TX_Channel_State->Timer = CanTp_Get_TX_N_AS(TX_Channel_State->TX_SDU_Handle);

        CanTp_TX_Transmit(TX_Channel_State);
    }

}

static Std_ReturnType CanTp_TX_Start_Connection(PduIdType TX_SDU_ID, const PduInfoType *PduInfoPtr) {
    CanTp_TX_State_Type *TX_Channel_State;
    Std_ReturnType      return_value;

    CanTp_Get_TX_Channel_State(TX_Channel_State, TX_SDU_ID);

    /* Single or Multi? */
    if (PduInfoPtr->SduLength > CANTP_TX_MAX_PAYLOAD_SF) {
        TX_Channel_State->Channel_State = CanTp_TX_Prepare_Transmit_FF;
    }
    else {
        TX_Channel_State->Channel_State = CanTp_TX_Prepare_Transmit_SF;
    }

    /* Set channel */
    TX_Channel_State->Data_Index  = 0;
    TX_Channel_State->Data_Length = PduInfoPtr->SduLength;
    TX_Channel_State->Timer       = CanTp_Get_TX_N_CS(TX_SDU_ID);

    /* Trigger next stage */
    return_value = CanTp_TX_Transmit_Prepare(TX_Channel_State);
}

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/

void CanTp_TX_MainFunction(void) {

    CanTp_TX_State_Type *TX_Channel_State;
    uint8 channel_Id;

    if (CanTp_InitState == CANTP_STATE_INITIALIZED) {
        for (channel_Id = 0; channel_Id < CANTP_TX_CHANNEL_NUMS; channel_Id++) {

            *TX_Channel_State = CanTp_TX_State[channel_Id];

            /* Update and check stmin */
            if (TX_Channel_State->STmin > 0) {
                TX_Channel_State->STmin--;

                /* STmin = 0, waiting for CF */
                if (TX_Channel_State->STmin == 0) {
                    TX_Channel_State->Channel_State = CanTp_TX_Prepare_Transmit_CF;
                }
            }

            /* Update channel Timer */
            TX_Channel_State->Timer--;

            /* Timeer is expired, start actions */
            if (TX_Channel_State->Timer == 0) {
                switch (TX_Channel_State->Channel_State) {
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
                        TX_Channel_State->STmin = 0;
                        TX_Channel_State->Channel_State = CanTp_TX_Prepare_Transmit_CF;
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
            else {
                switch (TX_Channel_State->Channel_State) {
                    case CanTp_TX_Prepare_Transmit_SF:
                    case CanTp_TX_Prepare_Transmit_FF:
                    case CanTp_TX_Prepare_Transmit_CF: {
                        CanTp_TX_Transmit_Prepare(TX_Channel_State);
                       break;
                    }

                    case CanTp_TX_Transmit_SF:
                    case CanTp_TX_Transmit_FF:
                    case CanTp_TX_Transmit_CF: {
                        CanTp_TX_Transmit(TX_Channel_State);
                        break;
                    }
                    default : {
                        break;
                    }
                }

            }
        }
    }
}

void CanTp_RX_MainFunction(void) {
    CanTp_RX_State_Type *RX_Channel_State;
    uint8 channel_Id;

    if (CanTp_InitState == CANTP_STATE_INITIALIZED) {
        for (channel_Id = 0; channel_Id < CANTP_RX_CHANNEL_NUMS; channel_Id++) {
            *RX_Channel_State = CanTp_RX_State[channel_Id];

            RX_Channel_State->Timer--;
            if (RX_Channel_State->Timer == 0) {
                switch (RX_Channel_State->Channel_State) {
                    /* N_CR timeout */
                    case CanTp_RX_Wait_CF: {
                        CanTp_RX_Error_Handler(CANTP_E_RX_TIMEOUT_CR, RX_Channel_State, E_NOT_OK);
                        break;
                    }

                    /* N_AR timeout */
                    case CanTp_RX_Wait_Confirm_FC_CTS:
                    case CanTp_RX_Wait_Confirm_FC_WT:
                    case CanTp_RX_Transmit_FC_WT:
                    case CanTp_RX_Transmit_FC_CTS: {
                        CanTp_RX_Error_Handler(CANTP_E_RX_TIMEOUT_AR, RX_Channel_State, E_NOT_OK);
                        break;
                    }

                    /* N_AR timeout & something wrong with buffer */
                    case CanTp_RX_Transmit_FC_OVFL:
                    case CanTp_RX_Wait_Confirm_FC_OVFL: {
                        CanTp_RX_Error_Handler(CANTP_E_INVALID_RX_BUFFER, RX_Channel_State, E_NOT_OK);
                        break;
                    }

                    /* Wait again */
                    case CanTp_RX_Wait_Next_FC_WT: {
                        RX_Channel_State->Channel_State = CanTp_RX_Transmit_FC_WT;
                        RX_Channel_State->Timer = CanTp_Get_TX_N_AR(RX_Channel_State->RX_SDU_Handle);
                        CanTp_Rx_Transmit(RX_Channel_State);
                        break;
                    }

                    default:{
                        /* report to DET */
                        break;
                    }
                }
            }
            else {
                if ((RX_Channel_State->Channel_State == CanTp_RX_Store_SF)
                 || (RX_Channel_State->Channel_State == CanTp_RX_Store_FF)
                 || (RX_Channel_State->Channel_State == CanTp_RX_Store_CF)
                 || (RX_Channel_State->Channel_State == CanTp_RX_Wait_Next_FC_WT)) {
                    CanTp_RX_Store(RX_Channel_State);
                }

                if ((RX_Channel_State->Channel_State == CanTp_RX_Transmit_FC_CTS)
                 || (RX_Channel_State->Channel_State == CanTp_RX_Transmit_FC_WT)
                 || (RX_Channel_State->Channel_State == CanTp_RX_Transmit_FC_OVFL)) {
                    CanTp_Rx_Transmit(RX_Channel_State);
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

void CanTp_RxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr) {

}