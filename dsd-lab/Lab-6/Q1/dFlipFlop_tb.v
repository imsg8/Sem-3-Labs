`timescale 1ns/1ns
`include "dFlipFlop.v"
module dFlipFlop_tb;
reg d,clk,reset;
wire q;
dFlipFlop dFF(d,clk,reset,q);
always #10 clk=~clk;
initial begin
$dumpfile("dFlipFlop_tb.vcd");
$dumpvars(0,dFlipFlop_tb);
clk=0;
#80 $finish;
end
initial begin
d=1;reset=1;#10;
d=1;reset=0;#20;
d=1;reset=1;#10;
d=0;reset=1;#10;
d=1;reset=0;#20;
d=0;reset=0;#10;
$display("Test Completed");
end
endmodule
