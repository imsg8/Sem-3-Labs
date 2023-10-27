module mux8(S,W,f);
input [2:0]S;
input [7:0]W;
output reg f;
always @ (S|W)
begin
case (S)
0:begin
f=W[0];
end
1:begin
f=W[1];
end
2:begin
f=W[2];
end
3:begin
f=W[3];
end
4:begin
f=W[4];
end
5:begin
f=W[5];
end
6:begin
f=W[6];
end
7:begin
f=W[7];
end
default : begin
f=0;
end
endcase
end
endmodule
