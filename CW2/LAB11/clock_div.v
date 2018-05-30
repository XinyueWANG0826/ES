module clock_div(clk, reset, out_clk,SW1,SW2);

input clk,reset,SW1,SW2;
output out_clk;
reg out_clk,out_clk_aux;
reg [27:0]counter;


always @(posedge (clk),posedge (reset))
	begin

		if(reset==1'b1)
			begin
			counter = 28'd0;
			out_clk_aux=1'b0;
			end
			
			else
			begin
			if((SW1 == 1'b0) && (SW2 == 1'b0))
					begin
						if((counter>=28'd0) && (counter<28'd25000000))
							begin
							out_clk_aux=1'b1;
							counter = counter +1;
							end
						else if ((counter>=28'd25000000) && (counter<28'd50000000))
							begin
							out_clk_aux=1'b0;
							counter = counter +1;
							end
						else
							begin
							counter = 28'd0;
							end
					end
			else if((SW1 == 1'b1) && (SW2 == 1'b0))
					begin
						if((counter>=28'd0) && (counter<28'd12500000))
							begin
							out_clk_aux=1'b1;
							counter = counter +1;
							end
						else if((counter>=28'd12500000) && (counter<28'd25000000))
							begin
							out_clk_aux=1'b0;
							counter = counter +1;
							end

						else
							begin
							counter = 28'd0;
							end
					end
			else if((SW1 == 1'b0) && (SW2 == 1'b1))
					begin
						if((counter>=28'd0) && (counter<28'd6250000))
							begin
							out_clk_aux=1'b1;
							counter = counter +1;
							end
						else if ((counter>=28'd6250000) && (counter<28'd12500000))
							begin
							out_clk_aux=1'b0;
							counter = counter +1;
							end
						else
							begin
							counter = 28'd0;
							end
					end
			else if((SW1 == 1'b1) && (SW2 == 1'b1))
					begin
						if((counter>=28'd0) && (counter<28'd3125000))
							begin
							out_clk_aux=1'b1;
							counter = counter +1;
							end
						else if ((counter>=28'd3125000) && (counter<28'd6250000))
							begin
							out_clk_aux=1'b0;
							counter = counter +1;
							end
						else
							begin
							counter = 28'd0;
							end
					end
				else
					begin
						counter = 28'd0;
					end
					end
			
		// port assignements
		out_clk=out_clk_aux;
	end
endmodule


