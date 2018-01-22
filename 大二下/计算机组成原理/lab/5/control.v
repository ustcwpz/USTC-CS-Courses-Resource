module control(
input [5:0] opcode,
output reg memtoreg,
output reg memwrite,
output reg branch,
output reg [2:0] alucontrol,
output reg alusrc,
output reg regdst,
output reg regwrite,
output reg jump
);
always@(*)
begin
    case(opcode)
        6'b001000: //la
            begin
                memtoreg = 0;
                memwrite = 0;
                branch = 0;
                alucontrol = 3'h1;
                alusrc = 1;
                regdst = 0;
                regwrite = 1;
                jump = 0;
            end
        6'b100011: //lw
            begin
                memtoreg = 1;
                memwrite = 0;   
                branch = 0;
                alucontrol = 3'h1;
                alusrc = 1;
                regdst = 0;
                regwrite = 1;
                jump = 0;
            end
        6'b101011: //sw
            begin
                memtoreg = 0;
                memwrite = 1;
                branch = 0;
                alucontrol = 3'h1;
                alusrc = 1;
                regdst = 0;
                regwrite = 0;
                jump = 0;
            end
        6'b001000: //addi
            begin
                memtoreg = 0;
                memwrite = 0;
                branch = 0;
                alucontrol = 3'h1;
                alusrc = 1;
                regdst = 0;
                regwrite = 1;
                jump = 0;
            end
        6'b000000: //add
            begin
                memtoreg = 0;
                memwrite = 0;
                branch = 0;
                alucontrol = 3'h1;
                alusrc = 0;
                regdst = 1;
                regwrite = 1;
                jump = 0;
            end
        6'b000111: //bgtz
            begin
                memtoreg = 0;
                memwrite = 0;
                branch = 1;
                alucontrol = 3'h4;
                alusrc = 0;
                regdst = 0;
                regwrite = 0;
                jump = 0;
            end
        6'b000010: //jump
            begin
                memtoreg = 0;
                memwrite = 0;
                branch = 0;
                alucontrol = 3'h0;
                alusrc = 0;
                regdst = 0;
                regwrite = 0;
                jump = 1;
            end
        default:
            begin
                memtoreg = 0;
                memwrite = 0;
                branch = 0;
                alucontrol = 3'h0;
                alusrc = 0;
                regdst = 0;
                regwrite = 0;
                jump = 0;
            end
        endcase
end

endmodule