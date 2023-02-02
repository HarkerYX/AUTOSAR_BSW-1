/***********************************************************************************************************************
 *
 * Module:       ComStack Types
 *
 * File Name:    ComStackTypes.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_COMSTACKTYPES_H
#define AUTOSAR_LIB_COMSTACKTYPES_H
#include "../Std_Types//StandardTypes.h"

typedef uint16 PduIdType;
typedef uint16 PduLengthType;

typedef struct {
    uint8         *SduDataPtr;
    uint8         *MetaDataPtr;
    PduLengthType SduLength;
} PduInfoType;

#endif //AUTOSAR_LIB_COMSTACKTYPES_H
