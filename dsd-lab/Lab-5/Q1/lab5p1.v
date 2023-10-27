module mux4to1(w,s,f);
input [0:3]w;
input [1:0]s;
output reg f;

always @ *
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

module lab5p1(w,f);
    input [0:3]w;
    output f;
    wire [0:3]m;
    assign m[0] = (~w[2] & ~w[3]);
    assign m[1] = ~w[3];
    assign m[2] = (~w[2] & w[3]);
    assign m[3] = ~w[3];
    mux4to1 stg0(m, w[0:1], f);
endmodule
