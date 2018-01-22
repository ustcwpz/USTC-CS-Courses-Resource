module control(
input   [5:0]		opcode,
input   [5:0]		funct,
input               clk,
input               rst,
output  reg         iord,
output  reg         memwrite,
output  reg         irwrite,
output  reg         pcwrite,
output  reg         branch,
output  reg [1:0]   pcsrc,
output  reg [2:0]   alucontrol,
output  reg [1:0]   alusrcb,
output  reg         alusrca,
output  reg         regwrite,
output  reg         memtoreg,
output  reg         regdst
    );

reg    [3:0]  curr_state;
reg    [3:0]  next_state;

always@(posedge clk or posedge rst)
begin
	if(rst)
		curr_state	<=	4'h0;
	else
		curr_state	<=	next_state;
end

always@(*)
begin
	case(curr_state)
		4'd0:	
            next_state	=	4'd1;
		4'd1:	
        begin
			case(opcode)
				6'b100011:	next_state = 4'd2;
				6'b101011:	next_state = 4'd2;
				6'b000000:	next_state = 4'd6;
				6'b000111:	next_state = 4'd8;
				6'b001000:	next_state = 4'd9;
				6'b000010:	next_state = 4'd11;
				default:	next_state = 4'd0;
			endcase
		end
		4'd2:	
            begin
				case(opcode)
					6'b100011:	next_state = 4'd3;
					6'b101011:	next_state = 4'd5;
					default:	next_state = 4'd0;
				endcase
			end
		4'd3:	next_state = 4'd12;
		4'd4:	next_state = 4'd0;
		4'd5:	next_state = 4'd13;
		4'd6:	next_state = 4'd7;
		4'd7:	next_state = 4'd0;
		4'd8:	next_state = 4'd15;
		4'd9:	next_state = 4'd10;
		4'd10:	next_state = 4'd0;
		4'd11:	next_state = 4'd0;
		4'd12:	next_state = 4'd4;
		4'd13:	next_state = 4'd0;
		4'd14:	next_state = 4'd0;
		4'd15:	next_state = 4'd0;
		default:	next_state = 4'd0;
	endcase
end

always@(*)
begin
	case(curr_state)
		4'd0:	begin
            iord = 1'b0;
            memwrite = 1'b0;
            irwrite = 1'b1;
            pcwrite = 1'b1;
            branch = 1'b0;
            pcsrc = 2'b0;
            alucontrol = 3'b001;
            alusrcb = 2'b01;
            alusrca = 1'b0;
            regwrite = 1'b0;
            memtoreg = 1'b0;
            regdst = 1'b0;
				end
		4'd1:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b11;
			alusrca = 1'b0;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd2:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b10;
			alusrca = 1'b1;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd3:	begin
			iord = 1'b1;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b0;
			alusrca = 1'b0;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd4:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b0;
			alusrca = 1'b0;
			regwrite = 1'b1;
			memtoreg = 1'b1;
			regdst = 1'b0;
				end
		4'd5:	begin
			iord = 1'b1;
			memwrite = 1'b1;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b0;
			alusrca = 1'b0;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd6:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b0;
			alusrca = 1'b1;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd7:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b0;
			alusrca = 1'b0;
			regwrite = 1'b1;
			memtoreg = 1'b0;
			regdst = 1'b1;
				end
		4'd8:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b1;
			pcsrc = 2'b1;
			alucontrol = 3'b100;
			alusrcb = 2'b0;
			alusrca = 1'b1;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd9:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b10;
			alusrca = 1'b1;
			regwrite = 1'b0;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd10:	begin
			iord = 1'b0;
			memwrite = 1'b0;
			irwrite = 1'b0;
			pcwrite = 1'b0;
			branch = 1'b0;
			pcsrc = 2'b0;
			alucontrol = 3'b001;
			alusrcb = 2'b0;
			alusrca = 1'b0;
			regwrite = 1'b1;
			memtoreg = 1'b0;
			regdst = 1'b0;
				end
		4'd11:	
            begin
			    iord = 1'b0;
			    memwrite = 1'b0;
			    irwrite = 1'b0;
			    pcwrite = 1'b1;
			    branch = 1'b0;
			    pcsrc = 2'b10;
			    alucontrol = 3'b001;
			    alusrcb = 2'b0;
			    alusrca = 1'b0;
			    regwrite = 1'b0;
			    memtoreg = 1'b0;
			    regdst = 1'b0;
			end
		default:	
            begin
                iord = 1'b0;
                memwrite = 1'b0;
                irwrite = 1'b0;
                pcwrite = 1'b0;
                branch = 1'b0;
                pcsrc = 2'b10;
                alucontrol = 3'b0;
                alusrcb = 2'b0;
                alusrca = 1'b0;
                regwrite = 1'b0;
                memtoreg = 1'b0;
                regdst = 1'b0;
			end
	endcase
end

endmodule
