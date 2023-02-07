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
#include "../inc/CanIf.h"
#include "../../Config/inc/Can_Types.h"
#include "../../Config/inc/CanIf_PbCfg.h"
/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr)
{
    Can_ReturnType Can_Return;
    Can_PduType    Can_Pdu;
    uint8          Can_Controller_Id;
    uint8          Can_Object_Id;

    Can_Return = E_OK;

    if (Can_Return == E_OK) {
        Can_Controller_Id = CanIf_Tx_Pdu_Cfg_Group[TxPduId]
                            .CanIf_Buffer_Cfg_Ref
                            ->CanIf_Buffer_Hth_Ref
                            ->CanIf_Hth_Id_Sym_Ref
                            ->Can_Object_Id;
    }
}