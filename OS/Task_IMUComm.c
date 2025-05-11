/**
 * @file Task_IMUComm.c
 * @author .noe
 * @brief   cooperate MCU communication
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Task_IMUComm.h"
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
void vIMUProcess(uint8_t* data,uint16_t length)
{
    printf("co MCU task recv : %d , %d\r\n",data[0],data[1]);
}

void UART4_Receive_Task(void *argument)
{
    for(;;)
    {
        if (xQueueReceive(uart4_rx_packet_queue, &uart4_instance.rx_packet, portMAX_DELAY) == pdPASS)
        {
            // 拿到一包数据，处理
            vIMUProcess(uart4_instance.rx_packet.data,  uart4_instance.rx_packet.length);
        }
    }
}

void UART4_Send_Task(void *argument)
{
    for (;;)
    {
        // 等待发送请求
        if (xQueueReceive(uart4_tx_packet_queue, &uart4_instance.tx_packet, portMAX_DELAY) == pdPASS)
        {
            // 等待上一次发送完成
            if (xSemaphoreTake(uart4_tx_done_semaphore, portMAX_DELAY) == pdPASS)
            {
                DMA_Cmd(DMA2_Channel5, DISABLE);  // 保险起见先关闭

                GPIO_SetBits(GPIOC, GPIO_Pin_12); 

                // 配置DMA发送
                DMA2_Channel5->MADDR = (uint32_t)uart4_instance.tx_packet.data;
                DMA2_Channel5->CNTR = uart4_instance.tx_packet.length;
                DMA_Cmd(DMA2_Channel5, ENABLE);
            }
        }
    }
}

void UART4_App_Send_Task(void *argument)
{
    for (;;)
    {
        // 这里模拟准备一条数据，实际你可以换成消息通知、外部事件等
        UART_TxPacket_t packet;
        static const char hello[] = "hello\r\n";  // 字符串常量
        memcpy(packet.data, hello, sizeof(hello));  // 拷贝到data数组
        packet.length = sizeof(hello);

        // 放到发送队列中，等待UART4_Send_Task统一发送
        if (xQueueSend(uart4_tx_packet_queue, &packet, portMAX_DELAY) != pdPASS)
        {
            printf("UART4 App Send Failed!\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(500));  // 每500ms发一次
    }
}

 