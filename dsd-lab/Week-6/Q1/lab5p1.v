module mux4to1(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
reg f;
always @ (w or s)
begin
if (s==2'b00)
    f = w[0];
else if (s==2'b01)
    f = w[1];
else if (s==2'b10)
    f = w[2];
else if(s==2'b11)
    f = w[3];    
    end
endmodule

module lab5p1(a,b,c,d,f);
    input a,b,c,d;
    output f;
    wire [1:0]m;
    wire [3:0]n;
    assign m = {a , b};
    assign n[0] = (~c & ~d);
    assign n[1] = ~d;
    assign n[2] = (~c & d);
    assign n[3] = ~d;
    mux4to1 stg0(m, n, f);
endmodule
