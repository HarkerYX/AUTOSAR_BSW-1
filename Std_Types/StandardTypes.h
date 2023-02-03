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
