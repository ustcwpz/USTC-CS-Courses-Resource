module top(
input					clk,
input					rst_n,
input 				btn,
input					In,
output				led,
output		[3:0]	sel,
output		[7:0]	data/*,
output		[4:0]	ledtest*/
    );

wire	Op;
wire	out;

EraseGlintch	u_EraseGlintch(
 .clk				(clk),
 .rst_n			(rst_n),
 .btn				(btn),
 .Op				(Op)
);

fsm				u_fsm(
 .clk				(clk),
 .rst_n				(rst_n),
 .In				(In),
 .Op				(Op),
 .led				(led)/*,
 .ledtest			(ledtest)*/
);

Output			u_Output(
 .clk				(clk),
 .rst_n				(rst_n),
 .Op				(Op),
 .In				(In),
 .sel				(sel),
 .data				(data)
);



endmodule



module key_jitter(
 input				clk,
 input				rst_n,
 input 			btn,
 output	reg	Op
     );
 
 reg				Ol;
 reg	[18:0]	cnt;
 
  initial	Ol		=	0;
 always@(posedge	clk	or	negedge	rst_n)
 begin
 	if(~rst_n)
 		cnt	<=	19'h0;
 	else
 	begin
 		if(Ol	==	btn)
 			cnt	<=	19'h0;
 		else
 			cnt	<=	cnt	+	19'h1;
 		if(cnt	==	19'h511_999)
 		begin
 			Ol	=	btn;
 			cnt	<=	19'h0;
 		end
 	end
 end
 
 always@(posedge	clk)
 begin
 	if((cnt	==	19'h511_999)	&&	(Ol	==	1))
 		Op	<=	1;
 	if(Op	==	1)
 		Op	<=	0;
 end


endmodule

module FSM(
input      clk,
input      rst_n,
input      In,
input      Op,
output reg led
   );

parameter  S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4;

reg    [2:0]   next_state;
reg    [2:0]   curr_state;

initial next_state = S0;
always@(posedge clk or negedge rst_n)
begin
   if(~rst_n)
       curr_state  <=  S0;
   else    if(Op)
       curr_state  <=  next_state;
end

always@(*) begin
   case(curr_state)
       S0: if(In) next_state <= S1; else next_state <= S0;
       S1: if(In) next_state <= S2; else next_state <= S0;
       S2: if(In) next_state <= S2; else next_state <= S3;
       S3: if(In) next_state <= S4; else next_state <= S0;
       S4: if(In) next_state <= S1; else next_state <= S0;
       default: next_state <= S0;
   endcase
end

always@(posedge    clk or  negedge rst_n) begin
   if(~rst_n)
       led <= 0;
   else    if(Op) begin
       case(curr_state)
           S0: if(In) led <=  0; else led <= 0;
           S1: if(In) led <=  0; else led <= 0;
           S2: if(In) led <=  0; else led <= 0;
           S3: if(In) led <=  1; else led <= 0;
           S4: if(In) led <=  0; else led <= 0;
           default: led <=  0;
           endcase
   end
end

endmodule







module Output(
 input						clk,
 input						rst_n,
 input						Op,
 input						In,
 output	reg	[3:0]	sel,
 output	reg	[7:0]	data
     );
 
 reg	[16:0]	sel_ctrl;
 reg	[7:0]		data1;
 reg	[7:0]		data2;
 reg	[7:0]		data3;
 reg	[7:0]		data4;
 
 initial 	sel_ctrl	=	17'h0;
 initial	sel		    =	4'b1110;
 initial	data		=	8'b1111_1111;
 initial	data1		=	8'b1111_1111;
 initial	data2		=	8'b1111_1111;
 initial	data3		=	8'b1111_1111;
 initial	data4		=	8'b1111_1111;
 
 always@(posedge	clk)
 begin
 	if(sel_ctrl	==	17'd100_000)
 		sel_ctrl	<=	17'd0;
 	else
 		sel_ctrl	<=	sel_ctrl	+	17'h1;
 end
 
 always@(posedge	clk)
 begin
 	if(sel_ctrl	==	17'd25000)
 		sel	<=	4'b1110;
 	else	if(sel_ctrl	==	17'd50000)
 		sel	<=	4'b1101;
 	else	if(sel_ctrl	==	17'd75000)
 		sel	<=	4'b1011;
 	else	if(sel_ctrl	==	17'd100_000)
 		sel	<=	4'b0111;
 end
 
 always@(posedge	clk	or	negedge	rst_n)
 begin
 	if(~rst_n)
 	begin
 		data1		<=	8'b1111_1111;
 		data2		<=	8'b1111_1111;
 		data3		<=	8'b1111_1111;
 		data4		<=	8'b1111_1111;
 	end
 	else if(Op)
 	begin
 		data4	<=	data3;
 		data3	<=	data2;
 		data2	<=	data1;
 		if(In)
 			data1	<=	8'b1001_1111;
 		else
 			data1	<=	8'b0000_0011;
 	end
 end
 
 always@(*)
 begin
 	if(sel == 4'b1110)
 		data = data1;
 	else if(sel	== 4'b1101)
 		data = data2;
 	else if(sel == 4'b1011)
 		data = data3;
 	else
 		data = data4;
 end
 
endmodule

