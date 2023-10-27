`timescale 1ns/1ns
`include "q1.v"

module q1_tb;

reg clk, reset;
wire [3:0]Q;
q1 h1(reset, clk, Q);

initial begin
	clk=0;
	forever #10 clk = ~clk;
end
initial begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);
	reset=1; #20;
	reset=0; #80;
	$display("Test Completed");
	$finish;
end
endmodule
