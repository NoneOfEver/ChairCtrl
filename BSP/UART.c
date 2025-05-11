/**
 * @file UART.c
 * @author .noe
 * @brief UART bsp for CH32V307
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "UART.h"
#include "FreeRTOS.h"
#include "OS_objects.h"
#include "string.h"


/******************************
        Local Variable 
 ******************************/
UART_Instance_t uart1_instance;
UART_Instance_t uart2_instance;
UART_Instance_t uart3_instance;
UART_Instance_t uart4_instance;
UART_Instance_t uart6_instance;

/******************************
        Global Variable 
 ******************************/

/******************************
      Interrupt Functions 
 ******************************/
void USART1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void USART3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART6_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void DMA1_Channel4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA1_Channel7_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA1_Channel2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA2_Channel5_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void DMA2_Channel6_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
/******************************
      Initial Functions 
 ******************************/
void UART1_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure  = {0};
    USART_InitTypeDef  USART_InitStructure = {0};
    NVIC_InitTypeDef   NVIC_InitStructure  = {0};
    DMA_InitTypeDef    DMA_InitStructure   = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    /* USART1 TX-->A.9   RX-->A.10 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART1, &USART_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;      //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                              //中断优先级初始化

    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  // FreeRTOS要求
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    DMA_DeInit(DMA1_Channel4);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&USART1->DATAR); /* USART2->DATAR:0x40004404 */
    DMA_InitStructure.DMA_MemoryBaseAddr = 0;// dynamic set
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 0;//dynamic set
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);

    DMA_DeInit(DMA1_Channel5);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&USART1->DATAR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)uart1_instance.uart_dma_rx_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
    DMA_Init(DMA1_Channel5, &DMA_InitStructure);

    USART_ITConfig(USART1,USART_IT_IDLE,ENABLE);// enable the idle line interrupt
    DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE);

    DMA_Cmd(DMA1_Channel5, ENABLE); // USART1 Tx 
    DMA_Cmd(DMA1_Channel4, ENABLE); // USART1 Rx

    USART_DMACmd(USART1,USART_DMAReq_Rx|USART_DMAReq_Tx,ENABLE);
    USART_Cmd(USART1,ENABLE);
}


void UART2_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure  = {0};
    USART_InitTypeDef  USART_InitStructure = {0};
    NVIC_InitTypeDef   NVIC_InitStructure  = {0};
    DMA_InitTypeDef    DMA_InitStructure   = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    /* USART2 TX-->A.2   RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART2, &USART_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;      //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                              //中断优先级初始化

    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel7_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  // FreeRTOS要求
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    DMA_DeInit(DMA1_Channel7);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&USART2->DATAR); /* USART2->DATAR:0x40004404 */
    DMA_InitStructure.DMA_MemoryBaseAddr = 0;// dynamic set
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 0;//dynamic set
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel7, &DMA_InitStructure);

    DMA_DeInit(DMA1_Channel6);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&USART2->DATAR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)uart2_instance.uart_dma_rx_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
    DMA_Init(DMA1_Channel6, &DMA_InitStructure);

    USART_ITConfig(USART2,USART_IT_IDLE,ENABLE);// enable the idle line interrupt
    DMA_ITConfig(DMA1_Channel7, DMA_IT_TC, ENABLE);

    DMA_Cmd(DMA1_Channel7, ENABLE); // USART2 Tx 
    DMA_Cmd(DMA1_Channel6, ENABLE); // USART2 Rx

    USART_DMACmd(USART2,USART_DMAReq_Rx|USART_DMAReq_Tx,ENABLE);
    USART_Cmd(USART2,ENABLE);
}

void UART3_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure  = {0};
    USART_InitTypeDef  USART_InitStructure = {0};
    NVIC_InitTypeDef   NVIC_InitStructure  = {0};
    DMA_InitTypeDef    DMA_InitStructure   = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    /* USART3 TX-->B.10   RX-->B.11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART3, &USART_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;      //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                              //中断优先级初始化

    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  // FreeRTOS要求
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    DMA_DeInit(DMA1_Channel2);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&USART3->DATAR); /* USART2->DATAR:0x40004404 */
    DMA_InitStructure.DMA_MemoryBaseAddr = 0;// dynamic set
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 0;//dynamic set
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel2, &DMA_InitStructure);

    DMA_DeInit(DMA1_Channel3);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&USART3->DATAR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)uart3_instance.uart_dma_rx_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
    DMA_Init(DMA1_Channel3, &DMA_InitStructure);

    USART_ITConfig(USART3,USART_IT_IDLE,ENABLE);// enable the idle line interrupt
    DMA_ITConfig(DMA1_Channel2, DMA_IT_TC, ENABLE);

    DMA_Cmd(DMA1_Channel3, ENABLE); // USART2 Tx 
    DMA_Cmd(DMA1_Channel3, ENABLE); // USART2 Rx

    USART_DMACmd(USART3,USART_DMAReq_Rx|USART_DMAReq_Tx,ENABLE);
    USART_Cmd(USART3,ENABLE);
}

void UART4_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure  = {0};
    USART_InitTypeDef  USART_InitStructure = {0};
    NVIC_InitTypeDef   NVIC_InitStructure  = {0};
    DMA_InitTypeDef    DMA_InitStructure   = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    /* USART4 TX-->C.10   RX-->C.11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; // 流控引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOC, GPIO_Pin_12); // 默认接收模式

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(UART4, &USART_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;      //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                              //中断优先级初始化

    NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  // FreeRTOS要求
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    DMA_DeInit(DMA2_Channel5);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART4->DATAR); /* USART2->DATAR:0x40004404 */
    DMA_InitStructure.DMA_MemoryBaseAddr = 0;// dynamic set
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 0;//dynamic set
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA2_Channel5, &DMA_InitStructure);

    DMA_DeInit(DMA2_Channel3);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART4->DATAR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)uart4_instance.uart_dma_rx_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
    DMA_Init(DMA2_Channel3, &DMA_InitStructure);

    USART_ITConfig(UART4,USART_IT_IDLE,ENABLE);// enable the idle line interrupt
    DMA_ITConfig(DMA2_Channel5, DMA_IT_TC, ENABLE);

    DMA_Cmd(DMA2_Channel5, ENABLE); // USART2 Tx 
    DMA_Cmd(DMA2_Channel3, ENABLE); // USART2 Rx

    USART_DMACmd(UART4,USART_DMAReq_Rx|USART_DMAReq_Tx,ENABLE);
    USART_Cmd(UART4,ENABLE);
}

void UART6_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure  = {0};
    USART_InitTypeDef  USART_InitStructure = {0};
    NVIC_InitTypeDef   NVIC_InitStructure  = {0};
    DMA_InitTypeDef    DMA_InitStructure   = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART6,ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    /* USART6 TX-->B.8   RX-->B.9 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(UART6, &USART_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = UART6_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;      //抢占优先级为1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //子优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                              //中断优先级初始化

    NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel6_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  // FreeRTOS要求
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    DMA_DeInit(DMA2_Channel6);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART6->DATAR); /* USART2->DATAR:0x40004404 */
    DMA_InitStructure.DMA_MemoryBaseAddr = 0;// dynamic set
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = 0;//dynamic set
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA2_Channel6, &DMA_InitStructure);

    DMA_DeInit(DMA2_Channel7);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART6->DATAR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)uart6_instance.uart_dma_rx_buffer;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = BUFFER_SIZE;
    DMA_Init(DMA2_Channel7, &DMA_InitStructure);

    USART_ITConfig(UART6,USART_IT_IDLE,ENABLE);// enable the idle line interrupt
    DMA_ITConfig(DMA2_Channel6, DMA_IT_TC, ENABLE);

    DMA_Cmd(DMA2_Channel6, ENABLE); // UART6 Tx 
    DMA_Cmd(DMA2_Channel7, ENABLE); // UART6 Rx

    USART_DMACmd(UART6,USART_DMAReq_Rx|USART_DMAReq_Tx,ENABLE);
    USART_Cmd(UART6,ENABLE);
}

/******************************
      Interrupt Functions 
 ******************************/
void USART1_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
    {
        volatile uint32_t tmp;
        tmp = USART1->STATR;  // 先读SR
        tmp = USART1->DATAR;  // 再读DR清除IDLE
        (void)tmp;

        DMA_Cmd(DMA1_Channel5, DISABLE);

        // 计算收到的数据长度
        uint16_t len = BUFFER_SIZE - DMA_GetCurrDataCounter(DMA1_Channel5);

        if (len > 0 && len <= BUFFER_SIZE)
        {
            UART_RxPacket_t packet;
            memcpy(packet.data, uart1_instance.uart_dma_rx_buffer, len);
            packet.length = len;

            // 把接收到的一包数据放入队列
            xQueueSendFromISR(uart1_rx_packet_queue, &packet, &xHigherPriorityTaskWoken);
        }

        // 重启DMA
        DMA_SetCurrDataCounter(DMA1_Channel5, BUFFER_SIZE);
        DMA_Cmd(DMA1_Channel5, ENABLE);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void DMA1_Channel4_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (DMA_GetITStatus(DMA1_IT_TC4))
    {
        DMA_ClearITPendingBit(DMA1_IT_TC4);

        // 停止DMA
        DMA_Cmd(DMA1_Channel4, DISABLE);

        // 给发送完成信号
        xSemaphoreGiveFromISR(uart1_tx_done_semaphore, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}


void USART2_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
    {
        volatile uint32_t tmp;
        tmp = USART2->STATR;  // 先读SR
        tmp = USART2->DATAR;  // 再读DR清除IDLE
        (void)tmp;

        DMA_Cmd(DMA1_Channel6, DISABLE);

        // 计算收到的数据长度
        uint16_t len = BUFFER_SIZE - DMA_GetCurrDataCounter(DMA1_Channel6);

        if (len > 0 && len <= BUFFER_SIZE)
        {
            UART_RxPacket_t packet;
            memcpy(packet.data, uart2_instance.uart_dma_rx_buffer, len);
            packet.length = len;

            // 把接收到的一包数据放入队列
            xQueueSendFromISR(uart2_rx_packet_queue, &packet, &xHigherPriorityTaskWoken);
        }

        // 重启DMA
        DMA_SetCurrDataCounter(DMA1_Channel6, BUFFER_SIZE);
        DMA_Cmd(DMA1_Channel6, ENABLE);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void DMA1_Channel7_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (DMA_GetITStatus(DMA1_IT_TC7))
    {
        DMA_ClearITPendingBit(DMA1_IT_TC7);

        // 停止DMA
        DMA_Cmd(DMA1_Channel7, DISABLE);

        // 给发送完成信号
        xSemaphoreGiveFromISR(uart2_tx_done_semaphore, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void USART3_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART_GetITStatus(USART3, USART_IT_IDLE) != RESET)
    {
        volatile uint32_t tmp;
        tmp = USART3->STATR;  // 先读SR
        tmp = USART3->DATAR;  // 再读DR清除IDLE
        (void)tmp;

        DMA_Cmd(DMA1_Channel6, DISABLE);

        // 计算收到的数据长度
        uint16_t len = BUFFER_SIZE - DMA_GetCurrDataCounter(DMA1_Channel3);

        if (len > 0 && len <= BUFFER_SIZE)
        {
            UART_RxPacket_t packet;
            memcpy(packet.data, uart3_instance.uart_dma_rx_buffer, len);
            packet.length = len;

            // 把接收到的一包数据放入队列
            xQueueSendFromISR(uart3_rx_packet_queue, &packet, &xHigherPriorityTaskWoken);
        }

        // 重启DMA
        DMA_SetCurrDataCounter(DMA1_Channel3, BUFFER_SIZE);
        DMA_Cmd(DMA1_Channel3, ENABLE);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void DMA1_Channel2_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (DMA_GetITStatus(DMA1_IT_TC2))
    {
        DMA_ClearITPendingBit(DMA1_IT_TC2);

        // 停止DMA
        DMA_Cmd(DMA1_Channel2, DISABLE);

        // 给发送完成信号
        xSemaphoreGiveFromISR(uart3_tx_done_semaphore, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void UART4_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART_GetITStatus(UART4, USART_IT_IDLE) != RESET)
    {
        volatile uint32_t tmp;
        tmp = UART4->STATR;  // 先读SR
        tmp = UART4->DATAR;  // 再读DR清除IDLE
        (void)tmp;

        DMA_Cmd(DMA2_Channel3, DISABLE);

        // 计算收到的数据长度
        uint16_t len = BUFFER_SIZE - DMA_GetCurrDataCounter(DMA2_Channel3);

        if (len > 0 && len <= BUFFER_SIZE)
        {
            UART_RxPacket_t packet;
            memcpy(packet.data, uart4_instance.uart_dma_rx_buffer, len);
            packet.length = len;

            // 把接收到的一包数据放入队列
            xQueueSendFromISR(uart4_rx_packet_queue, &packet, &xHigherPriorityTaskWoken);
        }

        // 重启DMA
        DMA_SetCurrDataCounter(DMA2_Channel3, BUFFER_SIZE);
        DMA_Cmd(DMA2_Channel3, ENABLE);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void DMA2_Channel5_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (DMA_GetITStatus(DMA2_IT_TC5))
    {
        DMA_ClearITPendingBit(DMA2_IT_TC5);

        // 停止DMA
        DMA_Cmd(DMA2_Channel5, DISABLE);
        // 切回接收方向
        GPIO_ResetBits(GPIOC, GPIO_Pin_12);  // RE+DE = 0，接收模式
        // 给发送完成信号
        xSemaphoreGiveFromISR(uart4_tx_done_semaphore, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void UART6_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART_GetITStatus(UART6, USART_IT_IDLE) != RESET)
    {
        volatile uint32_t tmp;
        tmp = UART6->STATR;  // 先读SR
        tmp = UART6->DATAR;  // 再读DR清除IDLE
        (void)tmp;
        
        DMA_Cmd(DMA2_Channel7, DISABLE);

        // 计算收到的数据长度
        uint16_t len = BUFFER_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7);

        if (len > 0 && len <= BUFFER_SIZE)
        {
            UART_RxPacket_t packet;
            memcpy(packet.data, uart6_instance.uart_dma_rx_buffer, len);
            packet.length = len;

            // 把接收到的一包数据放入队列
            xQueueSendFromISR(uart6_rx_packet_queue, &packet, &xHigherPriorityTaskWoken);
        }

        // 重启DMA
        DMA_SetCurrDataCounter(DMA2_Channel7, BUFFER_SIZE);
        DMA_Cmd(DMA2_Channel7, ENABLE);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

void DMA2_Channel6_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (DMA_GetITStatus(DMA2_IT_TC6))
    {
        DMA_ClearITPendingBit(DMA2_IT_TC6);

        // 停止DMA
        DMA_Cmd(DMA2_Channel6, DISABLE);

        // 给发送完成信号
        xSemaphoreGiveFromISR(uart6_tx_done_semaphore, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}
