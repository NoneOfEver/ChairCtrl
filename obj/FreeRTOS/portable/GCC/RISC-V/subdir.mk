################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/RISC-V/port.c 

C_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/port.d 

S_UPPER_SRCS += \
../FreeRTOS/portable/GCC/RISC-V/portASM.S 

S_UPPER_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/portASM.d 

OBJS += \
./FreeRTOS/portable/GCC/RISC-V/port.o \
./FreeRTOS/portable/GCC/RISC-V/portASM.o 



# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Debug" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Core" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/User" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Peripheral/inc" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/include" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/Common" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/MemMang" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/BSP" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Comm" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Algorithm" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Adjustor" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Utils" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/OS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.S
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -x assembler-with-cpp -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/Startup" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/include" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/Common" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Desktop/Proj_SmartChair/Center/FreeRTOS/portable/MemMang" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
