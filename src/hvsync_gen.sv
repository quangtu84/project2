/* verilator lint_off UNUSED */
module hvsync_gen (
    input logic clk_i,
    output logic hsync_no,
    output logic vsync_no,
    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o
);
  localparam H_DISPLAY = 640;
  localparam H_FRONT = 16;
  localparam H_BACK = 48;
  localparam H_SYNC = 96;

  localparam V_DISPLAY = 480;
  localparam V_FRONT = 10;
  localparam V_BACK = 33;
  localparam V_SYNC = 2;

  localparam H_SYNC_START = H_DISPLAY + H_FRONT - 1;  //655 
  localparam H_SYNC_END = H_DISPLAY + H_FRONT + H_SYNC - 2;  //750
  localparam H_MAX = H_DISPLAY + H_FRONT + H_SYNC + H_BACK - 1;  //799

  localparam V_SYNC_START = V_DISPLAY + V_FRONT - 1;  //489
  localparam V_SYNC_END = V_DISPLAY + V_FRONT + V_SYNC - 2;  //490
  localparam V_MAX = V_DISPLAY + V_FRONT + V_SYNC + V_BACK - 1;  //524

  logic hsync;
  logic vsync;

  wire h_maxxed = (hpos_o == H_MAX);// || reset_i;
  wire v_maxxed = (vpos_o == V_MAX);// || reset_i;

  assign display_enable_o = (hpos_o < H_DISPLAY) && (vpos_o < V_DISPLAY);
  assign hsync_no = ~hsync;
  assign vsync_no = ~vsync;

  //Horizontal position counter
  always_ff @(posedge clk_i) begin
    hsync <= (hpos_o >= H_SYNC_START && hpos_o <= H_SYNC_END);
    if (h_maxxed) hpos_o <= 0;
    else hpos_o <= hpos_o + 1;
  end
  //Vertical position counter
  always_ff @(posedge clk_i) begin
    vsync <= (vpos_o >= V_SYNC_START && vpos_o <= V_SYNC_END);
    if (h_maxxed)
      if (v_maxxed) vpos_o <= 0;
      else vpos_o <= vpos_o + 1;
  end
endmodule
/* verilator lint_off UNUSED */