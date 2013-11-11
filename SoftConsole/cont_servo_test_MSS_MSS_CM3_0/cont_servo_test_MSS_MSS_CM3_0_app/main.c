#include "drivers/mss_gpio/mss_gpio.h"
#include "drivers/mss_timer/mss_timer.h"
#include "drivers/mss_uart/mss_uart.h"
#include "drivers/mss_i2c/mss_i2c.h"
#include <stdio.h>
#include <inttypes.h>

#define IMU_ADDRESS_READ 0b11010001
#define IMU_ADDRESS_WRITE 0b11010000

#define X_OUT_LOWER 0x44//3C
#define X_OUT_UPPER 0x43//3B
#define WHOAMI 0x75

#define TEMP 0x41

int main()
{
	//uint32_t count;

	MSS_GPIO_init();
	MSS_GPIO_config( MSS_GPIO_0, MSS_GPIO_OUTPUT_MODE);
	MSS_TIM1_init(MSS_TIMER_ONE_SHOT_MODE);
	MSS_I2C_init(&g_mss_i2c1 , IMU_ADDRESS_WRITE, MSS_I2C_PCLK_DIV_256 );

	uint8_t transmit[2] = {0x6B, 0x0};

	MSS_I2C_write
	(
		&g_mss_i2c1,
		IMU_ADDRESS_WRITE,
		transmit,
		sizeof(transmit),
		MSS_I2C_RELEASE_BUS
	);
	MSS_I2C_wait_complete(&g_mss_i2c1);

	while( 1 )
	{
		uint8_t transmit_lower = X_OUT_LOWER;
		uint8_t transmit_upper = X_OUT_UPPER;
		uint8_t receive;
		uint8_t receive2;



		MSS_I2C_write
		(
			&g_mss_i2c1,
			IMU_ADDRESS_WRITE,
			&transmit_lower,
			sizeof(transmit_lower),
			MSS_I2C_RELEASE_BUS
		);

		MSS_I2C_wait_complete(&g_mss_i2c1);

		MSS_I2C_read
		(
				&g_mss_i2c1,
				IMU_ADDRESS_READ,
				&receive,
				sizeof(receive),
				MSS_I2C_RELEASE_BUS
		 );
		MSS_I2C_wait_complete(&g_mss_i2c1);

		MSS_I2C_write
		(
			&g_mss_i2c1,
			IMU_ADDRESS_WRITE,
			&transmit_upper,
			sizeof(transmit_upper),
			MSS_I2C_RELEASE_BUS
		);

		MSS_I2C_wait_complete(&g_mss_i2c1);

		MSS_I2C_read
		(
				&g_mss_i2c1,
				IMU_ADDRESS_READ,
				&receive2,
				sizeof(receive),
				MSS_I2C_RELEASE_BUS
		 );
		MSS_I2C_wait_complete(&g_mss_i2c1);

		uint16_t result = receive + (receive2<<8);

		printf("Position X: %u\n\r", result);





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