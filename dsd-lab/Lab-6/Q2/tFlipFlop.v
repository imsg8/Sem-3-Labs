module tFlipFlop(t,clk,reset,q);
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
