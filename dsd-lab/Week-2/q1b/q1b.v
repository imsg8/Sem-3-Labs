module q1b(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=(b&(~c))|(c&(~d));
endmodule
