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
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../Std_Types//StandardTypes.h"

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef uint16 PduIdType;
typedef uint16 PduLengthType;
typedef uint8  IcomConfigIdType;

typedef struct {
    uint8         *SduDataPtr;
    uint8         *MetaDataPtr;
    PduLengthType SduLength;
} PduInfoType;

typedef enum {
    ICOM_SWITCH_E_OK     = 0x00,
    ICOM_SWITCH_E_FAILED = 0x01,
} IcomSwitch_ErrorType;

#endif //AUTOSAR_LIB_COMSTACKTYPES_H
