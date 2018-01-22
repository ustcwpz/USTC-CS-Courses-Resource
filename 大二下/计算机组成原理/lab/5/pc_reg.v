module pc_reg(
input clk,
input rst,
input [31:0] pc1,
output reg [31:0] pc
);

always@(posedge clk or posedge rst)
begin
    if(rst)
        pc <= 32'h0;
    else
        pc <= pc1;
end
endmodule