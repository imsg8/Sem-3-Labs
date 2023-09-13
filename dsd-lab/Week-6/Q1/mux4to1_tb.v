`timescale 1ns/1ns
`include "lab5p1.v"

module lab5p1_tb;
  reg a,b,c,d;
  wire f;
  
  lab5p1 tb1(a,b,c,d,f);
  // Initialize simulation
  initial begin
    $dumpfile("lab5p1_tb.vcd");
    $dumpvars(0, lab5p1_tb);

    a=0; b=0; c=0; d=0; #20;
    a=0; b=0; c=0; d=1; #20;
    a=0; b=0; c=1; d=0; #20;
    a=0; b=0; c=1; d=1; #20;
    a=0; b=1; c=0; d=0; #20;
    a=0; b=1; c=0; d=1; #20;
    a=0; b=1; c=1; d=0; #20;
    a=0; b=1; c=1; d=1; #20;
    a=1; b=0; c=0; d=0; #20;
    a=1; b=0; c=0; d=1; #20;
    a=1; b=0; c=1; d=0; #20;
    a=1; b=0; c=1; d=1; #20;
    a=1; b=1; c=0; d=0; #20;
    a=1; b=1; c=0; d=1; #20;
    a=1; b=1; c=1; d=0; #20;
    a=1; b=1; c=1; d=1; #20;

    $display("Test Complete");
    $finish; // End simulation
  end
endmodule
