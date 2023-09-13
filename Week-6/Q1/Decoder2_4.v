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

