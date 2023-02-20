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

typedef enum {
    TP_STMIN = 0x00,
    TP_BS    = 0x01,
    TP_BC    = 0x02,
} TPParameterType;

typedef enum
{
    BUFREQ_OK       = 0x00,
    BUFREQ_E_NOT_OK = 0x01,
    BUFREQ_E_BUSY   = 0x02,
    BUFREQ_E_OVFL   = 0x03
} BufReq_ReturnType;

#endif //AUTOSAR_LIB_COMSTACKTYPES_H
