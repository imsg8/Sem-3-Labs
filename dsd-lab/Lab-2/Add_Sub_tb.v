`timescale 1ns/1ns
`include "Add_Sub.v"
module Add_Sub_tb;
reg cin;
reg [3:0]X,Y;
wire [3:0]S;
wire cout;
Add_Sub S(X,Y,S,cin,cout);
initial begin
	$dumpfile("Add_Sub_tb.vcd");
	$dumpvars(0,Add_Sub_tb);
	//Addition_no_carry
	X=3;
	Y=2;
	cin=0;
	#5
	$display("Test Case 1: X=%b,Y=%b,cin=%b,res=%b,overflow=%b",X,Y,cin,S,cout);
	//Addition_with_carry
	X=4'b1011;
	Y=4'b1011;
	cin=0;
	#5
	$display("Test Case 2: X=%b,Y=%b,cin=%b,res=%b,overflow=%b",X,Y,cin,S,cout);
	//Sub_no_carry
	X=5;
	Y=-2;
	cin=1;
	#5
	$display("Test Case 3: X=%b,Y=%b,cin=%b,res=%b,overflow=%b",X,Y,cin,S,cout);
	//sub
	X=4;
	Y=4;
	cin=1;
	#5
	$display("Test Case 4: X=%b,Y=%b,cin=%b,res=%b,overflow=%b",X,Y,cin,S,cout);
	//add
	X=1;
	Y=2;
	cin=0;
	#5
	$display("Test Case 5: X=%b,Y=%b,cin=%b,res=%b,overflow=%b",X,Y,cin,S,cout);
	$display("Test_completed");
	end
endmodule
