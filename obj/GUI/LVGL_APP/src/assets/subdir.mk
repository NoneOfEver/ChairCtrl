################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/lvgl_app/src/assets/img_cogwheel_alpha16.c \
../GUI/lvgl_app/src/assets/img_cogwheel_argb.c \
../GUI/lvgl_app/src/assets/img_cogwheel_chroma_keyed.c \
../GUI/lvgl_app/src/assets/img_cogwheel_indexed16.c \
../GUI/lvgl_app/src/assets/img_cogwheel_rgb.c \
../GUI/lvgl_app/src/assets/img_hand.c \
../GUI/lvgl_app/src/assets/lv_font_montserrat_12_compr_az.c \
../GUI/lvgl_app/src/assets/lv_font_montserrat_16_compr_az.c \
../GUI/lvgl_app/src/assets/lv_font_montserrat_28_compr_az.c 

C_DEPS += \
./GUI/lvgl_app/src/assets/img_cogwheel_alpha16.d \
./GUI/lvgl_app/src/assets/img_cogwheel_argb.d \
./GUI/lvgl_app/src/assets/img_cogwheel_chroma_keyed.d \
./GUI/lvgl_app/src/assets/img_cogwheel_indexed16.d \
./GUI/lvgl_app/src/assets/img_cogwheel_rgb.d \
./GUI/lvgl_app/src/assets/img_hand.d \
./GUI/lvgl_app/src/assets/lv_font_montserrat_12_compr_az.d \
./GUI/lvgl_app/src/assets/lv_font_montserrat_16_compr_az.d \
./GUI/lvgl_app/src/assets/lv_font_montserrat_28_compr_az.d 

OBJS += \
./GUI/lvgl_app/src/assets/img_cogwheel_alpha16.o \
./GUI/lvgl_app/src/assets/img_cogwheel_argb.o \
./GUI/lvgl_app/src/assets/img_cogwheel_chroma_keyed.o \
./GUI/lvgl_app/src/assets/img_cogwheel_indexed16.o \
./GUI/lvgl_app/src/assets/img_cogwheel_rgb.o \
./GUI/lvgl_app/src/assets/img_hand.o \
./GUI/lvgl_app/src/assets/lv_font_montserrat_12_compr_az.o \
./GUI/lvgl_app/src/assets/lv_font_montserrat_16_compr_az.o \
./GUI/lvgl_app/src/assets/lv_font_montserrat_28_compr_az.o 



# Each subdirectory must supply rules for building sources it contributes
GUI/lvgl_app/src/assets/%.o: ../GUI/lvgl_app/src/assets/%.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/User" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/SRC/Peripheral/inc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/include" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/Common" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/GCC/RISC-V/chip_specific_extensions/RV32I_PFIC_no_extensions" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/FreeRTOS/portable/MemMang" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/examples/porting" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app/src/lv_demo_widgets" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl_app" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_core" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_draw" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_font" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_gpu" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_hal" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_misc" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_themes" -I"c:/Users/noneo/Downloads/CH32V307EVT/EVT/EXAM/FreeRTOS/FreeRTOS_Core/GUI/lvgl/src/lv_widgets" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
