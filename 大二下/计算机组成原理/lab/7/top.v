module top(
input               CLK,
input               rst
);

wire    [31:0]      PC;
wire    [31:0]      PCPlus4F;
reg     [31:0]      PCPlus4D;
wire    [31:0]      PCBranchD;
reg     [31:0]      PCF;
wire                BranchD;     
wire                Jump;
wire                JumpR;

wire    [31:0]      instr;
reg     [31:0]      instrD;
wire    [31:0]      SignImmD;
reg     [31:0]      SignImmE;

wire                EN1;
wire                EN2;
wire                RegWriteD;   
reg                 RegWriteE;   
reg                 RegWriteM;   
reg                 RegWriteW;   
wire                MemtoRegD;   
reg                 MemtoRegE;   
reg                 MemtoRegM;   
reg                 MemtoRegW;   
wire                MemWriteD;   
reg                 MemWriteE;   
reg                 MemWriteM;   

wire    [2:0]       ALUControlD; 
wire    [2:0]       ALUOp; 
reg     [2:0]       ALUControlE; 
wire                ALUSrcD;     
reg                 ALUSrcE;     
wire                RegDstD;     
reg                 RegDstE;     
wire    [31:0]      RD1;
wire    [31:0]      RDreal1;
reg     [31:0]      RDrealreal1;
wire    [31:0]      RD2;
wire    [31:0]      RDreal2;
reg     [31:0]      RDrealreal2;
wire    [1:0]       PCSrcD;
wire                EqualD;

wire    [4:0]       RsD = instrD[25:21];
wire    [4:0]       RtD = instrD[20:16];
wire    [4:0]       RdD = instrD[15:11];
reg     [4:0]       RsE;
reg     [4:0]       RtE;
reg     [4:0]       RdE;

wire    [31:0]      WriteDataE;
reg     [31:0]      WriteDataM;
wire    [31:0]      ALUOutE;
reg     [31:0]      ALUOutM;
reg     [31:0]      ALUOutW;
wire    [4:0]       WriteRegE;
reg     [4:0]       WriteRegM;
reg     [4:0]       WriteRegW;
wire    [31:0]      SrcAE;
wire    [31:0]      SrcBE;
wire    [31:0]      ReadDataM;
reg     [31:0]      ReadDataW;

wire                StallF; 
wire                StallD; 
wire                ForwardAD;
wire                ForwardBD;
wire    [1:0]       ForwardAE;
wire    [1:0]       ForwardBE;
wire                FlushE;
wire                CLR;
wire    [31:0]      PCJump;
wire    [31:0]      PCJumpR;
wire    [31:0]      ResultW = MemtoRegW ? ReadDataW : ALUOutW;



assign PC = PCSrcD == 0 ? PCPlus4F : PCSrcD == 1 ? PCBranchD : PCJumpR;
assign EN1 = ~StallF;
assign EN2 = ~StallD;
assign PCPlus4F = PCF + 32'd4;
assign PCSrcD[0] = EqualD && BranchD;
assign PCSrcD[1] = Jump;
assign RDreal1 = ForwardAD ? ALUOutM : RD1;
assign RDreal2 = ForwardBD ? ALUOutM : RD2;

assign CLR = PCSrcD || Jump || JumpR;
assign SrcAE = ForwardAE == 0 ? RDrealreal1 : (ForwardAE == 1 ? ResultW : ALUOutM);
assign WriteDataE = ForwardBE == 0 ? RDrealreal2 : (ForwardBE == 1 ? ResultW : ALUOutM);
assign SrcBE = ALUSrcE ? SignImmE : WriteDataE;
assign WriteRegE = RegDstE ? RdE : RtE;
assign PCJump[27:0] = instrD[25:0] << 2;
assign PCJump[31:28] = PCPlus4D[31:28];
assign PCJumpR = JumpR ? RDreal1 : PCJump;
assign PCBranchD = (SignImmD << 2) + PCPlus4D;


always@(posedge CLK or posedge rst) begin
    if(rst)begin
        instrD <= 0;
        PCPlus4D <= 0;
    end
    else if(EN2) begin
        if(CLR)
        begin
            instrD<=0;
            PCPlus4D<=0;
        end
        else
        begin
            instrD<=instr;
            PCPlus4D<=PCPlus4F;
        end
    end
end

always@(posedge CLK or posedge rst) begin
    if(rst)begin
        RDrealreal1 <= 0;
        RDrealreal2 <= 0;
        RsE <= 0;
        RtE <= 0;
        RdE <= 0;
        RegWriteE <= 0;
        MemtoRegE <= 0;
        MemWriteE <= 0;
        ALUControlE <= 0;
        ALUSrcE <= 0;
        RegDstE <= 0;
        SignImmE <= 0;
    end
    else begin
        RDrealreal1 <= FlushE ? 0 : RD1 ;
        RDrealreal2 <= FlushE ? 0 : RD2 ;
        RsE <= FlushE ? 0 : RsD;
        RtE <= FlushE ? 0 : RtD;
        RdE <= FlushE ? 0 : RdD;
        RegWriteE <= FlushE ? 0 : RegWriteD;
        MemtoRegE <= FlushE ? 0 : MemtoRegD;
        MemWriteE <= FlushE ? 0 : MemWriteD;
        ALUControlE <= FlushE ? 0 : ALUControlD;
        ALUSrcE <= FlushE ? 0 : ALUSrcD;
        RegDstE <= FlushE ? 0 : RegDstD;
        SignImmE <= FlushE ? 0 : SignImmD;
    end
        
end

always@(posedge CLK or posedge rst) begin
    if(rst)begin
        PCF <= 0;

        RegWriteM <= 0;
        MemtoRegM <= 0;
        MemWriteM <= 0;
        ALUOutM <= 0;
        WriteDataM <= 0;
        WriteRegM <= 0;
    end
    else begin
        if(EN1)
            PCF <= PC;
        RegWriteM <= RegWriteE;
        MemtoRegM <= MemtoRegE;
        MemWriteM <= MemWriteE;
        ALUOutM <= ALUOutE;
        WriteDataM <= WriteDataE;
        WriteRegM <= WriteRegE;
    end
end

always@(posedge CLK or posedge rst) begin
    if(rst) begin
        RegWriteW <= 0;
        MemtoRegW <= 0;
        ReadDataW <= 0;
        ALUOutW <= 0;
        WriteRegW <= 0;
    end
    else begin
        RegWriteW <= RegWriteM;
        MemtoRegW <= MemtoRegM;
        ReadDataW <= ReadDataM;
        ALUOutW <= ALUOutM;
        WriteRegW <= WriteRegM;
    end
    
end

control      u_control(
.Op          (instrD[31:26]       ),
.Funct       (instrD[5:0]         ),
.RegWriteD   (RegWriteD           ),
.MemtoRegD   (MemtoRegD           ),
.MemWriteD   (MemWriteD           ),
.ALUOp       (ALUOp               ),
.ALUSrcD     (ALUSrcD             ),
.RegDstD     (RegDstD             ),
.BranchD     (BranchD             ),
.Jump        (Jump               ),
.JumpR       (JumpR               )
);



REG_FILE    u_REG_FILE(
.CLK        (CLK                  ),
.rst        (rst                  ),
.A1         (instrD[25:21]        ),
.A2         (instrD[20:16]        ),
.A3         (WriteRegW            ),
.WD3        (ResultW              ),
.WE3        (RegWriteW            ),
.RD1        (RD1                  ),
.RD2        (RD2                  )
);

InsMem     u_InsMem(
            PCF[7:2],
            instr
);

DataMem    u_DataMem(
            ALUOutM[6:2],
            WriteDataM,
            CLK,
            MemWriteM,
            ReadDataM
);

sign_extend  u_sign_extend(
            instrD[15:0],
            SignImmD
);

alu          u_alu(
.SrcAE       (SrcAE               ),
.SrcBE       (SrcBE               ),
.ALUControlE (ALUControlE         ),
.ALUOutE     (ALUOutE             )
);

alu_decoder  u_alu_decoder(
.ALUOp       (ALUOp               ),
.Funct       (instrD[5:0]         ),
.ALUControl  (ALUControlD         )
);

hazard       u_hazard(
.WriteRegE   (WriteRegE           ),
.WriteRegM   (WriteRegM           ),
.WriteRegW   (WriteRegW           ),
.RegWriteE   (RegWriteE           ),
.RegWriteM   (RegWriteM           ),
.RegWriteW   (RegWriteW           ),
.MemtoRegE   (MemtoRegE           ),
.MemtoRegM   (MemtoRegM           ),
.BranchD     (BranchD             ),
.JumpR       (JumpR               ),
.RtE         (RtE                 ),
.RsE         (RsE                 ),
.RtD         (RtD                 ),
.RsD         (RsD                 ),
.StallF      (StallF              ),
.StallD      (StallD              ),
.ForwardAD   (ForwardAD           ),
.ForwardBD   (ForwardBD           ),
.FlushE      (FlushE              ),
.ForwardAE   (ForwardAE           ),
.ForwardBE   (ForwardBE           )
);

judge        u_judge(
.RDreal1     (RDreal1             ),
.RDreal2     (RDreal2             ),
.Op          (instrD[31:26]       ),
.RtD         (RtD                 ),
.EqualD      (EqualD              )    
);



endmodule
