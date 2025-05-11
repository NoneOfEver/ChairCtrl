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
            // 处理接收到的CAN数据
            // 比如：
            //printf("Received CAN ID: %X, Data: %X %X ...\n", rxMsg.StdId, rxMsg.Data[0], rxMsg.Data[1]);
        }
    }
}

void CAN1SendTask(void *pvParameters)
{
    CanTxMsg txMsg;

    for(;;)
    {
        // 先取出要发送的数据,使得"发送任务统一出栈"
        if (xQueueReceive(CAN1_TxQueue, &txMsg, portMAX_DELAY) == pdPASS)
        {
            uint8_t data[8] = {0x01, 0xF6, 0x01, 0x05, 0xDC, 0x01, 0x00, 0x6B};
            memcpy(txMsg.Data, data, 8);
            while (CAN_Transmit(CAN1, &txMsg) == CAN_NO_MB)
            {
                // 只有在邮箱满了才等待中断通知
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
    
    CanTxMsg txMsg;
    // uint8_t command[8] = {0x01,0xF6,0x01,0x05,0xDC,0x01,0x00,0x6B};
 
    //uint8_t command[8] = {0x01,0xF3,0xAB,0x01,0x00,0x6B};
    txMsg.ExtId = 0x01<<8;
    txMsg.IDE = CAN_Id_Extended;
    txMsg.RTR = CAN_RTR_Data;
    txMsg.DLC = 8;
    // memcpy(txMsg.Data, (command), 8);

    CAN1_SendMessage(&txMsg, 10);  // 放进去，10个tick超时

}

void TEST_CAN1_Tx_Task(void *pvParameters)
{
    for(;;)
    {
        TEST_CAN1_Tx();
        vTaskDelay(1000);
    }
}