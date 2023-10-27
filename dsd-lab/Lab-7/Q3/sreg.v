`include "D_FF.v"
`include "Mul4_1.v"
module sreg(I,A,S,clk);
input clk;
input [1:0]S;
output [3:0]A;
input [3:0]I;
wire [3:0]D;

Mul4_1 M1({A[2],I[3],A[3],A[3]},S,D[3]);
Mul4_1 M2({A[1],I[2],A[2],A[2]},S,D[2]);
Mul4_1 M3({A[0],I[1],A[1],A[1]},S,D[1]);
Mul4_1 M4({S[1],I[0],A[0],A[0]},S,D[0]);

D_FF D1(D[3],clk,A[3],1'b0);
D_FF D2(D[2],clk,A[2],1'b0);
D_FF D3(D[1],clk,A[1],1'b0);
D_FF D4(D[0],clk,A[0],1'b0);

endmodule
