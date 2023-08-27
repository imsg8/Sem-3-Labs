`timescale 1ns/1ns
`include "fd.v"
module fd_tb;
reg a,b,c,d;
wire f;
fd fd1(a,b,c,d,f);
initial begin
	$dumpfile("fd_tb.vcd");
	$dumpvars(0,fd_tb);
	a=0;
	b=0;
	c=0;
	d=0;
	#20; 
	a=0;
	b=0;
	c=0;
	d=1;
	#20; 
	a=0;
	b=0;
	c=1;
	d=0;
	#20; 
	a=0;
	b=0;
	c=1;
	d=1;
	#20; 
	a=0;
	b=1;
	c=0;
	d=0;
	#20; 
	a=0;
	b=1;
	c=0;
	d=1;
	#20; 
	a=0;
	b=1;
	c=1;
	d=0;
	#20; 
	a=0;
	b=1;
	c=1;
	d=1;
	#20; 
	a=1;
	b=0;
	c=0;
	d=0;
	#20; 
	a=1;
	b=0;
	c=0;
	d=1;
	#20; 
	a=1;
	b=0;
	c=1;
	d=0;
	#20; 
	a=1;
	b=0;
	c=1;
	d=1;
	#20; 
	a=1;
	b=1;
	c=0;
	d=0;
	#20; 
	a=1;
	b=1;
	c=0;
	d=1;
	#20; 
	a=1;
	b=1;
	c=1;
	d=0;
	#20; 
	a=1;
	b=1;
	c=1;
	d=1;
	#20;
	$display("Test Completed");
end
endmodule