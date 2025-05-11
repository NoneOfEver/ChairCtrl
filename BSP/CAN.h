/**
 * @file CAN.h
 * @author .noe
 * @brief CAN bsp for CH32V307
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef CAN_H
#define CAN_H
#include "ch32v30x.h"

#ifndef INTERRUPT_ATTRIBUTE
    #if defined(__GNUC__)
        // GCC编译器
        #define INTERRUPT_ATTRIBUTE __attribute__((interrupt("WCH-Interrupt-fast")))
    #elif defined(__CC_ARM)
        // Keil MDK ARMCC编译器
        #define INTERRUPT_ATTRIBUTE __irq
    #else
        // 其他编译器默认什么都不加
        #define INTERRUPT_ATTRIBUTE
    #endif
#endif

void USB_HP_CAN1_TX_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void USB_LP_CAN1_RX0_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void CAN2_TX_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void CAN2_RX0_IRQHandler(void) INTERRUPT_ATTRIBUTE;

typedef struct
{
    uint32_t id;         // 标准ID or 扩展ID
    uint8_t ide;         // CAN_Id_Standard / CAN_Id_Extended
    uint8_t rtr;         // CAN_RTR_Data / CAN_RTR_Remote
    uint8_t dlc;         // 数据长度
    uint8_t data[8];     // 数据
} CAN_Message_t;

/*********************************************************************
 * @fn      CAN_Mode_Init
 *
 * @brief   Initializes CAN communication test mode.
 *          Bps =Fpclk1/((tpb1+1+tbs2+1+1)*brp)
 *
 * @return  none
 */
void CAN1_Mode_Init(void);

void CAN2_Mode_Init(void);
#endif
