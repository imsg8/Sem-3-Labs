`include "adder.v"
module Add_Sub(X,Y,S,cin,cout);
input cin;
input [3:0]X,Y;
wire [3:0]B;
output [3:0]S;
output cout;
wire [3:1]c;
assign B[0]=(Y[0]^cin);
assign B[1]=(Y[1]^cin);
assign B[2]=(Y[2]^cin);
assign B[3]=(Y[3]^cin);
FAdder F1(X[0],B[0],cin,S[0],c[1]);
FAdder F2(X[1],B[1],c[1],S[1],c[2]);
FAdder F3(X[2],B[2],c[2],S[2],c[3]);
FAdder F4(X[3],B[3],c[3],S[3],cout);
endmodule
