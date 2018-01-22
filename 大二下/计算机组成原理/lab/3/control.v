module control(
input           clk,
input           rst,
input    [5:0]  cnt,
output   [4:0]  r1_addr, 
output   [4:0]  r2_addr, 
output   [4:0]  r3_addr,
output   [4:0]  alu_op,
output          we_reg,
output          we_ram
);
reg [4:0]  r1_addr_reg, r2_addr_reg, r3_addr_reg;
reg we_reg_reg;
reg we_ram_reg;

assign r1_addr = r1_addr_reg;
assign r2_addr = r2_addr_reg;
assign r3_addr = r3_addr_reg;
assign we_reg = we_reg_reg;
assign we_ram = we_ram_reg;

assign  alu_op = 5'h01;
assign  we_reg = clk;
always @(posedge clk or posedge rst) begin
    if (rst) begin
        r1_addr_reg <= 0;
        r2_addr_reg <= 0;
        r3_addr_reg <= 0;
    end
    else if(cnt == 1) begin
        r1_addr_reg <= 0;
        r2_addr_reg <= 0;
        r3_addr_reg <= 1;
    end
    else if(cnt == 2) begin
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

always @(posedge clk or posedge rst) begin
    if (rst) begin
        we_reg_reg <= 1;
        we_ram_reg <= 0;        
    end
    else if (cnt > 1) begin
        we_reg_reg <= 1;
        we_ram_reg <= 1;
    end
end



endmodule