`timescale 1ns/1ns
`include "q1.v"

module q1_tb;
reg q,clk;
wire a;
dff1 stage0(q,clk,a);
initial begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	clk = 0;
	forever #10 clk=~clk;
end
initial begin
	q=0;#20;
	q=0;#20;
	q=0;#20;
	q=0;#20;
	q=0;#20;
	q=1;#20;
	q=0;#20;
	q=1;#20;
	q=0;#20;
	q=1;#20;
	q=0;#20;
	$display("Test Complete");
	$finish;
	end
endmodule
	
