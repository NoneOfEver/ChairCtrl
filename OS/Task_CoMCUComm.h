/**
 * @file Task_CoMCUComm.h
 * @author .noe
 * @brief  cooperate MCU communication
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef TASK_COMCUCOMM_H
#define TASK_COMCUCOMM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief UART2 receive task,used in coMCU communication 
* 
* @param argument 
*/
void UART1_Receive_Task(void *argument);

/**
* @brief UART2 send task,used in coMCU communication 
* 
* @param argument 
*/
void UART1_Send_Task(void *argument);

void UART1_App_Send_Task(void *argument);

#ifdef __cplusplus
}
#endif
#endif /*TASK_COMCUCOMM_H*/