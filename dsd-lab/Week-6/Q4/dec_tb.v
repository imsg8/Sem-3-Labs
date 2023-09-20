`timescale 1ns/1ns
`include "dec.v"

module dec_tb;
	reg [2:0] w;
    wire f;

	dec d1(w, f);

    initial begin
        $dumpfile("dec_tb.vcd");
        $dumpvars(0, dec_tb);

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
