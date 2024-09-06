module speed_control (
    input logic clk_i,
    output logic player_update_o,
    output logic bullet_update_o,
	 output logic VGA_clk_o
);
  logic [24:0] count;
  logic [24:0] count2;
  logic a;

  always @(posedge clk_i) begin
    count <= count + 1;
    if (count == 200000) begin
      player_update_o <= ~player_update_o;
      count  <= 0;
    end
  end

  always @(posedge clk_i) begin
    count2 <= count2 + 1;
    if (count2 == 75000) begin
      bullet_update_o <= ~bullet_update_o;
      count2  <= 0;
    end
  end
  
	 always_ff @(posedge clk_i) begin
		  a <= ~a;
		  VGA_clk_o <= a;
	 end
endmodule
