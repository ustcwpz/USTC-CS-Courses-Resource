module top(
input clk,
input rst,
output[31:0] dout
);

wire [31:0] pcjump;
wire [31:0] pc2;
wire [31:0] pc1;
wire [31:0] pc;
wire [31:0] pcplus4;
wire [31:0] instr;
wire memtoreg;
wire memwrite;
wire branch;
wire [2:0] alucontrol;
wire alusrc;
wire regdst;
wire regwrite;
wire jump;
wire pcsrc;
wire [4:0] writereg;
reg [31:0] signimm;
wire [31:0] signimml2;
wire [31:0] srca;
wire [31:0] srcb;
wire bgtz;
wire [31:0] aluresult;
wire [31:0] writedata;
wire [31:0] pcbranch;
wire [31:0] readdata;
wire [31:0] result;

assign pcjump[31:28]= pcplus4[31:28];
assign pcjump[27:2] = instr[25:0];
assign pcjump[1:0] = 2'h0;
assign signimml2[31:2]= signimm[29:0];
assign signimml2[1:0] = 2'h0;
assign pcplus4 = pc + 32'h4;
assign pcbranch = signimml2 + pcplus4;
assign pcsrc = branch & bgtz;
assign pc2 = pcsrc ? pcbranch : pcplus4;
assign pc1 = jump ? pcjump :pc2;
assign writereg = regdst ? instr[15:11] : instr[20:16];
assign srcb = alusrc ? signimm :writedata;
assign result = memtoreg ? readdata: aluresult;
assign dout = aluresult;

always@(*)
begin
    if(instr[15])
        signimm = 32'hffff0000 + instr[15:0];
    else
        signimm = 32'h00000000 + instr[15:0];
end

pc_reg u_pc_reg(
.clk (clk ),
.rst (rst ),
.pc1 (pc1 ),
.pc (pc )
);

control u_control(
.opcode (instr[31:26]),
.memtoreg (memtoreg ),
.memwrite (memwrite ),
.branch (branch ),
.alucontrol (alucontrol ),
.alusrc (alusrc ),
.regdst (regdst ),
.regwrite (regwrite ),
.jump (jump )
);

ins_mem u_ins_mem(
.a (pc[9:2] ),
.spo (instr )
);

REG_FILE u_REG_FILE(
.clk (clk ),
.rst (rst),
.r1_addr (instr[25:21]),
.r2_addr (instr[20:16]),
.r3_addr (writereg ),
.r3_din (result ),
.r3_wr (regwrite ),
.r1_dout (srca ),
.r2_dout (writedata )
);

alu u_alu(
.alu_a (srca ),
.alu_b (srcb ),
.alu_op (alucontrol ),
.alu_out (aluresult ),
.alu_bgtz (bgtz )
);

data_mem u_data_mem(
.clk (clk ),
.we (memwrite ),
.a (aluresult[11:2] ),
.d (writedata ),
.spo (readdata ));

endmodule