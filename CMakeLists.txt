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
        Can/inc/Can.h
        SchM/inc/SchM_Can.h
        CanIf/src/CanIf.c
        Config/inc/CanIf_PbCfg.h
        Config/inc/CanIf_LCfg.h
        Config/src/CanIf_LCfg.c
        Config/src/CanIf_PbCfg.c
        Config/src/CanDrv_PbCfg.c
        Config/inc/CanDrv_PbCfg.h
        Config/src/CanDrv_LCfg.c
        Config/inc/CanDrv_LCfg.h Config/inc/Can_Types.h Config/src/CanTrcv_PbCfg.c Config/inc/CanTrcv_PbCfg.h Config/src/CanTrcv_LCfg.c Config/inc/CanTrcv_LCfg.h)
