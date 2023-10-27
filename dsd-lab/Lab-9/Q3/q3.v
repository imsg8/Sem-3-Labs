module TFF(t, clk, reset, q);
	input t, clk, reset;
	output reg q;
	always @(negedge clk)
	begin
		if (reset)
			q <= 0;
		else if (t)
			q <= ~q;
	end
endmodule

module q3(clk, reset, Q);
	input clk, reset;
	output [3:0]Q;
	TFF s0(1'b1, clk, reset, Q[0]);
	TFF s1(1'b1, Q[0], reset, Q[1]);
	TFF s2(1'b1, Q[1], reset, Q[2]);
	TFF s3(1'b1, Q[2], reset, Q[3]);
endmodule
	
