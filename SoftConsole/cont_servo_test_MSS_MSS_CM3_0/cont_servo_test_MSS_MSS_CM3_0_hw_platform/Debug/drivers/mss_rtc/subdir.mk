################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/mss_rtc/mss_rtc.c 

OBJS += \
./drivers/mss_rtc/mss_rtc.o 

C_DEPS += \
./drivers/mss_rtc/mss_rtc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/mss_rtc/%.o: ../drivers/mss_rtc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -DACTEL_STDIO_THRU_UART -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\CMSIS -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\CMSIS\startup_gcc -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers\mss_gpio -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers\mss_nvm -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers\mss_pdma -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers\mss_rtc -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers\mss_timer -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\drivers\mss_uart -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\hal -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\hal\CortexM3 -IC:\Users\rwooster\Documents\cont_servo_test\SoftConsole\cont_servo_test_MSS_MSS_CM3_0\cont_servo_test_MSS_MSS_CM3_0_hw_platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

