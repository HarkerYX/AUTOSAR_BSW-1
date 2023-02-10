/***********************************************************************************************************************
 *
 * Module:       Std_Types
 *
 * File Name:    StandardTypes.h
 *
 * Author:       yiyang.cai@pm.me
 *
 * Description:
 *
 **********************************************************************************************************************/
#ifndef AUTOSAR_LIB_STANDARDTYPES_H
#define AUTOSAR_LIB_STANDARDTYPES_H
/***********************************************************************************************************************
*                                                   Includes                                                           *
***********************************************************************************************************************/
#include "../Platform/x86/Platform_Types.h"

/***********************************************************************************************************************
*                                                    Macro                                                             *
***********************************************************************************************************************/
#define E_OK       0x00u
#define E_NOT_OK   0x01u
#define STD_ON     0x01u
#define STD_OFF    0x00u
#define STD_HIGH   0x01u
#define STD_LOW    0x00u
#define NULL       (0)
/***********************************************************************************************************************
*                                               Type definitions                                                       *
***********************************************************************************************************************/
typedef uint8 Std_ReturnType;

typedef struct
{
    uint16  vendorID;
    uint16  moduleID;
    uint8   sw_major_version;
    uint8   sw_minor_version;
    uint8   sw_patch_version;
} Std_VersionInfoType;

#endif //AUTOSAR_LIB_STANDARDTYPES_H
