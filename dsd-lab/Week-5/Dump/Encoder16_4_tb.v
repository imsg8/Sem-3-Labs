`timescale 1ns/1ns
`include "Encoder16_4.v"

module Encoder16_4_tb();
    reg [15:0] w;
    wire [3:0] y;
    wire z;

    // Instantiate the Encoder16_4 module
    Encoder16_4 q(w, y, z);

    initial begin
        $dumpfile("Encoder16_4_tb.vcd");
        $dumpvars(0, Encoder16_4_tb);

        // Test case 1: Set w to a value with two '1's
        w = 16'b0000000000000011; 
        #20;

        // Test case 2: Set w to a value with one '1' at a different position
        w = 16'b1010000000000000; 
        #20;

        // Test case 3: Set w to a value with one '1' at a different position
        w = 16'b0000000000000100; 
        #20;

        // Test case 4: Set w to a value with one '1' at a different position
        w = 16'b0010000000000000; 
        #20;

        $display("Test Complete");
        $finish;
    end
endmodule

