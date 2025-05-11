/**
 * @file Task_BackCtrl.c
 * @author .noe
 * @brief chair back control task
 * @version 0.1
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Task_BackCtrl.h"
#include "string.h"

void CAN2RecvTask(void *pvParameters)
{
    CanRxMsg rxMsg;

    for(;;)
    {
        if (xQueueReceive(CAN2_RxQueue, &rxMsg, portMAX_DELAY) == pdPASS)
        {
            // 处理接收到的CAN数据
            // 比如：
            printf("Received CAN ID: %X, Data: %X %X ...\n", rxMsg.StdId, rxMsg.Data[0], rxMsg.Data[1]);
        }
    }
}

void CAN2SendTask(void *pvParameters)
{
    CanTxMsg txMsg;

    for(;;)
    {
        // 先取出要发送的数据,使得"发送任务统一出栈"
        if (xQueueReceive(CAN2_TxQueue, &txMsg, portMAX_DELAY) == pdPASS)
        {

            while (CAN_Transmit(CAN2, &txMsg) == CAN_NO_MB)
            {
                // 只有在邮箱满了才等待中断通知
                ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
            }        
        }
    }
}

BaseType_t CAN2_SendMessage(CanTxMsg *msg, TickType_t ticksToWait)
{
     if (msg == NULL)
        return pdFAIL;

    return xQueueSend(CAN2_TxQueue, msg, ticksToWait);
}

static void TEST_CAN2_Tx()
{
    CanTxMsg txMsg;
    txMsg.StdId = 0x132;
    txMsg.IDE = CAN_Id_Standard;
    txMsg.RTR = CAN_RTR_Data;
    txMsg.DLC = 8;
    memcpy(txMsg.Data, (uint8_t*)("hello\r\n"), 8);

    CAN2_SendMessage(&txMsg, 10);  // 放进去，10个tick超时

}

void TEST_CAN2_Tx_Task(void *pvParameters)
{
    for(;;)
    {
        TEST_CAN2_Tx();
        vTaskDelay(1000);
    }
}