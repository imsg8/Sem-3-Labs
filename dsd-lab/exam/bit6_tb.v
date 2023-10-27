`timescale 1ns/1ns
`include "bit6.v"

module bit6_tb;
reg a,b,c,d,e,f;
wire s1,s2,cout1,cout2;

bit6 b1(a,b,c,d,e,f,s1,s2,cout1,cout2);
initial begin
	$dumpfile("bit6_tb.vcd");
	$dumpvars(0,bit6_tb);
a=0;b=0;c=0;d=0;e=0;f=0;#20;
a=0;b=0;c=0;d=0;e=0;f=1;#20;
a=0;b=0;c=0;d=1;e=1;f=1;#20;
a=0;b=0;c=0;d=0;e=0;f=0;#20;
a=1;b=0;c=1;d=0;e=1;f=1;#20;
a=0;b=0;c=0;d=0;e=0;f=0;#20;
a=0;b=1;c=1;d=1;e=1;f=1;#20;
a=1;b=1;c=1;d=1;e=1;f=1;#20;
$display("Test Complete");
end
endmodule
