`timescale 1ns/1ns
`include "Decoder4_16.v"

module Decoder4_16_tb;
  reg [3:0]w;   // 4-bit input
  reg e;
  wire [0:15]y;   


Decoder4_16 D2(w, e, y);
  // Initialize simulation
  initial begin
    $dumpfile("Decoder4_16_tb.vcd");
    $dumpvars(0, Decoder4_16_tb);

    e=1;
    w = 0;
    #20;

    e=1;
    w = 1;
    #20;

    e=1;
    w = 2;
    #20;

    e=1;
    w = 3;
    #20;
    
    e=1;
    w = 4;
    #20;
    
    e=1;
    w = 5;
    #20;
    
    e=1;
    w = 6;
    #20;
    
    e=1;
    w = 7;
    #20;
    
    e=1;
    w = 8;
    #20;
    
    e=1;
    w = 9;
    #20;
    
    e=1;
    w = 10;
    #20;
    
    e=1;
    w = 11;
    #20;
    
    e=1;
    w = 12;
    #20;

    e=1;
    w = 13;
    #20;
    
    e=1;
    w = 14;
    #20;
    
    e=1;
    w = 15;
    #20;
    
    e=0;
    w = 15;
    #20;
    
    $display("Test Complete");
    $finish; // End simulation
  end
endmodule

