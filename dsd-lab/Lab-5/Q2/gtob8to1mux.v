module gtob8to1mux(g,b);
input [3:0]g;
output [3:0]b;
wire [0:7]m3,m2,m1,m0;
  assign m3=8'b00001111;
  assign m2=8'b00111100;
  assign m1=8'b01101001;
  assign m0={g[0],~g[0],~g[0],g[0],~g[0],g[0],g[0],~g[0]};
    mux8to1 st0(g[3:1],m3,b[3]);
    mux8to1 st1(g[3:1],m2,b[2]);
    mux8to1 st2(g[3:1],m1,b[1]);
    mux8to1 st3(g[3:1],m0,b[0]);
endmodule

module mux8to1(s,w,f);
input [0:7]w;
input [2:0]s;
output reg f;
always @(w or s)
case(s)
3'b000:f=w[0];
3'b001:f=w[1];
3'b010:f=w[2];
3'b011:f=w[3];
3'b100:f=w[4];
3'b101:f=w[5];
3'b110:f=w[6];
3'b111:f=w[7];
endcase
endmodule

