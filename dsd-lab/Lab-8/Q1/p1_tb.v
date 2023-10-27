`timescale 1ns/1ns
`include "p1.v"

module p1_tb;
reg clk,x,reset;
wire y;
wire [2:0]l;
p1 out(clk,x,y,reset,l);
initial begin
	$dumpfile("p1_tb.vcd");
	$dumpvars(0,p1_tb);
	
x = 0; reset = 0; #20; 
x = 1; reset = 1; #20; 
x = 0; 
x = 1; 
x = 0; 
x = 1; 
x = 0; 
x = 1; 
x = 0; 

$display("Test Complete");
$finish;
end
endmodule
