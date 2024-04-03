/* verilator lint_off UNUSED */
module game_top #(
    parameter COLOR_BITS = 24
)(
    input logic [3:0] player_1_move_i,
    input logic [3:0] player_2_move_i,
    input logic player_1_shoot_i,
    input logic player_2_shoot_i,
    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o,
    input logic clk_i,
    input logic reset_i
);
    logic map_enable, clk_slow, cannot_walk_through, hsync, vsync, destroyable_block, all_hard_block, bullet_collide, bullet_collide_player_1, bullet_collide_player_2;
    logic [(COLOR_BITS/3)-1 :0] map_blue, map_green, map_red, player_red, player_green, player_blue, bullet_blue, bullet_green, bullet_red;

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
        .bullet_collide_i(bullet_collide),
        .display_enable_i(display_enable_o),
        .hpos_i(hpos_o),
        .vpos_i(vpos_o),
        .map_enable_o(map_enable),
        .cannot_walk_through_o(cannot_walk_through),
        .destroyable_block_o(destroyable_block),
        .all_hard_block_o(all_hard_block),
        .map_blue_o(map_blue), 
        .map_green_o(map_green), 
        .map_red_o(map_red),
        .clk_i(clk_i),
        .reset_i(reset)
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
        .bullet_blue_i(bullet_blue),
        .bullet_green_i(bullet_green),
        .bullet_red_i(bullet_red),

        .is_menu_i(is_menu),
        .is_playing_i(is_playing),
        .is_continue_i(is_continue),
        .is_final_i(is_final),

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
        //control tanks
        .player_1_move_i(player_1_move_i),
        .player_2_move_i(player_2_move_i),
        .player_1_shoot_i(player_1_shoot_i),
        .player_2_shoot_i(player_2_shoot_i),
        //video signal
        .display_enable_i(display_enable_o),
        .hpos_i(hpos_o),
        .vpos_i(vpos_o),
        .player_blue_o(player_blue),
        .player_green_o(player_green),
        .player_red_o(player_red),
        .bullet_blue_o(bullet_blue),
        .bullet_green_o(bullet_green),
        .bullet_red_o(bullet_red),
        //other signal
        .map_enable_i(map_enable),
        .destroyable_block_i(destroyable_block),
        .cannot_walk_through_i(cannot_walk_through),
        .all_hard_block_i(all_hard_block),
        .hsync_i(hsync),
        .bullet_collide_o(bullet_collide),
        .bullet_collide_player_1_o(bullet_collide_player_1),
        .bullet_collide_player_2_o(bullet_collide_player_2),

        .clk_slow_i(clk_slow),
        .clk_i(clk_i),
        .reset_i(reset)
    );

    logic is_menu, is_playing, is_continue, is_final, reset;
    FSM game_FSM (
        .space_i(player_1_shoot_i),
        .sellect_up_i(player_1_move_i[1]),
        .sellect_down_i(player_1_move_i[0]),
        .bullet_collide_player_1_i(bullet_collide_player_1),
        .bullet_collide_player_2_i(bullet_collide_player_2),

        .is_menu_o(is_menu),
        .is_playing_o(is_playing),
        .is_continue_o(is_continue),
        .is_final_o(is_final),
        .reset_o(reset),

        .reset_i(reset_i),
        .clk_i(clk_i)
    );
/* verilator lint_off PINCONNECTEMPTY */
endmodule
/* verilator lint_off UNUSED */
