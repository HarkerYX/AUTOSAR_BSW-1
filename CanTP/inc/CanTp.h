/***********************************************************************************************************************
 *
 * Module:       CanTP
 *
 * File Name:    CanTP.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANTP_H
#define AUTOSAR_LIB_CANTP_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../EcuM/EcuM.h"

/***********************************************************************************************************************
*                                                     MACRO                                                            *
***********************************************************************************************************************/

#define CANTP_OFF 0
#define CANTP_ON  1

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {

} CanTp_ConfigType;

typedef enum {
    CANTP_MODE_FULL_DUPLEX = 0x00,
    CANTP_MODE_HALF_DUPLEX = 0x01,
} CanTpChannelMode_Enum;

typedef enum {
    CANTP_EXTENDED    = 0x00,
    CANTP_MIXED       = 0x01,
    CANTP_MIXED29BIT  = 0x02,
    CANTP_NorMALFIXED = 0x03,
    CANTP_STANDARD    = 0x04,
} CanTpAddressingFormat_Enum;

typedef enum {
    CANTP_CANFD_FUNCTIONAL = 0x00,
    CANTP_CANFD_PHYSICAL   = 0x01,
    CANTP_FUNCTIONAL       = 0x02,
    CANTP_PHYSICAL         = 0x03,
} CanTpTaType_Enum;

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
void CanTp_Init(const CanTp_ConfigType *CfgPtr);

void CanTp_GetVersionInfo(Std_VersionInfoType *versioninfo);

void CanTp_Shutdown(void);

Std_ReturnType CanTp_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr);

Std_ReturnType CanTp_CancelTransmit(PduIdType TxPduId);

Std_ReturnType CanTp_CalcelReceive(PduInfoType RxPduId);

Std_ReturnType CanTp_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);

Std_ReturnType CanTp_ReadParameter(PduIdType id, TPParameterType parameter, uint16 value);

void CanTp_RxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr);

void CanTp_TxConfirmation(PduIdType TxPduId);

#endif //AUTOSAR_LIB_CANTP_H
