`include "mux2.v" 
`include "mux8.v"
module mux16(S,W,f);
input [3:0]S;
input [15:0]W;
wire[1:0]I;
output f;
mux8 st0(S[2:0] , W[7:0] , I[0]);
mux8 st1(S[2:0] , W[15:8] , I[1]);
mux2 st2(S[3] , I, f);
endmodule
