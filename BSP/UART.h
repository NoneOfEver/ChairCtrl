/**
 * @file UART.h
 * @author .noe
 * @brief UART bsp for CH32V307
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef USART_H
#define USART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v30x.h"

/******************************
           MACRO 
 ******************************/
#define BUFFER_SIZE 256

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

/*********************************
 *          TYPES
 *********************************/
typedef struct
{
    uint8_t data[256];  // 接收缓冲
    uint16_t length;    // 有效数据长度
} UART_RxPacket_t;

typedef struct
{
    uint8_t data[64];    // 发送数据指针
    uint16_t length;  // 发送数据长度
} UART_TxPacket_t;

typedef struct
{
    UART_RxPacket_t temp_rx_packet;
    UART_RxPacket_t rx_packet;
    UART_TxPacket_t tx_packet;
    uint8_t uart_dma_rx_buffer[BUFFER_SIZE];
    uint8_t uart_dma_tx_buffer[BUFFER_SIZE];
} UART_Instance_t;

/*********************************
 *         VARIABLES
 *********************************/
extern UART_Instance_t uart1_instance;
extern UART_Instance_t uart2_instance;
extern UART_Instance_t uart3_instance;
extern UART_Instance_t uart4_instance;
extern UART_Instance_t uart6_instance;

/*********************************
 *        FUNCTIONS
 *********************************/
void UART1_Init();
void UART2_Init();
void UART3_Init();
void UART4_Init();
void UART6_Init();

/* IRQ Handlers */
void USART1_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void USART2_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void USART3_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void UART4_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void UART6_IRQHandler(void) INTERRUPT_ATTRIBUTE;

void DMA1_Channel4_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void DMA1_Channel7_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void DMA1_Channel2_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void DMA2_Channel5_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void DMA2_Channel6_IRQHandler(void) INTERRUPT_ATTRIBUTE;

#ifdef __cplusplus
}
#endif
#endif/* __UART_H */
