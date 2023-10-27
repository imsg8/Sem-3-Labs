`timescale 1ns/1ns
`include "srFlipFlop.v"
module srFlipFlop_tb;
reg s,r,clk,reset;
wire q;
srFlipFlop sff(s,r,clk,reset,q);
always #10 clk=~clk;
initial begin
$dumpfile("srFlipFlop_tb.vcd");
$dumpvars(0,srFlipFlop_tb);
clk=0;
#100 $finish;
end
initial begin
s=0;r=0;reset=0;#10;
s=0;r=0;reset=1;#20;
s=1;r=0;reset=1;#20;
s=0;r=1;reset=1;#20;
s=0;r=0;reset=0;#20;
s=0;r=0;reset=1;#10;
end
endmodule
