module dff(d,clock,g);
inout d, clock;
output reg g;
always @ (posedge clock)
	g<=d;
endmodule
module q1(q,clk,a);
input q, clk;
output reg a;
wire [5:1]i;
dff s1(g,clk,i[5]);
dff s2(i[5],clk,i[4]);
dff s3(i[4],clk,i[3]);
dff s4(i[3],clk,i[2]);
dff s5(i[2],clk,i[1]);
dff s6(i[1],clk,a);
endmodule
