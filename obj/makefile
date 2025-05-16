################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utils/subdir.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include OS/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/RISC-V/subdir.mk
-include FreeRTOS/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include Comm/subdir.mk
-include BSP/subdir.mk
-include Algorithm/subdir.mk
-include Adjustor/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
MainCtrl_OS.hex \

SECONDARY_LIST += \
MainCtrl_OS.lst \

SECONDARY_SIZE += \
MainCtrl_OS.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: MainCtrl_OS.elf secondary-outputs

# Tool invocations
MainCtrl_OS.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -T "/Users/panpoming/Documents/ChairCtrl/ChairCtrl/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -Xlinker --print-memory-usage -Wl,-Map,"MainCtrl_OS.map" --specs=nano.specs --specs=nosys.specs -o "MainCtrl_OS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
MainCtrl_OS.hex: MainCtrl_OS.elf
	@	riscv-none-embed-objcopy -O ihex "MainCtrl_OS.elf" "MainCtrl_OS.hex"
MainCtrl_OS.lst: MainCtrl_OS.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "MainCtrl_OS.elf" > "MainCtrl_OS.lst"
MainCtrl_OS.siz: MainCtrl_OS.elf
	riscv-none-embed-size --format=berkeley "MainCtrl_OS.elf"

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS) MainCtrl_OS.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets