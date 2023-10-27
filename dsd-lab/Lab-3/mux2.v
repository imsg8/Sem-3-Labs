module mux2(S,W,f);
input S;
input [1:0]W;
output reg f;
always @ (S|W)
begin
f = S ? W[1] : W[0];
end
endmodule
