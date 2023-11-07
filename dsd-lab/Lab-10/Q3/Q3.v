`include "tFlipFlop.v"
module Q3(reset,clk,V);
input reset,clk;
output [2:0]V;

tFlipFlop t1((V[2]^V[1]),clk,reset,V[2]);
tFlipFlop t2((V[1]^V[0]),clk,reset,V[1]);
tFlipFlop t3(~(V[2]^V[0]),clk,reset,V[0]);

endmodule

