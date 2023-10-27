module srFlipFlop(s,r,clk,reset,q);
input s,r,clk,reset;
output reg q;
always@(negedge clk)
begin
if(!reset)
q<=0;
else if(s==1&r==0)
q<=1;
else if(s==0&r==1)
q<=0;
end
endmodule
