`timescale 1ns / 1ps

module top(
input           clk,
input           rst
    );
wire div;
wire [31:0] r1_dout, r2_dout, r3_din;
wire [4:0]  r1_addr, r2_addr, r3_addr;
wire [4:0]  alu_op;
wire [5:0]  cnt;
wire we_reg;
wire we_ram;
wire [31:0] doutb;
reg div_reg;
reg [31:0] r3_din_reg;
reg [5:0]  cnt_reg;
wire [31:0] alu_out;

assign div = div_reg;
assign cnt = cnt_reg;
assign r3_din = r3_din_reg;

ALU ALU1(r1_dout, r2_dout, alu_op, alu_out);
REG_FILE RF(clk, rst, r1_addr, r2_addr, r3_addr, r3_din, we_reg, r1_dout, r2_dout);
control CTR(clk, rst, cnt, r1_addr, r2_addr, r3_addr, alu_op, we_reg, we_ram);
myram ram(clk, we_ram, r3_addr, r3_din, clk, r3_addr, doutb);

always @(posedge clk or posedge rst) begin
    if (rst) begin
        cnt_reg <= 0; 
    end
    else if(cnt_reg < 36)begin
        cnt_reg <= cnt_reg + 1;
    end
    else cnt_reg <= 0;
end

always @(posedge clk or posedge rst) begin
    if (rst) begin
        r3_din_reg <= doutb;        
    end
    else if (cnt <= 4) begin
        r3_din_reg <= doutb;        
    end
    else begin
        r3_din_reg <= alu_out;
    end
end

always @(posedge clk or posedge rst) begin
    if (rst) begin
        div_reg <= 0;
    end
    else begin
        case (div_reg)
            0 : div_reg <= 1;
            1 : div_reg <= 0;
          endcase
    end
end

endmodule