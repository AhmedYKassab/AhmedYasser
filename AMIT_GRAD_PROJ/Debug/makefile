################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/Interrupt/subdir.mk
-include MCAL/DIO0/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Temp\ Sensor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/Heater/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/Button/subdir.mk
-include HAL/7\ Segment/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AMIT_GRAD_PROJ.lss \

FLASH_IMAGE += \
AMIT_GRAD_PROJ.hex \

EEPROM_IMAGE += \
AMIT_GRAD_PROJ.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AMIT_GRAD_PROJ.elf secondary-outputs

# Tool invocations
AMIT_GRAD_PROJ.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AMIT_GRAD_PROJ.map -mmcu=atmega32 -o "AMIT_GRAD_PROJ.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AMIT_GRAD_PROJ.lss: AMIT_GRAD_PROJ.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AMIT_GRAD_PROJ.elf  >"AMIT_GRAD_PROJ.lss"
	@echo 'Finished building: $@'
	@echo ' '

AMIT_GRAD_PROJ.hex: AMIT_GRAD_PROJ.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AMIT_GRAD_PROJ.elf  "AMIT_GRAD_PROJ.hex"
	@echo 'Finished building: $@'
	@echo ' '

AMIT_GRAD_PROJ.eep: AMIT_GRAD_PROJ.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AMIT_GRAD_PROJ.elf  "AMIT_GRAD_PROJ.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AMIT_GRAD_PROJ.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AMIT_GRAD_PROJ.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AMIT_GRAD_PROJ.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
