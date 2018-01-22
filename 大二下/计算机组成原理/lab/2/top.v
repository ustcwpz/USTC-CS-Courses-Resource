
module top(
input           clk,
input           rst
    );

wire [31:0] r1_dout, r2_dout, r3_din;
wire [4:0]  r1_addr, r2_addr, r3_addr;
reg [4:0]  r1_addr_reg, r2_addr_reg, r3_addr_reg;

parameter  alu_op = 5'h01;
assign r3_wr = clk;
assign r1_addr = r1_addr_reg;
assign r2_addr = r2_addr_reg;
assign r3_addr = r3_addr_reg;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        r1_addr_reg <= 0;
        r2_addr_reg <= 1;
        r3_addr_reg <= 2;
    end
    else begin
        r1_addr_reg <= r1_addr_reg + 1;
        r2_addr_reg <= r2_addr_reg + 1;
        r3_addr_reg <= r3_addr_reg + 1;
    end
end

ALU ALU1(r1_dout,r2_dout,alu_op,r3_din);
REG_FILE RF(clk, rst, r1_addr, r2_addr, r3_addr, r3_din, r3_wr, r1_dout, r2_dout);

endmodule