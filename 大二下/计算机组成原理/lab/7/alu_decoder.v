
module alu_decoder(
    input [2:0]ALUOp,
    input [5:0]Funct,
    output reg [2:0]ALUControl
   );

    always@(*)
    begin
    case(ALUOp)
        0:  ALUControl<=1;
        1:  ALUControl<=2;
        2:
        begin
            case(Funct)
                6'b100000: ALUControl<=1;//add
                6'b100001: ALUControl<=1;//addu
                6'b100010: ALUControl<=2;//sub
                6'b100011: ALUControl<=2;//subu
                6'b100100: ALUControl<=3;//and
                6'b100101: ALUControl<=4;//or
                6'b100110: ALUControl<=5;//xor
                6'b100111: ALUControl<=6;//nor
                6'b001000: ALUControl<=0;//jr
                default:      ALUControl<=3'b000;
            endcase
        end
        3:  ALUControl<=3;
        4:  ALUControl<=4;
        5:  ALUControl<=5;
        6:  ALUControl<=6;
        7:  ALUControl<=7;
        default: ALUControl<=1;
    endcase
    end

endmodule
