module counter(clk, reset, enable, counter,SW1,SW2);
input clk, reset, enable,SW1,SW2;
output [23:0] counter; // red LEDs
reg [23:0] counter;
always @(posedge (clk),posedge (reset))
	begin

		if(reset==1'b1)
			counter = 24'd0;

		else 
			begin 
			if(enable==1'b1)
				counter = counter +1;
				
			else
				counter = counter - 1;
			end
		
	end
endmodule
