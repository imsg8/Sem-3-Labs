`timescale 1ns/1ns
`include "mux4.v"

module mux4_tb;
reg[1:0]S;
reg[3:0]W;
wire f;

mux4 h1(S,W,f);
initial begin

        $dumpfile("mux4_tb.vcd");
        $dumpvars(0,mux4_tb);

	S=0;
	W=4'b 1110;
	#20

	S=1;
	W=4'b 0011;
	#20

	S=2;
	W=4'b 0111;
	#20

	S=3;
	W=4'b 0100;
	#20

	S=0;
	W=4'b 0001;
	#20

	S=1;
	W=4'b 0101;
	#20

	S=2;
	W=4'b 1010;
	#20

	S=3;
	W=4'b 1001;
	#20

	$display("Test Complete");

end
endmodule
