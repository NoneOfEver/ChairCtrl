#ifndef TASK_LEGCTRL_H
#define TASK_LEGCTRL_H

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
void CAN1RecvTask(void *pvParameters);

/**
 * @brief can send task
 * 
 * @param pvParameters 
 */
void CAN1SendTask(void *pvParameters);

void TEST_CAN1_Tx_Task(void *pvParameters);

#ifdef __cplusplus
}
#endif
#endif/*TASK_LEGCTRL_H*/
