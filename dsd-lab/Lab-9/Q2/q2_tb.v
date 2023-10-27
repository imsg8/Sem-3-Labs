`timescale 1ns/1ns
`include "q2.v"

module q2_tb;

reg clk, reset;
wire [4:0]Q;

q2 h1(clk, reset, Q);

initial begin
	clk=0;
	forever #10 clk = ~clk;
end
initial begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0, q2_tb);
	reset=1; #20;
	reset=0; #220;
	$display("Test Completed");
	$finish;
end
endmodule
