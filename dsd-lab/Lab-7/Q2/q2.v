module q2(i,clk,q);
parameter n = 8;
input [n-1:0]i;
input clk;
output reg [n-1:0]q;
always @ (posedge clk)
	q<=i;
endmodule
