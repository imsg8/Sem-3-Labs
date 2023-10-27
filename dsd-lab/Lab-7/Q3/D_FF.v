module D_FF(D,clk,Q,reset);
input clk,D,reset;
output reg Q;
always@(posedge clk)
begin
Q<=D;
end
always@(reset)
begin
if(reset)
Q<=0;
end
endmodule
