/***********************************************************************************************************************
 *
 * Module:       Can
 *
 * File Name:    Can.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_CAN_H
#define AUTOSAR_LIB_CAN_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {

} Can_ConfigType;

/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
void Can_Init(const Can_ConfigType *Config);

void Can_GetVersionInfo(Std_VersionInfoType *versioninfo);

void Can_DeInit(void);

Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID);

Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);

void Can_DisableControllerInterrupts(uint8 controller);

void Can_EnableControllerInterrupts(uint8 controller);

Std_ReturnType Can_CheckWakeup(uint8 Controller);

Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType *ErrorStatePtr);

Std_ReturnType Can_GetControllerMode(uint8 Controller, Can_ControllerStateType *ControllerModePtr);

Std_ReturnType Can_GetControllerRxErrorCounter(uint8 ControllerId, uint8 *RxErrorCounterPtr);

Std_ReturnType Can_GetControllerTxErrorCounter(uint8 ControllerId, uint8 *TxErrorCounterPtr);

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);

Std_ReturnType Can_SetIcomConfiguration(uint8 Controller, IcomConfigIdType ConfigurationId);

#endif //AUTOSAR_LIB_CAN_H
