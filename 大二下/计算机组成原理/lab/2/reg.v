module REG_FILE(
input           clk,
input           rst,
input   [4:0]   r1_addr,
input   [4:0]   r2_addr,
input   [4:0]   r3_addr,
input   [31:0]  r3_din,
input           r3_wr,
output  [31:0]  r1_dout,
output  [31:0]  r2_dout
);

reg [31:0]  regs[31:0];

always @(posedge clk or posedge rst) begin
    if (rst) begin
        regs[0] <= 32'b1;
        regs[1] <= 32'b1;
        regs[2] <= 32'b1;
        regs[3] <= 32'b1;
        regs[4] <= 32'b1;
        regs[5] <= 32'b1;
        regs[6] <= 32'b1;
        regs[7] <= 32'b1;
        regs[8] <= 32'b1;
        regs[9] <= 32'b1;
        regs[10] <= 32'b1;
        regs[11] <= 32'b1;
        regs[12] <= 32'b1;
        regs[13] <= 32'b1;
        regs[14] <= 32'b1;
        regs[15] <= 32'b1;
        regs[16] <= 32'b1;
        regs[17] <= 32'b1;
        regs[18] <= 32'b1;
        regs[19] <= 32'b1;
        regs[20] <= 32'b1;
        regs[21] <= 32'b1;
        regs[22] <= 32'b1;
        regs[23] <= 32'b1;
        regs[24] <= 32'b1;
        regs[25] <= 32'b1;
        regs[26] <= 32'b1;
        regs[27] <= 32'b1;
        regs[28] <= 32'b1;
        regs[29] <= 32'b1;
        regs[30] <= 32'b1;
        regs[31] <= 32'b1;
    end
    else if (r3_wr)begin
        regs[r3_addr] <= r3_din;
    end
end

assign r1_dout = regs[r1_addr];
assign r2_dout = regs[r2_addr];
endmodule
