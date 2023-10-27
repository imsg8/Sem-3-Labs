module DFF(D, clk, reset, Q);
	input D, clk, reset;
	output reg Q;
	always @(posedge clk)
		if (!reset)
			Q <= D;
		else 
			Q <= 0;
endmodule

module q2(clk, reset, Q);
	input clk, reset;
	output [4:0]Q;
	DFF st1(~Q[0], clk, reset, Q[4]);
	DFF st2(Q[4], clk, reset, Q[3]);
	DFF st3(Q[3], clk, reset, Q[2]);
	DFF st4(Q[2], clk, reset, Q[1]);
	DFF st5(Q[1], clk, reset, Q[0]);
endmodule
