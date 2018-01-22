`timescale 1ns / 1ps

module top(
input clk,
input rst_n
    );

wire  [31:0]  alu_out, r1_dout, r2_dout, ram_out;
wire  [7:0]  addr_ram_out, addr_save, addr_to_reg;
wire  we_ram, we_reg;
reg  [4:0] r1 = 0, r2 = 1;

ALU ALU1(r1_dout, r2_dout, ram_out, alu_out);
REG_FILE REG_FILE1(clk, rst_n, r1, r2, addr_to_reg, ram_out, we_reg, r1_dout, r2_dout);
ram ram1(clk, we_ram, addr_save, alu_out, clk, addr_ram_out, ram_out);
control control1(clk, rst_n, ram_out, addr_ram_out, addr_save, addr_to_reg, we_ram, we_reg);


endmodule
