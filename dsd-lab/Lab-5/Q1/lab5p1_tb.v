`timescale 1ns/1ns
`include "lab5p1.v"

module lab5p1_tb;
  reg [0:3]w;
  wire f;
  integer k;
  
  lab5p1 tb1(w,f);
  // Initialize simulation
  initial begin
    $dumpfile("lab5p1_tb.vcd");
    $dumpvars(0, lab5p1_tb);
	
	for( k=0;k<15;k++)
	begin
	 w = k;
	 #20;
	 end	
	
    $display("Test Complete");
    $finish; // End simulation
  end
endmodule
