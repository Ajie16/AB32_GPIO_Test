################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/hal_drivers/drv_gpio.c \
../libraries/hal_drivers/drv_usart.c 

OBJS += \
./libraries/hal_drivers/drv_gpio.o \
./libraries/hal_drivers/drv_usart.o 

C_DEPS += \
./libraries/hal_drivers/drv_gpio.d \
./libraries/hal_drivers/drv_usart.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/hal_drivers/%.o: ../libraries/hal_drivers/%.c
	riscv64-unknown-elf-gcc  -DDEBUG -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rt-thread\include\libc" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\applications" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\board" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libcpu\cpu" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libraries\hal_drivers\config" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libraries\hal_drivers" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libraries\hal_libraries\ab32vg1_hal\include" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libraries\hal_libraries\ab32vg1_hal" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libraries\hal_libraries\bmsis\include" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\libraries\hal_libraries\bmsis" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rt-thread\components\libc\compilers\common" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rt-thread\include" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB" -I"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\Hardware" -include"D:\RT-ThreadStudio\workspace\AB32_GPIO_RGB\rtconfig_preinc.h" -std=gnu11 -c -mcmodel=medany -march=rv32imc -mabi=ilp32 -Os -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

