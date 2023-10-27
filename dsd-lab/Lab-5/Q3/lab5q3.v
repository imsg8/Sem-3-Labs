module dec4to16(w, en, y);
   input [3:0]w;
   input en;
   output reg [0:15]y;
   integer k;
   
   always @ (w or en)
      for (k=0;k<=15;k++)
         if ((w==k) && (en==1))
            	y[k] = 1;
         else 
        	y[k] = 0;
endmodule

 module lab5q3 (w,f);
    input [3:0]w;
    wire [0:15]y;
    output f;
    dec4to16 stg0(w[3:0], 1'b1, y[0:15]);
    assign f = {y[1], y[4], y[6], y[8], y[9], y[13], y[15]};
 endmodule
