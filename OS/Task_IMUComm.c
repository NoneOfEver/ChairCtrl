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
            // �õ�һ�����ݣ�����
            vIMUProcess(uart4_instance.rx_packet.data,  uart4_instance.rx_packet.length);
        }
    }
}

void UART4_Send_Task(void *argument)
{
    for (;;)
    {
        // �ȴ���������
        if (xQueueReceive(uart4_tx_packet_queue, &uart4_instance.tx_packet, portMAX_DELAY) == pdPASS)
        {
            // �ȴ���һ�η������
            if (xSemaphoreTake(uart4_tx_done_semaphore, portMAX_DELAY) == pdPASS)
            {
                DMA_Cmd(DMA2_Channel5, DISABLE);  // ��������ȹر�

                GPIO_SetBits(GPIOC, GPIO_Pin_12); 

                // ����DMA����
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
        // ����ģ��׼��һ�����ݣ�ʵ������Ի�����Ϣ֪ͨ���ⲿ�¼���
        UART_TxPacket_t packet;
        static const char hello[] = "hello\r\n";  // �ַ�������
        memcpy(packet.data, hello, sizeof(hello));  // ������data����
        packet.length = sizeof(hello);

        // �ŵ����Ͷ����У��ȴ�UART4_Send_Taskͳһ����
        if (xQueueSend(uart4_tx_packet_queue, &packet, portMAX_DELAY) != pdPASS)
        {
            printf("UART4 App Send Failed!\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(500));  // ÿ500ms��һ��
    }
}

 