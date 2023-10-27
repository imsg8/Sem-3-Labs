`timescale 1ns/1ns
`include "p2.v"

module p2_tb;
reg clk, x, reset;
wire A,B;
p2 out(clk,x,reset,A,B);
initial begin
	clk=1;
	forever #10 clk = ~clk;
end
initial begin
	$dumpfile("p2_tb.vcd");
	$dumpvars(0,p2_tb);
	x = 0; reset = 1; #20;
	x = 1; reset = 0; #20;
	x = 0; #20;
	x = 1; #20;
	x = 0; #20;
	x = 1; #20;
	x = 0; #20;
	x = 1; #20;
	$display("Test Complete");
	$finish;
end
endmodule
