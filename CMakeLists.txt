cmake_minimum_required(VERSION 3.23)
project(AUTOSAR_LIB C)

set(CMAKE_C_STANDARD 99)

add_executable(AUTOSAR_LIB main.c
        CanIf/inc/CanIf.h
        Std_Types/StandardTypes.h
        Platform/x86/Platform_Types.h
        Can_GeneralTypes/Can_GeneralTypes.h
        ComStack_Types/ComStackTypes.h
        EcuM/EcuM.h
        CanIf/inc/CanIf_Can.h
        CanIf/inc/CanIf_CanTrcv.h
        CanTrv/inc/CanTrcv.h
        CanTrv/src/CanTrcv.c
        CanTrv/inc/CanTrcv.h
        SchM/inc/SchM_CanTrcv.h
        Can/inc/Can.h SchM/inc/SchM_Can.h)
