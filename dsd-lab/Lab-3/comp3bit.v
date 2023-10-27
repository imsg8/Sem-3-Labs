module comp3bit(A,B,g,l,e);
input [2:0]A,B;
output g,l,e;
wire i2, i1, i0;
assign i2 = ~(A[2]^B[2]);
assign i1 = ~(A[1]^B[1]);
assign i0 = ~(A[0]^B[0]);
assign e = i2 & i1 & i0;
assign g = A[2] & ~B[2] | i2 & A[1] & ~B[1];
assign l = ~(g|e);
endmodule
