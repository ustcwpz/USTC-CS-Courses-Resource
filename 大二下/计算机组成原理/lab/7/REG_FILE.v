module REG_FILE(
input               CLK,
input               rst,
input [4:0]         A1,
input [4:0]         A2,
input [4:0]         A3,
input [31:0]        WD3,
input               WE3,
output reg [31:0]   RD1,
output reg [31:0]   RD2
);

reg [31:0] data [31:0];
always@(posedge CLK or posedge rst)
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
    else if(WE3)
        data[A3]<= WD3;
end

always@(*)
begin
    if(A1)
        RD1 = data[A1];
    else
        RD1 = 32'h0;
end

always@(*)begin
    if(A2)
        RD2 = data[A2];
    else
        RD2 = 32'h0;
end
endmodule
