`timescale 1ns/1ns
`include "hello.v"

module hello_tb;
reg a,b;
wire c;

hello h1(a,b,c);
initial begin

$dumpfile("hello_tb.vcd");
$dumpvars(0,hello_tb);

a=0;
b=0;
#20;

a=0;
b=1;
#20;

a=1;
b=0;
#20;

a=1;
b=1;
#20;

$display("Test Complete");
end
endmodule
