/* verilator lint_off UNUSED */
module game_top #(
    parameter COLOR_BITS = 24
)(
    input logic [3:0] player_1_move_i,
    input logic [3:0] player_2_move_i,

    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o,
    output logic [9:0] player_1_x_o,
    output logic [9:0] player_1_y_o,
    output logic [9:0] player_2_x_o,
    output logic [9:0] player_2_y_o,
    output logic player_1_collide_with_wall_top_o, 
    output logic player_1_collide_with_wall_bottom_o, 
    output logic player_1_collide_with_wall_left_o, 
    output logic player_1_collide_with_wall_right_o,
    input logic clk_i,
    input logic reset_i
);
    logic map_enable, clk_slow, cannot_walk_through, hsync, vsync;
    logic [(COLOR_BITS/3)-1 :0] map_blue, map_green, map_red, player_red, player_green, player_blue;

    hvsync_gen hvsync_gen(
        .clk_i(clk_i),
        .hsync_no(hsync),
        .vsync_no(vsync),
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
        .cannot_walk_through_o(cannot_walk_through),
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
        .player_blue_i(player_blue),
        .player_green_i(player_green),
        .player_red_i(player_red),
        .blue_o(blue_o),
        .green_o(green_o),
        .red_o(red_o)
    );

    speed_control speed_control(
        .clk_i(clk_i),
        .update_clk_o(clk_slow)
    );
/* verilator lint_off PINCONNECTEMPTY */
    player_rgb #(
        .COLOR_BITS(24)
    ) player_rgb (
        .player_1_move_i(player_1_move_i),
        .player_2_move_i(player_2_move_i),
        .player_1_shoot_i(),
        .player_2_shoot_i(),
        .display_enable_i(display_enable_o),
        .hpos_i(hpos_o),
        .vpos_i(vpos_o),
        .map_enable_i(map_enable),
        .destroyable_block_i(),
        .cannot_walk_through_i(cannot_walk_through),
        .shoot_through_block_i(),
        .hsync_i(hsync),
        .bullet_collide_o(),
        .player_blue_o(player_blue),
        .player_green_o(player_green),
        .player_red_o(player_red),
        .player_1_x_o(player_1_x_o),
        .player_1_y_o(player_1_y_o),
        .player_2_x_o(player_2_x_o),
        .player_2_y_o(player_2_y_o),
        .player_1_collide_with_wall_top_o(player_1_collide_with_wall_top_o), 
        .player_1_collide_with_wall_bottom_o(player_1_collide_with_wall_bottom_o), 
        .player_1_collide_with_wall_left_o(player_1_collide_with_wall_left_o), 
        .player_1_collide_with_wall_right_o(player_1_collide_with_wall_right_o),
        .clk_slow_i(clk_slow),
        .clk_i(clk_i),
        .reset_i(reset_i)
    );
/* verilator lint_off PINCONNECTEMPTY */
endmodule
/* verilator lint_off UNUSED */
