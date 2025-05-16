#include "OS_objects.h"
#include "UART.h"
#include "CAN.h"
#include "Task_LegCtrl.h"
/*****************************************
                Queue
******************************************/
QueueHandle_t uart1_rx_packet_queue;
QueueHandle_t uart2_rx_packet_queue;
QueueHandle_t uart3_rx_packet_queue;
QueueHandle_t uart4_rx_packet_queue;
QueueHandle_t uart6_rx_packet_queue;

QueueHandle_t uart1_tx_packet_queue;
QueueHandle_t uart2_tx_packet_queue;
QueueHandle_t uart3_tx_packet_queue;
QueueHandle_t uart4_tx_packet_queue;
QueueHandle_t uart6_tx_packet_queue;

QueueHandle_t CAN1_RxQueue;
QueueHandle_t CAN1_TxQueue;
QueueHandle_t CAN2_RxQueue;
QueueHandle_t CAN2_TxQueue;

xQueueHandle MotorCtrlQueue;
/*****************************************
                Semaphore
******************************************/
SemaphoreHandle_t uart1_tx_done_semaphore;
SemaphoreHandle_t uart2_tx_done_semaphore;
SemaphoreHandle_t uart3_tx_done_semaphore;
SemaphoreHandle_t uart4_tx_done_semaphore;
SemaphoreHandle_t uart6_tx_done_semaphore;

/**************************
       Task Handles
***************************/
TaskHandle_t CAN1_Send_Task_Handler;
TaskHandle_t CAN1_Recv_Task_Handler;
TaskHandle_t Motor_CAN1_Send_Task_Handler;
TaskHandle_t CAN2_Send_Task_Handler;
TaskHandle_t CAN2_Recv_Task_Handler;
TaskHandle_t TEST_CAN2_Tx_Task_Handler;
TaskHandle_t UART1_Recv_Task_Handler;
TaskHandle_t UART1_Send_Task_Handler;
TaskHandle_t UART1_App_Send_Task_Handler;
TaskHandle_t UART4_Recv_Task_Handler;
TaskHandle_t UART4_Send_Task_Handler;
TaskHandle_t UART4_App_Send_Task_Handler;

void OSObjects_Init(void)
{
    uart1_rx_packet_queue = xQueueCreate(10, sizeof(UART_RxPacket_t));       
    uart2_rx_packet_queue = xQueueCreate(10, sizeof(UART_RxPacket_t));    
    uart3_rx_packet_queue = xQueueCreate(10, sizeof(UART_RxPacket_t));    
    uart4_rx_packet_queue = xQueueCreate(10, sizeof(UART_RxPacket_t));    
    uart6_rx_packet_queue = xQueueCreate(10, sizeof(UART_RxPacket_t));    

    // 发送请求队列（可以缓冲10个待发送的包）
    uart1_tx_packet_queue = xQueueCreate(10, sizeof(UART_TxPacket_t));
    uart2_tx_packet_queue = xQueueCreate(10, sizeof(UART_TxPacket_t));
    uart3_tx_packet_queue = xQueueCreate(10, sizeof(UART_TxPacket_t));
    uart4_tx_packet_queue = xQueueCreate(10, sizeof(UART_TxPacket_t));
    uart6_tx_packet_queue = xQueueCreate(10, sizeof(UART_TxPacket_t));
    
    // 创建接收队列（深度20，可自己调）
    CAN1_RxQueue = xQueueCreate(20, sizeof(CanRxMsg));
    CAN1_TxQueue = xQueueCreate(20, sizeof(CanTxMsg));
    CAN2_RxQueue = xQueueCreate(20, sizeof(CanRxMsg));
    CAN2_TxQueue = xQueueCreate(20, sizeof(CanTxMsg));

    MotorCtrlQueue = xQueueCreate(10, sizeof(MotorCtrlCommand_t));
    // 发送完成信号量，初始设为"可用"
    uart1_tx_done_semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(uart1_tx_done_semaphore);
    uart2_tx_done_semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(uart2_tx_done_semaphore);
    uart3_tx_done_semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(uart3_tx_done_semaphore);
    uart4_tx_done_semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(uart4_tx_done_semaphore);
    uart6_tx_done_semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(uart6_tx_done_semaphore);


}