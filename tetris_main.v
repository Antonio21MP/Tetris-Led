`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    05:33:00 03/25/2017 
// Design Name: 
// Module Name:    tetris_main 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module tetris_main(
		input clk,
		input moveR,
		input moveL,
		output right,
		output left
	 );
	 tetris_logic tl(clk, moveR, moveL, right, left);


endmodule
