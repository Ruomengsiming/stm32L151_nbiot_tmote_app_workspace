///////////////////////////////////////////////////////////////////////////////
//
// IAR C/C++ Compiler V3.11.1.207 for STM8                22/Aug/2019  15:05:22
// Copyright 2010-2019 IAR Systems AB.
// PC-locked license - IAR Embedded Workbench for STMicroelectronics STM8
//
//    Source file  =  
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Libraries\src\stm8l15x_spi.c
//    Command line =  
//        -f C:\Users\kyjapple\AppData\Local\Temp\EWD1E6.tmp
//        (F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Libraries\src\stm8l15x_spi.c
//        -e -Ol --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa
//        --no_cross_call --debug --code_model small --data_model medium -o
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Output\Obj
//        --dlib_config "F:\IAR Systems\Embedded Workbench
//        8.3\stm8\LIB\dlstm8smn.h" -D STM8L05X_LD_VL -lcN
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Output\List
//        -lb
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Output\List
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Core\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Libraries\inc\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Libraries\src\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\System\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\User\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\System\Delay\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\System\Sys\
//        -I
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\System\Usart\
//        --vregs 16)
//    Locale       =  Chinese (Simplified)_CHN.936
//    List file    =  
//        F:\Movebroad\stm32L151_nbiot\workspace\stm32L151_nbiot_tmote_app_workspace\stm8L001_ook_tmote_app_lockctrl\Output\List\stm8l15x_spi.s
//
///////////////////////////////////////////////////////////////////////////////

        EXTERN ?b0
        EXTERN ?b1
        EXTERN ?b2
        EXTERN ?b3
        EXTERN ?b4
        EXTERN ?b5
        EXTERN ?b6
        EXTERN ?b7
        EXTERN ?sll16_x_x_a
        EXTERN ?w1

        PUBLIC SPI_BiDirectionalLineConfig
        PUBLIC SPI_CalculateCRCCmd
        PUBLIC SPI_ClearFlag
        PUBLIC SPI_ClearITPendingBit
        PUBLIC SPI_Cmd
        PUBLIC SPI_DMACmd
        PUBLIC SPI_DeInit
        PUBLIC SPI_GetCRC
        PUBLIC SPI_GetCRCPolynomial
        PUBLIC SPI_GetFlagStatus
        PUBLIC SPI_GetITStatus
        PUBLIC SPI_ITConfig
        PUBLIC SPI_Init
        PUBLIC SPI_NSSInternalSoftwareCmd
        PUBLIC SPI_ReceiveData
        PUBLIC SPI_ResetCRC
        PUBLIC SPI_SendData
        PUBLIC SPI_TransmitCRC


        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_DeInit:
        LDW       Y, X
        CLR       (Y)
        LDW       X, Y
        INCW      X
        CLR       (X)
        LDW       X, Y
        INCW      X
        INCW      X
        CLR       (X)
        LD        A, #0x2
        LDW       X, Y
        ADDW      X, #0x3
        LD        (X), A
        LD        A, #0x7
        LDW       X, Y
        ADDW      X, #0x5
        LD        (X), A
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_Init:
        LDW       Y, X
        LD        S:?b7, A
        LD        A, S:?b3
        OR        A, S:?b2
        PUSH      A
        LD        A, S:?b0
        OR        A, S:?b7
        LD        S:?b0, A
        POP       A
        OR        A, S:?b0
        LD        (Y), A
        LD        A, S:?b5
        OR        A, S:?b4
        LDW       X, Y
        INCW      X
        LD        (X), A
        LD        A, S:?b1
        CP        A, #0x4
        JRNE      L:??SPI_Init_0
        LDW       X, Y
        INCW      X
        LD        A, (X)
        OR        A, #0x1
        LDW       X, Y
        INCW      X
        LD        (X), A
        JRA       L:??SPI_Init_1
??SPI_Init_0:
        LDW       X, Y
        INCW      X
        LD        A, (X)
        AND       A, #0xfe
        LDW       X, Y
        INCW      X
        LD        (X), A
??SPI_Init_1:
        LD        A, (Y)
        OR        A, S:?b1
        LD        (Y), A
        LD        A, S:?b6
        LDW       X, Y
        ADDW      X, #0x5
        LD        (X), A
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_Cmd:
        TNZ       A
        JREQ      L:??SPI_Cmd_0
        LD        A, (X)
        OR        A, #0x40
        LD        (X), A
        RET
??SPI_Cmd_0:
        LD        A, (X)
        AND       A, #0xbf
        LD        (X), A
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_NSSInternalSoftwareCmd:
        LDW       Y, X
        TNZ       A
        JREQ      L:??SPI_NSSInternalSoftwareCmd_0
        LDW       X, Y
        INCW      X
        LD        A, (X)
        OR        A, #0x1
        INCW      Y
        LD        (Y), A
        RET
??SPI_NSSInternalSoftwareCmd_0:
        LDW       X, Y
        INCW      X
        LD        A, (X)
        AND       A, #0xfe
        INCW      Y
        LD        (Y), A
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_BiDirectionalLineConfig:
        LDW       Y, X
        TNZ       A
        JREQ      L:??SPI_BiDirectionalLineConfig_0
        LDW       X, Y
        INCW      X
        LD        A, (X)
        OR        A, #0x40
        INCW      Y
        LD        (Y), A
        RET
??SPI_BiDirectionalLineConfig_0:
        LDW       X, Y
        INCW      X
        LD        A, (X)
        AND       A, #0xbf
        INCW      Y
        LD        (Y), A
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_SendData:
        ADDW      X, #0x4
        LD        (X), A
        SUBW      X, #0x4
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_ReceiveData:
        ADDW      X, #0x4
        LD        A, (X)
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_TransmitCRC:
        LDW       Y, X
        LDW       X, Y
        INCW      X
        LD        A, (X)
        OR        A, #0x10
        INCW      Y
        LD        (Y), A
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_CalculateCRCCmd:
        LDW       Y, X
        LD        S:?b0, A
        CLR       A
        LDW       X, #0x5200
        CALL      L:SPI_Cmd
        TNZ       S:?b0
        JREQ      L:??SPI_CalculateCRCCmd_0
        LDW       X, Y
        INCW      X
        LD        A, (X)
        OR        A, #0x20
        INCW      Y
        LD        (Y), A
        RET
??SPI_CalculateCRCCmd_0:
        LDW       X, Y
        INCW      X
        LD        A, (X)
        AND       A, #0xdf
        INCW      Y
        LD        (Y), A
        RET

        SECTION `.near_func.text`:CODE:NOROOT(0)
        CODE
SPI_GetCRC:
        CLR       S:?b0
        TNZ       A
        JREQ      L:??SPI_GetCRC_0
        ADDW      X, #0x7
        LD        A, (X)
        LD        S:?b0, A
        JRA       L:??SPI_GetCRC_1
??SPI_GetCRC_0:
        ADDW      X, #0x6
        LD        A, (X)
        LD        S:?b0, A
??SPI_GetCRC_1:
        LD        A, S:?b0
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_ResetCRC:
        LDW       S:?w1, X
        LD        A, #0x1
        LDW       X, S:?w1
        CALL      L:SPI_CalculateCRCCmd
        LD        A, #0x1
        LDW       X, S:?w1
        JP        L:SPI_Cmd

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_GetCRCPolynomial:
        ADDW      X, #0x5
        LD        A, (X)
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_DMACmd:
        LDW       Y, X
        LD        S:?b1, A
        TNZ       S:?b0
        JREQ      L:??SPI_DMACmd_0
        LDW       X, Y
        INCW      X
        INCW      X
        LD        A, (X)
        OR        A, S:?b1
        INCW      Y
        INCW      Y
        LD        (Y), A
        RET
??SPI_DMACmd_0:
        LDW       X, Y
        INCW      X
        INCW      X
        CPL       S:?b1
        LD        A, S:?b1
        AND       A, (X)
        INCW      Y
        INCW      Y
        LD        (Y), A
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_ITConfig:
        LDW       Y, X
        CLR       S:?b1
        AND       A, #0xf
        CLRW      X
        INCW      X
        CALL      L:?sll16_x_x_a
        LD        A, XL
        LD        S:?b1, A
        TNZ       S:?b0
        JREQ      L:??SPI_ITConfig_0
        LDW       X, Y
        INCW      X
        INCW      X
        LD        A, (X)
        OR        A, S:?b1
        INCW      Y
        INCW      Y
        LD        (Y), A
        RET
??SPI_ITConfig_0:
        LDW       X, Y
        INCW      X
        INCW      X
        CPL       S:?b1
        LD        A, S:?b1
        AND       A, (X)
        INCW      Y
        INCW      Y
        LD        (Y), A
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_GetFlagStatus:
        LD        S:?b1, A
        CLR       S:?b0
        ADDW      X, #0x3
        LD        A, (X)
        AND       A, S:?b1
        CP        A, #0x0
        JREQ      L:??SPI_GetFlagStatus_0
        MOV       S:?b0, #0x1
        JRA       L:??SPI_GetFlagStatus_1
??SPI_GetFlagStatus_0:
        CLR       S:?b0
??SPI_GetFlagStatus_1:
        LD        A, S:?b0
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_ClearFlag:
        CPL       A
        ADDW      X, #0x3
        LD        (X), A
        SUBW      X, #0x3
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_GetITStatus:
        SUB       SP, #0x1
        LDW       Y, X
        LD        S:?b2, A
        CLR       S:?b0
        CLR       S:?b4
        CLR       S:?b1
        CLR       S:?b3
        CLR       (0x1,SP)
        LD        A, S:?b2
        AND       A, #0xf
        CLRW      X
        INCW      X
        CALL      L:?sll16_x_x_a
        LD        A, XL
        LD        S:?b4, A
        LD        A, S:?b2
        SWAP      A
        AND       A, #0xf
        LD        S:?b1, A
        CLRW      X
        INCW      X
        LD        A, S:?b1
        CALL      L:?sll16_x_x_a
        LD        A, XL
        LD        S:?b3, A
        LDW       X, Y
        ADDW      X, #0x3
        LD        A, (X)
        AND       A, S:?b3
        LD        (0x1,SP), A
        INCW      Y
        INCW      Y
        LD        A, (Y)
        AND       A, S:?b4
        CP        A, #0x0
        JREQ      L:??SPI_GetITStatus_0
        TNZ       (0x1,SP)
        JREQ      L:??SPI_GetITStatus_0
        MOV       S:?b0, #0x1
        JRA       L:??SPI_GetITStatus_1
??SPI_GetITStatus_0:
        CLR       S:?b0
??SPI_GetITStatus_1:
        LD        A, S:?b0
        ADD       SP, #0x1
        RET

        SECTION `.near_func.text`:CODE:REORDER:NOROOT(0)
        CODE
SPI_ClearITPendingBit:
        LDW       Y, X
        CLR       S:?b0
        SWAP      A
        AND       A, #0xf
        CLRW      X
        INCW      X
        CALL      L:?sll16_x_x_a
        LD        A, XL
        LD        S:?b0, A
        CPL       S:?b0
        LD        A, S:?b0
        LDW       X, Y
        ADDW      X, #0x3
        LD        (X), A
        RET

        SECTION VREGS:DATA:REORDER:NOROOT(0)

        END
// 
// 481 bytes in section .near_func.text
// 
// 481 bytes of CODE memory
//
//Errors: none
//Warnings: none
