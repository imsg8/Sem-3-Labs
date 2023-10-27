module dFlipFlop(d,clk,reset,q);
input d,clk,reset;
output reg q;
always@(posedge clk)
begin
if(!reset)
q<=d;
end
always@(reset)
begin
if(reset)
q<=0;
end
endmodule
