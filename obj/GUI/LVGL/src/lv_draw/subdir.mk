################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/lvgl/src/lv_draw/lv_draw_arc.c \
../GUI/lvgl/src/lv_draw/lv_draw_blend.c \
../GUI/lvgl/src/lv_draw/lv_draw_img.c \
../GUI/lvgl/src/lv_draw/lv_draw_label.c \
../GUI/lvgl/src/lv_draw/lv_draw_line.c \
../GUI/lvgl/src/lv_draw/lv_draw_mask.c \
../GUI/lvgl/src/lv_draw/lv_draw_rect.c \
../GUI/lvgl/src/lv_draw/lv_draw_triangle.c \
../GUI/lvgl/src/lv_draw/lv_img_buf.c \
../GUI/lvgl/src/lv_draw/lv_img_cache.c \
../GUI/lvgl/src/lv_draw/lv_img_decoder.c 

C_DEPS += \
./GUI/lvgl/src/lv_draw/lv_draw_arc.d \
./GUI/lvgl/src/lv_draw/lv_draw_blend.d \
./GUI/lvgl/src/lv_draw/lv_draw_img.d \
./GUI/lvgl/src/lv_draw/lv_draw_label.d \
./GUI/lvgl/src/lv_draw/lv_draw_line.d \
./GUI/lvgl/src/lv_draw/lv_draw_mask.d \
./GUI/lvgl/src/lv_draw/lv_draw_rect.d \
./GUI/lvgl/src/lv_draw/lv_draw_triangle.d \
./GUI/lvgl/src/lv_draw/lv_img_buf.d \
./GUI/lvgl/src/lv_draw/lv_img_cache.d \
./GUI/lvgl/src/lv_draw/lv_img_decoder.d 

OBJS += \
./GUI/lvgl/src/lv_draw/lv_draw_arc.o \
./GUI/lvgl/src/lv_draw/lv_draw_blend.o \
./GUI/lvgl/src/lv_draw/lv_draw_img.o \
./GUI/lvgl/src/lv_draw/lv_draw_label.o \
./GUI/lvgl/src/lv_draw/lv_draw_line.o \
./GUI/lvgl/src/lv_draw/lv_draw_mask.o \
./GUI/lvgl/src/lv_draw/lv_draw_rect.o \
./GUI/lvgl/src/lv_draw/lv_draw_triangle.o \
./GUI/lvgl/src/lv_draw/lv_img_buf.o \
./GUI/lvgl/src/lv_draw/lv_img_cache.o \
./GUI/lvgl/src/lv_draw/lv_img_decoder.o 



# Each subdirectory must supply rules for building sources it contributes
GUI/lvgl/src/lv_draw/%.o: ../GUI/lvgl/src/lv_draw/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/User" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Peripheral/inc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/include" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/Common" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/MemMang" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/examples/porting" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app/src/lv_demo_widgets" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_draw" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_font" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_gpu" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_hal" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_misc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_themes" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_widgets" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
