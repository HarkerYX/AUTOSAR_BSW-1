/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanIf_LCfg.c
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 * Note:         For better reading, Please refer to /Config/doc/CanIf.xlsx
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../inc/CanIf_LCfg.h"

/***********************************************************************************************************************
*                                                 Configurations                                                       *
***********************************************************************************************************************/
CanIf_Hth_Can_Controller_Config CanIf_Hth_Can_Controler_Config_Group_1[2] = {
    {0, 0},
    {1, 0},
};

CanIf_Hrh_Can_Controller_Config CanIf_Hrh_Can_Controler_Config_Group_1[1] = {
    {0, 0}
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_0 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 0,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_1 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 1,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_2 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 2,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_3 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 3,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_4 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 4,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_5 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 5,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_6 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 6,
};

CanIf_Buffer_Data_Unit Hth_0_Buffer_Data_Uint_7 = {
    .CanIf_Buffering_Hth   = NULL,
    .Pdu_Handle            = NULL,
    .CanIf_Buffer_Data_Ptr = NULL,
    .CanIf_Buffer_Index_Id = 7,
};

struct CanIf_Buffer CanIf_Buffer_Hth_0[8] = {
    {
        .Data  = &Hth_0_Buffer_Data_Uint_0,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_1,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_2,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_3,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_4,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_5,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_6,
        .front = NULL,
        .back  = NULL,
    },
    {
        .Data  = &Hth_0_Buffer_Data_Uint_7,
        .front = NULL,
        .back  = NULL,
    },
};

struct CanIf_Buffer CanIf_BUffer_Head_List[1] = {
    {
        .Data  = NULL,
        .back  = NULL,
        .front = &CanIf_Buffer_Hth_0[0],
    },

};

Can_ControllerStateType CanIf_Controller_Mode_Local[3];