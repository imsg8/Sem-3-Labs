`timescale 1ns/1ns
`include "adder.v"
module adder_tb;
reg x,y,cin;
wire s,cout;
adder adder1(x,y,cin,s,cout);
initial begin
	$dumpfile("adder_tb.vcd");
	$dumpvars(0,adder_tb);
	x=0;
	y=0;
	cin=0;
	#20;
	
	x=0;
	y=0;
	cin=1;
	#20;
	
	x=0;
	y=1;
	cin=0;
	#20;
	
	x=0;
	y=1;
	cin=1;
	#20;
	
	x=1;
	y=0;
	cin=0;
	#20;
	
	x=1;
	y=0;
	cin=1;
	#20;
	
	x=1;
	y=1;
	cin=0;
	#20;
	
	x=1;
	y=1;
	cin=1;
	#20;
	$display("Test Completed");
end
endmodule
