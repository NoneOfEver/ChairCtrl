/**
 * @file CAN.c
 * @author .noe
 * @brief CAN bsp for CH32V307
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "CAN.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "OS_objects.h"

// 中断服务函数
void USB_HP_CAN1_TX_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void USB_LP_CAN1_RX0_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void CAN2_TX_IRQHandler(void) INTERRUPT_ATTRIBUTE;
void CAN2_RX0_IRQHandler(void) INTERRUPT_ATTRIBUTE;
/*********************************************************************
 * @fn      CAN_Mode_Init
 *
 * @brief   Initializes CAN communication test mode.
 *          Bps =Fpclk1/((tpb1+1+tbs2+1+1)*brp)
 *
 * @param   tsjw - CAN synchronisation jump width.
 *          tbs2 - CAN time quantum in bit segment 1.
 *          tbs1 - CAN time quantum in bit segment 2.
 *          brp - Specifies the length of a time quantum.
 *          mode - Test mode.
 *            CAN_Mode_Normal.
 *            CAN_Mode_LoopBack.
 *            CAN_Mode_Silent.
 *            CAN_Mode_Silent_LoopBack.
 *
 * @return  none
 */
void CAN1_Mode_Init(void)
{
	GPIO_InitTypeDef GPIO_InitSturcture={0};
	CAN_InitTypeDef CAN_InitSturcture={0};
	CAN_FilterInitTypeDef CAN_FilterInitSturcture={0};
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE ); 
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_CAN1, ENABLE );	
	
	//GPIO_PinRemapConfig( GPIO_Remap1_CAN1, ENABLE);	
	
	GPIO_InitSturcture.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitSturcture.GPIO_Mode = GPIO_Mode_AF_PP;		
	GPIO_InitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOA, &GPIO_InitSturcture);
	
	GPIO_InitSturcture.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitSturcture.GPIO_Mode = GPIO_Mode_IPU;	
	GPIO_Init( GPIOA, &GPIO_InitSturcture);
	
	CAN_InitSturcture.CAN_TTCM = DISABLE;		
	CAN_InitSturcture.CAN_ABOM = DISABLE;		
	CAN_InitSturcture.CAN_AWUM = DISABLE;		
	CAN_InitSturcture.CAN_NART = DISABLE;		
	CAN_InitSturcture.CAN_RFLM = DISABLE;		
	CAN_InitSturcture.CAN_TXFP = DISABLE;
	CAN_InitSturcture.CAN_Mode = CAN_Mode_Normal;
	CAN_InitSturcture.CAN_SJW = CAN_SJW_1tq;//1		
	CAN_InitSturcture.CAN_BS1 = CAN_BS1_6tq;		
	CAN_InitSturcture.CAN_BS2 = CAN_BS2_5tq;		
	CAN_InitSturcture.CAN_Prescaler = 48;		
	CAN_Init(CAN1, &CAN_InitSturcture);
	
	CAN_FilterInitSturcture.CAN_FilterNumber = 0;		
	CAN_FilterInitSturcture.CAN_FilterMode = CAN_FilterMode_IdMask;	 
	CAN_FilterInitSturcture.CAN_FilterScale = CAN_FilterScale_32bit; 
	CAN_FilterInitSturcture.CAN_FilterIdHigh = 0x0000;	 
	CAN_FilterInitSturcture.CAN_FilterIdLow = 0x0000; 
	CAN_FilterInitSturcture.CAN_FilterMaskIdHigh = 0x0000;  	
	CAN_FilterInitSturcture.CAN_FilterMaskIdLow = 0x0000;
	CAN_FilterInitSturcture.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterInitSturcture.CAN_FilterActivation = ENABLE;
	CAN_FilterInit( &CAN_FilterInitSturcture );

 	NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;  // FIFO0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; // 注意优先级要大于FreeRTOS临界区设定
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	NVIC_InitStructure.NVIC_IRQChannel = USB_HP_CAN1_TX_IRQn;
	NVIC_Init(&NVIC_InitStructure);
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE); // FIFO0消息挂号中断使能
	CAN_ITConfig(CAN1, CAN_IT_TME, ENABLE);
}

void CAN2_Mode_Init(void)
{
	GPIO_InitTypeDef GPIO_InitSturcture={0};
	CAN_InitTypeDef CAN_InitSturcture={0};
	CAN_FilterInitTypeDef CAN_FilterInitSturcture={0};
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE ); 
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_CAN1 | RCC_APB1Periph_CAN2, ENABLE );	
		
	GPIO_InitSturcture.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitSturcture.GPIO_Mode = GPIO_Mode_AF_PP;		
	GPIO_InitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOB, &GPIO_InitSturcture);
	
	GPIO_InitSturcture.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitSturcture.GPIO_Mode = GPIO_Mode_IPU;	
	GPIO_Init( GPIOB, &GPIO_InitSturcture);
	
	CAN_InitSturcture.CAN_TTCM = DISABLE;		
	CAN_InitSturcture.CAN_ABOM = DISABLE;		
	CAN_InitSturcture.CAN_AWUM = DISABLE;		
	CAN_InitSturcture.CAN_NART = DISABLE;		
	CAN_InitSturcture.CAN_RFLM = DISABLE;		
	CAN_InitSturcture.CAN_TXFP = DISABLE;
	CAN_InitSturcture.CAN_Mode = CAN_Mode_Normal;
	CAN_InitSturcture.CAN_SJW = CAN_SJW_1tq;//1		
	CAN_InitSturcture.CAN_BS1 = CAN_BS1_6tq;		
	CAN_InitSturcture.CAN_BS2 = CAN_BS2_5tq;		
	CAN_InitSturcture.CAN_Prescaler = 48;//16		
	CAN_Init(CAN2, &CAN_InitSturcture);
	
	CAN_FilterInitSturcture.CAN_FilterNumber = 14;		
	CAN_FilterInitSturcture.CAN_FilterMode = CAN_FilterMode_IdMask;	 
	CAN_FilterInitSturcture.CAN_FilterScale = CAN_FilterScale_32bit; 
	CAN_FilterInitSturcture.CAN_FilterIdHigh = 0x0000;	 
	CAN_FilterInitSturcture.CAN_FilterIdLow = 0x0000; 
	CAN_FilterInitSturcture.CAN_FilterMaskIdHigh = 0x0000;  	
	CAN_FilterInitSturcture.CAN_FilterMaskIdLow = 0x0000;
	CAN_FilterInitSturcture.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterInitSturcture.CAN_FilterActivation = ENABLE;
	CAN_FilterInit( &CAN_FilterInitSturcture );

 	NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = CAN2_RX0_IRQn;  // FIFO0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; // 注意优先级要大于FreeRTOS临界区设定
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	NVIC_InitStructure.NVIC_IRQChannel = CAN2_TX_IRQn;
	NVIC_Init(&NVIC_InitStructure);
	CAN_ITConfig(CAN2, CAN_IT_FMP0, ENABLE); // FIFO0消息挂号中断使能
	CAN_ITConfig(CAN2, CAN_IT_TME, ENABLE);
}

void USB_HP_CAN1_TX_IRQHandler(void)
{
    if (CAN_GetITStatus(CAN1, CAN_IT_TME) != RESET)
    {
	    // 清除中断标志
        CAN_ClearITPendingBit(CAN1, CAN_IT_TME);

        // 发送邮箱空了，可以继续发下一个数据
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        
        // 通知发送任务邮箱空闲
        vTaskNotifyGiveFromISR(CAN1_Send_Task_Handler, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

    }
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
    while (CAN_GetITStatus(CAN1, CAN_IT_FMP0) != RESET)
    {
		// 清除中断标志
        CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);   

        CanRxMsg rx;
        CAN_Receive(CAN1, CAN_FIFO0, &rx);

		// 接收到数据，放入消息队列,
		// ！！！队列可能会满，出现问题严查这里！！！
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xQueueSendFromISR(CAN1_RxQueue, &rx, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

	}
}

void CAN2_TX_IRQHandler(void)
{
    if (CAN_GetITStatus(CAN2, CAN_IT_TME) != RESET)
    {
		// 清除中断标志
        CAN_ClearITPendingBit(CAN2, CAN_IT_TME);

        // 发送邮箱空了，可以继续发下一个数据
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        
        // 通知发送任务邮箱空闲
        vTaskNotifyGiveFromISR(CAN2_Send_Task_Handler, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

    }
}

void CAN2_RX0_IRQHandler(void)
{
    while (CAN_GetITStatus(CAN2, CAN_IT_FMP0) != RESET)
    {
		// 清除中断标志
        CAN_ClearITPendingBit(CAN2, CAN_IT_FMP0);   

        CanRxMsg rx;
        CAN_Receive(CAN2, CAN_FIFO0, &rx);

		// 接收到数据，放入消息队列,
		// ！！！队列可能会满，出现问题严查这里！！！
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xQueueSendFromISR(CAN2_RxQueue, &rx, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

	}
}
