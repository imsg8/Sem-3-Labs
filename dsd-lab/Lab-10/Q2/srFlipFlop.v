module srFlipFlop(s,r,clk,reset,q);
input s,r,clk,reset;
output reg q;

always@(posedge clk)
begin

if(s==1&r==0)
q<=1;
else if(s==0&r==1)
q<=0;
end

always@(reset)
begin
if(reset)
q<=0;
end

endmodule
