/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanIf_PbCfg.c
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../inc/CanIf_PbCfg.h"


/***********************************************************************************************************************
*                                                Configruation                                                          *
***********************************************************************************************************************/

Can_Controller_Baudrate_Config Can_Controller_Baudrate_Config_Group_1[1] = {
    {
        .Can_Controller_BaudRate           = 0x00000000,
        .Can_Controller_BaudRate_Config_ID = 0x01,
        .Can_Controller_PropSeg            = 0x00,
        .Can_Controller_Seg_1              = 0x00,
        .Can_Controller_Seg_2              = 0x00,
        .Can_Controller_Sync_Jump_Width    = 0x00,
    },
};

Can_Controller Can_Controller_Group_1[1] = {
    {
        .Can_Busoff_Processing        = CAN_MODE_INTERRUPT,
        .Can_Controller_Activation    = STD_OFF,
        .Can_Controller_BaseAddress   = 0x00000000,
        .Can_Controller_Id            = 0x01,
        .Can_Rx_Processing            = CAN_MODE_INTERRUPT,
        .Can_Tx_Processing            = CAN_MODE_INTERRUPT,
        .Can_Wakeup_Functionality_API = STD_OFF,
        .Can_Wakeup_Processing        = CAN_MODE_INTERRUPT,
        .Can_Wakeup_Support           = STD_OFF,
        .Can_Controller_Default_Baudrate_Ref = &Can_Controller_Baudrate_Config_Group_1[0],
    }
};

CanIf_Ctrl_Cfg CanIf_Ctrl_Cfg_Group_1[1] = {
    {
        .CanIf_Ctrl_Id             = 1,
        .CanIf_Ctrl_Wakeup_Support = STD_OFF,
        .CanIf_Ctrl_Can_Ctrl_Ref   = &Can_Controller_Group_1[0],
    }
};

Can_Hardware_Object Can_Hardware_Object_Group_1[1] = {
    {
        .CanFd_Padding_Value         = 0xcc,
        .Can_Handle_Type             = FULL,
        .Can_Hardware_Object_Uses_Polling = STD_OFF,
        .Can_Id_Type                 = CAN_ID_STANDARD,
        .Can_Object_Id               = 0x01,
        .Can_Object_Type             = TRANSMIT,
        .Can_Trigger_Transmit_enable = STD_OFF,
    }
};

CanIf_Hth_Cfg CanIf_Hth_Cfg_Group_1[1] = {
    {
        .CanIf_Hth_Id_Sym_Ref      = &Can_Hardware_Object_Group_1[0],
        .CanIf_Hth_Can_Ctrl_Id_Ref = &CanIf_Ctrl_Cfg_Group_1[0],
    },
};

CanIf_Buffer_Cfg CanIf_Buffer_Cfg_Group_1[1] = {
    {
        .CanIfBufferSize      = 8,
        .CanIf_Buffer_Hth_Ref = &CanIf_Hth_Cfg_Group_1[0],
    }
};

CanIf_Tx_Pdu_Cfg CanIf_Tx_Pdu_Cfg_Group_1[1] = {
    {
        .CanIf_Tx_Pdu_CanId              = 0x000007D2U,
        .CanIf_Tx_Pdu_CanId_Mask         = 0xFFFFFFFFU,
        .CanIf_Tx_Pdu_CanId_Type         = STANDARD_CAN,
        .CanIf_Tx_Pdu_Id                 = 0,
        .CanIf_Tx_Pdu_Pn_Filter_Pdu      = STD_OFF,
        .CanIf_Tx_Pdu_Read_Notify_Status = STD_OFF,
        .CanIf_Tx_Pdu_Trigger_Transmit   = STD_OFF,
        .CanIf_Tx_Pdu_Truncation         = STD_OFF,
        .CanIf_Tx_Pdu_Type               = STATIC,
        .CanIf_Buffer_Cfg_Ref            = &CanIf_Buffer_Cfg_Group_1[0],
    }
};

CanIf_Public_Cfg CanIf_Public_Cfg_Group_1[1] = {
    {
        .CanIf_Bus_Mirroring_Support                = STD_OFF,
        .CanIf_Dev_Error_Detect                     = STD_OFF,
        .CanIf_MetaData_Support                     = STD_OFF,
        .CanIf_Public_Icom_Support                  = STD_OFF,
        .CanIf_Public_Multiple_Drv_Support          = STD_OFF,
        .CanIf_Public_Pn_Support                    = STD_OFF,
        .CanIf_Public_Read_Rx_Pdu_Data_Api          = STD_OFF,
        .CanIf_Public_Read_Rx_Pdu_Notify_Status_Api = STD_OFF,
        .CanIf_Public_Read_Tx_Pdu_Notify_Status_Api = STD_OFF,
        .CanIf_Public_Set_Dynamic_Tx_Id_Api         = STD_OFF,
        .CanIf_Public_Tx_Buffering                  = STD_OFF,
        .CanIf_Public_Tx_Confirm_Polling_Support    = STD_OFF,
        .CanIf_Public_Wakeup_Check_Valid_By_NM      = STD_OFF,
        .CanIf_Public_Wakeup_Check_Valid_Support    = STD_OFF,
        .CanIf_Set_Baudrate_Api                     = STD_OFF,
        .CanIf_Trigger_Transmit_Support             = STD_OFF,
        .CanIf_Tx_Offline_Active_Support            = STD_OFF,
        .CanIf_Version_Info_Api                     = STD_OFF,
        .CanIf_Wakeup_Support                       = STD_OFF,
    },
};

CanIf CanIf_Group_1[1] = {
    {
        .CanIf_Public_Cfg_Ref = &CanIf_Public_Cfg_Group_1[0],
    },
};

