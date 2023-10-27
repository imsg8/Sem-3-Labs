`timescale 1ns/1ns
`include "q1.v"
module q1_tb;
reg reset;
reg clk;
wire [2:0]B;
reg x;
wire y;
q1 q(x,B,y,clk,reset);
always #10 clk=~clk;
initial begin
$dumpfile("q1_tb.vcd");
$dumpvars(0,q1_tb);
clk=0;
end
initial begin
	x=1'b0;reset=1'b1;#20;
	x=1'b1;reset=1'b0;#20;
	x=1'b0;reset=1'b0;#20;
	x=1'b1;reset=1'b0;#20;
	x=1'b0;reset=1'b0;#20;
	x=1'b1;reset=1'b0;#20;
	x=1'b0;reset=1'b0;#20;
	x=1'b1;reset=1'b0;#20;
	x=1'b0;reset=1'b0;#20;
	x=1'b1;reset=1'b0;#20;
$finish;
end
endmodule
