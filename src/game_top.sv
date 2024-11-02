/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
/* verilator lint_off IMPLICIT */
/* verilator lint_off PINCONNECTEMPTY */
/* verilator lint_off MULTITOP */
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

    logic map_enable, clk_player, clk_bullet, one_sec_clk, cannot_walk_through, destroyable_block, all_hard_block, bullet_collide_wall, eagle_block, bullet_collide_eagle;
    logic tank_left_enable, player_tank_enable, level_enable, menu_enable;
    logic [(COLOR_BITS/3)-1 :0] map_blue, map_green, map_red, player_red, player_green, player_blue, bullet_blue, bullet_green, bullet_red, menu_blue, menu_green, menu_red;
    logic [(COLOR_BITS/3)-1 :0] tank_left_blue, tank_left_green, tank_left_red, player_tank_blue, player_tank_green, player_tank_red, level_blue, level_green, level_red;
    logic [5:0] enemy_left;
    logic [9:0] hpos, vpos;
    logic [10:0] player_1_score, player_2_score;
    logic [3:0] player_1_live_left, player_2_live_left;
    logic [3:0] level;
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
        .map_type_i(level - 4'b1),
        // .map_type_i(4'd9),
        .bullet_collide_eagle_i(bullet_collide_eagle),
        .bullet_collide_i(bullet_collide_wall),
        .display_enable_i(display_enable),
        .hpos_i(hpos),
        .vpos_i(vpos),
        .map_enable_o(map_enable),
        .cannot_walk_through_o(cannot_walk_through),
        .destroyable_block_o(destroyable_block),
        .all_hard_block_o(all_hard_block),
        .eagle_block_o(eagle_block),
        .map_blue_o(map_blue), 
        .map_green_o(map_green), 
        .map_red_o(map_red),
        .clk_i(VGA_clk),
        .reset_i(reset)
    );

    menu  #(
        .COLOR_BITS(COLOR_BITS)
    ) menu(
        .hpos_i(hpos),
        .vpos_i(vpos),

        .is_menu_i(is_menu),
        .is_playing_i(is_playing),
        .is_level_done_i(is_level_done),
        .is_game_over_i(is_game_over),
        .is_game_win_i(is_game_win),

        .menu_blue_o(menu_blue),
        .menu_green_o(menu_green),
        .menu_red_o(menu_red),
        .menu_enable_o(menu_enable),

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
        .player_blue_i(player_1_blue | player_2_blue | enemy_1_blue | enemy_2_blue),
        .player_green_i(player_1_green | player_2_green | enemy_1_green | enemy_2_green),
        .player_red_i(player_1_red | player_2_red | enemy_1_red | enemy_2_red),
        .bullet_blue_i(bullet_blue),
        .bullet_green_i(bullet_green),
        .bullet_red_i(bullet_red),
        .tank_left_blue_i(tank_left_blue),
        .tank_left_green_i(tank_left_green),
        .tank_left_red_i(tank_left_red),
        .tank_left_enable_i(tank_left_enable),
        .player_tank_blue_i(player_tank_blue),
        .player_tank_green_i(player_tank_green),
        .player_tank_red_i(player_tank_red),
        .player_tank_enable_i(player_tank_enable),
        .level_blue_i(level_blue),
        .level_green_i(level_green),
        .level_red_i(level_red),
        .level_enable_i(level_enable),
        .menu_blue_i(menu_blue),
        .menu_green_i(menu_green),
        .menu_red_i(menu_red),
        .menu_enable_i(menu_enable),

        .is_menu_i(is_menu),
        .is_playing_i(is_playing),
        .is_level_done_i(is_level_done),
        .is_game_over_i(is_game_over),
        .is_game_win_i(is_game_win),

        .blue_o(blue_o),
        .green_o(green_o),
        .red_o(red_o)


    );

    speed_control speed_control(
        .clk_i(clk_i),
        .hsync_i(hsync_no),
        .player_update_o(clk_player),
        .bullet_update_o(clk_bullet),
        .one_sec_clock_o(one_sec_clk),
        .VGA_clk_o(VGA_clk)
    );


    bullet_collide bullet_collide_1 (
        .player_1_lives_i(4'd4),
        .player_1_box_i(player_1_tank_enable),
        .player_1_bullet_i(player_1_bullet),
        .player_1_bullet_explose_o(player_1_bullet_explose),
        .player_1_die_o(player_1_die),
        .player_1_revive_o(player_1_revive),
        .player_1_live_left_o(player_1_live_left),

        .player_2_lives_i(4'd4),
        .player_2_box_i(player_2_tank_enable),
        .player_2_bullet_i(player_2_bullet),
        .player_2_bullet_explose_o(player_2_bullet_explose),
        .player_2_die_o(player_2_die),
        .player_2_revive_o(player_2_revive),
        .player_2_live_left_o(player_2_live_left),

        .enemy_1_lives_i(4'd1),
        .enemy_1_box_i(enemy_1_tank_enable),
        .enemy_1_bullet_i(enemy_1_bullet),
        .enemy_1_bullet_explose_o(enemy_1_bullet_explose),
        .enemy_1_die_o(enemy_1_die),
        .enemy_1_revive_o(enemy_1_revive),
        
        .eagle_block_i(eagle_block),
        .all_hard_block_i(all_hard_block),
        .destroyable_block_i(destroyable_block),
        .bullet_collide_wall_o(bullet_collide_wall),
        .bullet_collide_eagle_o(bullet_collide_eagle),

        .enemy_left_o(enemy_left),
        .player_1_score_o(player_1_score),
        .player_2_score_o(player_2_score),
        .clk_i(VGA_clk),
        .reset_i(reset),
        .reset_all_i(reset_i)
    );

    logic player_box;
    assign player_box = player_1_tank_enable || player_2_tank_enable || enemy_1_tank_enable || enemy_2_tank_enable;
    assign {bullet_blue, bullet_green, bullet_red} = (player_2_bullet || player_1_bullet || enemy_1_bullet || enemy_2_bullet) ? 24'hFFFFFF : 0;

    logic is_menu, is_playing, is_level_done, is_game_over, is_game_win, reset;
    FSM game_FSM (
        .space_i(player_1_shoot_i | player_2_shoot_i),
        .bullet_collide_eagle_i(bullet_collide_eagle),
        .enemy_left_i(enemy_left),

        .is_menu_o(is_menu),
        .is_playing_o(is_playing),
        .is_level_done_o(is_level_done),
        .is_game_over_o(is_game_over),
        .is_game_win_o(is_game_win),
        .reset_game_o(reset),
        .level_o(level),

        .reset_i(reset_i),
        .clk_i(clk_i)
    );

    score_board score_board (
        .tank_left_i(enemy_left),
        .level_i(level),
        .player_1_score_i(player_1_score),
        .player_2_score_i(player_2_score),
        .player_1_live_left_i(player_1_live_left),
        .player_2_live_left_i(player_2_live_left),
        .hpos_i(hpos),
        .vpos_i(vpos),
        .tank_left_blue_o(tank_left_blue),
        .tank_left_green_o(tank_left_green),
        .tank_left_red_o(tank_left_red),
        .tank_left_enable_o(tank_left_enable),

        .player_tank_blue_o(player_tank_blue),
        .player_tank_green_o(player_tank_green),
        .player_tank_red_o(player_tank_red),
        .player_tank_enable_o(player_tank_enable),

        .level_blue_o(level_blue),
        .level_green_o(level_green),
        .level_red_o(level_red),
        .level_enable_o(level_enable)
    );

/* verilator lint_off PINCONNECTEMPTY */
///////////////////////////////////////
////        PLAYER 1              /////
///////////////////////////////////////
    logic [(COLOR_BITS/3)-1 :0] player_1_blue , player_1_green, player_1_red;
    logic player_1_bullet, player_1_tank_enable, player_1_bullet_explose, player_1_die, player_1_revive;
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
        .tank_revive_i(player_1_revive),

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

        //clock
        .hsync_i(hsync_no),
        .one_sec_clk_i(one_sec_clk),
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
    logic player_2_bullet, player_2_tank_enable, player_2_bullet_explose, player_2_die, player_2_revive;
    logic [COLOR_BITS-1 :0] player_2_bits;
    logic [9:0] player_2_addr;

    tank #(
        .COLOR_BITS(COLOR_BITS),
        // .TANK_X_INIT(10'd160),
        // .TANK_Y_INIT(10'd416),
        .TANK_X_INIT(10'd32),
        .TANK_Y_INIT(10'd180),
        .TANK_DIR_INIT(4'b0010),
        .TANK_MOVE_SPEED(10'd1),
        .BULLET_MOVE_SPEED(10'd1)
    ) player_2 (
        //control tanks
        .tank_move_i(player_2_move_i),
        .tank_shoot_i(player_2_shoot_i),
        .bullet_collide_i(player_2_bullet_explose),
        .tank_die_i(player_2_die),
        .tank_revive_i(player_2_revive),

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

        //clock
        .hsync_i(hsync_no),
        .one_sec_clk_i(one_sec_clk),
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

///////////////////////////////////////
////        ENEMY 1               /////
///////////////////////////////////////
    logic [(COLOR_BITS/3)-1 :0] enemy_1_blue , enemy_1_green, enemy_1_red;
    logic enemy_1_bullet, enemy_1_tank_enable, enemy_1_bullet_explose, enemy_1_die, enemy_1_revive;
    logic [COLOR_BITS-1 :0] enemy_1_bits;
    logic [9:0] enemy_1_addr;

    tank_bot #(
        .COLOR_BITS(COLOR_BITS),
        .TANK_X_INIT(10'd32),
        .TANK_Y_INIT(10'd32),
        .TANK_DIR_INIT(4'b0001),
        .TANK_MOVE_SPEED(10'd1),
        .BULLET_MOVE_SPEED(10'd1)
    ) enemy_1 (
        //control tanks
        .bullet_collide_i(enemy_1_bullet_explose),
        .tank_die_i(enemy_1_die),
        .tank_revive_i(enemy_1_revive),

        //video signal
        .hpos_i(hpos),
        .vpos_i(vpos),
        .tank_gfx_bit_i(enemy_1_bits),
        .tank_gfx_addr_o(enemy_1_addr),
        .tank_blue_o(enemy_1_blue),
        .tank_green_o(enemy_1_green),
        .tank_red_o(enemy_1_red),
        .bullet_enable_o(enemy_1_bullet),
        .tank_enable_o(enemy_1_tank_enable),

        //other control signal
        .cannot_walk_through_i(cannot_walk_through || player_box),

        //clock
        .hsync_i(hsync_no),
        .one_sec_clk_i(one_sec_clk),
        .player_clk_i(clk_player),
        .bullet_clk_i(clk_bullet),
        .clk_i(VGA_clk),
        .reset_i(reset)
    );

    mem_enemy_1  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_enemy_1 (
        .addr(enemy_1_addr),
        .dout(enemy_1_bits)
    );

///////////////////////////////////////
////        ENEMY 2               /////
///////////////////////////////////////
    logic [(COLOR_BITS/3)-1 :0] enemy_2_blue , enemy_2_green, enemy_2_red;
    logic enemy_2_bullet, enemy_2_tank_enable, enemy_2_bullet_explose, enemy_2_die;
    logic [COLOR_BITS-1 :0] enemy_2_bits;
    logic [9:0] enemy_2_addr;


endmodule
/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
/* verilator lint_off IMPLICIT */
/* verilator lint_off PINCONNECTEMPTY */
/* verilator lint_off MULTITOP */
