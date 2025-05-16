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
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Debug" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Core" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/User" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Peripheral/inc" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/include" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/Common" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/MemMang" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/BSP" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Comm" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Algorithm" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Adjustor" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Utils" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/OS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.S
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -x assembler-with-cpp -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Startup" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/include" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/Common" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/MemMang" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
