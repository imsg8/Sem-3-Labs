module dff1(d,clock,g);
input d, clock;
output reg g;

always @ (posedge clock)
	g<=d;
endmodule

module q1(q,clk,a);
input q, clk;
output a;
wire [5:1]i;
	dff1 s1(q,clk,i[5]);
	dff1 s2(i[5],clk,i[4]);
	dff1 s3(i[4],clk,i[3]);
	dff1 s4(i[3],clk,i[2]);
	dff1 s5(i[2],clk,i[1]);
	dff1 s6(i[1],clk,a);

endmodule
