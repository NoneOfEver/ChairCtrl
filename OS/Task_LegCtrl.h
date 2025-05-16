#ifndef TASK_LEGCTRL_H
#define TASK_LEGCTRL_H

#ifdef __cplusplus
extern "C"{
#endif
#include "FreeRTOS.h"
#include "task.h"
#include "OS_objects.h"

typedef struct
{
    uint8_t *motorCmds[4];   // ÿ�����һ������ָ��
    uint16_t cmdLens[4];     // ÿ����������ʵ�ʳ���
} MotorCtrlCommand_t;

/**
 * @brief can recive task
 * 
 * @param pvParameters 
 */
void CAN1RecvTask(void *pvParameters);

/**
 * @brief can send task
 * 
 * @param pvParameters 
 */
void CAN1SendTask(void *pvParameters);

void Example_SendMotorCommands();

void MotorCAN1SendTask(void *pvParameters);
BaseType_t SendMotorCommandToQueue(const MotorCtrlCommand_t *cmd, TickType_t ticksToWait);
#ifdef __cplusplus
}
#endif
#endif/*TASK_LEGCTRL_H*/
