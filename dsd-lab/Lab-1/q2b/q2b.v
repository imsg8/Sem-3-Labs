module q2b                                              (a,b,c,d,f);
input a,b,c,d;
output f;
assign f=(~c|d) & (~a|d) & (a|~b|~c|~d);
endmodule
