module q1(reset, clk, Q);
	input clk, reset;
	output reg [3:0]Q;
	always @(posedge clk or posedge reset)
	begin
		if (reset)
			Q <= 4'b1000;
		else
		begin
			Q[3] <= Q[0];
			Q[2] <= Q[3];
			Q[1] <= Q[2];
			Q[0] <= Q[1];
		end
	end
endmodule
