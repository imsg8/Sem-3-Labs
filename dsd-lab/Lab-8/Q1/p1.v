module d_ff(d,clk,reset,q);
input d,clk,reset;
output reg q;
always@(posedge clk)
begin
if(!reset)
q<=d;
end
always@(posedge reset)
begin
if(reset)
q<=0;
end
endmodule
module p1(clk,x,y,reset,q);
input clk,x,reset;
output y;
output [2:0]q;
wire [2:0]s,l;
assign s[2] = (~q[0] & ~x & q[1]) | (~x & q[2]);
assign s[1] = (~q[2] & ~x & ~q[1] & ~q[0]) | (x & q[0] ) | ( ~x & q[0] );
assign s[0] = (~q[2] & q[1] & ~q[0] ) | (q[1] & q[0] );
d_ff st0(s[2], l[2], clk, reset);
d_ff st1(s[1], l[1], clk, reset);
d_ff st2(s[0], l[0], clk, reset);
assign y = (q[2] & x) | (q[1] & ~x) | (q[1] & q[0]);
assign q=l;
endmodule
