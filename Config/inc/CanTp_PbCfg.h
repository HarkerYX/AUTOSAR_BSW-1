/***********************************************************************************************************************
 *
 * Module:       Static Config
 *
 * File Name:    CanTp_PbCfg.c
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:  AUTOSAR_SWS_CANInterface 4.4
 *
 **********************************************************************************************************************/
#ifndef AUTOSAR_LIB_CANTP_PBCONFIG_H
#define AUTOSAR_LIB_CANTP_PBCONFIG_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../../Std_Types/StandardTypes.h"
#include "../../Can_GeneralTypes/Can_GeneralTypes.h"
#include "../../ComStack_Types/ComStackTypes.h"
#include "../../CanTP/inc/CanTp.h"

/***********************************************************************************************************************
*                                                    MACRO                                                            *
***********************************************************************************************************************/
#define CANTP_CHANNEL_NUMS 3
#define CANTP_RX_NSDU_NUMS 2
#define CANTP_TX_NSDU_NUMS 2

/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef struct {
    uint8 CanTpNTa;
} CanTp_NTa;

typedef struct {
    uint8 CanTpNSa;
} CanTp_NSa;

typedef struct {
    uint8 CanTpNAe;
} CanTp_NAe;

typedef struct {
    uint16    CanTpRxNPduId;
    PduIdType CanTpRxNPduRef;
} CanTpRxNPdu;

typedef struct {
    uint16    CanTpTxFcNPduConfirmationPduId;
    PduIdType CanTpTxFcNPduRef;
} CanTpTxFcNPdu;

typedef struct {
    uint16    CanTpTxNPduId;
    PduIdType CanTpTxNPduRef;
} CanTpTxNPdu;

typedef struct {
    uint16    CanTpRxFcNPduConfirmationPduId;
    PduIdType CanTpRxFcNPduRef;
} CanTpRxFcNPdu;

typedef struct {
    uint8              CanTpBs;
    float64            CanTpNar;
    float64            CanTpNbr;
    float64            CanTpNcr;
    CanTpAddressingFormat_Enum CanTpRxAddressingFormat;
    uint16             CanTpRxNSduId;
    boolean            CanTpRxPaddingActivation;
    CanTpTaType_Enum   CanTpRxTaType;
    uint16             CanTpRxWftMax;
    float64            CanTpSTmin;
    PduIdType          CanTpRxNSduRef;
    CanTp_NAe          CanTp_NAe_Group[1];
    CanTp_NSa          CanTp_NSa_Group[1];
    CanTp_NTa          CanTp_NTa_Group[1];
    CanTpRxNPdu        CanTpRxNPdu_Group[1];
    CanTpTxFcNPdu      CanTpTxFcNPdu_Group[1];
} CanTpRxNSdu;

typedef struct {
    float64          CanTpNas;
    float64          CanTpNbs;
    float64          CanTpNcs;
    boolean          CanTpTc;
    CanTpAddressingFormat_Enum CanTpTxAddressingFormat;
    uint16           CanTpTxNSduId;
    boolean          CanTpTxPaddingActivation;
    CanTpTaType_Enum CanTpTxTaType;
    PduIdType        CanTpTxNSduRef;
    CanTp_NAe        CanTp_NAe_Group[1];
    CanTp_NSa        CanTp_NSa_Group[1];
    CanTp_NTa        CanTp_NTa_Group[1];
    CanTpTxNPdu      CanTpTxNPdu_Group[1];
    CanTpRxFcNPdu    CanTpRxFcNPdu_Group[1];
} CanTpTxNSdu;

typedef struct {
    CanTpChannelMode_Enum CanTpChannelMode;
    CanTpRxNSdu CanTpRxNSdu_Group[CANTP_RX_NSDU_NUMS];
    CanTpTxNSdu CanTpTxNSdu_Group[CANTP_TX_NSDU_NUMS];
} CanTpChannel;

typedef struct {
    boolean CanTpChangeParameterApi;
    boolean CanTpDevErrorDetect;
    boolean CanTpDynIdSupport;
    boolean CanTpFlexibleDataRateSupport;
    boolean CanTpGenericConnectionSupport;
    uint8   CanTpPaddingByte;
    boolean CanTpReadParameterApi;
    boolean CanTpVersionInfoApi;
} CanTpGeneral;

typedef struct {
    float32 CanTpMainFunctionPeriod;
    uint64  CanTpMaxChannelCnt;
    CanTpChannel CanTpChannel_Group[CANTP_CHANNEL_NUMS];
} CanTpConfig;

typedef struct {
    CanTpConfig  *CanTpConfig_Ref;
    CanTpGeneral *CanTpGeneral_Ref;
} CanTp;

typedef struct {
    volatile uint16      Timer;
    uint16               STmin;
    volatile uint16      Stmin_Timer;
    uint16               Data_Length;
    uint16               Data_Index;
    PduIdType            TX_SDU_Handle;
    volatile CanTp_TX_SM Channel_State;
    BufReq_ReturnType    Buffer_State;
    uint8                BS;
    uint8                BS_Counter;
    uint8                Payload_Length;
    uint8                Payload[7];
    uint8                Secquence_Number;
    uint8                FC_Length;
    uint8                FC_Data[4];
} CanTp_TX_State_Type;



extern CanTp_TX_State_Type CanTp_TX_State[3];
#endif //AUTOSAR_LIB_CANTP_PBCONFIG_H
