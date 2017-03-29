`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    05:33:21 03/25/2017 
// Design Name: 
// Module Name:    tetris_logic 
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
module tetris_logic(
	input clk,
	input moveR,
	input moveL,
	output reg right,
	output reg left
   );
	always @(posedge clk)
	begin
		if(moveR)
		begin
			right <= 1;
		end
		else if(moveL)
		begin
			left <= 1;
		end
		else
		begin
			left<=0;
			right<=0;
		end
	end
endmodule
