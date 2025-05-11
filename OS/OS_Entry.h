/**
 * @file OS_Entry.h
 * @author .noe
 * @brief  os entry file
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef OS_ENTRY_H
#define OS_ENTRY_H
#ifdef __cplusplus
extern "C"{
#endif
#include "debug.h"
#include "FreeRTOS.h"
#include "task.h"

void OS_Entry();

#ifdef __cplusplus
}
#endif
#endif/*OS_ENTRY_H*/
