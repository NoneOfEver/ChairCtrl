################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/OS_Entry.c \
../OS/OS_objects.c \
../OS/Task_BackCtrl.c \
../OS/Task_CoMCUComm.c \
../OS/Task_FanCtrl.c \
../OS/Task_IMUComm.c \
../OS/Task_L610Comm.c \
../OS/Task_LegCtrl.c \
../OS/Task_TempCtrl.c 

C_DEPS += \
./OS/OS_Entry.d \
./OS/OS_objects.d \
./OS/Task_BackCtrl.d \
./OS/Task_CoMCUComm.d \
./OS/Task_FanCtrl.d \
./OS/Task_IMUComm.d \
./OS/Task_L610Comm.d \
./OS/Task_LegCtrl.d \
./OS/Task_TempCtrl.d 

OBJS += \
./OS/OS_Entry.o \
./OS/OS_objects.o \
./OS/Task_BackCtrl.o \
./OS/Task_CoMCUComm.o \
./OS/Task_FanCtrl.o \
./OS/Task_IMUComm.o \
./OS/Task_L610Comm.o \
./OS/Task_LegCtrl.o \
./OS/Task_TempCtrl.o 



# Each subdirectory must supply rules for building sources it contributes
OS/%.o: ../OS/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Debug" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Core" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/User" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Peripheral/inc" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/include" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/Common" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/MemMang" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/BSP" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Comm" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Algorithm" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Adjustor" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Utils" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/OS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
