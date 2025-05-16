################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

C_DEPS += \
./Core/core_riscv.d 

OBJS += \
./Core/core_riscv.o 



# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Debug" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Core" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/User" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Peripheral/inc" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/include" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/Common" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/MemMang" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/BSP" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Comm" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Algorithm" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Adjustor" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Utils" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/OS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
