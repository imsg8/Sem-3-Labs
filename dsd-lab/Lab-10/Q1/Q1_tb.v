`timescale 1ns/1ns
`include "Q1.v"


module Q1_tb;
reg clk,reset;
wire [2:0]V;
Q1 Q(clk,reset,V);
always #10 clk=~clk;
initial begin
$dumpfile("Q1_tb.vcd");
$dumpvars(0,Q1_tb);
clk=0;
end
initial begin
reset=1'b1;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
reset=1'b0;#20;
$finish;
end
endmodule
