`timescale 1ns/1ns
`include "Encoder16_4.v"

module Encoder16_4_tb();
    reg [15:0] w;
    wire [3:0] y;
    wire z;

    Encoder16_4 q(w, y, z);

    initial begin
        $dumpfile("Encoder16_4_tb.vcd");
        $dumpvars(0, Encoder16_4_tb);

        w = 16'b0000000000000000; 
        #20;
        
        w = 16'b0000000000000001; 
        #20;

	w = 16'b0000000000000010; 
        #20;
        
        w = 16'b0000000000000011; 
        #20;
        
        w = 16'b0000000000000100; 
        #20;
        
        w = 16'b0000000000000101; 
        #20;
        
        w = 16'b0000000000000110; 
        #20;
        
        w = 16'b0000000000000111; 
        #20;
        
        w = 16'b0000000000001000; 
        #20;
        
        w = 16'b0000000000001001; 
        #20;
        
        w = 16'b0000000000001010; 
        #20;
        
        w = 16'b0000000000001011; 
        #20;
        
        w = 16'b0000000000001100; 
        #20;
        
        w = 16'b0000000000001101; 
        #20;
        
        w = 16'b0000000000001110; 
        #20;
        
        w = 16'b0000000000001111; 
        #20;


        $display("Test Complete");
        $finish;
    end
endmodule

