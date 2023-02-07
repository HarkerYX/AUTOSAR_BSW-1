/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    Can_Types.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CAN_TYPES_H
#define AUTOSAR_LIB_CAN_TYPES_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef enum {
    BASIC = 0x00,
    FULL  = 0x01,
} Can_Handle_Type_Enum;

typedef enum {
    CAN_ID_EXTENDED = 0x00,
    CAN_ID_MIXED    = 0x01,
    CAN_ID_STANDARD = 0x02,
} Can_Id_Type_Enum;

typedef enum {
    RECEIVE  = 0x00,
    TRANSMIT = 0x01,
} Can_Object_Type_Enum;

typedef enum {
    CAN_MODE_INTERRUPT = 0x00,
    CAN_MODE_POLLING   = 0x01,
    CAN_MODE_MIXED     = 0x02,
} Can_Opertaion_Mode_Enum;

typedef enum {
    AND     = 0x00,
    EQUAL   = 0x01,
    GREATER = 0x02,
    SMLLER  = 0x03,
    XOR     = 0x04,
} Can_Compare_Enum;

typedef enum {
    BINARY = 0x00,
    INDEX  = 0x01,
    LINEAR = 0x02,
    TABLE  = 0x03,
} Can_SW_Filter_Method_Enum;

typedef enum {
    UINT16 = 0x00,
    UINT8  = 0x01,
} Can_HW_Handle_Type_Enum;

typedef enum {
    EXTENDED_CAN    = 0x00,
    EXTENDED_FD_CAN = 0x01,
    STANDARD_CAN    = 0x02,
    STANDARD_FD_CAN = 0x03,
} Can_LPdu_ID_Type_Enum;

typedef enum {
    DYNAMIC = 0x00,
    STATIC  = 0x00,
} CanIf_Tx_Pdu_Type_Enum;

typedef enum {
    NONE            = 0x00,
    TIMER_1US_16BIT = 0x01,
} CanTrcv_Timer_Type_Enum;

typedef enum {
    CANTRCV_WAKEUP_BY_POLLING    = 0x00,
    CANTRCV_WAKEUP_NOT_SUPPORTED = 0x01,
} CanTrcv_Wakeup_Type_Enum;

typedef enum {
    CANTRCV_OP_MODE_NORMAL = 0x00,
    CANTRCV_OP_MODE_SLEEP  = 0x01,
    CANTRCV_OP_MODE_STANDBY = 0x02,
} CanTrcv_OP_Mode_Type_Enum;

typedef enum {
    CAN_OK     = 0x00,
    CAN_NOT_OK = 0x01,
    CAN_BUSY   = 0x02,
} Can_ReturnType;

#endif //AUTOSAR_LIB_CAN_TYPES_H
