module REG_FILE(
input clk,
input rst,
input [4:0] r1_addr,
input [4:0] r2_addr,
input [4:0] r3_addr,
input [31:0] r3_din,
input r3_wr,
output reg [31:0] r1_dout,
output reg [31:0] r2_dout
);
reg [31:0] data [31:0];
always@(posedge clk or posedge rst)
begin
    if (rst) begin
        data[0] <= 32'b1;
        data[1] <= 32'b1;
        data[2] <= 32'b1;
        data[3] <= 32'b1;
        data[4] <= 32'b1;
        data[5] <= 32'b1;
        data[6] <= 32'b1;
        data[7] <= 32'b1;
        data[8] <= 32'b1;
        data[9] <= 32'b1;
        data[10] <= 32'b1;
        data[11] <= 32'b1;
        data[12] <= 32'b1;
        data[13] <= 32'b1;
        data[14] <= 32'b1;
        data[15] <= 32'b1;
        data[16] <= 32'b1;
        data[17] <= 32'b1;
        data[18] <= 32'b1;
        data[19] <= 32'b1;
        data[20] <= 32'b1;
        data[21] <= 32'b1;
        data[22] <= 32'b1;
        data[23] <= 32'b1;
        data[24] <= 32'b1;
        data[25] <= 32'b1;
        data[26] <= 32'b1;
        data[27] <= 32'b1;
        data[28] <= 32'b1;
        data[29] <= 32'b1;
        data[30] <= 32'b1;
        data[31] <= 32'b1;
    end
    else if(r3_wr)
        data[r3_addr]<= r3_din;
end

always@(*)
begin
    if(r1_addr)
        r1_dout = data[r1_addr];
    else
        r1_dout = 32'h0;
end

always@(*)begin
    if(r2_addr)
        r2_dout = data[r2_addr];
    else
        r2_dout = 32'h0;
end
endmodule
