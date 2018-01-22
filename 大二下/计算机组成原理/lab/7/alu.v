module alu(
input   signed  [31:0]  SrcAE,
input   signed  [31:0]  SrcBE,
input           [2:0]   ALUControlE,
output  reg     [31:0]  ALUOutE
);

always@(*)
begin
    case(ALUControlE)
        3'h0: ALUOutE = 32'h0;
        3'h1: ALUOutE = SrcAE + SrcBE;
        3'h2: ALUOutE = SrcAE - SrcBE;
        3'h3: ALUOutE = SrcAE & SrcBE;
        3'h4: ALUOutE = SrcAE | SrcBE;
        3'h5: ALUOutE = SrcAE ^ SrcBE;
        3'h6: ALUOutE = ~(SrcAE | SrcBE);
        default: ALUOutE = 32'h0;
    endcase
end

endmodule
