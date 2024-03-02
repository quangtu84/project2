module map_render #(
    parameter COLOR_BITS = 24
) (
    input logic clk_i,
    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic [(COLOR_BITS/3)-1 :0] blue_o, green_o, red_o
);
    
    mem_tile #(
        .ADDRESS(13),
        .COLOR_BITS(COLOR_BITS)
    ) tile (
        .addr({block_type,vpos_o[4:0],hpos_o[4:0]}),
        .dout(dout)
    );

    map_block map_block(
        .map_enable_i(map_enable),
        .map_x_i(hpos_o[8:5]-1),
        .map_y_i(vpos_o[8:5]-1),
        .block_type_o(block_type)
    );

    logic map_enable;
    logic [2:0] block_type;
    logic [COLOR_BITS-1:0] dout;

    assign map_enable = display_enable_o && (hpos_o >=32) && (hpos_o <= 447) && (vpos_o >=32) && (vpos_o <= 447);

    hvsync_gen hvsync_gen(
        .clk_i(clk_i),
        /* verilator lint_off PINCONNECTEMPTY */
        .hsync_no(),
        .vsync_no(),
        /* verilator lint_off PINCONNECTEMPTY */
        .display_enable_o(display_enable_o),
        .hpos_o(hpos_o),
        .vpos_o(vpos_o)
    );

    always_comb begin
        if (display_enable_o) begin
            if(map_enable) {blue_o, green_o, red_o} = dout;
            else {blue_o, green_o, red_o} = 24'hE0E0E0;
        end else begin
            {blue_o, green_o, red_o} = 24'b0;
        end
            
    end
























endmodule
