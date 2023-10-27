module dec2to4(w, en, y);
    input [1:0] w;
    input en;
    output reg [0:3]y;
    integer k;

    always @ (w or en)
        for (k=0;k<=3;k++)
            if ((w==k) && (en==1'b1))
                y[k] = 1;
            else
                y[k] = 0;
endmodule

module lab5q4(w,f);
    input [2:0]w;
    wire [1:8]y;
    output f;
    dec2to4 stg0 (w[2:1], ~w[0], y[1:4]);
    dec2to4 stg1 (w[2:1], ~w[0], y[5:8]);
    assign f = (y[3] | y[6] | y[7] | y[8]);
endmodule
