`timescale 1ns / 1ps

module control(
input clk,
input rst_n,
input [31:0] ram_out,
output reg [7:0] addr_ram_out,
output reg [7:0] address2,
output reg [7:0] address3,
output reg we_ram,
output reg we_reg
    );

reg [1:0] current_state = 0, next_state = 1;
reg [7:0] addr_base_number = 0, addr_op = 8'd100, addr_save = 8'd200, addr_to_reg = 0;
parameter s0 = 2'd0, s1 = 2'd1, s2 = 2'd2, s3 = 2'd3;
reg is_on = 1;

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        is_on <= 1;
    else if(current_state == s3 && ram_out == 32'hffffffff)
        is_on <= 0;
end

always@(*) begin
    case(current_state)
        s0:  next_state = s1;
        s1:  next_state = s2;
        s2:  next_state = s3;
        s3:  next_state = s0;
        default: next_state = s0;
    endcase
end

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        current_state <= 0;
    else if(is_on)
        current_state <= next_state;
end

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        addr_base_number <= 0;
    else if(current_state == s1||current_state == s0)
        addr_base_number <= addr_base_number + 1;
end

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        addr_to_reg <= 0;
    else if(current_state == s0)
        addr_to_reg <= 0;
    else if(current_state == s1)
        addr_to_reg <= 1;
end

always@(*) begin
    address3 = addr_to_reg;
end

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        addr_op <= 8'd100;
    else if(current_state == s2)
        addr_op <= addr_op + 1;
end

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        addr_save <= 8'd200;
    else if(current_state == s3)
        addr_save <= addr_save + 1;
end

always@(posedge clk,negedge rst_n) begin
    address2 = addr_save;
end

always@(*) begin
    if(~rst_n)
        addr_ram_out = 0;
    else begin
        case(current_state)
            s0:  addr_ram_out = addr_base_number;
            s1:  addr_ram_out = addr_base_number;
            s2:  addr_ram_out = addr_op;
            s3:  addr_ram_out = addr_base_number;
        default: addr_ram_out = 0;
        endcase
    end
end

always@(negedge clk,negedge rst_n) begin
    if(~rst_n)
        we_ram = 0;
    else begin
        case(current_state)
            s0:  we_ram = 0;
            s1:  we_ram = 0;
            s2:  we_ram = 0;
            s3:  we_ram = 1;
            default: we_ram = 0;
        endcase
    end
end

always@(posedge clk,negedge rst_n) begin
    if(~rst_n)
        we_reg = 0;
    else begin
        case(current_state)
            s0:  we_reg = 0;
            s1:  we_reg = 1;
            s2:  we_reg = 1;
            s3:  we_reg = 0;
            default: we_reg = 0;
        endcase
    end
end

endmodule
