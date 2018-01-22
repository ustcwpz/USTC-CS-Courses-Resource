
module sign_extend(
    input [15:0]din,
    output [31:0]dout
    );
     
assign dout[15:0]=din[15:0];
assign dout[31]=din[15];
assign dout[30]=din[15];
assign dout[29]=din[15];
assign dout[28]=din[15];
assign dout[27]=din[15];
assign dout[26]=din[15];
assign dout[25]=din[15];
assign dout[24]=din[15];
assign dout[23]=din[15];
assign dout[22]=din[15];
assign dout[21]=din[15];
assign dout[20]=din[15];
assign dout[19]=din[15];
assign dout[18]=din[15];
assign dout[17]=din[15];
assign dout[16]=din[15];

endmodule
