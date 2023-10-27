`timescale 1ns/1ns
`include "q2.v"

module q2_tb;
	parameter n=8;
	reg [n-1:0]i;
	reg clk;
	wire [n-1:0]q;
q2 stage0(i,clk,q);

initial begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	clk = 0;
	forever #10 clk = ~clk;
end
initial begin
	i=8'b 10101010;#20;
	i=8'b 01010101;#20;
	i=8'b 11101010;#20;
	i=8'b 01011111;#20;
	i=8'b 00000000;#20;
	i=8'b 01111100;#20;
	i=8'b 10000000;#20;
	i=8'b 00010001;#20;
	
	$display("Test Complete");
	$finish;
	
end
endmodule
	
