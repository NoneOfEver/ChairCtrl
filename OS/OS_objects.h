#ifndef OS_OBJECTS_H
#define OS_OBJECTS_H
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"


/*****************************************
                Queue
******************************************/
extern QueueHandle_t uart1_rx_packet_queue;
extern QueueHandle_t uart2_rx_packet_queue;
extern QueueHandle_t uart3_rx_packet_queue;
extern QueueHandle_t uart4_rx_packet_queue;
extern QueueHandle_t uart6_rx_packet_queue;

extern QueueHandle_t uart1_tx_packet_queue;
extern QueueHandle_t uart2_tx_packet_queue;
extern QueueHandle_t uart3_tx_packet_queue;
extern QueueHandle_t uart4_tx_packet_queue;
extern QueueHandle_t uart6_tx_packet_queue;

extern QueueHandle_t CAN1_RxQueue;
extern QueueHandle_t CAN1_TxQueue;
extern QueueHandle_t CAN2_TxQueue;
extern QueueHandle_t CAN2_RxQueue;

extern xQueueHandle MotorCtrlQueue;
/*****************************************
                Semaphore
******************************************/
extern SemaphoreHandle_t uart1_tx_done_semaphore;
extern SemaphoreHandle_t uart2_tx_done_semaphore;
extern SemaphoreHandle_t uart3_tx_done_semaphore;
extern SemaphoreHandle_t uart4_tx_done_semaphore;
extern SemaphoreHandle_t uart6_tx_done_semaphore;

/**************************
       Task Handles
***************************/
extern TaskHandle_t CAN1_Send_Task_Handler;
extern TaskHandle_t CAN1_Recv_Task_Handler;
extern TaskHandle_t Motor_CAN1_Send_Task_Handler;
extern TaskHandle_t CAN2_Send_Task_Handler;
extern TaskHandle_t CAN2_Recv_Task_Handler;
extern TaskHandle_t TEST_CAN2_Tx_Task_Handler;
extern TaskHandle_t UART1_Recv_Task_Handler;
extern TaskHandle_t UART1_Send_Task_Handler;
extern TaskHandle_t UART1_App_Send_Task_Handler;
extern TaskHandle_t UART4_Recv_Task_Handler;
extern TaskHandle_t UART4_Send_Task_Handler;
extern TaskHandle_t UART4_App_Send_Task_Handler;

void OSObjects_Init(void);
#endif
