module jkFlipFlop(j,k,clk,reset,q);
input j,k,clk,reset;
output reg q;
always@(posedge clk)
begin
if(reset)
q<=0;
else if(k==1&j==1)
q<=~q;
else if(k==1)
q<=0;
else if(j==1)
q<=1;
end
endmodule
