module speed_control (
    input logic clk_i,
    input logic hsync_i,
    output logic player_update_o,
    output logic bullet_update_o,
    output logic one_sec_clock_o,
	  output logic VGA_clk_o
);
  logic [23:0] count;
  logic [23:0] count2;
  logic [5:0] count3;
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

  always @(posedge clk_i) begin
    count3 <= count3 + 1;
    if (count3 == 60) begin
      one_sec_clock_o <= ~one_sec_clock_o;
      count3  <= 0;
    end
  end
endmodule
