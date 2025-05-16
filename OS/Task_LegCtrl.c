/**
 * @file Task_LegCtrl.c
 * @author .noe
 * @brief chair legs control task
 * @version 0.1
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Task_LegCtrl.h"
#include "string.h"

void CAN1RecvTask(void *pvParameters)
{
    CanRxMsg rxMsg;

    for(;;)
    {
        if (xQueueReceive(CAN1_RxQueue, &rxMsg, portMAX_DELAY) == pdPASS)
        {
            // ������յ���CAN����
            // ���磺
            //printf("Received CAN ID: %X, Data: %X %X ...\n", rxMsg.StdId, rxMsg.Data[0], rxMsg.Data[1]);
        }
    }
}

void CAN1SendTask(void *pvParameters)
{
    CanTxMsg txMsg;

    for(;;)
    {
        // ��ȡ��Ҫ���͵�����,ʹ��"��������ͳһ��ջ"
        if (xQueueReceive(CAN1_TxQueue, &txMsg, portMAX_DELAY) == pdPASS)
        {
            while (CAN_Transmit(CAN1, &txMsg) == CAN_NO_MB)
            {
                ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
            }
        }
    }
}

BaseType_t CAN1_SendMessage(CanTxMsg *msg, TickType_t ticksToWait)
{
     if (msg == NULL)
        return pdFAIL;

    return xQueueSend(CAN1_TxQueue, msg, ticksToWait);
}
static void TEST_CAN1_Tx()
{
    uint8_t data[13] = {0xFD, 0x00, 0x03, 0xA0, 0x00, 0x00, 0x00, 0xF0, 0xFD, 0x00, 0x00,0x00, 0x6B};

    // ��һ֡
    CanTxMsg txMsg1 = {0};
    txMsg1.ExtId = 0x0100;  // ��һ֡ID
    txMsg1.IDE = CAN_Id_Extended;
    txMsg1.RTR = CAN_RTR_Data;
    txMsg1.DLC = 8;
    memcpy(txMsg1.Data, data, 8);  // ����ǰ8�ֽ�
    CAN1_SendMessage(&txMsg1, 10);

    // �ڶ�֡
    CanTxMsg txMsg2 = {0};
    txMsg2.ExtId = 0x0101;  // �ڶ�֡ID
    txMsg2.IDE = CAN_Id_Extended;
    txMsg2.RTR = CAN_RTR_Data;
    txMsg2.DLC = 5;  // ֻʣ��4�ֽ�
    memcpy(txMsg2.Data, data + 8, 5);  // ������4�ֽ�
    CAN1_SendMessage(&txMsg2, 10);
}

void TEST_CAN1_Tx_Task(void *pvParameters)
{
    for(;;)
    {
        TEST_CAN1_Tx();
        vTaskDelay(10000);
    }
}