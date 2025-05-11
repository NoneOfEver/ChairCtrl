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
            // �õ�һ�����ݣ�����
            vCoMCURxProcess(uart1_instance.rx_packet.data,  uart1_instance.rx_packet.length);
        }
    }
}

void UART1_Send_Task(void *argument)
{
    for (;;)
    {
        // �ȴ���������
        if (xQueueReceive(uart1_tx_packet_queue, &uart1_instance.tx_packet, portMAX_DELAY) == pdPASS)
        {
            // �ȴ���һ�η������
            if (xSemaphoreTake(uart1_tx_done_semaphore, portMAX_DELAY) == pdPASS)
            {
                DMA_Cmd(DMA1_Channel4, DISABLE);  // ��������ȹر�
                // ����DMA����
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
        // ����ģ��׼��һ�����ݣ�ʵ������Ի�����Ϣ֪ͨ���ⲿ�¼���
        UART_TxPacket_t packet;
        static const char hello[] = "hello\r\n";  // �ַ�������
        memcpy(packet.data, hello, sizeof(hello));  // ������data����
        packet.length = sizeof(hello);

        // �ŵ����Ͷ����У��ȴ�UART2_Send_Taskͳһ����
        if (xQueueSend(uart1_tx_packet_queue, &packet, portMAX_DELAY) != pdPASS)
        {
            printf("UART1 App Send Failed!\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(500));  // ÿ500ms��һ��
    }
}

 