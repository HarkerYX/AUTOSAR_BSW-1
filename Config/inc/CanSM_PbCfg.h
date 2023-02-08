/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanSM_PbCfg.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANSM_PBCFG_H
#define AUTOSAR_LIB_CANSM_PBCFG_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"
#include "../../Config/inc/CanDrv_PbCfg.h"
#include "../../Config/inc/Can_Types.h"
#include "../../Config/inc/CanIf_PbCfg.h"

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/

typedef struct {
    CanIf_Ctrl_Cfg CanSM_Controller_Id;
} CanSM_Controller;

typedef struct {

} CanSM_Dem_Event_Parameter_Refs;

typedef struct {
    uint8            CanSM_Bor_Counter_L1_To_L2;
    float32          CanSM_Bor_Time_L1;
    float32          CanSM_Bor_Time_L2;
    boolean          CanSM_Bor_Tx_Confirmation_Polling;
    boolean          CanSM_Enable_BusOff_Delay;
    CanIf_Trcv_Cfg   *CanSM_TransceiverId_Ref;
    CanSM_Controller *CanSM_Controller_Ref;
    CanSM_Dem_Event_Parameter_Refs *CanSM_Dem_Event_Parameter_Refs_Ref;
} CanSM_Manager_Network;

typedef struct {
    uint8 CanSM_Mode_Request_Repetition_Max;
    uint8 CanSM_Mode_Request_Repetition_Time;
    CanSM_Manager_Network *CanSM_Manager_Network_Ref;
} CanSM_Configuraiton;

typedef struct {
    boolean CanSM_Dev_Error_Detect;
    void (*CanSMGetBusOffDelayFunction)(void);
    char    CanSM_Get_BusOff_Delay_Header[30];
    boolean CanSM_Icom_Support;
    float64 CanSM_MainFunction_Time_Period;
    boolean CanSM_Pnc_Support;
    boolean CanSM_Set_Baudrate_Api;
    boolean CanSM_Tx_Offline_ActiveSupport;
    boolean CanSM_Version_Info_Api;
} CanSM_General;

typedef struct {
    CanSM_Configuraiton *CanSM_Comfiguraiton_Ref;
    CanSM_General       *CanSM_General_Ref;
} CanSM;
#endif //AUTOSAR_LIB_CANSM_PBCFG_H
