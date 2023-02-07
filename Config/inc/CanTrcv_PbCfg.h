/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanTrcv_PbCfg.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANTRCV_PBCFG_H
#define AUTOSAR_LIB_CANTRCV_PBCFG_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"
#include "../../Config/inc/Can_Types.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {
    boolean CanTrcv_Spi_Access_Synchronous;
    uint8   CanTrcv_Spi_Sequence_Name;
} CanTrcv_Spi_Sequence;

typedef struct {
    char  CanTrcv_Hardware_Interface_Name[50];
    uint8 *CanTrcv_Dio_Sym_Name_Ref;
} CanTrcv_Dio_Channel_Access;

typedef struct {
    CanTrcv_Spi_Sequence *CanTrcv_Spi_Sequence_Ref;
} CanTrcv_Spi_Access;

typedef struct {
    CanTrcv_Dio_Channel_Access *CanTrcv_Dio_Channel_Access_Ref;
} CanTrcv_Dio_Access;

typedef struct {
    uint8 CanTrcv_Pn_Frame_Data_Mask;
    uint8 CanTrcv_Pn_Frame_Data_Mask_Index;
} CanTrcv_Pn_Frame_Data_Mask_Spec;

typedef struct {
    uint16  CanTrcv_Baud_Rate;
    boolean CanTrcv_Bus_Err_Flag;
    boolean CanTrcv_Pn_CanId_Is_Extended;
    boolean CanTrcv_Pn_Enabled;
    uint32  CanTrcv_Pn_Frame_CanId;
    uint32  CanTrcv_Pn_Frame_CanId_Mask;
    uint8   CanTrcv_Pn_Frame_Dlc;
    boolean CanTrcv_Power_On_Flag;
    CanTrcv_Pn_Frame_Data_Mask_Spec *CanTrcv_Pn_Frame_Data_Mask_Spec_Ref;
} CanTrcv_Partial_Network;


typedef struct {
    uint8 CANTRCV_E_BUS_ERROR;
} CanTrcv_Dem_Event_Parameter_Refs;

typedef struct {
    CanTrcv_Dio_Access *CanTrcv_Dio_Access_Ref;
    CanTrcv_Spi_Access *CanTrcv_Spi_Access_Ref;
} CanTrcv_Access;

typedef struct {
    uint8                     CanTrcv_Channel_Id;
    boolean                   CanTrcv_Channel_Used;
    boolean                   CanTrcv_Controls_Power_Supply;
    boolean                   CanTrcv_Hw_Pn_Support;
    CanTrcv_OP_Mode_Type_Enum CanTrcv_Init_State;
    uint16                    CanTrcv_Max_Baudrate;
    boolean                   CanTrcv_Wakeup_By_Bus_Used;
    CanTrcv_Access            *CanTrcv_Access_Ref;
    CanTrcv_Dem_Event_Parameter_Refs *CanTrcv_Dem_Event_Parameter_Refs_Ref;
    CanTrcv_Partial_Network   *CanTrcv_Partial_Network_Ref;
} CanTrcv_Channel;

typedef struct {
    uint8           CanTrcv_SPI_Comm_Retries;
    uint8           CanTrcv_SPI_Comm_Timeout;
    CanTrcv_Channel *CanTrcv_Channel_Ref;
} CanTrcv_Config_Set;

typedef struct {
    boolean                  CanTrcv_Dev_Error_Detect;
    uint8                    CanTrcv_Index;
    float64                  CanTrcv_MainFunction_Diagnostics_Period;
    float64                  CanTrcv_MainFunction_Period;
    CanTrcv_Timer_Type_Enum  CanTrcv_Timer_Type;
    boolean                  CanTrcv_Version_Info_Api;
    float64                  CanTrcv_Wait_Time;
    CanTrcv_Wakeup_Type_Enum CanTrcv_WakeUp_Support;
} CanTrcv_General;

typedef struct {
    CanTrcv_Config_Set *CanTrcv_Config_Set_Ref;
    CanTrcv_General    *CanTrcv_General_Ref;
} CanTrcv;

#endif //AUTOSAR_LIB_CANTRCV_PBCFG_H
