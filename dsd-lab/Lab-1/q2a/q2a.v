module q2a(a,b,c,d,f);
input a,b,c,d;
output f;
assign f=((~a)|(~b)|(~c)|(~d)) & (b|c) & (c|d);
endmodule
