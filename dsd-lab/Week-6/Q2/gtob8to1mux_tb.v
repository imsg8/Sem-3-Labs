`timescale 1ns/1ns
`include "gtob8to1mux.v"

module gtob8to1mux_tb;
  reg [3:0]g;
  wire [3:0]b;

  gtob8to1mux uut(g,b);

  initial begin
    $dumpfile("gtob8to1mux_tb.vcd");
    $dumpvars(0, gtob8to1mux_tb);

    
g = 4'b 0000;
#20;

g = 4'b 0001;
#20;

g = 4'b 0010;
#20; 

g = 4'b 0011; 
#20;

g = 4'b 0100;
#20;

g = 4'b 0101;
#20;

g = 4'b 0110;
#20;

g = 4'b 0111;
#20;

g = 4'b 1000;
#20;

g = 4'b 1001;
#20;

g = 4'b 1010;
#20;

g = 4'b 1011;
#20;

g = 4'b 1100;
#20;

g = 4'b 1101;
#20;

g = 4'b 1110;
#20;

g = 4'b 1111;
#20;
    
    $display("Test Complete");
    $finish; // End simulation
  end
endmodule

