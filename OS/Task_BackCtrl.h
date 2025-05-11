#ifndef TASK_BACKCTRL_H
#define TASK_BACKCTRL_H

#ifdef __cplusplus
extern "C"{
#endif
#include "FreeRTOS.h"
#include "task.h"
#include "OS_objects.h"

/**
 * @brief can recive task
 * 
 * @param pvParameters 
 */
void CAN2RecvTask(void *pvParameters);

/**
 * @brief can send task
 * 
 * @param pvParameters 
 */
void CAN2SendTask(void *pvParameters);

void TEST_CAN2_Tx_Task(void *pvParameters);

#ifdef __cplusplus
}
#endif
#endif/*TASK_BACKCTRL_H*/
