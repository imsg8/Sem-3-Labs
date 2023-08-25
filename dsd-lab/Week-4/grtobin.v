module grtobin(G,B);
parameter n = 8;
input [n-1:0]G;
output reg [n-1:0]B;
integer i;
always @ (G)
begin 
	B[n-1] = G[n-1];
	for (i=n-2;i>=0;i--)
		begin
		B[i] = B[i+1] ^ G[i];
		end
	end
endmodule
