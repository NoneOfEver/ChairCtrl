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

void SendMotorCommands(
    uint32_t motor0_len,uint8_t motor0_dir,
    uint32_t motor1_len,uint8_t motor1_dir,
    uint32_t motor2_len,uint8_t motor2_dir,
    uint32_t motor3_len,uint8_t motor3_dir)
{
    static uint8_t motor0Cmd[12] = {0};
    static uint8_t motor1Cmd[12] = {0};
    static uint8_t motor2Cmd[12] = {0};
    static uint8_t motor3Cmd[12] = {0};

    motor0Cmd[0]  = 0xFD;
    motor0Cmd[1]  = motor0_dir;
    motor0Cmd[2]  = 0x05;
    motor0Cmd[3]  = 0xDC;
    motor0Cmd[4]  = 0x00;
    motor0Cmd[5]  = motor0_len >> 24;
    motor0Cmd[6]  = motor0_len >> 16;
    motor0Cmd[7]  = motor0_len >> 8;
    motor0Cmd[8]  = motor0_len >> 0;
    motor0Cmd[9]  = 0x00;
    motor0Cmd[10] = 0x00;
    motor0Cmd[11] = 0x6B;

    motor1Cmd[0]  = 0xFD;
    motor1Cmd[1]  = motor1_dir;
    motor1Cmd[2]  = 0x05;
    motor1Cmd[3]  = 0xDC;
    motor1Cmd[4]  = 0x00;
    motor1Cmd[5]  = motor1_len >> 24;
    motor1Cmd[6]  = motor1_len >> 16;
    motor1Cmd[7]  = motor1_len >> 8;
    motor1Cmd[8]  = motor1_len >> 0;
    motor1Cmd[9]  = 0x00;
    motor1Cmd[10] = 0x00;
    motor1Cmd[11] = 0x6B;

    motor2Cmd[0]  = 0xFD;
    motor2Cmd[1]  = motor2_dir;
    motor2Cmd[2]  = 0x05;
    motor2Cmd[3]  = 0xDC;
    motor2Cmd[4]  = 0x00;
    motor2Cmd[5]  = motor2_len >> 24;
    motor2Cmd[6]  = motor2_len >> 16;
    motor2Cmd[7]  = motor2_len >> 8;
    motor2Cmd[8]  = motor2_len >> 0;
    motor2Cmd[9]  = 0x00;
    motor2Cmd[10] = 0x00;
    motor2Cmd[11] = 0x6B;

    motor3Cmd[0]  = 0xFD;
    motor3Cmd[1]  = motor3_dir;
    motor3Cmd[2]  = 0x05;
    motor3Cmd[3]  = 0xDC;
    motor3Cmd[4]  = 0x00;
    motor3Cmd[5]  = motor3_len >> 24;
    motor3Cmd[6]  = motor3_len >> 16;
    motor3Cmd[7]  = motor3_len >> 8;
    motor3Cmd[8]  = motor3_len >> 0;
    motor3Cmd[9]  = 0x00;
    motor3Cmd[10] = 0x00;
    motor3Cmd[11] = 0x6B;

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

