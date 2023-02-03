/***********************************************************************************************************************
 *
 * Module:       CanTrcv
 *
 * File Name:    CanTrcv.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CANTRCV_H
#define AUTOSAR_LIB_CANTRCV_H
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

} CanTrcv_ConfigType;

typedef enum {
    PN_ENABLED = 0x00,
    PN_DISABLE = 0x01,
} CanTrcv_PNActivationType;

typedef enum {
    CANTRCV_FLAG_SET    = 0x00,
    CANTRCV_FLAG_CLEARD = 0x01,
} CanTrcv_TrcvFlagStateType;

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
void CanTrcv_Init(const CanTrcv_ConfigType *ConfigPtr);

Std_ReturnType CanTrcv_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);

Std_ReturnType CanTrcv_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType *OpMode);

Std_ReturnType CanTrcv_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType *reason);

void CanTrcv_GetVersionInfo(Std_VersionInfoType *versioninfo);

Std_ReturnType CanTrcv_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

Std_ReturnType CanTrcv_GetSystemData(uint8 Transceiver, const uint32 *TrcvSysData);

Std_ReturnType Cantrcv_ClearTrcvWufFlag(uint8 Transceiver);

Std_ReturnType CanTrcv_ReadTrcvTimeoutFlag(uint8 Transceiver, CanTrcv_TrcvFlagStateType *FlagState);

Std_ReturnType CanTrcv_ClearTrcvTiemoutFlag(uint8 Transceiver);

Std_ReturnType CanTrcv_ReadTrcvSilenceFlag(uint8 Transceiver, CanTrcv_TrcvFlagStateType *FlagState);

Std_ReturnType CanTrcv_CheckWakeup(uint8 Transceiver);

Std_ReturnType CanTrcv_CheckWakeFlag(uint8 Transceiver);

void CanTrcv_DeInit(void);

#endif //AUTOSAR_LIB_CANTRCV_H
