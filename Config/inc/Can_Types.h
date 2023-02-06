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

#endif //AUTOSAR_LIB_CAN_TYPES_H
