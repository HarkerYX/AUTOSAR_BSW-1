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
                        break;
                    }

                    /* N_BS timeout. But no FC received.
                     * Handle Error. */
                    case CanTp_TX_Wait_FC: {
                        break;
                    }

                    /* N_CS timeout. But STmin is not expired.
                     * Reset STmin, prepare to transmit CF.  */
                    case CanTp_TX_Wait_STmin: {
                        break;
                    }

                    /* Something */
                    case CanTp_TX_Prepare_Transmit_SF:
                    case CanTp_TX_Prepare_Transmit_FF:
                    case CanTp_TX_Prepare_Transmit_CF: {
                        break;
                    }
                }
            }
        }
    }
}