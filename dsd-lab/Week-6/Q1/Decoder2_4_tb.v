`timescale 1ns/1ns
`include "Decoder2_4.v"

module Decoder2_4_tb;
  reg [1:0]w;   // 4-bit input
  reg e;
  wire [0:3]y;   


Decoder2_4 D1(w, e, y);
  // Initialize simulation
  initial begin
    $dumpfile("Decoder2_4_tb.vcd");
    $dumpvars(0, Decoder2_4_tb);

    // Test case 1: Select input 0
    e=1;
    w = 2'b00;
    #20;

    // Test case 2: Select input 1
    e=1;
    w = 2'b01;
    #20;

    // Test case 3: Select input 2
    e=1;
    w = 2'b10;
    #20;

    // Test case 4: Select input 3
    e=1;
    w = 2'b11;
    #20;
    
    //Don't care case
    e=0;
    w = 4'b11;
    #20;


    $finish; // End simulation
  end
endmodule

