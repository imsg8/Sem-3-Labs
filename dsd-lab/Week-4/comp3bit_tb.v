`timescale 1ns/1ns
`include "comp3bit.v"

module comp3bit_tb;
reg[2:0]a,b;
wire g,l,e;
comp3bit h1(a,b,g,l,e);
initial begin 		

		$dumpfile("comp3bit_tb.vcd");
		$dumpvars(0,comp3bit_tb);
		
a=3'b 011;
b=3'b 011;
#20;

a=3'b 010;
b=3'b 101;
#20;

a=3'b 110;
b=3'b 100;
#20;

end
endmodule
