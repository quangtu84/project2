// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_OUT8(hsync_no,0,0);
    VL_IN8(clk_i,0,0);
    VL_IN8(reset_i,0,0);
    VL_IN8(player_1_move_i,3,0);
    VL_IN8(player_2_move_i,3,0);
    VL_IN8(player_1_shoot_i,0,0);
    VL_IN8(player_2_shoot_i,0,0);
    VL_OUT8(vsync_no,0,0);
    VL_OUT8(display_enable_o,0,0);
    VL_OUT8(blue_o,7,0);
    VL_OUT8(green_o,7,0);
    VL_OUT8(red_o,7,0);
    VL_OUT8(VGA_clk_o,0,0);
    VL_OUT16(hpos_o,9,0);
    VL_OUT16(vpos_o,9,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__top__DOT__clk_player;
        CData/*0:0*/ top__DOT__top__DOT__clk_bullet;
        CData/*0:0*/ top__DOT__top__DOT__VGA_clk;
        CData/*0:0*/ top__DOT__top__DOT__reset;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__reset_tank;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__reset_tank;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__reset_tank;
        CData/*0:0*/ top__DOT__top__DOT__map_enable;
        CData/*0:0*/ top__DOT__top__DOT__cannot_walk_through;
        CData/*0:0*/ top__DOT__top__DOT__destroyable_block;
        CData/*0:0*/ top__DOT__top__DOT__all_hard_block;
        CData/*0:0*/ top__DOT__top__DOT__bullet_collide_eagle;
        CData/*0:0*/ top__DOT__top__DOT__player_tank_enable;
        CData/*0:0*/ top__DOT__top__DOT__level_enable;
        CData/*7:0*/ top__DOT__top__DOT__map_blue;
        CData/*7:0*/ top__DOT__top__DOT__map_green;
        CData/*7:0*/ top__DOT__top__DOT__map_red;
        CData/*7:0*/ top__DOT__top__DOT__menu_blue;
        CData/*7:0*/ top__DOT__top__DOT__menu_green;
        CData/*7:0*/ top__DOT__top__DOT__menu_red;
        CData/*7:0*/ top__DOT__top__DOT__tank_left_blue;
        CData/*7:0*/ top__DOT__top__DOT__tank_left_green;
        CData/*7:0*/ top__DOT__top__DOT__tank_left_red;
        CData/*7:0*/ top__DOT__top__DOT__player_tank_blue;
        CData/*7:0*/ top__DOT__top__DOT__player_tank_green;
        CData/*7:0*/ top__DOT__top__DOT__player_tank_red;
        CData/*7:0*/ top__DOT__top__DOT__level_blue;
        CData/*7:0*/ top__DOT__top__DOT__level_green;
        CData/*7:0*/ top__DOT__top__DOT__level_red;
        CData/*3:0*/ top__DOT__top__DOT__level;
        CData/*0:0*/ top__DOT__top__DOT__display_enable;
        CData/*0:0*/ top__DOT__top__DOT__player_box;
        CData/*0:0*/ top__DOT__top__DOT__is_menu;
        CData/*0:0*/ top__DOT__top__DOT__is_playing;
        CData/*0:0*/ top__DOT__top__DOT__is_level_done;
        CData/*0:0*/ top__DOT__top__DOT__is_game_over;
        CData/*0:0*/ top__DOT__top__DOT__is_game_win;
        CData/*7:0*/ top__DOT__top__DOT__player_1_blue;
        CData/*7:0*/ top__DOT__top__DOT__player_1_green;
        CData/*7:0*/ top__DOT__top__DOT__player_1_red;
        CData/*0:0*/ top__DOT__top__DOT__player_1_tank_enable;
        CData/*0:0*/ top__DOT__top__DOT__player_1_die;
        CData/*0:0*/ top__DOT__top__DOT__player_1_revive;
        CData/*7:0*/ top__DOT__top__DOT__player_2_blue;
        CData/*7:0*/ top__DOT__top__DOT__player_2_green;
        CData/*7:0*/ top__DOT__top__DOT__player_2_red;
        CData/*0:0*/ top__DOT__top__DOT__player_2_tank_enable;
        CData/*0:0*/ top__DOT__top__DOT__player_2_die;
        CData/*0:0*/ top__DOT__top__DOT__player_2_revive;
        CData/*7:0*/ top__DOT__top__DOT__enemy_1_blue;
        CData/*7:0*/ top__DOT__top__DOT__enemy_1_green;
        CData/*7:0*/ top__DOT__top__DOT__enemy_1_red;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1_tank_enable;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1_die;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1_revive;
        CData/*7:0*/ top__DOT__top__DOT__enemy_2_blue;
        CData/*7:0*/ top__DOT__top__DOT__enemy_2_green;
        CData/*7:0*/ top__DOT__top__DOT__enemy_2_red;
        CData/*0:0*/ top__DOT__top__DOT__enemy_2_bullet;
        CData/*0:0*/ top__DOT__top__DOT__enemy_2_tank_enable;
        CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__hsync;
        CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__vsync;
        CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed;
        CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed;
    };
    struct {
        CData/*2:0*/ top__DOT__top__DOT__map_rgb__DOT__block_type;
        CData/*3:0*/ top__DOT__top__DOT__map_rgb__DOT__block_state;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT__UL;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT__UR;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT__LR;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT__LL;
        CData/*2:0*/ top__DOT__top__DOT__menu__DOT__x_ofs;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__title_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__level_done_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__game_over_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__shoot_to_start_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__game_win_enable;
        CData/*0:0*/ top__DOT__top__DOT__menu__DOT__menu_enable;
        CData/*0:0*/ top__DOT__top__DOT__rgb_render__DOT__map_enable;
        CData/*0:0*/ top__DOT__top__DOT__speed_control__DOT__a;
        CData/*0:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__all_player;
        CData/*0:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet;
        CData/*0:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet;
        CData/*1:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage;
        CData/*3:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left;
        CData/*1:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage;
        CData/*3:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left;
        CData/*1:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage;
        CData/*3:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left;
        CData/*2:0*/ top__DOT__top__DOT__game_FSM__DOT__game_state;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__tank_left_enable;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__tank_left_enable_16;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__tank_left_enable_32;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__player_1_enable;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__player_2_enable;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__player_1_tank_enable;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__player_2_tank_enable;
        CData/*7:0*/ top__DOT__top__DOT__score_board__DOT__bit_number;
        CData/*2:0*/ top__DOT__top__DOT__score_board__DOT__x_ofs;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__level_enable;
        CData/*0:0*/ top__DOT__top__DOT__score_board__DOT__score_enable;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_box;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right;
        CData/*3:0*/ top__DOT__top__DOT__player_1__DOT__tank_prev_direct;
        CData/*4:0*/ top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
        CData/*4:0*/ top__DOT__top__DOT__player_1__DOT__tank_xofs_backward;
        CData/*4:0*/ top__DOT__top__DOT__player_1__DOT__tank_xofs;
        CData/*4:0*/ top__DOT__top__DOT__player_1__DOT__tank_yofs;
        CData/*1:0*/ top__DOT__top__DOT__player_1__DOT__bullet_stage;
        CData/*3:0*/ top__DOT__top__DOT__player_1__DOT__bullet_dir;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__show_bullet;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_bullet;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__tank_shoot;
        CData/*0:0*/ top__DOT__top__DOT__player_1__DOT__pos_edge_detect_1__DOT__sig_dly;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_box;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right;
        CData/*3:0*/ top__DOT__top__DOT__player_2__DOT__tank_prev_direct;
        CData/*4:0*/ top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
        CData/*4:0*/ top__DOT__top__DOT__player_2__DOT__tank_xofs_backward;
        CData/*4:0*/ top__DOT__top__DOT__player_2__DOT__tank_xofs;
        CData/*4:0*/ top__DOT__top__DOT__player_2__DOT__tank_yofs;
    };
    struct {
        CData/*1:0*/ top__DOT__top__DOT__player_2__DOT__bullet_stage;
        CData/*3:0*/ top__DOT__top__DOT__player_2__DOT__bullet_dir;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__show_bullet;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_bullet;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__tank_shoot;
        CData/*0:0*/ top__DOT__top__DOT__player_2__DOT__pos_edge_detect_1__DOT__sig_dly;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_box;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right;
        CData/*3:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct;
        CData/*3:0*/ top__DOT__top__DOT__enemy_1__DOT__auto_tank_move;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__auto_tank_shoot;
        CData/*4:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward;
        CData/*4:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward;
        CData/*4:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_xofs;
        CData/*4:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_yofs;
        CData/*1:0*/ top__DOT__top__DOT__enemy_1__DOT__bullet_stage;
        CData/*3:0*/ top__DOT__top__DOT__enemy_1__DOT__bullet_dir;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__show_bullet;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_bullet;
        CData/*1:0*/ top__DOT__top__DOT__enemy_1__DOT__bot_stage;
        CData/*1:0*/ top__DOT__top__DOT__enemy_1__DOT__dir_stage;
        CData/*3:0*/ top__DOT__top__DOT__enemy_1__DOT__premove_tank;
        CData/*4:0*/ top__DOT__top__DOT__enemy_1__DOT__count;
        CData/*7:0*/ top__DOT__top__DOT__enemy_1__DOT__count2;
        CData/*0:0*/ top__DOT__top__DOT__enemy_1__DOT__pos_edge_detect_1__DOT__sig_dly;
        SData/*9:0*/ top__DOT__top__DOT__hpos;
        SData/*9:0*/ top__DOT__top__DOT__vpos;
        SData/*10:0*/ top__DOT__top__DOT__player_1_score;
        SData/*10:0*/ top__DOT__top__DOT__player_2_score;
        SData/*9:0*/ top__DOT__top__DOT__player_1_addr;
        SData/*9:0*/ top__DOT__top__DOT__player_2_addr;
        SData/*9:0*/ top__DOT__top__DOT__enemy_1_addr;
        SData/*9:0*/ top__DOT__top__DOT__menu__DOT__rom_addr;
        SData/*9:0*/ top__DOT__top__DOT__score_board__DOT__rom_addr;
        SData/*9:0*/ top__DOT__top__DOT__player_1__DOT__tank_x;
        SData/*9:0*/ top__DOT__top__DOT__player_1__DOT__tank_y;
        SData/*9:0*/ top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
        SData/*9:0*/ top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
        SData/*9:0*/ top__DOT__top__DOT__player_2__DOT__tank_x;
        SData/*9:0*/ top__DOT__top__DOT__player_2__DOT__tank_y;
        SData/*9:0*/ top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
        SData/*9:0*/ top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
        SData/*9:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_x;
        SData/*9:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_y;
        SData/*9:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x;
        SData/*9:0*/ top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y;
        IData/*23:0*/ top__DOT__top__DOT__player_1_bits;
        IData/*23:0*/ top__DOT__top__DOT__player_2_bits;
        IData/*23:0*/ top__DOT__top__DOT__enemy_1_bits;
        IData/*23:0*/ top__DOT__top__DOT__map_rgb__DOT__dout;
        IData/*23:0*/ top__DOT__top__DOT__speed_control__DOT__count;
        IData/*23:0*/ top__DOT__top__DOT__speed_control__DOT__count2;
        IData/*31:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive;
        IData/*31:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive;
        IData/*31:0*/ top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive;
        IData/*23:0*/ top__DOT__top__DOT__game_FSM__DOT__counter;
        IData/*23:0*/ top__DOT__top__DOT__game_FSM__DOT__counter2;
        IData/*23:0*/ top__DOT__top__DOT__score_board__DOT__tank_left_dout;
        IData/*23:0*/ top__DOT__top__DOT__score_board__DOT__player_1_bits;
        IData/*23:0*/ top__DOT__top__DOT__score_board__DOT__player_2_bits;
        CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT__map_tiles[13][13];
    };
    struct {
        IData/*23:0*/ top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem[8192];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__title_buffer[11];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__level_done[10];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__game_over[9];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__game_win[7];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__shoot_to_start[14];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__shoot_to_continue[13];
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT__shoot_to_restart[16];
        CData/*7:0*/ top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem[1024];
        CData/*5:0*/ top__DOT__top__DOT__score_board__DOT__level[7];
        CData/*5:0*/ top__DOT__top__DOT__score_board__DOT__player_score[10];
        IData/*23:0*/ top__DOT__top__DOT__score_board__DOT__mem_lives__DOT__mem[256];
        IData/*23:0*/ top__DOT__top__DOT__score_board__DOT__mem_player_1__DOT__mem[1024];
        IData/*23:0*/ top__DOT__top__DOT__score_board__DOT__mem_player_2__DOT__mem[1024];
        CData/*7:0*/ top__DOT__top__DOT__score_board__DOT__ascii_rom__DOT__mem[1024];
        IData/*23:0*/ top__DOT__top__DOT__mem_player_1__DOT__mem[1024];
        IData/*23:0*/ top__DOT__top__DOT__mem_player_2__DOT__mem[1024];
        IData/*23:0*/ top__DOT__top__DOT__mem_enemy_1__DOT__mem[1024];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__top__DOT____Vcellinp__game_FSM__space_i;
        CData/*0:0*/ top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i;
        CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT____Vxrand2;
        CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT____Vxrand1;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT____Vlvbound3;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT____Vlvbound4;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT____Vlvbound5;
        CData/*0:0*/ top__DOT__top__DOT__map_rgb__DOT____Vlvbound6;
        CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT____Vlvbound7;
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT____Vxrand6;
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT____Vxrand5;
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT____Vxrand4;
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT____Vxrand3;
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT____Vxrand2;
        CData/*5:0*/ top__DOT__top__DOT__menu__DOT____Vxrand1;
        CData/*5:0*/ top__DOT__top__DOT__score_board__DOT____Vxrand2;
        CData/*5:0*/ top__DOT__top__DOT__score_board__DOT____Vxrand1;
        CData/*1:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage;
        CData/*3:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left;
        CData/*1:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage;
        CData/*3:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left;
        CData/*1:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage;
        CData/*3:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left;
        CData/*2:0*/ __Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state;
        CData/*3:0*/ __Vdly__top__DOT__top__DOT__level;
        CData/*0:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top;
        CData/*0:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom;
        CData/*0:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right;
        CData/*0:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left;
        CData/*1:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage;
        CData/*1:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage;
        CData/*7:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__count2;
        CData/*3:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank;
        CData/*4:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__count;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__clk_player;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__clk_bullet;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__VGA_clk;
        CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__reset;
        CData/*0:0*/ __Vclklast__TOP__clk_i;
        CData/*0:0*/ __Vclklast__TOP__reset_i;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset;
        CData/*0:0*/ __Vclklast__TOP__hsync_no;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__clk_player;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__clk_bullet;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__VGA_clk;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__reset;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank;
        CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__hpos;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__vpos;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_x;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_y;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_x;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_y;
    };
    struct {
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x;
        SData/*9:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y;
        IData/*31:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive;
        IData/*31:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive;
        IData/*31:0*/ __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive;
        IData/*23:0*/ __Vdly__top__DOT__top__DOT__game_FSM__DOT__counter;
        IData/*23:0*/ __Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2;
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__24(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__28(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__9(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__32(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__33(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__34(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__35(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__36(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__37(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__39(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__40(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__41(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__42(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__43(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__44(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__45(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__46(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__47(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__10(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__13(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__14(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__15(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__16(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__17(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__18(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__19(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__20(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__21(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__22(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__23(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__25(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__26(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__27(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__29(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__30(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__31(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__38(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
