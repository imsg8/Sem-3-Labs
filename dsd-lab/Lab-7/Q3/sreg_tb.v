`timescale 1ns/1ns
`include "sreg.v"
module sreg_tb;
reg clk;
reg [1:0]S;
reg [3:0]I;
wire [3:0]A;
sreg s(I,A,S,clk);
always #10 clk=~clk;
initial begin
$dumpfile("sreg_tb.vcd");
$dumpvars(0,sreg_tb);
clk=1;
#100 $finish;
end
initial begin
S=1;I=14;#20;
S=0;I=14;#20;
S=1;I=7;#20;
S=2;I=14;#20;
S=3;I=14;#20;
end
endmodule
