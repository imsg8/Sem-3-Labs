`timescale 1ns/1ns
`include "mux16.v"

module mux16_tb;
reg [3:0]S;
reg [15:0]W;
wire f;

mux16 h1(S,W,f);
initial begin
	
		$dumpfile("mux16_tb.vcd");
		$dumpvars(0,mux16_tb);
		
S=4'b 0000;
W=16'b 1010101010101010;
#20;

S=4'b 0001;
W=16'b 1010101010101010;
#20;

S=4'b 0010;
W=16'b 1010101010101010;
#20;

S=4'b 0011;
W=16'b 1010101010101010;
#20;

S=4'b 0100;
W=16'b 1010101010101010;
#20;

S=4'b 0101;
W=16'b 1010101010101010;
#20;

S=4'b 0110;
W=16'b 1010101010101010;
#20;

S=4'b 0111;
W=16'b 1010101010101010;
#20;

S=4'b 1000;
W=16'b 1010101010101010;
#20;

S=4'b 1001;
W=16'b 1010101010101010;
#20;

S=4'b 1010;
W=16'b 1010101010101010;
#20;

S=4'b 1011;
W=16'b 1010101010101010;
#20;

S=4'b 1100;
W=16'b 1010101010101010;
#20;

S=4'b 1101;
W=16'b 1010101010101010;
#20;

S=4'b 1110;
W=16'b 1010101010101010;
#20;

S=4'b 1111;
W=16'b 1010101010101010;
#20;

		$display("Test Complete");

end 
endmodule
