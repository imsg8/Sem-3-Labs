`timescale 1ns/1ns
`include "lab5q4.v"

module lab5q4_tb;
	reg [2:0] w;
    wire f;

	lab5q4 l1(w, f);

    initial begin
        $dumpfile("lab5q4_tb.vcd");
        $dumpvars(0, lab5q4_tb);

		w = 3'b 000; #20;
		w = 3'b 001; #20;
		w = 3'b 010; #20;
		w = 3'b 011; #20;
		w = 3'b 100; #20;
		w = 3'b 101; #20;
		w = 3'b 110; #20;
		w = 3'b 111; #20;

        $display("Test Complete");
        $finish;
    end
endmodule

