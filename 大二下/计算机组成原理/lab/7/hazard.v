module hazard(
input               BranchD,
input               MemtoRegE,
input               RegWriteE,
input               MemtoRegM,
input               RegWriteM,
input               RegWriteW,
input               JumpR,
input       [4:0]   RsD,
input       [4:0]   RtD,
input       [4:0]   RsE,
input       [4:0]   RtE,
input       [4:0]   WriteRegE,
input       [4:0]   WriteRegM,
input       [4:0]   WriteRegW,
output              StallF,
output              StallD,
output              ForwardAD,
output              ForwardBD,
output              FlushE,
output reg  [1:0]   ForwardAE,
output reg  [1:0]   ForwardBE
    );

wire lwstall = ((RsD == RtE) | (RtD == RtE)) & MemtoRegE;
wire branchstall = (BranchD | JumpR ) & RegWriteE &(WriteRegE == RsD | WriteRegE == RtD) | (BranchD|JumpR ) & MemtoRegM & (WriteRegM == RsD | WriteRegM == RtD);

always@(*) begin
    ForwardAE=0;
    ForwardBE=0;
    if((RsE != 0) && (RsE == WriteRegM) && RegWriteM)
        ForwardAE=2;
    else if((RsE != 0) && (RsE == WriteRegW) && RegWriteW)
            ForwardAE=1;
    if((RtE != 0) && (RtE == WriteRegM) && RegWriteM)
        ForwardBE=2;
    else if((RtE != 0) && (RtE == WriteRegW) && RegWriteW)
            ForwardBE=1;
end

assign ForwardAD = (RsD != 0) & (RsD == WriteRegM) & RegWriteM;
assign ForwardBD = (RtD != 0) & (RtD == WriteRegM) & RegWriteM;

assign StallF = lwstall | branchstall;
assign StallD = lwstall | branchstall;
assign FlushE = lwstall | branchstall;

endmodule
