`timescale 1ns/1ns
`include "tFlipFlop.v"
module tFlipFlop_tb;
reg t,clk,reset;
wire q;
tFlipFlop tFF(t,clk,reset,q);
always #10 clk=~clk;
initial begin
$dumpfile("tFlipFlop_tb.vcd");
$dumpvars(0,tFlipFlop_tb);
clk=0;
#80 $finish;
end
initial begin
t=0;reset=0;#10;
t=1;reset=1;#10;
t=1;reset=0;#20;
t=1;reset=1;#10;
t=0;reset=1;#10;
t=1;reset=0;#20;
t=0;reset=0;#10;
end
endmodule
