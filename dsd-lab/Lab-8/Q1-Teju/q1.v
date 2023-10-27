`include "d_FF.v"
module q1(x,B,y,clk,reset);
input clk,reset;
output [2:0]B;
input x;
output y;
wire [2:0]D;
assign D[2]=(B[2]&(~x))|(B[1]&(~B[0])&(~x));
assign D[1]=((B[0]&(~x))|(B[2]&x)|((~B[2])&(~B[1])&(~x)));
assign D[0]=((~B[2])&(~B[1])&(~B[0]))|(B[1]&B[0]);
d_FF d1(D[2],clk,reset,B[2]);
d_FF d2(D[1],clk,reset,B[1]);
d_FF d3(D[0],clk,reset,B[0]);
assign y=(B[1]&(~x))|(B[1]&B[0])|(B[2]&x);
endmodule
