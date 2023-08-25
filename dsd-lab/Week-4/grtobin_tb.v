`timescale 1ns/1ns
`include "grtobin.v"

module grtobin_tb;
parameter n=8;
reg [n-1:0]G;
wire [n-1:0]B;

grtobin h1(G,B);
initial begin
	
		$dumpfile("grtobin_tb.vcd");
		$dumpvars(0,grtobin_tb);
		
G = 4'b 0000;
#20;

G = 4'b 0001;
#20;

G = 4'b 0010;
#20; 

G = 4'b 0011; 
#20;

G = 4'b 0100;
#20;

G = 4'b 0101;
#20;

G = 4'b 0110;
#20;

G = 4'b 0111;
#20;

G = 4'b 1000;
#20;

G = 4'b 1001;
#20;

G = 4'b 1010;
#20;

G = 4'b 1011;
#20;

G = 4'b 1100;
#20;

G = 4'b 1101;
#20;

G = 4'b 1110;
#20;

G = 4'b 1111;
#20;

	$display("Test Complete");
	
end
endmodule
