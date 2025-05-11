################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_1.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_10.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_11.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_2.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_3.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_4.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_5.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_6.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_7.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_8.c \
../GUI/lvgl_app/src/lv_ex_style/lv_ex_style_9.c 

C_DEPS += \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_1.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_10.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_11.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_2.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_3.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_4.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_5.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_6.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_7.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_8.d \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_9.d 

OBJS += \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_1.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_10.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_11.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_2.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_3.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_4.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_5.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_6.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_7.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_8.o \
./GUI/lvgl_app/src/lv_ex_style/lv_ex_style_9.o 



# Each subdirectory must supply rules for building sources it contributes
GUI/lvgl_app/src/lv_ex_style/%.o: ../GUI/lvgl_app/src/lv_ex_style/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/User" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Peripheral/inc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/include" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/Common" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/MemMang" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/examples/porting" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app/src/lv_demo_widgets" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_draw" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_font" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_gpu" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_hal" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_misc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_themes" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_widgets" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
