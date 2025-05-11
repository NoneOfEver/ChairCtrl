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
#ifndef TASK_IMUCOMM_H
#define TASK_IMUCOMM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief UART2 receive task,used in coMCU communication 
* 
* @param argument 
*/
void UART4_Receive_Task(void *argument);

/**
* @brief UART2 send task,used in coMCU communication 
* 
* @param argument 
*/
void UART4_Send_Task(void *argument);

void UART4_App_Send_Task(void *argument);

#ifdef __cplusplus
}
#endif
#endif /*TASK_IMUCOMM_H*/