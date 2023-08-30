module Decoder2_4(w, e, y);
  input [1:0] w;
  input e;
  output reg [0:3] y;

  always @(e, w)
  begin 
  y = 4'b0000;
    if (w == 2'b00 && e == 1)
      y[0] = 1;
    else if (w == 2'b01 && e == 1)
      y[1] = 1;
    else if (w == 2'b10 && e == 1)
      y[2] = 1;
    else if (w == 2'b11 && e == 1)
      y[3] = 1;
  end
endmodule

module Decoder4_16(w, e, y);
  input [3:0]w;
  input e;
  output [0:15]y;
  wire [0:3]m;

  Decoder2_4 D1(w[3:2], e, m[0:3]);
  Decoder2_4 D2(w[1:0], m[0], y[0:3]);
  Decoder2_4 D3(w[1:0], m[1], y[4:7]);
  Decoder2_4 D4(w[1:0], m[2], y[8:11]);
  Decoder2_4 D5(w[1:0], m[3], y[12:15]);
 endmodule


