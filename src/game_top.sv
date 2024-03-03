module game_top #(
    parameter COLOR_BITS = 24
)(
    input logic clk_i,
    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o
);
    logic map_enable;
    logic [(COLOR_BITS/3)-1 :0] map_blue, map_green, map_red;

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

    map_rgb  #(
        .COLOR_BITS(COLOR_BITS)
    ) map_rgb(
        .display_enable_i(display_enable_o),
        .hpos_i(hpos_o),
        .vpos_i(vpos_o),
        .map_enable_o(map_enable),
        .map_blue_o(map_blue), 
        .map_green_o(map_green), 
        .map_red_o(map_red)
    );
    
    rgb_render  #(
        .COLOR_BITS(COLOR_BITS)
    ) rgb_render(
        .map_enable_i(map_enable),
        .display_enable_i(display_enable_o),
        .map_blue_i(map_blue),
        .map_green_i(map_green),
        .map_red_i(map_red),
        .blue_o(blue_o),
        .green_o(green_o),
        .red_o(red_o)
    );

endmodule
