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

#endif //AUTOSAR_LIB_CAN_GENERALTYPES_H
