################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/lvgl/src/lv_misc/lv_anim.c \
../GUI/lvgl/src/lv_misc/lv_area.c \
../GUI/lvgl/src/lv_misc/lv_async.c \
../GUI/lvgl/src/lv_misc/lv_bidi.c \
../GUI/lvgl/src/lv_misc/lv_color.c \
../GUI/lvgl/src/lv_misc/lv_debug.c \
../GUI/lvgl/src/lv_misc/lv_fs.c \
../GUI/lvgl/src/lv_misc/lv_gc.c \
../GUI/lvgl/src/lv_misc/lv_ll.c \
../GUI/lvgl/src/lv_misc/lv_log.c \
../GUI/lvgl/src/lv_misc/lv_math.c \
../GUI/lvgl/src/lv_misc/lv_mem.c \
../GUI/lvgl/src/lv_misc/lv_printf.c \
../GUI/lvgl/src/lv_misc/lv_task.c \
../GUI/lvgl/src/lv_misc/lv_templ.c \
../GUI/lvgl/src/lv_misc/lv_txt.c \
../GUI/lvgl/src/lv_misc/lv_txt_ap.c \
../GUI/lvgl/src/lv_misc/lv_utils.c 

C_DEPS += \
./GUI/lvgl/src/lv_misc/lv_anim.d \
./GUI/lvgl/src/lv_misc/lv_area.d \
./GUI/lvgl/src/lv_misc/lv_async.d \
./GUI/lvgl/src/lv_misc/lv_bidi.d \
./GUI/lvgl/src/lv_misc/lv_color.d \
./GUI/lvgl/src/lv_misc/lv_debug.d \
./GUI/lvgl/src/lv_misc/lv_fs.d \
./GUI/lvgl/src/lv_misc/lv_gc.d \
./GUI/lvgl/src/lv_misc/lv_ll.d \
./GUI/lvgl/src/lv_misc/lv_log.d \
./GUI/lvgl/src/lv_misc/lv_math.d \
./GUI/lvgl/src/lv_misc/lv_mem.d \
./GUI/lvgl/src/lv_misc/lv_printf.d \
./GUI/lvgl/src/lv_misc/lv_task.d \
./GUI/lvgl/src/lv_misc/lv_templ.d \
./GUI/lvgl/src/lv_misc/lv_txt.d \
./GUI/lvgl/src/lv_misc/lv_txt_ap.d \
./GUI/lvgl/src/lv_misc/lv_utils.d 

OBJS += \
./GUI/lvgl/src/lv_misc/lv_anim.o \
./GUI/lvgl/src/lv_misc/lv_area.o \
./GUI/lvgl/src/lv_misc/lv_async.o \
./GUI/lvgl/src/lv_misc/lv_bidi.o \
./GUI/lvgl/src/lv_misc/lv_color.o \
./GUI/lvgl/src/lv_misc/lv_debug.o \
./GUI/lvgl/src/lv_misc/lv_fs.o \
./GUI/lvgl/src/lv_misc/lv_gc.o \
./GUI/lvgl/src/lv_misc/lv_ll.o \
./GUI/lvgl/src/lv_misc/lv_log.o \
./GUI/lvgl/src/lv_misc/lv_math.o \
./GUI/lvgl/src/lv_misc/lv_mem.o \
./GUI/lvgl/src/lv_misc/lv_printf.o \
./GUI/lvgl/src/lv_misc/lv_task.o \
./GUI/lvgl/src/lv_misc/lv_templ.o \
./GUI/lvgl/src/lv_misc/lv_txt.o \
./GUI/lvgl/src/lv_misc/lv_txt_ap.o \
./GUI/lvgl/src/lv_misc/lv_utils.o 



# Each subdirectory must supply rules for building sources it contributes
GUI/lvgl/src/lv_misc/%.o: ../GUI/lvgl/src/lv_misc/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/User" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Peripheral/inc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/include" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/Common" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/MemMang" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/examples/porting" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app/src/lv_demo_widgets" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_draw" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_font" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_gpu" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_hal" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_misc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_themes" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_widgets" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
