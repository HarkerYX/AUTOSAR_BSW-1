/***********************************************************************************************************************
 *
 * Module:       EcuM
 *
 * File Name:    EcuM_Can.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/

#ifndef AUTOSAR_LIB_SCHM_CAN_H
#define AUTOSAR_LIB_SCHM_CAN_H
/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
void Can_MainFunction_Write(void);

void Can_MainFunction_Read(void);

void Can_MainFunction_BusOff(void);

void Can_MainFunction_Wakeup(void);

void Can_MainFunction_Mode(void);

#endif //AUTOSAR_LIB_SCHM_CAN_H
