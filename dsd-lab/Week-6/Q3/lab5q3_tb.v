`timescale 1ns/1ns
`include "lab5q3.v"

module lab5q3_tb;
  reg [3:0]w;
  wire f;

  lab5q3 l1(w,f);
  initial begin
        $dumpfile("Encoder4_2_tb.vcd");
        $dumpvars(0, Encoder4_2_tb);

w = 4'b 0000;
#20;

w = 4'b 0001;
#20;

w = 4'b 0010;
#20; 

w = 4'b 0011; 
#20;

w = 4'b 0100;
#20;

w = 4'b 0101;
#20;

w = 4'b 0110;
#20;

w = 4'b 0111;
#20;

w = 4'b 1000;
#20;

w = 4'b 1001;
#20;

w = 4'b 1010;
#20;

w = 4'b 1011;
#20;

w = 4'b 1100;
#20;

w = 4'b 1101;
#20;

w = 4'b 1110;
#20;

w = 4'b 1111;
#20;

    
    $display ("Test Complete");
    $finish; 
  end
endmodule

