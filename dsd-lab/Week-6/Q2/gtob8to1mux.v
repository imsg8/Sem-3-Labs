module mux8to1(w, s, f);
  input [0:7] w;
  input [2:0]s;
  output f;
  reg f;

  always @(w or s)
    case (s) 
      0: f = w[0];
      1: f = w[1];
      2: f = w[2];
      3: f = w[3];
      4: f = w[4];
      5: f = w[5];
      6: f = w[6];
      7: f = w[7];
  end
endmodule

module gtob8to1mux(g ,b);
        input [3:0]g;
        input [3:0]b;
        wire [0:7]u3, u2, u1, u0;
  assign u3 = 8'b 00001111;
  assign u2 = 8'b 00111100;
  assign u1 = 8'b 01101001;
        assign u0 = {g[0], ~g[0], ~g[0], g[0], g[0], ~g[0], ~g[0], g[0]};

        mux8to1 stg0(m3, g[3:1], b[3]);
        mux8to1 stg1(m2, g[3:1], b[2]);
        mux8to1 stg2(m1, g[3:1], b[1]);
        mux8to1 stg3(m0, g[3:1], b[0]);
        
 endmodule
