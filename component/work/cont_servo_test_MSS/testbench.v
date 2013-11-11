//////////////////////////////////////////////////////////////////////
// Created by Actel SmartDesign Mon Nov 11 16:26:44 2013
// Testbench Template
// This is a basic testbench that instantiates your design with basic 
// clock and reset pins connected.  If your design has special
// clock/reset or testbench driver requirements then you should 
// copy this file and modify it. 
//////////////////////////////////////////////////////////////////////

`timescale 1ns/100ps

module testbench;

parameter SYSCLK_PERIOD = 100; // 10MHz

reg SYSCLK;
reg NSYSRESET;

initial
begin
    SYSCLK = 1'b0;
    NSYSRESET = 1'b0;
end

//////////////////////////////////////////////////////////////////////
// Reset Pulse
//////////////////////////////////////////////////////////////////////
initial
begin
    #(SYSCLK_PERIOD * 10 )
        NSYSRESET = 1'b1;
end


//////////////////////////////////////////////////////////////////////
// 10MHz Clock Driver
//////////////////////////////////////////////////////////////////////
always @(SYSCLK)
    #(SYSCLK_PERIOD / 2.0) SYSCLK <= !SYSCLK;


//////////////////////////////////////////////////////////////////////
// Instantiate Unit Under Test:  cont_servo_test_MSS
//////////////////////////////////////////////////////////////////////
cont_servo_test_MSS cont_servo_test_MSS_0 (
    // Inputs
    .UART_0_RXD({1{1'b0}}),
    .MSS_RESET_N(NSYSRESET),

    // Outputs
    .UART_0_TXD( ),
    .GPIO_0_OUT( ),

    // Inouts
    .I2C_1_SDA( ),
    .I2C_1_SCL( )

);

endmodule
