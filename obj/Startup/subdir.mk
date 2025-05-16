################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Startup/startup_ch32v30x_D8C.S 

S_UPPER_DEPS += \
./Startup/startup_ch32v30x_D8C.d 

OBJS += \
./Startup/startup_ch32v30x_D8C.o 



# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.S
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -x assembler-with-cpp -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Startup" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/include" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/Common" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"/Users/panpoming/Documents/ChairCtrl/ChairCtrl/FreeRTOS/portable/MemMang" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
