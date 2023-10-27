module fulladd(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
assign s = (a^b^cin);
assign cout = ((a&b)|(b&cin)|(cin&a));
endmodule

module bit6(a,b,c,d,e,f,s1,s2,cout1,cout2);
input a,b,c,d,e,f;
output s1,s2,cout1,cout2;
fulladd f1(a,b,c,s1,cout1);
fulladd f2(d,e,f,s2,cout2);
endmodule
