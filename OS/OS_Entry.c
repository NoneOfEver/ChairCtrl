/**
 * @file OS_Entry.c
 * @author .noe
 * @brief os entry file
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "OS_Entry.h"
#include "OS_objects.h"
#include "CAN.h"
#include "Task_CoMCUComm.h"
#include "UART.h"
#include "Task_LegCtrl.h"
#include "Task_BackCtrl.h"
#include "Task_IMUComm.h"

/**************************
       Task Settings
***************************/
#define CAN1_SEND_TASK_PRIO                      4
#define CAN1_SEND_TASK_STK_SIZE                  256

#define CAN1_RECV_TASK_PRIO                      5
#define CAN1_RECV_TASK_STK_SIZE                  256

#define TEST_CAN1_TX_TASK_PRIO                   4
#define TEST_CAN1_TX_TASK_STK_SIZE               256

#define CAN2_SEND_TASK_PRIO                      4
#define CAN2_SEND_TASK_STK_SIZE                  256

#define CAN2_RECV_TASK_PRIO                      5
#define CAN2_RECV_TASK_STK_SIZE                  256

#define TEST_CAN2_TX_TASK_PRIO                   4
#define TEST_CAN2_TX_TASK_STK_SIZE               256

#define UART1_RECV_TASK_PRIO                     4
#define UART1_RECV_TASK_STK_SIZE                 256

#define UART1_SEND_TASK_PRIO                     4
#define UART1_SEND_TASK_STK_SIZE                 256

#define UART1_APP_SEND_TASK_PRIO                 4
#define UART1_APP_SEND_TASK_STK_SIZE             256

#define UART4_RECV_TASK_PRIO                     4
#define UART4_RECV_TASK_STK_SIZE                 256

#define UART4_SEND_TASK_PRIO                     4
#define UART4_SEND_TASK_STK_SIZE                 256

#define UART4_APP_SEND_TASK_PRIO                 4
#define UART4_APP_SEND_TASK_STK_SIZE             256

void OS_Entry()
{
       NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();
       OSObjects_Init();
	USART_Printf_Init(115200);
       CAN1_Mode_Init();
       CAN2_Mode_Init();
       UART1_Init();
       UART2_Init();
       UART4_Init();
       
       /* create tasks */
       xTaskCreate((TaskFunction_t )CAN1SendTask,
                     (const char*    )"CAN1_Send_Task",
                     (uint16_t       )CAN1_SEND_TASK_STK_SIZE,
                     (void*          )NULL,
                     (UBaseType_t    )CAN1_SEND_TASK_PRIO,
                     (TaskHandle_t*  )&CAN1_Send_Task_Handler);
       xTaskCreate((TaskFunction_t )CAN1RecvTask,
                     (const char*    )"CAN1_Recv_Task",
                     (uint16_t       )CAN1_RECV_TASK_STK_SIZE,
                     (void*          )NULL,
                     (UBaseType_t    )CAN1_RECV_TASK_PRIO,
                     (TaskHandle_t*  )&CAN1_Recv_Task_Handler);
       xTaskCreate((TaskFunction_t )TEST_CAN1_Tx_Task,
                     (const char*    )"TEST_CAN1_Tx_Task",
                     (uint16_t       )TEST_CAN1_TX_TASK_STK_SIZE,
                     (void*          )NULL,
                     (UBaseType_t    )TEST_CAN1_TX_TASK_PRIO,
                     (TaskHandle_t*  )&TEST_CAN1_Tx_Task_Handler);

       xTaskCreate((TaskFunction_t )CAN2SendTask,
                     (const char*    )"CAN2_Send_Task",
                     (uint16_t       )CAN2_SEND_TASK_STK_SIZE,
                     (void*          )NULL,
                     (UBaseType_t    )CAN2_SEND_TASK_PRIO,
                     (TaskHandle_t*  )&CAN2_Send_Task_Handler);
       xTaskCreate((TaskFunction_t )CAN2RecvTask,
                     (const char*    )"CAN2_Recv_Task",
                     (uint16_t       )CAN2_RECV_TASK_STK_SIZE,
                     (void*          )NULL,
                     (UBaseType_t    )CAN2_RECV_TASK_PRIO,
                     (TaskHandle_t*  )&CAN2_Recv_Task_Handler);
       xTaskCreate((TaskFunction_t )TEST_CAN2_Tx_Task,
                     (const char*    )"TEST_CAN2_Tx_Task",
                     (uint16_t       )TEST_CAN2_TX_TASK_STK_SIZE,
                     (void*          )NULL,
                     (UBaseType_t    )TEST_CAN2_TX_TASK_PRIO,
                     (TaskHandle_t*  )&TEST_CAN2_Tx_Task_Handler);

       // xTaskCreate((TaskFunction_t )UART1_Receive_Task,
       //               (const char*    )"UART1_Receive_Task",
       //               (uint16_t       )UART1_RECV_TASK_STK_SIZE,
       //               (void*          )NULL,
       //               (UBaseType_t    )UART1_RECV_TASK_PRIO,
       //               (TaskHandle_t*  )&UART1_Recv_Task_Handler);
       // xTaskCreate((TaskFunction_t )UART1_Send_Task,
       //               (const char*    )"UART1_Send_Task",
       //               (uint16_t       )UART1_SEND_TASK_STK_SIZE,
       //               (void*          )NULL,
       //               (UBaseType_t    )UART1_SEND_TASK_PRIO,
       //               (TaskHandle_t*  )&UART1_Send_Task_Handler);
       // xTaskCreate((TaskFunction_t )UART1_App_Send_Task,
       //               (const char*    )"UART1_App_Send_Task",
       //               (uint16_t       )UART1_APP_SEND_TASK_STK_SIZE,
       //               (void*          )NULL,
       //               (UBaseType_t    )UART1_APP_SEND_TASK_PRIO,
       //               (TaskHandle_t*  )&UART1_App_Send_Task_Handler);

       // xTaskCreate((TaskFunction_t )UART4_Receive_Task,
       //               (const char*    )"UART4_Receive_Task",
       //               (uint16_t       )UART4_RECV_TASK_STK_SIZE,
       //               (void*          )NULL,
       //               (UBaseType_t    )UART4_RECV_TASK_PRIO,
       //               (TaskHandle_t*  )&UART4_Recv_Task_Handler);
       // xTaskCreate((TaskFunction_t )UART4_Send_Task,
       //               (const char*    )"UART4_Send_Task",
       //               (uint16_t       )UART4_SEND_TASK_STK_SIZE,
       //               (void*          )NULL,
       //               (UBaseType_t    )UART4_SEND_TASK_PRIO,
       //               (TaskHandle_t*  )&UART4_Send_Task_Handler);
       // xTaskCreate((TaskFunction_t )UART4_App_Send_Task,
       //               (const char*    )"UART4_App_Send_Task",
       //               (uint16_t       )UART4_APP_SEND_TASK_STK_SIZE,
       //               (void*          )NULL,
       //               (UBaseType_t    )UART4_APP_SEND_TASK_PRIO,
       //               (TaskHandle_t*  )&UART4_App_Send_Task_Handler);

       vTaskStartScheduler();
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    printf("Stack overflow in task: %s\n", pcTaskName);
    taskDISABLE_INTERRUPTS();
    while (1);
}

