/***********************************************************************************************************************
 *
 * Module:       Can_GeneralTypes
 *
 * File Name:    Can_GeneralTypes.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/
#ifndef AUTOSAR_LIB_CAN_GENERALTYPES_H
#define AUTOSAR_LIB_CAN_GENERALTYPES_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../Platform/x86/Platform_Types.h"
#include "../../ComStack_Types/ComStackTypes.h"
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef uint32 Can_IdType;
typedef uint32 Can_HwHandleType;

typedef enum {
    CAN_CS_UNINIT  = 0x00,
    CAN_CS_STARTED = 0x01,
    CAN_CS_STOPPED = 0x02,
    CAN_CS_SLEEP   = 0x03,
} Can_ControllerStateType;

typedef enum {
    CAN_ERRORSTATE_ACTIVE  = 0x00,
    CAN_ERRORSTATE_PASSIVE = 0x01,
    CAN_ERRORSTATE_BUSOFF  = 0x02
} Can_ErrorStateType;

typedef enum {
    CANTRCV_TRCVMODE_NORMAL  = 0x00,
    CANTRCV_TRCVMODE_STANDBY = 0x01,
    CANTRCV_TRCVMODE_SLEEP   = 0x02,
} CanTrcv_TrcvModeType;

typedef enum {
    CANTRCV_WUMODE_ENABLE  = 0x00,
    CANTRCV_WUMODE_DISABLE = 0x01,
    CANTRCV_WUMODE_CLEAR   = 0x02,
} CanTrcv_TrcvWakeupModeType;

typedef enum {
    CANTRV_WU_ERROR         = 0x00,
    CANTRV_WU_NOT_SUPPORTED = 0x01,
    CANTRV_WU_BY_BUS        = 0x02,
    CANTRV_WU_INTERNALLY    = 0x03,
    CANTRV_WU_RESET         = 0x04,
    CANTRV_WU_POWER_ON      = 0x05,
    CANTRV_WU_BY_PIN        = 0x06,
    CANTRV_WU_BY_SYSERR     = 0x07,
} CanTrcv_TrcvWakeupReasonType;

typedef struct {
    Can_IdType       Canid;
    Can_HwHandleType Hoh;
    uint8            ControllerId;
} Can_HwType;

typedef struct {
    PduIdType  swPduHandle;
    uint8      length;
    Can_IdType id;
    uint8      *sdu;
} Can_PduType;

#endif //AUTOSAR_LIB_CAN_GENERALTYPES_H
