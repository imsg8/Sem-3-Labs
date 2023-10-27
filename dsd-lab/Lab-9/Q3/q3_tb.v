`timescale 1ns/1ns
`include "q3.v"

module q3_tb;

reg clk, reset;
wire [0:3]Q;

q3 h1(clk, reset, Q);

initial begin
	clk=0;
	forever #10 clk = ~clk;
end
initial begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0, q3_tb);
	reset=1; #20;
	reset=0; #320;
	$display("Test Completed");
	$finish;
end
endmodule
