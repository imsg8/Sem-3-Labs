module mux4(S,W,f);
input [1:0]S;
input[3:0]W;
output reg f;
always @ (S|W)
begin
if (S==0)
f = W[0];
else if (S==1)
f = W[1];
else if (S==2)
f = W[2];
else
f = W[3];
end
endmodule
