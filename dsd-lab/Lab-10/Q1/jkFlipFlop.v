module jkFlipFlop(j,k,reset,clk,Q);
input j,k,reset,clk;
output reg Q;

always@(reset)
begin
if(reset)
Q<=0;
end

always@(posedge clk)
begin
if(j==1&k==1)
Q<=(~Q);
else if(k==1)
Q<=0;
else if(j==1)
Q<=1;
end

endmodule
