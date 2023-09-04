`timescale 1ns/1ns
`include "Encoder4_2.v"

module Encoder4_2_tb;
  reg [3:0]w;
  wire [1:0]y;
  wire z;   
integer i;

Encoder4_2 E1(w, y, z);
  initial begin
    $dumpfile("Encoder4_2_tb.vcd");
    $dumpvars(0, Encoder4_2_tb);

    for(i=0;i<15;i=i+1)
    begin
    w=i;
    #10;
    end

    $display ("Test Complete");
    $finish; 
  end
endmodule

