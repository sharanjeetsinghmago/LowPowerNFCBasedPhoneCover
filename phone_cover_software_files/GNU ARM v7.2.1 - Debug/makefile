################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32LG/subdir.mk
-include BSP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Phone_cover.axf

# Tool invocations
Phone_cover.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "Phone_cover.ld" -Xlinker --gc-sections -Xlinker -Map="Phone_cover.map" --specs=nano.specs -o Phone_cover.axf "./BSP/bsp_bcc.o" "./BSP/bsp_stk.o" "./BSP/bsp_stk_leds.o" "./BSP/bsp_trace.o" "./CMSIS/EFM32LG/startup_efm32lg.o" "./CMSIS/EFM32LG/system_efm32lg.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./src/i2c.o" "./src/phone_cover.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: Phone_cover.hex'
	arm-none-eabi-objcopy -O ihex "Phone_cover.axf" "Phone_cover.hex"
	@echo ' '

	@echo 'Building bin file: Phone_cover.bin'
	arm-none-eabi-objcopy -O binary "Phone_cover.axf" "Phone_cover.bin"
	@echo ' '

	@echo 'Building s37 file: Phone_cover.s37'
	arm-none-eabi-objcopy -O srec "Phone_cover.axf" "Phone_cover.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Phone_cover.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Phone_cover.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
