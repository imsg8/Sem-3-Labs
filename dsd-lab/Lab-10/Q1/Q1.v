`include "jkFlipFlop.v"
module Q1(clk,reset,V);
input clk,reset;
output [2:0]V;

jkFlipFlop jk1(V[1],(V[1]&V[0]),reset,clk,V[2]);
jkFlipFlop jk2(V[0],((~V[2])|V[0]),reset,clk,V[1]);
jkFlipFlop jk3((V[2]|(~V[1])),1'b1,reset,clk,V[0]);

endmodule
