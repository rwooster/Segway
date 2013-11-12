#include "drivers/mss_gpio/mss_gpio.h"
#include "drivers/mss_timer/mss_timer.h"
#include "drivers/mss_uart/mss_uart.h"

#include <stdio.h>
#include <inttypes.h>

#include "imu.h"

int16_t x_gyro;

void Timer1_IRQHandler( void )
{


    static int16_t array[1000];
    static int index = 0;

    int i;
    array[index] =  x_gyro;

    index++;
    if (index >= 1000) index = 0;

    int32_t total = 0;
    for (i = 0; i < 1000; ++i) {
        total += array[i];
    }
    float gyro_avg = total / 1000;

    float value = (gyro_avg * 90) / 16384;

    printf("Avg: %f\r\n", value);

    MSS_TIM1_clear_irq();
}

int main()
{
	//uint32_t count;

	MSS_GPIO_init();
	MSS_GPIO_config( MSS_GPIO_0, MSS_GPIO_OUTPUT_MODE);


	MSS_I2C_init(&g_mss_i2c1 , IMU_ADDRESS_WRITE, MSS_I2C_PCLK_DIV_256 );
	imu_init();

	MSS_TIM1_init( MSS_TIMER_PERIODIC_MODE);
	MSS_TIM1_enable_irq();
	MSS_TIM1_load_background(1000);
	MSS_TIM1_start();







	while( 1 ) {

		//int16_t x_accl = imu_accl_x();
		//int16_t y_accl = imu_accl_y();
		//int16_t z_accl = imu_accl_z();



	    x_gyro = imu_accl_y();
		//uint16_t y_gyro = imu_gyro_y();
		//uint16_t z_gyro = imu_gyro_z();


		//printf("Avg X: %f\r\n", avg_x);
		//printf("Accel X: %i\n\r", x_accl);
		//printf("Accel Y: %u\n\r", y_accl);
		//printf("Accel Z: %u\n\r", z_accl);

		//printf("Gyro X: %u\r\n", x_gyro);
		//printf("Gyro Y: %u\r\n", y_gyro);
		//printf("Gyro Z: %u\r\n", z_gyro);



//		//150000 = 1.5ms pulse
//		//1.49ms pulse = equilibrium point
//		uint32_t pulsewidth = 200000;
//		uint32_t period = 2000000;
//		MSS_TIM1_load_immediate(period);
//	    MSS_TIM1_start();
//
//	    while (MSS_TIM1_get_current_value() > 0) {
//
//	    	if (MSS_TIM1_get_current_value() > (period - pulsewidth))
//	    		MSS_GPIO_set_output( MSS_GPIO_0, 1);
//	    	else
//	    		MSS_GPIO_set_output( MSS_GPIO_0, 0);
//	    }
	}

	return 0;
}
