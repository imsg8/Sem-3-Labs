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
else (s==2'b11)
    f = w[3];
    
    end
endmodule
