// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*255:0*/ __Vtemp1[8];
    WData/*255:0*/ __Vtemp2[8];
    WData/*191:0*/ __Vtemp3[6];
    WData/*255:0*/ __Vtemp4[8];
    WData/*255:0*/ __Vtemp5[8];
    WData/*223:0*/ __Vtemp6[7];
    // Body
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x65725f31U;
    __Vtemp1[2U] = 0x706c6179U;
    __Vtemp1[3U] = 0x7267625fU;
    __Vtemp1[4U] = 0x6269745fU;
    __Vtemp1[5U] = 0x622f3234U;
    __Vtemp1[6U] = 0x745f7267U;
    __Vtemp1[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp1)
                 , vlTOPp->top__DOT__top__DOT__score__DOT__tank_player_1__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e747874U;
    __Vtemp2[1U] = 0x65725f32U;
    __Vtemp2[2U] = 0x706c6179U;
    __Vtemp2[3U] = 0x7267625fU;
    __Vtemp2[4U] = 0x6269745fU;
    __Vtemp2[5U] = 0x622f3234U;
    __Vtemp2[6U] = 0x745f7267U;
    __Vtemp2[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp2)
                 , vlTOPp->top__DOT__top__DOT__score__DOT__tank_player_2__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp3[0U] = 0x2e62696eU;
    __Vtemp3[1U] = 0x5f6d6f64U;
    __Vtemp3[2U] = 0x74657874U;
    __Vtemp3[3U] = 0x6369695fU;
    __Vtemp3[4U] = 0x6c2f6173U;
    __Vtemp3[5U] = 0x70697865U;
    VL_READMEM_N(false, 8, 1024, 0, VL_CVT_PACK_STR_NW(6, __Vtemp3)
                 , vlTOPp->top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp4[0U] = 0x2e747874U;
    __Vtemp4[1U] = 0x65725f31U;
    __Vtemp4[2U] = 0x706c6179U;
    __Vtemp4[3U] = 0x7267625fU;
    __Vtemp4[4U] = 0x6269745fU;
    __Vtemp4[5U] = 0x622f3234U;
    __Vtemp4[6U] = 0x745f7267U;
    __Vtemp4[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp4)
                 , vlTOPp->top__DOT__top__DOT__mem_player_1__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp5[0U] = 0x2e747874U;
    __Vtemp5[1U] = 0x65725f32U;
    __Vtemp5[2U] = 0x706c6179U;
    __Vtemp5[3U] = 0x7267625fU;
    __Vtemp5[4U] = 0x6269745fU;
    __Vtemp5[5U] = 0x622f3234U;
    __Vtemp5[6U] = 0x745f7267U;
    __Vtemp5[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp5)
                 , vlTOPp->top__DOT__top__DOT__mem_player_2__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand5 
        = VL_RAND_RESET_I(6);
    vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand4 
        = VL_RAND_RESET_I(6);
    vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand3 
        = VL_RAND_RESET_I(6);
    vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand2 
        = VL_RAND_RESET_I(6);
    vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand1 
        = VL_RAND_RESET_I(6);
    __Vtemp6[0U] = 0x2e747874U;
    __Vtemp6[1U] = 0x5f6d6170U;
    __Vtemp6[2U] = 0x5f726762U;
    __Vtemp6[3U] = 0x34626974U;
    __Vtemp6[4U] = 0x67622f32U;
    __Vtemp6[5U] = 0x69745f72U;
    __Vtemp6[6U] = 0x323462U;
    VL_READMEM_N(true, 24, 8192, 0, VL_CVT_PACK_STR_NW(7, __Vtemp6)
                 , vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1 
        = VL_RAND_RESET_I(7);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2 
        = VL_RAND_RESET_I(7);
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[0U] = 0xcU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[1U] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[2U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[3U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[4U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[5U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[6U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[7U] = 0xdU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[8U] = 0x13U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[9U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer[0xaU] = 0x23U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer[0U] = 0x17U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer[1U] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer[2U] = 0x1aU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer[3U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer[4U] = 2U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer[0U] = 0x17U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer[1U] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer[2U] = 0x1aU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer[3U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer[4U] = 3U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer[0U] = 0x17U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer[1U] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer[2U] = 0x1aU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer[3U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer[4U] = 4U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer[0U] = 0x17U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer[1U] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer[2U] = 0x1aU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer[3U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer[4U] = 5U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__arrow = 0U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos = 9U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__a;
    IData/*24:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__count;
    IData/*24:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__count2;
    // Body
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__count;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__a 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__a;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count2 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count 
        = (0x1ffffffU & ((IData)(1U) + vlTOPp->top__DOT__top__DOT__speed_control__DOT__count));
    if ((0x30d40U == vlTOPp->top__DOT__top__DOT__speed_control__DOT__count)) {
        vlTOPp->top__DOT__top__DOT__clk_player = (1U 
                                                  & (~ (IData)(vlTOPp->top__DOT__top__DOT__clk_player)));
        __Vdly__top__DOT__top__DOT__speed_control__DOT__count = 0U;
    }
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count2 
        = (0x1ffffffU & ((IData)(1U) + vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2));
    if ((0x124f8U == vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2)) {
        vlTOPp->top__DOT__top__DOT__clk_bullet = (1U 
                                                  & (~ (IData)(vlTOPp->top__DOT__top__DOT__clk_bullet)));
        __Vdly__top__DOT__top__DOT__speed_control__DOT__count2 = 0U;
    }
    __Vdly__top__DOT__top__DOT__speed_control__DOT__a 
        = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__speed_control__DOT__a)));
    vlTOPp->top__DOT__top__DOT__VGA_clk = vlTOPp->top__DOT__top__DOT__speed_control__DOT__a;
    vlTOPp->top__DOT__top__DOT__speed_control__DOT__count 
        = __Vdly__top__DOT__top__DOT__speed_control__DOT__count;
    vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2 
        = __Vdly__top__DOT__top__DOT__speed_control__DOT__count2;
    vlTOPp->top__DOT__top__DOT__speed_control__DOT__a 
        = __Vdly__top__DOT__top__DOT__speed_control__DOT__a;
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_clk_o = vlTOPp->top__DOT__top__DOT__VGA_clk;
    vlTOPp->vsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__vsync)));
    vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up 
        = (1U & (((IData)(vlTOPp->player_1_move_i) 
                  >> 1U) & (~ (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up_edge_dect__DOT__sig_dly))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down 
        = (1U & ((IData)(vlTOPp->player_1_move_i) & 
                 (~ (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down_edge_dect__DOT__sig_dly))));
    vlTOPp->hsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync)));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot 
        = ((IData)(vlTOPp->player_1_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__pos_edge_detect_1__DOT__sig_dly)));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot 
        = ((IData)(vlTOPp->player_2_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__pos_edge_detect_1__DOT__sig_dly)));
    vlTOPp->hpos_o = vlTOPp->top__DOT__top__DOT__hpos;
    vlTOPp->vpos_o = vlTOPp->top__DOT__top__DOT__vpos;
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed 
        = (0x31fU == (IData)(vlTOPp->top__DOT__top__DOT__hpos));
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed 
        = (0x20cU == (IData)(vlTOPp->top__DOT__top__DOT__vpos));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box 
        = ((((0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
             & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
            & (0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                         - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
           & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box 
        = ((((0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
             & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
            & (0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                         - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
           & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable 
        = (((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          >> 7U))) & (4U < (0x1fU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                             >> 5U)))) 
           & (0x10U > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1 = (
                                                   ((9U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2 = (
                                                   ((0xaU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3 = (
                                                   ((0xbU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4 = (
                                                   ((0xcU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__display_enable = ((0x280U 
                                                   > (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
                                                  & (0x1e0U 
                                                     > (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
    vlTOPp->top__DOT__top__DOT__player_1_bits = vlTOPp->top__DOT__top__DOT__mem_player_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_1_addr];
    vlTOPp->top__DOT__top__DOT__player_2_bits = vlTOPp->top__DOT__top__DOT__mem_player_2__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_2_addr];
    vlTOPp->top__DOT__top__DOT__map_type = ((9U == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                             ? 0U : 
                                            ((0xaU 
                                              == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                              ? 1U : 
                                             ((0xbU 
                                               == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                               ? 2U
                                               : ((0xcU 
                                                   == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                                   ? 3U
                                                   : 0U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_en 
        = ((((0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       >> 5U)) == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos)) 
            & (0xeU < (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 4U)))) & (0x10U 
                                             > (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                   >> 4U))));
    vlTOPp->top__DOT__top__DOT__player_1_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)));
    vlTOPp->top__DOT__top__DOT__player_2_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)));
    vlTOPp->display_enable_o = vlTOPp->top__DOT__top__DOT__display_enable;
    vlTOPp->top__DOT__top__DOT__map_enable = (((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
                                                 & (0x20U 
                                                    <= (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                                                & (0x1bfU 
                                                   >= (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                                               & (0x20U 
                                                  <= (IData)(vlTOPp->top__DOT__top__DOT__vpos))) 
                                              & (0x1bfU 
                                                 >= (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
    vlTOPp->top__DOT__top__DOT__player_1_blue = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
                                                  & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box))
                                                  ? 
                                                 (0xffU 
                                                  & (vlTOPp->top__DOT__top__DOT__player_1_bits 
                                                     >> 0x10U))
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__player_1_red = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
                                                 & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box))
                                                 ? 
                                                (0xffU 
                                                 & vlTOPp->top__DOT__top__DOT__player_1_bits)
                                                 : 0U);
    vlTOPp->top__DOT__top__DOT__player_1_green = ((
                                                   (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
                                                   & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box))
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->top__DOT__top__DOT__player_1_bits 
                                                      >> 8U))
                                                   : 0U);
    vlTOPp->top__DOT__top__DOT__player_2_blue = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
                                                  & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box))
                                                  ? 
                                                 (0xffU 
                                                  & (vlTOPp->top__DOT__top__DOT__player_2_bits 
                                                     >> 0x10U))
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__player_2_red = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
                                                 & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box))
                                                 ? 
                                                (0xffU 
                                                 & vlTOPp->top__DOT__top__DOT__player_2_bits)
                                                 : 0U);
    vlTOPp->top__DOT__top__DOT__player_2_green = ((
                                                   (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
                                                   & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box))
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->top__DOT__top__DOT__player_2_bits 
                                                      >> 8U))
                                                   : 0U);
    vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs = 0U;
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map1) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map2) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map3) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map4) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_en) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr = 0U;
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((0xaU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(5U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 5U) - (IData)(5U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand1)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map1) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand2)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map2) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand3)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map3) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand4)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map4) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand5)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_en) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = (((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (7U & (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                         >> 5U) - (IData)(1U))))
                       ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                      [((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                           >> 5U) - (IData)(1U))))
                         ? (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                     >> 5U) - (IData)(1U)))
                         : 0U)][(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                          >> 5U) - (IData)(1U)))]
                       : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1)) 
                     >> 4U)) : 7U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (0xfU & ((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                          >> 5U) - (IData)(1U))))
                        ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                       [((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                            >> 5U) 
                                           - (IData)(1U))))
                          ? (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                      >> 5U) - (IData)(1U)))
                          : 0U)][(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                           >> 5U) - (IData)(1U)))]
                        : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2)))
            : 0U);
    vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number 
        = vlTOPp->top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem
        [vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
        [(((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type) 
           << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  << 5U)) | (0x1fU 
                                             & (IData)(vlTOPp->top__DOT__top__DOT__hpos))))];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 1U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 2U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 3U));
    vlTOPp->top__DOT__top__DOT__menu_blue = ((1U & 
                                              ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number) 
                                               >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)))
                                              ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_green = ((1U & 
                                               ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number) 
                                                >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)))
                                               ? 0U
                                               : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_red = ((1U & ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number) 
                                                   >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)))
                                             ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__all_hard_block = ((
                                                   ((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
                                                          & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable))) 
                                                         | ((0U 
                                                             == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                            & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
                                                        | ((0U 
                                                            == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                           & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                                                       | ((0U 
                                                           == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                          & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
                                                      | ((0U 
                                                          == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
                                                     | ((1U 
                                                         == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                        & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
                                                    | ((1U 
                                                        == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                       & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                                                   | ((1U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
                                                  | ((1U 
                                                      == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                     & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__cannot_walk_through 
        = (((((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
                    & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable))) 
                   | (3U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type))) 
                  | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                     & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
                 | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                    & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                   & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
               | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                  & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
              | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
             | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
            | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
               & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
           | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
              & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__map_red = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                            | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                            ? (0xffU 
                                               & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout)
                                            : 0U);
    vlTOPp->top__DOT__top__DOT__map_blue = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                             ? (0xffU 
                                                & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                   >> 0x10U))
                                             : 0U);
    vlTOPp->top__DOT__top__DOT__map_green = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                              ? (0xffU 
                                                 & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                    >> 8U))
                                              : 0U);
    vlTOPp->top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i 
        = ((IData)(vlTOPp->top__DOT__top__DOT__cannot_walk_through) 
           | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player));
    vlTOPp->top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i 
        = ((IData)(vlTOPp->top__DOT__top__DOT__cannot_walk_through) 
           | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player));
    vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable 
        = (((0U != (IData)(vlTOPp->top__DOT__top__DOT__map_blue)) 
            | (0U != (IData)(vlTOPp->top__DOT__top__DOT__map_green))) 
           | (0U != (IData)(vlTOPp->top__DOT__top__DOT__map_green)));
    vlTOPp->red_o = 0U;
    if (vlTOPp->top__DOT__top__DOT__display_enable) {
        if (vlTOPp->top__DOT__top__DOT__is_menu) {
            vlTOPp->red_o = vlTOPp->top__DOT__top__DOT__menu_red;
        } else {
            if (vlTOPp->top__DOT__top__DOT__is_playing) {
                vlTOPp->red_o = (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                                           ? (((IData)(vlTOPp->top__DOT__top__DOT__map_red) 
                                               | ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable)
                                                   ? 0U
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__top__DOT__player_1_red) 
                                                   | (IData)(vlTOPp->top__DOT__top__DOT__player_2_red)))) 
                                              | (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                  | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))
                                                  ? 0xffffffU
                                                  : 0U))
                                           : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_enable_i)
                                               ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_red_i)
                                               : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_enable_i)
                                                   ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_red_i)
                                                   : 0xe0U))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_continue) {
                    vlTOPp->red_o = 0xe0U;
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_final) {
                        vlTOPp->red_o = 0xe0U;
                    }
                }
            }
        }
    } else {
        vlTOPp->red_o = 0U;
    }
    vlTOPp->blue_o = 0U;
    if (vlTOPp->top__DOT__top__DOT__display_enable) {
        if (vlTOPp->top__DOT__top__DOT__is_menu) {
            vlTOPp->blue_o = vlTOPp->top__DOT__top__DOT__menu_blue;
        } else {
            if (vlTOPp->top__DOT__top__DOT__is_playing) {
                vlTOPp->blue_o = (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                                            ? (((IData)(vlTOPp->top__DOT__top__DOT__map_blue) 
                                                | ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable)
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__top__DOT__player_1_blue) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__player_2_blue)))) 
                                               | ((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))
                                                    ? 0xffffffU
                                                    : 0U) 
                                                  >> 0x10U))
                                            : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_enable_i)
                                                ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_blue_i)
                                                : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_enable_i)
                                                    ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_blue_i)
                                                    : 0xe0U))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_continue) {
                    vlTOPp->blue_o = 0xe0U;
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_final) {
                        vlTOPp->blue_o = 0xe0U;
                    }
                }
            }
        }
    } else {
        vlTOPp->blue_o = 0U;
    }
    vlTOPp->green_o = 0U;
    if (vlTOPp->top__DOT__top__DOT__display_enable) {
        if (vlTOPp->top__DOT__top__DOT__is_menu) {
            vlTOPp->green_o = vlTOPp->top__DOT__top__DOT__menu_green;
        } else {
            if (vlTOPp->top__DOT__top__DOT__is_playing) {
                vlTOPp->green_o = (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                                             ? (((IData)(vlTOPp->top__DOT__top__DOT__map_green) 
                                                 | ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable)
                                                     ? 0U
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__top__DOT__player_1_green) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_2_green)))) 
                                                | ((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))
                                                     ? 0xffffffU
                                                     : 0U) 
                                                   >> 8U))
                                             : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_enable_i)
                                                 ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_green_i)
                                                 : 
                                                ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_enable_i)
                                                  ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_green_i)
                                                  : 0xe0U))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_continue) {
                    vlTOPp->green_o = 0xe0U;
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_final) {
                        vlTOPp->green_o = 0xe0U;
                    }
                }
            }
        }
    } else {
        vlTOPp->green_o = 0U;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y = 0x1a0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                    = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y) 
                                             - (IData)(1U)));
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)));
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x = 0xa0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                    = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x) 
                                             - (IData)(1U)));
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)));
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y = 0x1a0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                    = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y) 
                                             - (IData)(1U)));
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)));
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x = 0x120U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                    = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x) 
                                             - (IData)(1U)));
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)));
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
    // Body
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
    if (((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage)) 
         & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x) 
                                         - (IData)(1U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)));
                    }
                }
            }
        }
    }
    if (((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage)) 
         & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y) 
                                         - (IData)(1U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)));
                    }
                }
            }
        }
    }
    if (((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage)) 
         & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x) 
                                         - (IData)(1U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)));
                    }
                }
            }
        }
    }
    if (((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage)) 
         & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y) 
                                         - (IData)(1U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)));
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
}

VL_INLINE_OPT void Vtop::_combo__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_clk_o = vlTOPp->top__DOT__top__DOT__VGA_clk;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward;
    // Body
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs_backward;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs_backward;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs;
    vlTOPp->__Vdly__top__DOT__top__DOT__vpos = vlTOPp->top__DOT__top__DOT__vpos;
    vlTOPp->__Vdly__top__DOT__top__DOT__hpos = vlTOPp->top__DOT__top__DOT__hpos;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__pos_edge_detect_1__DOT__sig_dly 
        = vlTOPp->player_2_shoot_i;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__pos_edge_detect_1__DOT__sig_dly 
        = vlTOPp->player_1_shoot_i;
    vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down_edge_dect__DOT__sig_dly 
        = (1U & (IData)(vlTOPp->player_1_move_i));
    vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up_edge_dect__DOT__sig_dly 
        = (1U & ((IData)(vlTOPp->player_1_move_i) >> 1U));
    if (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))) {
        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward = 0x1fU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))) {
        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs = 2U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs))) {
            __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))) {
        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward = 0x1fU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))) {
        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs = 2U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs))) {
            __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs)));
        }
    }
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__vsync 
        = ((0x1e9U <= (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
           & (0x1eaU >= (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
    if ((0x31fU == (IData)(vlTOPp->top__DOT__top__DOT__hpos))) {
        vlTOPp->__Vdly__top__DOT__top__DOT__vpos = 
            ((IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed)
              ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__vpos))));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_2_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs_backward));
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_2_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs));
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_2_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward));
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                    vlTOPp->top__DOT__top__DOT__player_2_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs));
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs_backward));
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs));
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward));
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                    vlTOPp->top__DOT__top__DOT__player_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs));
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync 
        = ((0x28fU <= (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
           & (0x2eeU >= (IData)(vlTOPp->top__DOT__top__DOT__hpos)));
    vlTOPp->__Vdly__top__DOT__top__DOT__hpos = ((IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed)
                                                 ? 0U
                                                 : 
                                                (0x3ffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlTOPp->top__DOT__top__DOT__hpos))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs_backward 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs_backward 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs;
    vlTOPp->vsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__vsync)));
    vlTOPp->top__DOT__top__DOT__player_2_bits = vlTOPp->top__DOT__top__DOT__mem_player_2__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_2_addr];
    vlTOPp->top__DOT__top__DOT__player_1_bits = vlTOPp->top__DOT__top__DOT__mem_player_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_1_addr];
    vlTOPp->hsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_2 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__score_player_2;
    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_1 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__score_player_1;
    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state;
    __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos 
        = vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos;
    if (vlTOPp->reset_i) {
        __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos = 9U;
    } else {
        if (((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down) 
             & (0xcU > (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos)))) {
            __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos)));
        } else {
            if (vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down) {
                __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos = 9U;
            }
        }
        if (((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up) 
             & (9U < (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos)))) {
            __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos) 
                            - (IData)(1U)));
        } else {
            if (vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up) {
                __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos = 0xcU;
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos 
        = __Vdly__top__DOT__top__DOT__menu__DOT__arrow_pos;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__9\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679;
    CData/*1:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage;
    CData/*1:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage;
    // Body
    __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage;
    __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679 = 0U;
    if (vlTOPp->top__DOT__top__DOT__reset) {
        __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage))) {
            vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet = 0U;
            vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_dir 
                = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct;
            if (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot) 
                 & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)))) {
                __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet = 1U;
                if ((((IData)(vlTOPp->top__DOT__top__DOT__all_hard_block) 
                      | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player)) 
                     & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet))) {
                    __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage = 2U;
                    vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage))) {
                    __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage = 0U;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage))) {
            vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet = 0U;
            vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_dir 
                = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct;
            if (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot) 
                 & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)))) {
                __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet = 1U;
                if ((((IData)(vlTOPp->top__DOT__top__DOT__all_hard_block) 
                      | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player)) 
                     & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))) {
                    __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage = 2U;
                    vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage))) {
                    __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage = 0U;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_type))) {
            __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0 = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_type))) {
                __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 1U;
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__map_type))) {
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338 = 1U;
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__top__DOT__map_type))) {
                        __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507 = 1U;
                    }
                }
            }
        }
    } else {
        if (((((((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL)) 
                | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                   & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
               | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                  & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
              | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet) 
                | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet)))) {
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound3 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound3;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 = 0U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                    >> 5U) - (IData)(1U)));
                }
            }
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound4 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound4;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677 = 1U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                    >> 5U) - (IData)(1U)));
                }
            }
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound5 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound5;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678 = 2U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                    >> 5U) - (IData)(1U)));
                }
            }
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound6 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound6;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679 = 3U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                    >> 5U) - (IData)(1U)));
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage;
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 9U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 9U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x1fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v677)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v678)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v679)));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__10\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
    // Body
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs;
    if (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) {
        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward = 0x1eU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) {
        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs = 2U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs))) {
            __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) {
        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward = 0x1eU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) {
        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs = 2U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs))) {
            __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs)));
        }
    }
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs;
}

VL_INLINE_OPT void Vtop::_combo__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__11\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down 
        = (1U & ((IData)(vlTOPp->player_1_move_i) & 
                 (~ (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_down_edge_dect__DOT__sig_dly))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up 
        = (1U & (((IData)(vlTOPp->player_1_move_i) 
                  >> 1U) & (~ (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__sellect_up_edge_dect__DOT__sig_dly))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__12\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable) 
         & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))) {
        vlTOPp->top__DOT__top__DOT__player_2_die = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
         & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet))) {
        vlTOPp->top__DOT__top__DOT__player_1_die = 1U;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__13(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__13\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct = 2U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left)))) {
                            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct = 8U;
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right)))) {
                            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct = 4U;
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top)))) {
                            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct = 2U;
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct = 1U;
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct = 2U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left)))) {
                            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct = 8U;
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right)))) {
                            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct = 4U;
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top)))) {
                            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct = 2U;
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct = 1U;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__14(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__14\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__map_type = ((9U == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                             ? 0U : 
                                            ((0xaU 
                                              == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                              ? 1U : 
                                             ((0xbU 
                                               == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                               ? 2U
                                               : ((0xcU 
                                                   == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos))
                                                   ? 3U
                                                   : 0U))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__15(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__15\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 0U;
    } else {
        if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                      >> 3U)))) {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 0U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i) {
            if ((((0U == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 0U;
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 0U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i) {
            if ((((0x1fU == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            } else {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i) {
            if ((((0U == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i) {
            if ((((0x1fU == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 0U;
    } else {
        if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                      >> 3U)))) {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 0U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i) {
            if ((((0U == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 0U;
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 0U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i) {
            if ((((0x1fU == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            } else {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i) {
            if ((((0U == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot) {
            vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 0U;
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i) {
            if ((((0x1fU == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
                  & (0x1dU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                               - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
                 & (2U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 1U;
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__16(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__16\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot 
        = ((IData)(vlTOPp->player_2_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__pos_edge_detect_1__DOT__sig_dly)));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot 
        = ((IData)(vlTOPp->player_1_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__pos_edge_detect_1__DOT__sig_dly)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__17(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__17\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__18(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__18\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_1 = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_2 = 0U;
    } else {
        vlTOPp->top__DOT__top__DOT__is_menu = 0U;
        vlTOPp->top__DOT__top__DOT__is_playing = 0U;
        vlTOPp->top__DOT__top__DOT__is_continue = 0U;
        vlTOPp->top__DOT__top__DOT__is_final = 0U;
        vlTOPp->top__DOT__top__DOT__reset = 1U;
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
            vlTOPp->top__DOT__top__DOT__is_menu = 1U;
            vlTOPp->top__DOT__top__DOT__reset = 1U;
            if (vlTOPp->player_1_shoot_i) {
                vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                vlTOPp->top__DOT__top__DOT__reset = 0U;
                vlTOPp->top__DOT__top__DOT__is_playing = 1U;
                if (((IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__bullet_collide_player_1_i) 
                     & (~ (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__pos_edge_detect_bullet_1__DOT__sig_dly)))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_2 
                        = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__score_player_2)));
                    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
                }
                if (((IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__bullet_collide_player_2_i) 
                     & (~ (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__pos_edge_detect_bullet_2__DOT__sig_dly)))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_1 
                        = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__score_player_1)));
                    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                    vlTOPp->top__DOT__top__DOT__is_continue = 1U;
                    vlTOPp->top__DOT__top__DOT__reset = 1U;
                    if (vlTOPp->player_1_shoot_i) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 1U;
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                        vlTOPp->top__DOT__top__DOT__is_final = 1U;
                    } else {
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state 
        = vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state;
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__score_player_1 
        = vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_1;
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__score_player_2 
        = vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_2;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__19(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__19\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__vpos = vlTOPp->__Vdly__top__DOT__top__DOT__vpos;
    vlTOPp->top__DOT__top__DOT__hpos = vlTOPp->__Vdly__top__DOT__top__DOT__hpos;
    vlTOPp->vpos_o = vlTOPp->top__DOT__top__DOT__vpos;
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed 
        = (0x20cU == (IData)(vlTOPp->top__DOT__top__DOT__vpos));
    vlTOPp->hpos_o = vlTOPp->top__DOT__top__DOT__hpos;
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed 
        = (0x31fU == (IData)(vlTOPp->top__DOT__top__DOT__hpos));
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable 
        = (((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          >> 7U))) & (4U < (0x1fU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                             >> 5U)))) 
           & (0x10U > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map1 = (
                                                   ((9U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map2 = (
                                                   ((0xaU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map3 = (
                                                   ((0xbU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__map4 = (
                                                   ((0xcU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                                         >> 5U))) 
                                                    & (0x10U 
                                                       < 
                                                       (0x3fU 
                                                        & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                           >> 4U)))) 
                                                   & (0x16U 
                                                      > 
                                                      (0x3fU 
                                                       & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                          >> 4U))));
    vlTOPp->top__DOT__top__DOT__display_enable = ((0x280U 
                                                   > (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
                                                  & (0x1e0U 
                                                     > (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__pos_edge_detect_bullet_1__DOT__sig_dly 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__bullet_collide_player_1_i;
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__pos_edge_detect_bullet_2__DOT__sig_dly 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__bullet_collide_player_2_i;
    vlTOPp->display_enable_o = vlTOPp->top__DOT__top__DOT__display_enable;
    vlTOPp->top__DOT__top__DOT__map_enable = (((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
                                                 & (0x20U 
                                                    <= (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                                                & (0x1bfU 
                                                   >= (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                                               & (0x20U 
                                                  <= (IData)(vlTOPp->top__DOT__top__DOT__vpos))) 
                                              & (0x1bfU 
                                                 >= (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__20(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__20\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__21(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__21\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box 
        = ((((0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
             & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
            & (0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                         - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
           & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box 
        = ((((0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
             & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
            & (0x1eU >= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                         - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
           & (1U <= ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))));
    vlTOPp->top__DOT__top__DOT__player_1_blue = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
                                                  & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box))
                                                  ? 
                                                 (0xffU 
                                                  & (vlTOPp->top__DOT__top__DOT__player_1_bits 
                                                     >> 0x10U))
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__player_1_red = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
                                                 & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box))
                                                 ? 
                                                (0xffU 
                                                 & vlTOPp->top__DOT__top__DOT__player_1_bits)
                                                 : 0U);
    vlTOPp->top__DOT__top__DOT__player_1_green = ((
                                                   (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
                                                   & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box))
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->top__DOT__top__DOT__player_1_bits 
                                                      >> 8U))
                                                   : 0U);
    vlTOPp->top__DOT__top__DOT__player_1_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)));
    vlTOPp->top__DOT__top__DOT__player_2_blue = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
                                                  & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box))
                                                  ? 
                                                 (0xffU 
                                                  & (vlTOPp->top__DOT__top__DOT__player_2_bits 
                                                     >> 0x10U))
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__player_2_red = (((~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
                                                 & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box))
                                                 ? 
                                                (0xffU 
                                                 & vlTOPp->top__DOT__top__DOT__player_2_bits)
                                                 : 0U);
    vlTOPp->top__DOT__top__DOT__player_2_green = ((
                                                   (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
                                                   & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box))
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->top__DOT__top__DOT__player_2_bits 
                                                      >> 8U))
                                                   : 0U);
    vlTOPp->top__DOT__top__DOT__player_2_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)));
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__22(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__22\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_en 
        = ((((0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       >> 5U)) == (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_pos)) 
            & (0xeU < (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 4U)))) & (0x10U 
                                             > (0x3fU 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                   >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs = 0U;
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map1) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map2) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map3) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map4) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_en) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr = 0U;
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((0xaU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(5U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__title_buffer
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 5U) - (IData)(5U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand1)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map1) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map1_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand2)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map2) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map2_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand3)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map3) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map3_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand4)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__map4) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((4U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(1U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__map4_buffer
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(1U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand5)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__arrow_en) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = (((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__arrow) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number 
        = vlTOPp->top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem
        [vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr];
    vlTOPp->top__DOT__top__DOT__menu_blue = ((1U & 
                                              ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number) 
                                               >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)))
                                              ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_green = ((1U & 
                                               ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number) 
                                                >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)))
                                               ? 0U
                                               : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_red = ((1U & ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__bit_number) 
                                                   >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)))
                                             ? 0U : 0xe0U);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__23(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__23\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (7U & (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                         >> 5U) - (IData)(1U))))
                       ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                      [((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                           >> 5U) - (IData)(1U))))
                         ? (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                     >> 5U) - (IData)(1U)))
                         : 0U)][(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                          >> 5U) - (IData)(1U)))]
                       : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1)) 
                     >> 4U)) : 7U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (0xfU & ((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                          >> 5U) - (IData)(1U))))
                        ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                       [((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                            >> 5U) 
                                           - (IData)(1U))))
                          ? (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                      >> 5U) - (IData)(1U)))
                          : 0U)][(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                           >> 5U) - (IData)(1U)))]
                        : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2)))
            : 0U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
        [(((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type) 
           << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  << 5U)) | (0x1fU 
                                             & (IData)(vlTOPp->top__DOT__top__DOT__hpos))))];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 1U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 2U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 3U));
    vlTOPp->top__DOT__top__DOT__all_hard_block = ((
                                                   ((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
                                                          & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable))) 
                                                         | ((0U 
                                                             == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                            & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
                                                        | ((0U 
                                                            == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                           & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                                                       | ((0U 
                                                           == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                          & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
                                                      | ((0U 
                                                          == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
                                                     | ((1U 
                                                         == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                        & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
                                                    | ((1U 
                                                        == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                       & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                                                   | ((1U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
                                                  | ((1U 
                                                      == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                     & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__cannot_walk_through 
        = (((((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
                    & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable))) 
                   | (3U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type))) 
                  | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                     & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
                 | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                    & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                   & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
               | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                  & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
              | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
             | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
            | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
               & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
           | ((1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
              & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__map_red = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                            | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                            ? (0xffU 
                                               & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout)
                                            : 0U);
    vlTOPp->top__DOT__top__DOT__map_blue = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                             ? (0xffU 
                                                & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                   >> 0x10U))
                                             : 0U);
    vlTOPp->top__DOT__top__DOT__map_green = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                              ? (0xffU 
                                                 & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                    >> 8U))
                                              : 0U);
    vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable 
        = (((0U != (IData)(vlTOPp->top__DOT__top__DOT__map_blue)) 
            | (0U != (IData)(vlTOPp->top__DOT__top__DOT__map_green))) 
           | (0U != (IData)(vlTOPp->top__DOT__top__DOT__map_green)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__24(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__24\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i 
        = ((IData)(vlTOPp->top__DOT__top__DOT__cannot_walk_through) 
           | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player));
    vlTOPp->top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i 
        = ((IData)(vlTOPp->top__DOT__top__DOT__cannot_walk_through) 
           | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__25(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__25\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->red_o = 0U;
    if (vlTOPp->top__DOT__top__DOT__display_enable) {
        if (vlTOPp->top__DOT__top__DOT__is_menu) {
            vlTOPp->red_o = vlTOPp->top__DOT__top__DOT__menu_red;
        } else {
            if (vlTOPp->top__DOT__top__DOT__is_playing) {
                vlTOPp->red_o = (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                                           ? (((IData)(vlTOPp->top__DOT__top__DOT__map_red) 
                                               | ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable)
                                                   ? 0U
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__top__DOT__player_1_red) 
                                                   | (IData)(vlTOPp->top__DOT__top__DOT__player_2_red)))) 
                                              | (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                  | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))
                                                  ? 0xffffffU
                                                  : 0U))
                                           : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_enable_i)
                                               ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_red_i)
                                               : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_enable_i)
                                                   ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_red_i)
                                                   : 0xe0U))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_continue) {
                    vlTOPp->red_o = 0xe0U;
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_final) {
                        vlTOPp->red_o = 0xe0U;
                    }
                }
            }
        }
    } else {
        vlTOPp->red_o = 0U;
    }
    vlTOPp->blue_o = 0U;
    if (vlTOPp->top__DOT__top__DOT__display_enable) {
        if (vlTOPp->top__DOT__top__DOT__is_menu) {
            vlTOPp->blue_o = vlTOPp->top__DOT__top__DOT__menu_blue;
        } else {
            if (vlTOPp->top__DOT__top__DOT__is_playing) {
                vlTOPp->blue_o = (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                                            ? (((IData)(vlTOPp->top__DOT__top__DOT__map_blue) 
                                                | ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable)
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__top__DOT__player_1_blue) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__player_2_blue)))) 
                                               | ((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))
                                                    ? 0xffffffU
                                                    : 0U) 
                                                  >> 0x10U))
                                            : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_enable_i)
                                                ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_blue_i)
                                                : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_enable_i)
                                                    ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_blue_i)
                                                    : 0xe0U))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_continue) {
                    vlTOPp->blue_o = 0xe0U;
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_final) {
                        vlTOPp->blue_o = 0xe0U;
                    }
                }
            }
        }
    } else {
        vlTOPp->blue_o = 0U;
    }
    vlTOPp->green_o = 0U;
    if (vlTOPp->top__DOT__top__DOT__display_enable) {
        if (vlTOPp->top__DOT__top__DOT__is_menu) {
            vlTOPp->green_o = vlTOPp->top__DOT__top__DOT__menu_green;
        } else {
            if (vlTOPp->top__DOT__top__DOT__is_playing) {
                vlTOPp->green_o = (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                                             ? (((IData)(vlTOPp->top__DOT__top__DOT__map_green) 
                                                 | ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable)
                                                     ? 0U
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__top__DOT__player_1_green) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_2_green)))) 
                                                | ((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet))
                                                     ? 0xffffffU
                                                     : 0U) 
                                                   >> 8U))
                                             : ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_enable_i)
                                                 ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__number_green_i)
                                                 : 
                                                ((IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_enable_i)
                                                  ? (IData)(vlTOPp->top__DOT__top__DOT__rgb_render__DOT__tank_green_i)
                                                  : 0xe0U))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_continue) {
                    vlTOPp->green_o = 0xe0U;
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_final) {
                        vlTOPp->green_o = 0xe0U;
                    }
                }
            }
        }
    } else {
        vlTOPp->green_o = 0U;
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if (((IData)(vlTOPp->hsync_no) & (~ (IData)(vlTOPp->__Vclklast__TOP__hsync_no)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    vlTOPp->_combo__TOP__11(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))))) {
        vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    vlTOPp->_combo__TOP__16(vlSymsp);
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__17(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))))) {
        vlTOPp->_sequent__TOP__18(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) {
        vlTOPp->_sequent__TOP__19(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__20(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__21(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))))) {
        vlTOPp->_sequent__TOP__22(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__23(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__24(vlSymsp);
    }
    if (((((((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))) 
            | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__25(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk;
    vlTOPp->__Vclklast__TOP__reset_i = vlTOPp->reset_i;
    vlTOPp->__Vclklast__TOP__hsync_no = vlTOPp->hsync_no;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->top__DOT__top__DOT__clk_player;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->top__DOT__top__DOT__reset;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->top__DOT__top__DOT__clk_bullet;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->top__DOT__top__DOT__VGA_clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk;
    vlTOPp->__Vclklast__TOP__reset_i = vlTOPp->reset_i;
    vlTOPp->__Vclklast__TOP__hsync_no = vlTOPp->hsync_no;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__top__DOT__clk_player ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_player)
         | (vlTOPp->top__DOT__top__DOT__clk_bullet ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_bullet)
         | (vlTOPp->top__DOT__top__DOT__VGA_clk ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__VGA_clk)
         | (vlTOPp->top__DOT__top__DOT__reset ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__reset));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__clk_player ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_player))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:26: top.top.clk_player\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__clk_bullet ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_bullet))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:26: top.top.clk_bullet\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__VGA_clk ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__VGA_clk))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:32: top.top.VGA_clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__reset ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__reset))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:261: top.top.reset\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->top__DOT__top__DOT__clk_player;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->top__DOT__top__DOT__clk_bullet;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->top__DOT__top__DOT__VGA_clk;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->top__DOT__top__DOT__reset;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((player_1_move_i & 0xf0U))) {
        Verilated::overWidthError("player_1_move_i");}
    if (VL_UNLIKELY((player_2_move_i & 0xf0U))) {
        Verilated::overWidthError("player_2_move_i");}
    if (VL_UNLIKELY((player_1_shoot_i & 0xfeU))) {
        Verilated::overWidthError("player_1_shoot_i");}
    if (VL_UNLIKELY((player_2_shoot_i & 0xfeU))) {
        Verilated::overWidthError("player_2_shoot_i");}
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((reset_i & 0xfeU))) {
        Verilated::overWidthError("reset_i");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    player_1_move_i = VL_RAND_RESET_I(4);
    player_2_move_i = VL_RAND_RESET_I(4);
    player_1_shoot_i = VL_RAND_RESET_I(1);
    player_2_shoot_i = VL_RAND_RESET_I(1);
    hsync_no = VL_RAND_RESET_I(1);
    vsync_no = VL_RAND_RESET_I(1);
    hpos_o = VL_RAND_RESET_I(10);
    vpos_o = VL_RAND_RESET_I(10);
    display_enable_o = VL_RAND_RESET_I(1);
    blue_o = VL_RAND_RESET_I(8);
    green_o = VL_RAND_RESET_I(8);
    red_o = VL_RAND_RESET_I(8);
    VGA_clk_o = VL_RAND_RESET_I(1);
    clk_i = VL_RAND_RESET_I(1);
    reset_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__clk_player = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__clk_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__cannot_walk_through = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__all_hard_block = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__menu_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__menu_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__menu_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__hpos = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__vpos = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__map_type = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__display_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__VGA_clk = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_1_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_1_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_1_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_die = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__player_1_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT____Vcellinp__player_1__cannot_walk_through_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_2_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_2_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_2_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2_die = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__player_2_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT____Vcellinp__player_2__cannot_walk_through_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_menu = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_playing = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_continue = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_final = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__reset = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__hvsync_gen__DOT__hsync = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__hvsync_gen__DOT__vsync = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT____Vxrand2 = VL_RAND_RESET_I(7);
    top__DOT__top__DOT__map_rgb__DOT____Vxrand1 = VL_RAND_RESET_I(7);
    top__DOT__top__DOT__map_rgb__DOT__block_type = VL_RAND_RESET_I(3);
    top__DOT__top__DOT__map_rgb__DOT__dout = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__map_rgb__DOT__block_state = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__map_rgb__DOT__UL = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT__UR = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT__LR = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT__LL = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<13; ++__Vi0) {
            { int __Vi1=0; for (; __Vi1<13; ++__Vi1) {
                    top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vi0][__Vi1] = VL_RAND_RESET_I(7);
            }}
    }}
    top__DOT__top__DOT__map_rgb__DOT____Vlvbound3 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT____Vlvbound4 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT____Vlvbound5 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_rgb__DOT____Vlvbound6 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    top__DOT__top__DOT__menu__DOT____Vxrand5 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand4 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand3 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand2 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand1 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT__bit_number = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<11; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__title_buffer[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__map1_buffer[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__map2_buffer[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__map3_buffer[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__map4_buffer[__Vi0] = VL_RAND_RESET_I(6);
    }}
    top__DOT__top__DOT__menu__DOT__arrow = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT__rom_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__menu__DOT__x_ofs = VL_RAND_RESET_I(3);
    top__DOT__top__DOT__menu__DOT__title_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__map1 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__map2 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__map3 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__map4 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__arrow_en = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__sellect_up = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__sellect_down = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__arrow_pos = VL_RAND_RESET_I(5);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__top__DOT__menu__DOT__sellect_up_edge_dect__DOT__sig_dly = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__sellect_down_edge_dect__DOT__sig_dly = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__rgb_render__DOT__number_blue_i = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__rgb_render__DOT__number_green_i = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__rgb_render__DOT__number_red_i = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__rgb_render__DOT__number_enable_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__rgb_render__DOT__tank_blue_i = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__rgb_render__DOT__tank_green_i = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__rgb_render__DOT__tank_red_i = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__rgb_render__DOT__tank_enable_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__rgb_render__DOT__map_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__speed_control__DOT__count = VL_RAND_RESET_I(25);
    top__DOT__top__DOT__speed_control__DOT__count2 = VL_RAND_RESET_I(25);
    top__DOT__top__DOT__speed_control__DOT__a = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1__DOT__tank_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1__DOT__tank_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_prev_direct = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_1__DOT__tank_yofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_1__DOT__tank_xofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_1__DOT__tank_xofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_1__DOT__tank_yofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_1__DOT__tank_bullet_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1__DOT__tank_bullet_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1__DOT__bullet_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__player_1__DOT__bullet_dir = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_1__DOT__show_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_shoot = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__pos_edge_detect_1__DOT__sig_dly = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__mem_player_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    top__DOT__top__DOT__player_2__DOT__tank_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_2__DOT__tank_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_2__DOT__tank_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_prev_direct = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_2__DOT__tank_yofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_2__DOT__tank_xofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_2__DOT__tank_xofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_2__DOT__tank_yofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_2__DOT__tank_bullet_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_2__DOT__tank_bullet_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_2__DOT__bullet_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__player_2__DOT__bullet_dir = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_2__DOT__show_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__tank_shoot = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2__DOT__pos_edge_detect_1__DOT__sig_dly = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__mem_player_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    top__DOT__top__DOT__bullet_collide_1__DOT__all_player = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__game_FSM__DOT__bullet_collide_player_1_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__game_FSM__DOT__bullet_collide_player_2_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__game_FSM__DOT__game_state = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__game_FSM__DOT__score_player_1 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__game_FSM__DOT__score_player_2 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__game_FSM__DOT__pos_edge_detect_bullet_1__DOT__sig_dly = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__game_FSM__DOT__pos_edge_detect_bullet_2__DOT__sig_dly = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__score__DOT__tank_player_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__score__DOT__tank_player_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    __Vdly__top__DOT__top__DOT__hpos = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__vpos = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_1 = VL_RAND_RESET_I(6);
    __Vdly__top__DOT__top__DOT__game_FSM__DOT__score_player_2 = VL_RAND_RESET_I(6);
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_y = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_y = VL_RAND_RESET_I(10);
    __VinpClk__TOP__top__DOT__top__DOT__clk_player = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__reset = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__clk_bullet = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__VGA_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__clk_player = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__clk_bullet = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__VGA_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__reset = VL_RAND_RESET_I(1);
}
