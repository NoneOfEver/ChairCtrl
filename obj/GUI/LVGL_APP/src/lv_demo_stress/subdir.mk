################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/lvgl_app/src/lv_demo_stress/lv_demo_stress.c 

C_DEPS += \
./GUI/lvgl_app/src/lv_demo_stress/lv_demo_stress.d 

OBJS += \
./GUI/lvgl_app/src/lv_demo_stress/lv_demo_stress.o 



# Each subdirectory must supply rules for building sources it contributes
GUI/lvgl_app/src/lv_demo_stress/%.o: ../GUI/lvgl_app/src/lv_demo_stress/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/User" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Peripheral/inc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/include" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/Common" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/MemMang" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/examples/porting" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app/src/lv_demo_widgets" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_draw" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_font" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_gpu" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_hal" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_misc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_themes" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_widgets" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
