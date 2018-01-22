module judge(
    input signed [31:0] RDreal1,
    input signed [31:0] RDreal2,
    input        [5:0]  Op,
    input        [4:0]  RtD,
    output reg          EqualD
    );
    
    parameter beq = 6'b000100;
    parameter bgez = 6'b000001;
    parameter bgtz = 6'b000111;
    parameter blez = 6'b000110;
    parameter bltz = 6'b000001;
    parameter bne = 6'b000101;
    
    always@(*)
    begin
        case(Op)
        beq:    if(RDreal1 == RDreal2)
                EqualD = 1;
                else
                EqualD = 0;
        bgez:   if(RtD == 5'b00001)//bgez 
                        begin
                            if(RDreal1> = 0)
                            EqualD = 1;
                            else
                            EqualD = 0;
                        end
                        else
                        begin
                            if(RDreal1<0)//bltz
                            EqualD = 1;
                            else
                            EqualD = 0;
                        end
        bgtz:   if(RDreal1 > 0)
                EqualD = 1;
                else
                EqualD = 0;
        blez:   if(RDreal1 <= 0)
                EqualD = 1;
                else
                EqualD = 0;
        bne:    if(RDreal1 != RDreal2)
                EqualD = 1;
                else
                EqualD = 0;
        default:EqualD = 0;
        endcase
    end

endmodule
