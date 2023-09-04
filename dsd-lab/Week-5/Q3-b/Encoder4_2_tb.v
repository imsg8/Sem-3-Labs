`timescale 1ns/1ns
`include "Encoder4_2.v"

module Encoder4_2_tb;
  reg [3:0]w;   // 4-bit input
  wire [1:0]y;
  wire z;   


Encoder4_2 E1(w, y, z);
  // Initialize simulation
  initial begin
    $dumpfile("Encoder4_2_tb.vcd");
    $dumpvars(0, Encoder4_2_tb);

    // Test case 1: Select input 0
    w = 4'b0001;
    #20;

    // Test case 2: Select input 1
    w = 4'b0010;
    #20;

    // Test case 3: Select input 2
    w = 4'b0100;
    #20;


    // Test case 4: Select input 3
    w = 4'b1000;
    #20;

    //Don't care case
    w = 4'b0000;
    #20;

    $display ("Test Complete");
    $finish; // End simulation
  end
endmodule

