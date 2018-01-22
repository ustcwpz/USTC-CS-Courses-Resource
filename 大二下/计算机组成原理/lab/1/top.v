`timescale 1ns / 1ps

module top(
input [31:0] alu_a,
input [31:0] alu_b,
input [4:0] alu_op,
output [31:0] result
    );
     
wire [31:0] alu_out1,alu_out2,alu_out3;

ALU ALU1(alu_a,alu_b,alu_op,alu_out1);
ALU ALU2(alu_out1,alu_b,alu_op,alu_out2);
ALU ALU3(alu_out2,alu_out1,alu_op,alu_out3);
ALU ALU4(alu_out3,alu_out2,alu_op,result);

endmodule