//////////////////////////////////////////////////////////////////////
// Created by SmartDesign Mon Nov 11 16:26:52 2013
// Version: v11.0 11.0.0.23
//////////////////////////////////////////////////////////////////////

`timescale 1 ns/100 ps

// cont_servo_test
module cont_servo_test(
    // Inputs
    MSS_RESET_N,
    UART_0_RXD,
    // Outputs
    GPIO_0_OUT,
    UART_0_TXD,
    // Inouts
    I2C_1_SCL,
    I2C_1_SDA
);

//--------------------------------------------------------------------
// Input
//--------------------------------------------------------------------
input  MSS_RESET_N;
input  UART_0_RXD;
//--------------------------------------------------------------------
// Output
//--------------------------------------------------------------------
output GPIO_0_OUT;
output UART_0_TXD;
//--------------------------------------------------------------------
// Inout
//--------------------------------------------------------------------
inout  I2C_1_SCL;
inout  I2C_1_SDA;
//--------------------------------------------------------------------
// Nets
//--------------------------------------------------------------------
wire   GPIO_0_OUT_net_0;
wire   I2C_1_SCL;
wire   I2C_1_SDA;
wire   MSS_RESET_N;
wire   UART_0_RXD;
wire   UART_0_TXD_net_0;
wire   UART_0_TXD_net_1;
wire   GPIO_0_OUT_net_1;
//--------------------------------------------------------------------
// Top level output port assignments
//--------------------------------------------------------------------
assign UART_0_TXD_net_1 = UART_0_TXD_net_0;
assign UART_0_TXD       = UART_0_TXD_net_1;
assign GPIO_0_OUT_net_1 = GPIO_0_OUT_net_0;
assign GPIO_0_OUT       = GPIO_0_OUT_net_1;
//--------------------------------------------------------------------
// Component instances
//--------------------------------------------------------------------
//--------cont_servo_test_MSS
cont_servo_test_MSS cont_servo_test_MSS_0(
        // Inputs
        .UART_0_RXD  ( UART_0_RXD ),
        .MSS_RESET_N ( MSS_RESET_N ),
        // Outputs
        .UART_0_TXD  ( UART_0_TXD_net_0 ),
        .GPIO_0_OUT  ( GPIO_0_OUT_net_0 ),
        // Inouts
        .I2C_1_SCL   ( I2C_1_SCL ),
        .I2C_1_SDA   ( I2C_1_SDA ) 
        );


endmodule
