module t_ff(t,q,clk,reset);
input t,clk,reset;
output reg q;
always@(negedge clk)
begin
if(t)
q<=~q;
end
always@(reset)
begin
if(!reset)
q<=0;
end
endmodule

module p2(clk,x,reset,A,B);
input clk,x,reset;
output A,B;
wire [1:0]s;
assign s[1] = (B & ~x) | (B & ~A) ;
assign s[0] = (A & ~x) | (~B & ~x) | (x & ~A & B);
t_ff st0(s[1], A, clk, reset);
t_ff st1(s[0], B, clk, reset);
endmodule
