`timescale 1ns / 1ps


module sim;

	// Inputs
	reg CLK;
	reg rst;
	
	// Instantiate the Unit Under Test (UUT)
	top uut (
		.CLK(CLK), 
		.rst(rst)
	);

	always #5 CLK=~CLK;

	initial begin
		// Initialize Inputs
		CLK = 0;
		rst = 1;
	
		// Wait 100 ns for global reset to finish
		#10;
		
		rst = 0;
		// Add stimulus here

	end
      
endmodule