/**
 * @file Task_CoMCUComm.c
 * @author .noe
 * @brief   cooperate MCU communication
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Task_CoMCUComm.h"
#include "FreeRTOS.h"
#include "OS_objects.h"
#include "UART.h"
#include "string.h"

/**
 * @brief process in the receive task
 * 
 * @param data 
 * @param length 
 */
void vCoMCURxProcess(uint8_t* data,uint16_t length)
{
    printf("co MCU task recv : %d , %d\r\n",data[0],data[1]);
}

void UART1_Receive_Task(void *argument)
{
    for(;;)
    {
        if (xQueueReceive(uart1_rx_packet_queue, &uart1_instance.rx_packet, portMAX_DELAY) == pdPASS)
        {
            // 拿到一包数据，处理
            vCoMCURxProcess(uart1_instance.rx_packet.data,  uart1_instance.rx_packet.length);
        }
    }
}

void UART1_Send_Task(void *argument)
{
    for (;;)
    {
        // 等待发送请求
        if (xQueueReceive(uart1_tx_packet_queue, &uart1_instance.tx_packet, portMAX_DELAY) == pdPASS)
        {
            // 等待上一次发送完成
            if (xSemaphoreTake(uart1_tx_done_semaphore, portMAX_DELAY) == pdPASS)
            {
                DMA_Cmd(DMA1_Channel4, DISABLE);  // 保险起见先关闭
                // 配置DMA发送
                DMA1_Channel4->MADDR = (uint32_t)uart1_instance.tx_packet.data;
                DMA1_Channel4->CNTR = uart1_instance.tx_packet.length;
                DMA_Cmd(DMA1_Channel4, ENABLE);
            }
        }
    }
}

void UART1_App_Send_Task(void *argument)
{
    for (;;)
    {
        // 这里模拟准备一条数据，实际你可以换成消息通知、外部事件等
        UART_TxPacket_t packet;
        static const char hello[] = "hello\r\n";  // 字符串常量
        memcpy(packet.data, hello, sizeof(hello));  // 拷贝到data数组
        packet.length = sizeof(hello);

        // 放到发送队列中，等待UART2_Send_Task统一发送
        if (xQueueSend(uart1_tx_packet_queue, &packet, portMAX_DELAY) != pdPASS)
        {
            printf("UART1 App Send Failed!\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(500));  // 每500ms发一次
    }
}

 