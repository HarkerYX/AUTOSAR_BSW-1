/***********************************************************************************************************************
 *
 * Module:       CanTp
 *
 * File Name:    CanTp.h
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
#include "../../Config/inc/CanTp_PbCfg.h"

/***********************************************************************************************************************
*                                                     MACRO                                                            *
***********************************************************************************************************************/

#define CANTP_OFF 0
#define CANTP_ON  1
#define CANTP_STATE_INITIALIZED     1
#define CANTP_STATE_NOT_INITIALIZED 0
#define CANTP_SHUTDOWN              0

#define CANTP_E_NO_ERROR            0xFF

/* AUTOSAR Development Errors
 * SWS_CANTP_00293 */
#define CANTP_E_PARAM_CONFIG        0x01
#define CANTP_E_PARAM_ID            0x02
#define CANTP_E_PARAM_POINTER       0x03
#define CANTP_E_INIT_FAILED         0x04
#define CANTP_E_UNINIT              0x20
#define CANTP_E_INVALID_TX_ID       0x30
#define CANTP_E_INVALID_RX_ID       0x40

/* AUTOSAR Runtime Errors
 * SWS_CANTP_00352 */
#define CANTP_E_PADDING             0x70
#define CANTP_E_INVALID_TATYPE      0x90
#define CANTP_E_OPER_NOT_SUPPORTED  0xA0
#define CANTP_E_COM                 0xB0
#define CANTP_E_RX_COM              0xC0
#define CANTP_E_TX_COM              0xD0

/* Detail self-defined Errors */
#define CANTP_E_TX_TIMEOUT_AS       0xD1
#define CANTP_E_TX_TIMEOUT_BS       0xD2
#define CANTP_E_TX_TIMEOUT_CS       0xD3

/* Length */
#define CANTP_CAN20_FRAME_LENGTH    8

/* ISO 15765-2:2016 Table 9 */
#define CANTP_PCI_LENGTH_SF         1
#define CANTP_PCI_LENGTH_FF         2
#define CANTP_PCI_LENGTH_CF         1
#define CANTP_PCI_LENGTH_FC         3

#define CANTP_TX_MAX_PAYLOAD_SF     CANTP_CAN20_FRAME_LENGTH - CANTP_PCI_LENGTH_SF
#define CANTP_TX_MAX_PAYLOAD_CF     CANTP_CAN20_FRAME_LENGTH - CANTP_PCI_LENGTH_CF
#define CANTP_TX_MAX_PAYLOAD_FF     CANTP_CAN20_FRAME_LENGTH - CANTP_PCI_LENGTH_FF
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
    CanTp_TX_Transmit_SF         = 0x01,
    CanTp_TX_Transmit_FF         = 0x02,
    CanTp_TX_Transmit_CF         = 0x03,
    CanTp_TX_Wait_Confirm_SF     = 0x04,
    CanTp_TX_Wait_Confirm_FF     = 0x05,
    CanTp_TX_Wait_Confirm_CF     = 0x06,
    CanTp_TX_Prepare_Transmit_SF = 0x07,
    CanTp_TX_Prepare_Transmit_FF = 0x08,
    CanTp_TX_Prepare_Transmit_CF = 0x09,
    CanTp_TX_Wait_STmin          = 0x0A,
    CanTp_TX_Wait_FC             = 0x0B,
} CanTp_TX_SM;



/***********************************************************************************************************************
*                                                  Functions                                                           *
***********************************************************************************************************************/
void CanTp_Init(const CanTp_ConfigType *CfgPtr);

void CanTp_GetVersionInfo(Std_VersionInfoType *versioninfo);

void CanTp_Shutdown(void);

extern Std_ReturnType CanTp_Transmit(PduIdType TxPduId, const PduInfoType *PduInfoPtr);

Std_ReturnType CanTp_CancelTransmit(PduIdType TxPduId);

Std_ReturnType CanTp_CalcelReceive(PduInfoType RxPduId);

Std_ReturnType CanTp_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);

Std_ReturnType CanTp_ReadParameter(PduIdType id, TPParameterType parameter, uint16 value);

void CanTp_RxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr);

void CanTp_TxConfirmation(PduIdType TxPduId);

void CanTp_TX_MainFunction(void);

void CanTp_Rx_MainFunction(void);


#endif //AUTOSAR_LIB_CANTP_H
