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
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {

} CanTp_ConfigType;
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

#endif //AUTOSAR_LIB_CANTP_H
