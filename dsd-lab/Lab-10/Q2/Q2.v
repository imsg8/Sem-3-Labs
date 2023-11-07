`include "srFlipFlop.v"
module Q2(reset,clk,V);
input reset,clk;
output [2:0]V;

srFlipFlop sr1(((~V[1])&(~V[0])),(V[2]&(~V[1])),clk,reset,V[2]);
srFlipFlop sr2(((~V[2])&(~V[1])),((V[2]&(~V[0]))|((~V[2])&V[1]&V[0])),clk,reset,V[1]);
srFlipFlop sr3((~V[0]),(V[0]&((~V[2])|V[1])),clk,reset,V[0]);

endmodule
