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

BaseType_t SendMotorCommandToQueue(const MotorCtrlCommand_t *cmd, TickType_t ticksToWait)
{
    if (cmd == NULL)
        return pdFAIL;

    return xQueueSend(MotorCtrlQueue, cmd, ticksToWait);
}

void Example_SendMotorCommands()
{
    static uint8_t motor0Cmd[] = {0xFD, 0x00, 0x01, 0xDC, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x02, 0x03};  // 11字节
    static uint8_t motor1Cmd[] = {0xFD, 0x00, 0x01, 0xDC, 0x10, 0x00, 0x00};                           // 7字节
    static uint8_t motor2Cmd[] = {0xFD, 0x00, 0x01, 0xDC, 0x20};                                        // 5字节
    static uint8_t motor3Cmd[] = {0xFD, 0x00, 0x01, 0xDC, 0x30, 0x40, 0x50, 0x60, 0x70};                // 9字节

    MotorCtrlCommand_t cmd = {
        .motorCmds = {motor0Cmd, motor1Cmd, motor2Cmd, motor3Cmd},
        .cmdLens = {sizeof(motor0Cmd), sizeof(motor1Cmd), sizeof(motor2Cmd), sizeof(motor3Cmd)}
    };

    SendMotorCommandToQueue(&cmd, 10);
}

void MotorCAN1SendTask(void *pvParameters)
{
    MotorCtrlCommand_t motorCmd;

    for (;;)
    {
        if (xQueueReceive(MotorCtrlQueue, &motorCmd, portMAX_DELAY) == pdPASS)
        {
            for (uint8_t motorIndex = 0; motorIndex < 4; motorIndex++)
            {
                uint32_t baseID = (motorIndex + 1) << 8;  // 0x0100, 0x0200, 0x0300, 0x0400
                uint8_t *data = motorCmd.motorCmds[motorIndex];
                uint16_t length = motorCmd.cmdLens[motorIndex];

                if (data == NULL || length == 0) continue;

                uint16_t offset = 0;
                uint8_t frameIndex = 0;

                while (offset < length)
                {
                    CanTxMsg txMsg = {0};
                    txMsg.ExtId = baseID + frameIndex;
                    txMsg.IDE = CAN_Id_Extended;
                    txMsg.RTR = CAN_RTR_Data;

                    uint8_t bytesToSend = (length - offset >= 8) ? 8 : (length - offset);
                    txMsg.DLC = bytesToSend;

                    memcpy(txMsg.Data, data + offset, bytesToSend);

                    // 放进发送队列
                    if (CAN1_SendMessage(&txMsg, 10) != pdPASS)
                    {
                        // 可选：记录发送失败
                    }

                    offset += bytesToSend;
                    frameIndex++;
                }
            }
        }
    }
}

