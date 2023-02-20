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
*                                           State Machine definitions                                                  *
***********************************************************************************************************************/
typedef enum {
    CanTp_Tx_IDLE                = 0x00,
    CanTP_TX_Transmit_SF         = 0x01,
    CanTP_TX_Transmit_FF         = 0x02,
    CanTP_TX_Transmit_CF         = 0x03,
    CanTP_TX_Wait_Confirm_SF     = 0x04,
    CanTP_TX_Wait_Confirm_FF     = 0x05,
    CanTP_TX_Wait_Confirm_CF     = 0x06,
    CanTP_TX_Prepare_Transmit_SF = 0x07,
    CanTP_TX_Prepare_Transmit_FF = 0x08,
    CanTP_TX_Prepare_Transmit_CF = 0x09,
    CanTp_Tx_Wait_STmin          = 0x0A,
} CanTP_TX_SM;

typedef struct {
    volatile uint16      Timer;
    uint16               STmin;
    volatile uint16      Stmin_Timer;
    uint16               Data_Length;
    uint16               Data_Index;
    PduIdType            TX_SDU_Handle;
    volatile CanTP_TX_SM Channel_State;
    BufReq_ReturnType    Buffer_State;
    uint8                BS;
    uint8                BS_Counter;
    uint8                Payload_Length;
    uint8                Payload[7];
    uint8                Secquence_Number;
    uint8                FC_Length;
    uint8                FC_Data[4];
} CanTP_TX_State_Type;

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

void CanTp_TX_MainFunction(void);

void CanTp_Rx_MainFunction(void);

#endif //AUTOSAR_LIB_CANTP_H
