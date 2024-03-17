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
    VL_IN8(clk_i,0,0);
    VL_IN8(player_1_move_i,3,0);
    VL_IN8(player_2_move_i,3,0);
    VL_OUT8(display_enable_o,0,0);
    VL_OUT8(blue_o,7,0);
    VL_OUT8(green_o,7,0);
    VL_OUT8(red_o,7,0);
    VL_OUT8(player_1_collide_with_wall_top_o,0,0);
    VL_OUT8(player_1_collide_with_wall_bottom_o,0,0);
    VL_OUT8(player_1_collide_with_wall_left_o,0,0);
    VL_OUT8(player_1_collide_with_wall_right_o,0,0);
    VL_IN8(reset_i,0,0);
    VL_OUT16(hpos_o,9,0);
    VL_OUT16(vpos_o,9,0);
    VL_OUT16(player_1_x_o,9,0);
    VL_OUT16(player_1_y_o,9,0);
    VL_OUT16(player_2_x_o,9,0);
    VL_OUT16(player_2_y_o,9,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top__DOT__top__DOT__clk_slow;
    CData/*0:0*/ top__DOT__top__DOT__hsync;
    CData/*0:0*/ top__DOT__top__DOT__map_enable;
    CData/*0:0*/ top__DOT__top__DOT__cannot_walk_through;
    CData/*7:0*/ top__DOT__top__DOT__map_blue;
    CData/*7:0*/ top__DOT__top__DOT__map_green;
    CData/*7:0*/ top__DOT__top__DOT__map_red;
    CData/*7:0*/ top__DOT__top__DOT__player_red;
    CData/*7:0*/ top__DOT__top__DOT__player_green;
    CData/*7:0*/ top__DOT__top__DOT__player_blue;
    CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__hsync;
    CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed;
    CData/*0:0*/ top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed;
    CData/*2:0*/ top__DOT__top__DOT__map_rgb__DOT__block_type;
    CData/*3:0*/ top__DOT__top__DOT__map_rgb__DOT__block_state;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_box;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_box;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left;
    CData/*0:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right;
    CData/*3:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct;
    CData/*3:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_xofs;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_yofs;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_xofs;
    CData/*4:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_yofs;
    SData/*9:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_x;
    SData/*9:0*/ top__DOT__top__DOT__player_rgb__DOT__player_1_y;
    SData/*9:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_x;
    SData/*9:0*/ top__DOT__top__DOT__player_rgb__DOT__player_2_y;
    SData/*9:0*/ top__DOT__top__DOT__player_rgb__DOT__addr_1;
    SData/*9:0*/ top__DOT__top__DOT__player_rgb__DOT__addr_2;
    IData/*23:0*/ top__DOT__top__DOT__map_rgb__DOT__dout;
    IData/*24:0*/ top__DOT__top__DOT__speed_control__DOT__count;
    IData/*23:0*/ top__DOT__top__DOT__player_rgb__DOT__dout_1;
    IData/*23:0*/ top__DOT__top__DOT__player_rgb__DOT__dout_2;
    CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT__map_tiles[13][13];
    IData/*23:0*/ top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem[8192];
    IData/*23:0*/ top__DOT__top__DOT__player_rgb__DOT__mem_player_1__DOT__mem[2048];
    IData/*23:0*/ top__DOT__top__DOT__player_rgb__DOT__mem_player_2__DOT__mem[2048];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT____Vxrand2;
    CData/*6:0*/ top__DOT__top__DOT__map_rgb__DOT____Vxrand1;
    CData/*0:0*/ __VinpClk__TOP__top__DOT__top__DOT__clk_slow;
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow;
    CData/*0:0*/ __Vclklast__TOP__top__DOT__top__DOT__hsync;
    CData/*0:0*/ __Vchglast__TOP__top__DOT__top__DOT__clk_slow;
    SData/*9:0*/ __Vdly__hpos_o;
    SData/*9:0*/ __Vdly__vpos_o;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y;
    
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
    static void _multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
