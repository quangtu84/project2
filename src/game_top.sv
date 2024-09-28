/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
/* verilator lint_off IMPLICIT */
module game_top #(
    parameter COLOR_BITS = 24
)(
    input logic [3:0] player_1_move_i,
    input logic [3:0] player_2_move_i,
    input logic player_1_shoot_i,
    input logic player_2_shoot_i,
    output logic hsync_no,
    output logic vsync_no,
    //for simulation only
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic display_enable_o,
    /////////////////////////
    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o,
	output logic VGA_clk_o,
    input logic clk_i,
    input logic reset_i
);

    logic map_enable, clk_player, clk_bullet, cannot_walk_through, destroyable_block, all_hard_block, bullet_collide_wall, number_enable, tank_enable;
    logic [(COLOR_BITS/3)-1 :0] map_blue, map_green, map_red, player_red, player_green, player_blue, bullet_blue, bullet_green, bullet_red, menu_blue, menu_green, menu_red;
    logic [5:0] score_player_1, score_player_2;
    logic [9:0] hpos, vpos;
    logic [1:0] map_type;
    logic display_enable;
    logic VGA_clk;
    assign VGA_clk_o = VGA_clk;
    //for simulation only
    assign hpos_o = hpos;
    assign vpos_o = vpos;
    assign display_enable_o = display_enable;
    /////////////////////
    hvsync_gen hvsync_gen(
        .clk_i(VGA_clk),
        .hsync_no(hsync_no),
        .vsync_no(vsync_no),
        .display_enable_o(display_enable),
        .hpos_o(hpos),
        .vpos_o(vpos)
    );

    map_rgb  #(
        .COLOR_BITS(COLOR_BITS)
    ) map_rgb(
        .map_type_i(map_type),
        .bullet_collide_i(bullet_collide_wall),
        .display_enable_i(display_enable),
        .hpos_i(hpos),
        .vpos_i(vpos),
        .map_enable_o(map_enable),
        .cannot_walk_through_o(cannot_walk_through),
        .destroyable_block_o(destroyable_block),
        .all_hard_block_o(all_hard_block),
        .map_blue_o(map_blue), 
        .map_green_o(map_green), 
        .map_red_o(map_red),
        .clk_i(VGA_clk),
        .reset_i(reset)
    );

    menu  #(
        .COLOR_BITS(COLOR_BITS)
    ) menu(
        .sellect_up_i(player_1_move_i[1]),
        .sellect_down_i(player_1_move_i[0]),
        .hpos_i(hpos),
        .vpos_i(vpos),

        .menu_blue_o(menu_blue),
        .menu_green_o(menu_green),
        .menu_red_o(menu_red),
        .map_type_o(map_type),

        .clk_i(VGA_clk),
        .reset_i(reset_i)
    );

    rgb_render  #(
        .COLOR_BITS(COLOR_BITS)
    ) rgb_render(
        .map_enable_i(map_enable),
        .display_enable_i(display_enable),
        .map_blue_i(map_blue),
        .map_green_i(map_green),
        .map_red_i(map_red),
        .player_blue_i(player_1_blue | player_2_blue),
        .player_green_i(player_1_green | player_2_green),
        .player_red_i(player_1_red | player_2_red),
        .bullet_blue_i(bullet_blue),
        .bullet_green_i(bullet_green),
        .bullet_red_i(bullet_red),
        .number_blue_i(),
        .number_green_i(),
        .number_red_i(),
        .number_enable_i(),
        .tank_blue_i(),
        .tank_green_i(),
        .tank_red_i(),
        .tank_enable_i(),
        .menu_blue_i(menu_blue),
        .menu_green_i(menu_green),
        .menu_red_i(menu_red),

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
        .player_update_o(clk_player),
        .bullet_update_o(clk_bullet),
        .VGA_clk_o(VGA_clk)
    );
/* verilator lint_off PINCONNECTEMPTY */
///////////////////////////////////////
////        PLAYER 1              /////
///////////////////////////////////////
    logic [(COLOR_BITS/3)-1 :0] player_1_blue , player_1_green, player_1_red;
    logic player_1_bullet, player_1_tank_enable, player_1_bullet_explose, player_1_die;
    logic [COLOR_BITS-1 :0] player_1_bits;
    logic [9:0] player_1_addr;

    tank #(
        .COLOR_BITS(COLOR_BITS),
        .TANK_X_INIT(10'd288),
        .TANK_Y_INIT(10'd416),
        .TANK_DIR_INIT(4'b0010),
        .TANK_MOVE_SPEED(10'd1),
        .BULLET_MOVE_SPEED(10'd1)
    ) player_1 (
        //control tanks
        .tank_move_i(player_1_move_i),
        .tank_shoot_i(player_1_shoot_i),
        .bullet_collide_i(player_1_bullet_explose),
        .tank_die_i(player_1_die),

        //video signal
        .hpos_i(hpos),
        .vpos_i(vpos),
        .tank_gfx_bit_i(player_1_bits),
        .tank_gfx_addr_o(player_1_addr),
        .tank_blue_o(player_1_blue),
        .tank_green_o(player_1_green),
        .tank_red_o(player_1_red),
        .bullet_enable_o(player_1_bullet),
        .tank_enable_o(player_1_tank_enable),

        //other control signal
        .cannot_walk_through_i(cannot_walk_through || player_box),
        .tank_collide_with_wall_top_o(),
        .tank_collide_with_wall_bottom_o(),
        .tank_collide_with_wall_right_o(),
        .tank_collide_with_wall_left_o(),

        //clock
        .hsync_i(hsync_no),
        .player_clk_i(clk_player),
        .bullet_clk_i(clk_bullet),
        .clk_i(VGA_clk),
        .reset_i(reset)
    );

    mem_player_1  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_player_1 (
        .addr(player_1_addr),
        .dout(player_1_bits)
    );

///////////////////////////////////////
////        PLAYER 2              /////
///////////////////////////////////////
    logic [(COLOR_BITS/3)-1 :0] player_2_blue , player_2_green, player_2_red;
    logic player_2_bullet, player_2_tank_enable, player_2_bullet_explose, player_2_die;
    logic [COLOR_BITS-1 :0] player_2_bits;
    logic [9:0] player_2_addr;

    tank #(
        .COLOR_BITS(COLOR_BITS),
        .TANK_X_INIT(10'd160),
        .TANK_Y_INIT(10'd416),
        .TANK_DIR_INIT(4'b0010),
        .TANK_MOVE_SPEED(10'd1),
        .BULLET_MOVE_SPEED(10'd1)
    ) player_2 (
        //control tanks
        .tank_move_i(player_2_move_i),
        .tank_shoot_i(player_2_shoot_i),
        .bullet_collide_i(player_2_bullet_explose),
        .tank_die_i(player_2_die),

        //video signal
        .hpos_i(hpos),
        .vpos_i(vpos),
        .tank_gfx_bit_i(player_2_bits),
        .tank_gfx_addr_o(player_2_addr),
        .tank_blue_o(player_2_blue),
        .tank_green_o(player_2_green),
        .tank_red_o(player_2_red),
        .bullet_enable_o(player_2_bullet),
        .tank_enable_o(player_2_tank_enable),

        //other control signal
        .cannot_walk_through_i(cannot_walk_through || player_box),
        .tank_collide_with_wall_top_o(),
        .tank_collide_with_wall_bottom_o(),
        .tank_collide_with_wall_right_o(),
        .tank_collide_with_wall_left_o(),

        //clock
        .hsync_i(hsync_no),
        .player_clk_i(clk_player),
        .bullet_clk_i(clk_bullet),
        .clk_i(VGA_clk),
        .reset_i(reset)
    );

    mem_player_2  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_player_2 (
        .addr(player_2_addr),
        .dout(player_2_bits)
    );

    bullet_collide bullet_collide_1 (
        .player_1_box_i(player_1_tank_enable),
        .player_1_bullet_i(player_1_bullet),
        .player_1_bullet_explose_o(player_1_bullet_explose),
        .player_1_die_o(player_1_die),

        .player_2_box_i(player_2_tank_enable),
        .player_2_bullet_i(player_2_bullet),
        .player_2_bullet_explose_o(player_2_bullet_explose),
        .player_2_die_o(player_2_die),
        
        .all_hard_block_i(all_hard_block),
        .destroyable_block_i(destroyable_block),
        .bullet_collide_wall_o(bullet_collide_wall),

        .clk_i(VGA_clk)
    );

    logic player_box;
    assign player_box = player_1_tank_enable || player_2_tank_enable;
    assign {bullet_blue, bullet_green, bullet_red} = (player_2_bullet || player_1_bullet) ? 24'hFFFFFF : 0;

    logic is_menu, is_playing, is_continue, is_final, reset;
    FSM game_FSM (
        .space_i(player_1_shoot_i),
        .sellect_up_i(player_1_move_i[1]),
        .sellect_down_i(player_1_move_i[0]),
        .bullet_collide_player_1_i(),
        .bullet_collide_player_2_i(),

        .score_player_1_o(score_player_1),
        .score_player_2_o(score_player_2),

        .is_menu_o(is_menu),
        .is_playing_o(is_playing),
        .is_continue_o(is_continue),
        .is_final_o(is_final),
        .reset_o(reset),

        .reset_i(reset_i),
        .clk_i(VGA_clk)
    );

    score score (
        .clk_i(VGA_clk),
        .score_player_1_i(score_player_1),
        .score_player_2_i(score_player_2),
        .hpos_i(hpos),
        .vpos_i(vpos),

        .number_blue_o(),
        .number_green_o(),
        .number_red_o(),
        .number_enable_o(),

        .tank_blue_o(),
        .tank_green_o(),
        .tank_red_o(),
        .tank_enable_o()
    );
endmodule
/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
/* verilator lint_off IMPLICIT */