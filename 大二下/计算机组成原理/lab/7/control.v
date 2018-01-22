module control(
input   [5:0]       Op,
input   [5:0]       Funct,
output  reg         RegWriteD,
output  reg         MemtoRegD,
output  reg         MemWriteD,
output  reg [2:0]   ALUOp,
output  reg         ALUSrcD,
output  reg         RegDstD,
output  reg         BranchD,
output  reg         Jump,
output  reg         JumpR
    );
parameter Rtype=6'b000000;
parameter addi=6'b001000;
parameter addiu=6'b001001;
parameter andi=6'b001100;
parameter ori=6'b001101;
parameter xori=6'b001110;
parameter lw=6'b100011;
parameter sw=6'b101011;
parameter beq=6'b000100;
parameter bgez=6'b000001;
parameter bgtz=6'b000111;
parameter blez=6'b000110;
parameter bltz=6'b000001;
parameter bne=6'b000101;
parameter j=6'b000010;
always@(*) begin
    case(Op)
        Rtype  begin
            if(Funct==6'b001000)//jr
            begin
                RegWriteD=0;
                MemtoRegD=0;
                MemWriteD=0;
                ALUSrcD=0;
                RegDstD=0;
                BranchD=0;
                Jump=1;
                JumpR=1;
                ALUOp=2;
            end
            else
            begin
                RegWriteD=1;
                MemtoRegD=0;
                MemWriteD=0;
                ALUSrcD=0;
                RegDstD=1;
                BranchD=0;
                Jump=0;
                JumpR=0;
                ALUOp=2;
            end
        end
        addi: begin
            RegWriteD=1;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        addiu  begin
            RegWriteD=1;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        andi: begin
            RegWriteD=1;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=3;
        end
        ori: begin
            RegWriteD=1;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=4;
        end
        xori: begin
            RegWriteD=1;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=5;
        end
        lw: begin
            RegWriteD=1;
            MemtoRegD=1;
            MemWriteD=0;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        sw: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=1;
            ALUSrcD=1;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        beq: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=1;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        bne: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=1;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        blez: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=1;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        bgtz: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=1;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        bltz: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=1;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        bgez: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=1;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        j: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=0;
            Jump=1;
            JumpR=0;
            ALUOp=0;
        end
        default: begin
            RegWriteD=0;
            MemtoRegD=0;
            MemWriteD=0;
            ALUSrcD=0;
            RegDstD=0;
            BranchD=0;
            Jump=0;
            JumpR=0;
            ALUOp=0;
        end
        endcase
end
endmodule
