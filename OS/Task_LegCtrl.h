#ifndef TASK_LEGCTRL_H
#define TASK_LEGCTRL_H

#ifdef __cplusplus
extern "C"{
#endif
#include "FreeRTOS.h"
#include "task.h"
#include "OS_objects.h"

#define ONE_CIRCLE 3200
typedef struct
{
    uint8_t *motorCmds[4];   // 每个电机一个命令指针
    uint16_t cmdLens[4];     // 每个电机命令的实际长度
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

void SendMotorCommands(uint32_t motor0_len,uint8_t motor0_dir,
                        uint32_t motor1_len,uint8_t motro1_dir,
                        uint32_t motor2_len,uint8_t motor2_dir,
                        uint32_t motor3_len,uint8_t motor3_dir);

void MotorCAN1SendTask(void *pvParameters);
BaseType_t SendMotorCommandToQueue(const MotorCtrlCommand_t *cmd, TickType_t ticksToWait);
#ifdef __cplusplus
}
#endif
#endif/*TASK_LEGCTRL_H*/
