#include "drivers/mss_gpio/mss_gpio.h"
#include "drivers/mss_timer/mss_timer.h"
#include "drivers/mss_uart/mss_uart.h"

#include <stdio.h>
#include <inttypes.h>

#include "imu.h"

#define NUMBER_SAMPLES 100
#define dt 0.001

float angle = 0;

int16_t X_GYRO;
uint16_t Y_ACCL;

void Timer1_IRQHandler( void )
{
    int i;

    //average gyro readings
    static int16_t gyro_avgs[NUMBER_SAMPLES];
    static int index_gyro = 0;

    gyro_avgs[index_gyro] = X_GYRO;

    index_gyro++;
    if (index_gyro >= NUMBER_SAMPLES) index_gyro = 0;

    int32_t total_gyro = 0;
    for (i = 0; i < NUMBER_SAMPLES; ++i) {
        total_gyro += gyro_avgs[i];
    }
    float gyro_avg = total_gyro / NUMBER_SAMPLES;
    float gyro_angle = (gyro_avg ) / 131;

    //average accl readings
    static int16_t accl_avgs[NUMBER_SAMPLES];
    static int index_accl = 0;

    accl_avgs[index_accl] = Y_ACCL;

    index_accl++;
    if (index_accl >= NUMBER_SAMPLES) index_accl = 0;

    int32_t total_accl = 0;
    for (i = 0; i < NUMBER_SAMPLES; ++i) {
        total_accl += accl_avgs[i];
    }
    float accl_avg = total_accl / NUMBER_SAMPLES;
    float accl_angle = (accl_avg * 90) / 16384;

    //combine accel and gyro


    angle = (0.98) * (angle + gyro_angle * dt) + (0.02) * accl_angle;

    //printf("angle! : %f\r\n", angle);

    MSS_TIM1_clear_irq();
}

int main()
{
	//uint32_t count;

	MSS_GPIO_init();
	MSS_GPIO_config( MSS_GPIO_0, MSS_GPIO_OUTPUT_MODE);
	MSS_GPIO_config( MSS_GPIO_1, MSS_GPIO_OUTPUT_MODE);


	MSS_I2C_init(&g_mss_i2c1 , IMU_ADDRESS_WRITE, MSS_I2C_PCLK_DIV_256 );
	imu_init();

	//one timer tick is 10ns at 100Mhz
	MSS_TIM1_init( MSS_TIMER_PERIODIC_MODE);
	MSS_TIM1_enable_irq();
	MSS_TIM1_load_background(100000);
	MSS_TIM1_start();

	MSS_TIM2_init( MSS_TIMER_ONE_SHOT_MODE);







	while( 1 ) {

		//int16_t x_accl = imu_accl_x();
		//int16_t y_accl = imu_accl_y();
		//int16_t z_accl = imu_accl_z();



	    X_GYRO = imu_gyro_x();
	    Y_ACCL = imu_accl_y();
		//uint16_t y_gyro = imu_gyro_y();
		//uint16_t z_gyro = imu_gyro_z();


		//printf("Avg X: %f\r\n", avg_x);
		//printf("Accel X: %i\n\r", x_accl);
		//printf("Accel Y: %u\n\r", y_accl);
		//printf("Accel Z: %u\n\r", z_accl);

		//printf("Gyro X: %u\r\n", x_gyro);
		//printf("Gyro Y: %u\r\n", y_gyro);
		//printf("Gyro Z: %u\r\n", z_gyro);



		//150000 = 1.5ms pulse
		//1.49ms pulse = equilibrium point
		uint32_t pulsewidth_right = 150000 + (angle/90.0)*100000;
		uint32_t pulsewidth_left = 150000 - (angle/90.0)*100000;
		uint32_t period = 2000000;
		MSS_TIM2_load_immediate(period);
	    MSS_TIM2_start();

	    while (MSS_TIM2_get_current_value() > 0) {

	    	if (MSS_TIM2_get_current_value() > (period - pulsewidth_right))
	    		MSS_GPIO_set_output( MSS_GPIO_0, 1);
	    	else
	    		MSS_GPIO_set_output( MSS_GPIO_0, 0);

	    	if (MSS_TIM2_get_current_value() > (period - pulsewidth_left))
                MSS_GPIO_set_output( MSS_GPIO_1, 1);
            else
                MSS_GPIO_set_output( MSS_GPIO_1, 0);
	    }
	}

	return 0;
}
