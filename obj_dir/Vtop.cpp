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
    WData/*223:0*/ __Vtemp1[7];
    WData/*255:0*/ __Vtemp2[8];
    WData/*255:0*/ __Vtemp3[8];
    WData/*255:0*/ __Vtemp4[8];
    WData/*255:0*/ __Vtemp5[8];
    WData/*223:0*/ __Vtemp6[7];
    WData/*255:0*/ __Vtemp7[8];
    WData/*255:0*/ __Vtemp8[8];
    WData/*223:0*/ __Vtemp9[7];
    // Body
    __Vtemp1[0U] = 0x2e62696eU;
    __Vtemp1[1U] = 0x5f6d6f64U;
    __Vtemp1[2U] = 0x74657874U;
    __Vtemp1[3U] = 0x6369695fU;
    __Vtemp1[4U] = 0x622f6173U;
    __Vtemp1[5U] = 0x745f7267U;
    __Vtemp1[6U] = 0x32346269U;
    VL_READMEM_N(false, 8, 1024, 0, VL_CVT_PACK_STR_NW(7, __Vtemp1)
                 , vlTOPp->top__DOT__top__DOT__score_board__DOT__ascii_rom__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e747874U;
    __Vtemp2[1U] = 0x655f3136U;
    __Vtemp2[2U] = 0x5f6c6976U;
    __Vtemp2[3U] = 0x5f726762U;
    __Vtemp2[4U] = 0x34626974U;
    __Vtemp2[5U] = 0x67622f32U;
    __Vtemp2[6U] = 0x69745f72U;
    __Vtemp2[7U] = 0x323462U;
    VL_READMEM_N(true, 24, 256, 0, VL_CVT_PACK_STR_NW(8, __Vtemp2)
                 , vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_lives__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp3[0U] = 0x2e747874U;
    __Vtemp3[1U] = 0x65725f31U;
    __Vtemp3[2U] = 0x706c6179U;
    __Vtemp3[3U] = 0x7267625fU;
    __Vtemp3[4U] = 0x6269745fU;
    __Vtemp3[5U] = 0x622f3234U;
    __Vtemp3[6U] = 0x745f7267U;
    __Vtemp3[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp3)
                 , vlTOPp->top__DOT__top__DOT__mem_player_1__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp4[0U] = 0x2e747874U;
    __Vtemp4[1U] = 0x65725f32U;
    __Vtemp4[2U] = 0x706c6179U;
    __Vtemp4[3U] = 0x7267625fU;
    __Vtemp4[4U] = 0x6269745fU;
    __Vtemp4[5U] = 0x622f3234U;
    __Vtemp4[6U] = 0x745f7267U;
    __Vtemp4[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp4)
                 , vlTOPp->top__DOT__top__DOT__mem_player_2__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp5[0U] = 0x2e747874U;
    __Vtemp5[1U] = 0x6d795f31U;
    __Vtemp5[2U] = 0x5f656e65U;
    __Vtemp5[3U] = 0x5f726762U;
    __Vtemp5[4U] = 0x34626974U;
    __Vtemp5[5U] = 0x67622f32U;
    __Vtemp5[6U] = 0x69745f72U;
    __Vtemp5[7U] = 0x323462U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp5)
                 , vlTOPp->top__DOT__top__DOT__mem_enemy_1__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp6[0U] = 0x2e62696eU;
    __Vtemp6[1U] = 0x5f6d6f64U;
    __Vtemp6[2U] = 0x74657874U;
    __Vtemp6[3U] = 0x6369695fU;
    __Vtemp6[4U] = 0x622f6173U;
    __Vtemp6[5U] = 0x745f7267U;
    __Vtemp6[6U] = 0x32346269U;
    VL_READMEM_N(false, 8, 1024, 0, VL_CVT_PACK_STR_NW(7, __Vtemp6)
                 , vlTOPp->top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp7[0U] = 0x2e747874U;
    __Vtemp7[1U] = 0x65725f31U;
    __Vtemp7[2U] = 0x706c6179U;
    __Vtemp7[3U] = 0x7267625fU;
    __Vtemp7[4U] = 0x6269745fU;
    __Vtemp7[5U] = 0x622f3234U;
    __Vtemp7[6U] = 0x745f7267U;
    __Vtemp7[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp7)
                 , vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_player_1__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp8[0U] = 0x2e747874U;
    __Vtemp8[1U] = 0x65725f32U;
    __Vtemp8[2U] = 0x706c6179U;
    __Vtemp8[3U] = 0x7267625fU;
    __Vtemp8[4U] = 0x6269745fU;
    __Vtemp8[5U] = 0x622f3234U;
    __Vtemp8[6U] = 0x745f7267U;
    __Vtemp8[7U] = 0x32346269U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(8, __Vtemp8)
                 , vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_player_2__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__top__DOT__score_board__DOT____Vxrand2 
        = VL_RAND_RESET_I(6);
    vlTOPp->top__DOT__top__DOT__score_board__DOT____Vxrand1 
        = VL_RAND_RESET_I(6);
    vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand6 
        = VL_RAND_RESET_I(6);
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
    __Vtemp9[0U] = 0x2e747874U;
    __Vtemp9[1U] = 0x5f6d6170U;
    __Vtemp9[2U] = 0x5f726762U;
    __Vtemp9[3U] = 0x34626974U;
    __Vtemp9[4U] = 0x67622f32U;
    __Vtemp9[5U] = 0x69745f72U;
    __Vtemp9[6U] = 0x323462U;
    VL_READMEM_N(true, 24, 8192, 0, VL_CVT_PACK_STR_NW(7, __Vtemp9)
                 , vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1 
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
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[0U] = 0x1dU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[1U] = 0x12U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[2U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[3U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[4U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[6U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[7U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[8U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[9U] = 0x1dU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[0xaU] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[0xbU] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[0xcU] = 0x1cU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start[0xdU] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[0U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[1U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[2U] = 0x20U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[3U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[4U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[6U] = 0xeU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[7U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[8U] = 0x18U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done[9U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[0U] = 0x1dU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[1U] = 0x12U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[2U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[3U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[4U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[6U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[7U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[8U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[9U] = 0xdU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[0xaU] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[0xbU] = 0x18U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue[0xcU] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[0U] = 0x11U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[1U] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[2U] = 0x17U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[3U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[4U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[5U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[6U] = 0x20U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[7U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over[8U] = 0x1cU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[0U] = 0x20U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[1U] = 0x13U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[2U] = 0xdU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[3U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[4U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[5U] = 0x1cU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win[6U] = 0x23U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0U] = 0x1dU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[1U] = 0x12U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[2U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[3U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[4U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[6U] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[7U] = 0x19U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[8U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[9U] = 0x1cU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0xaU] = 0xfU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0xbU] = 0x1dU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0xcU] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0xdU] = 0xbU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0xeU] = 0x1cU;
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart[0xfU] = 0x1eU;
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2 
        = VL_RAND_RESET_I(7);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter2;
    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter;
    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state 
        = vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state;
    vlTOPp->__Vdly__top__DOT__top__DOT__level = vlTOPp->top__DOT__top__DOT__level;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__a;
    IData/*23:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__count;
    IData/*23:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__count2;
    // Body
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__count;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__a 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__a;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count2 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count 
        = (0xffffffU & ((IData)(1U) + vlTOPp->top__DOT__top__DOT__speed_control__DOT__count));
    if ((0x30d40U == vlTOPp->top__DOT__top__DOT__speed_control__DOT__count)) {
        vlTOPp->top__DOT__top__DOT__clk_player = (1U 
                                                  & (~ (IData)(vlTOPp->top__DOT__top__DOT__clk_player)));
        __Vdly__top__DOT__top__DOT__speed_control__DOT__count = 0U;
    }
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count2 
        = (0xffffffU & ((IData)(1U) + vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2));
    if ((0x61a8U == vlTOPp->top__DOT__top__DOT__speed_control__DOT__count2)) {
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

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_clk_o = vlTOPp->top__DOT__top__DOT__VGA_clk;
    vlTOPp->vsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__vsync)));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[0U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0x3e8U)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[1U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0x64U))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[2U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0xaU))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[3U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[4U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[6U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0x3e8U)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[7U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0x64U))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[8U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0xaU))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[9U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0xaU)))));
    vlTOPp->hsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync)));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank 
        = ((IData)(vlTOPp->top__DOT__top__DOT__reset) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_1_revive));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank 
        = ((IData)(vlTOPp->top__DOT__top__DOT__reset) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2_revive));
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank 
        = ((IData)(vlTOPp->top__DOT__top__DOT__reset) 
           | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_revive));
    vlTOPp->top__DOT__top__DOT____Vcellinp__game_FSM__space_i 
        = ((IData)(vlTOPp->player_1_shoot_i) | (IData)(vlTOPp->player_2_shoot_i));
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
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet 
        = ((((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet)) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet 
        = ((((~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet)) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet 
        = ((((~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet)) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x))));
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box 
        = ((((0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))) 
             & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                      - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)))) 
            & (0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)))) 
           & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box 
        = ((((0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
             & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                      - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
            & (0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
           & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box 
        = ((((0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
             & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                      - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
            & (0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
           & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))));
    if (((0x160U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x180U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = 0U;
        if (((0x1e0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & (0x200U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = 0U;
    }
    if (((0x160U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x180U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = 0U;
        if (((0x240U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & (0x260U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = 0U;
    }
    if (((0x1f0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
         & (0x200U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = 0U;
        if (((0x20U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
             & (0x20U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = 0U;
    }
    if (((0x1e0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
         & (0x1f0U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = 0U;
        if (((0x20U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                < (0x3ffU & ((IData)(0x20U) + ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left) 
                                               << 4U)))))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = 0U;
    }
    if (((0x180U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x190U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable = 0U;
        if (((0x1d0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                < (0x3ffU & ((IData)(0x1d0U) + ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left) 
                                                << 4U)))))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable = 0U;
    }
    if (((0x180U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x190U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable = 0U;
        if (((0x230U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                < (0x3ffU & ((IData)(0x230U) + ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left) 
                                                << 4U)))))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable = 0U;
    }
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[0U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[1U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[2U] = 0x20U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[3U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[4U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[6U] 
        = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__level)));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable 
        = (((0xaU == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               >> 5U))) & (0x1cU < 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                             >> 4U)))) 
           & (0x24U > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 4U))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable 
        = (((0xdU == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               >> 5U))) & (0x1cU < 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                             >> 4U)))) 
           & (0x27U > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 4U))));
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (4U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0x10U > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_menu));
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start_enable 
        = ((((9U == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              >> 5U))) & (0xdU < (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                     >> 4U)))) 
            & (0x1cU > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 4U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_menu));
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (4U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0xfU > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_level_done));
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable 
        = ((((9U == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              >> 5U))) & (0xdU < (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                     >> 4U)))) 
            & (0x1bU > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 4U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_level_done));
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (5U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0xfU > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_game_over));
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (6U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0xeU > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_game_win));
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable 
        = ((((9U == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              >> 5U))) & (0xcU < (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                     >> 4U)))) 
            & (0x1dU > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 4U)))) & ((IData)(vlTOPp->top__DOT__top__DOT__is_game_over) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__is_game_win)));
    vlTOPp->top__DOT__top__DOT__display_enable = ((0x280U 
                                                   > (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
                                                  & (0x1e0U 
                                                     > (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_lives__DOT__mem
        [((0xf0U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                    << 4U)) | (0xfU & (IData)(vlTOPp->top__DOT__top__DOT__hpos)))];
    vlTOPp->top__DOT__top__DOT__player_1_bits = vlTOPp->top__DOT__top__DOT__mem_player_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_1_addr];
    vlTOPp->top__DOT__top__DOT__player_2_bits = vlTOPp->top__DOT__top__DOT__mem_player_2__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_2_addr];
    vlTOPp->top__DOT__top__DOT__enemy_1_bits = vlTOPp->top__DOT__top__DOT__mem_enemy_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__enemy_1_addr];
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_player_1__DOT__mem
        [((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     << 5U)) | (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))];
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_player_2__DOT__mem
        [((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     << 5U)) | (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))];
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet));
    vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)));
    vlTOPp->top__DOT__top__DOT__player_1_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)));
    vlTOPp->top__DOT__top__DOT__player_2_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable 
        = ((((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16) 
             | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32)) 
            | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable)) 
           | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable));
    vlTOPp->top__DOT__top__DOT__level_enable = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs = 0U;
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr = 0U;
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr 
            = ((((6U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(5U))))
                  ? vlTOPp->top__DOT__top__DOT__score_board__DOT__level
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(5U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT____Vxrand1)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr 
            = ((((9U >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U) - (IData)(0xdU))))
                  ? vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 4U) - (IData)(0xdU)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT____Vxrand2)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs = 0U;
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__level_done_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_over_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_win_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr = 0x20U;
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
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((0xdU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 4U) - (IData)(0xeU))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 4U) - (IData)(0xeU)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand2)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__level_done_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((9U >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 5U) - (IData)(5U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__level_done
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 5U) - (IData)(5U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand3)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 4U) - (IData)(0xeU))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 4U) - (IData)(0xeU)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand4)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_over_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((8U >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 5U) - (IData)(6U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__game_over
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 5U) - (IData)(6U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand5)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_win_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((6U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U)) - (IData)(7U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__game_win
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 5U)) - (IData)(7U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand6)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart
                [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                           >> 4U) - (IData)(0xdU)))] 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
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
    vlTOPp->top__DOT__top__DOT__enemy_1_blue = (((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
                                                 & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box))
                                                 ? 
                                                (0xffU 
                                                 & (vlTOPp->top__DOT__top__DOT__enemy_1_bits 
                                                    >> 0x10U))
                                                 : 0U);
    vlTOPp->top__DOT__top__DOT__enemy_1_red = (((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
                                                & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box))
                                                ? (0xffU 
                                                   & vlTOPp->top__DOT__top__DOT__enemy_1_bits)
                                                : 0U);
    vlTOPp->top__DOT__top__DOT__enemy_1_green = (((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
                                                  & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box))
                                                  ? 
                                                 (0xffU 
                                                  & (vlTOPp->top__DOT__top__DOT__enemy_1_bits 
                                                     >> 8U))
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__player_tank_blue = 
        (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)
                   ? (((0xffffffU == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                        ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits) 
                      >> 0x10U) : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)
                                    ? (((0xffffffU 
                                         == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                         ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits) 
                                       >> 0x10U) : 0U)));
    vlTOPp->top__DOT__top__DOT__player_tank_red = (0xffU 
                                                   & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)
                                                       ? 
                                                      ((0xffffffU 
                                                        == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                                                        ? 0U
                                                        : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                                                       : 
                                                      ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)
                                                        ? 
                                                       ((0xffffffU 
                                                         == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                                         ? 0U
                                                         : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                                        : 0U)));
    vlTOPp->top__DOT__top__DOT__player_tank_green = 
        (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)
                   ? (((0xffffffU == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                        ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits) 
                      >> 8U) : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)
                                 ? (((0xffffffU == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                      ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits) 
                                    >> 8U) : 0U)));
    vlTOPp->top__DOT__top__DOT__player_tank_enable 
        = (((0U != vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits) 
            & (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)) 
           | ((0U != vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits) 
              & (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)));
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet 
        = ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet) 
           | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet));
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable));
    vlTOPp->top__DOT__top__DOT__player_box = ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable)) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_tank_enable));
    vlTOPp->top__DOT__top__DOT__tank_left_blue = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout 
                                                      >> 0x10U))
                                                   : 0U);
    vlTOPp->top__DOT__top__DOT__tank_left_red = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                  ? 
                                                 (0xffU 
                                                  & vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout)
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__tank_left_green = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                    ? 
                                                   (0xffU 
                                                    & (vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout 
                                                       >> 8U))
                                                    : 0U);
    vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__ascii_rom__DOT__mem
        [vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr];
    vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable 
        = (1U & (vlTOPp->top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem
                 [vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr] 
                 >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)));
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
    vlTOPp->top__DOT__top__DOT__level_blue = ((1U & 
                                               ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number) 
                                                >> (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs)))
                                               ? 0U
                                               : 0xe0U);
    vlTOPp->top__DOT__top__DOT__level_green = ((1U 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number) 
                                                   >> (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs)))
                                                ? 0U
                                                : 0xe0U);
    vlTOPp->top__DOT__top__DOT__level_red = ((1U & 
                                              ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number) 
                                               >> (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs)))
                                              ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_blue = ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                              ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_green = ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                               ? 0U
                                               : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_red = ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                             ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__bullet_collide_eagle 
        = ((4U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
           & (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
        [(((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type) 
           << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  << 5U)) | (0x1fU 
                                             & (IData)(vlTOPp->top__DOT__top__DOT__hpos))))];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL = 
        (((0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 1U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR = 
        (((0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 2U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 3U));
    vlTOPp->top__DOT__top__DOT__destroyable_block = 
        (((((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
            & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL)) 
           | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
              & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
          | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
         | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
            & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__all_hard_block = ((
                                                   (((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
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
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
                                                  | (4U 
                                                     == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)));
    vlTOPp->top__DOT__top__DOT__cannot_walk_through 
        = ((((((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
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
               & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
           | (4U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)));
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
    vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i 
        = ((IData)(vlTOPp->top__DOT__top__DOT__cannot_walk_through) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_box));
    vlTOPp->top__DOT__top__DOT__rgb_render__DOT__map_enable 
        = (((0U != (IData)(vlTOPp->top__DOT__top__DOT__map_blue)) 
            | (0U != (IData)(vlTOPp->top__DOT__top__DOT__map_green))) 
           | (0U != (IData)(vlTOPp->top__DOT__top__DOT__map_green)));
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
                                                    ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_green) 
                                                       | (IData)(vlTOPp->top__DOT__top__DOT__player_2_green)) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_green)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_green)))) 
                                                | ((((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                       | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_bullet))
                                                     ? 0xffffffU
                                                     : 0U) 
                                                   >> 8U))
                                             : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                 ? (IData)(vlTOPp->top__DOT__top__DOT__tank_left_green)
                                                 : 
                                                ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                                  ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_green)
                                                  : 
                                                 ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                                   ? (IData)(vlTOPp->top__DOT__top__DOT__level_green)
                                                   : 0xe0U)))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_level_done) {
                    vlTOPp->green_o = ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                        ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_green)
                                        : ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                            ? (IData)(vlTOPp->top__DOT__top__DOT__level_green)
                                            : ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                                ? (IData)(vlTOPp->top__DOT__top__DOT__menu_green)
                                                : 0xe0U)));
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_game_over) {
                        vlTOPp->green_o = vlTOPp->top__DOT__top__DOT__menu_green;
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__is_game_win) {
                            vlTOPp->green_o = vlTOPp->top__DOT__top__DOT__menu_green;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->green_o = 0U;
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
                                                   ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_blue) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__player_2_blue)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_blue)) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_blue)))) 
                                               | ((((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_bullet))
                                                    ? 0xffffffU
                                                    : 0U) 
                                                  >> 0x10U))
                                            : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                ? (IData)(vlTOPp->top__DOT__top__DOT__tank_left_blue)
                                                : ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                                    ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_blue)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                                     ? (IData)(vlTOPp->top__DOT__top__DOT__level_blue)
                                                     : 0xe0U)))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_level_done) {
                    vlTOPp->blue_o = ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                       ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_blue)
                                       : ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                           ? (IData)(vlTOPp->top__DOT__top__DOT__level_blue)
                                           : ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                               ? (IData)(vlTOPp->top__DOT__top__DOT__menu_blue)
                                               : 0xe0U)));
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_game_over) {
                        vlTOPp->blue_o = vlTOPp->top__DOT__top__DOT__menu_blue;
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__is_game_win) {
                            vlTOPp->blue_o = vlTOPp->top__DOT__top__DOT__menu_blue;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->blue_o = 0U;
    }
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
                                                  ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_red) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_2_red)) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_red)) 
                                                   | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_red)))) 
                                              | (((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                                                   | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                                                  | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_bullet))
                                                  ? 0xffffffU
                                                  : 0U))
                                           : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                               ? (IData)(vlTOPp->top__DOT__top__DOT__tank_left_red)
                                               : ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                                   ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_red)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                                    ? (IData)(vlTOPp->top__DOT__top__DOT__level_red)
                                                    : 0xe0U)))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_level_done) {
                    vlTOPp->red_o = ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                      ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_red)
                                      : ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                          ? (IData)(vlTOPp->top__DOT__top__DOT__level_red)
                                          : ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                              ? (IData)(vlTOPp->top__DOT__top__DOT__menu_red)
                                              : 0xe0U)));
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_game_over) {
                        vlTOPp->red_o = vlTOPp->top__DOT__top__DOT__menu_red;
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__is_game_win) {
                            vlTOPp->red_o = vlTOPp->top__DOT__top__DOT__menu_red;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->red_o = 0U;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__premove_tank;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count2 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count2;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__dir_stage;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bot_stage;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y = 0x20U;
    } else {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                    = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y) 
                                             - (IData)(1U)));
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)));
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y;
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x = 0x20U;
    } else {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                    = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x) 
                                             - (IData)(1U)));
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)));
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x 
                            = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x;
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y = 0xb4U;
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
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x = 0x20U;
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x;
    // Body
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x;
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
    if (((1U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage)) 
         & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x) 
                                         - (IData)(1U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)));
                    }
                }
            }
        }
    }
    if (((1U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage)) 
         & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y) 
                                         - (IData)(1U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)));
                    }
                }
            }
        }
    }
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
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0x1fU) 
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
                            = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0x1fU) 
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
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
                            = (0x3ffU & ((IData)(0x1fU) 
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
                            = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
                            = (0x3ffU & ((IData)(0x1fU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)));
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_x;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_bullet_y;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_x;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_bullet_y;
}

VL_INLINE_OPT void Vtop::_combo__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__9\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_clk_o = vlTOPp->top__DOT__top__DOT__VGA_clk;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__10\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward;
    // Body
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward;
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs;
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
    if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__enemy_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward));
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__enemy_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs));
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__enemy_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward));
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct))) {
                    vlTOPp->top__DOT__top__DOT__enemy_1_addr 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs));
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))) {
        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward = 0x1fU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward))) {
            __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))) {
        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs = 2U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs))) {
            __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs)));
        }
    }
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
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_xofs 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_xofs;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs_backward 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs_backward;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_xofs 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_xofs;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs_backward 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs_backward;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_xofs 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_xofs;
    vlTOPp->top__DOT__top__DOT__enemy_1_bits = vlTOPp->top__DOT__top__DOT__mem_enemy_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__enemy_1_addr];
    vlTOPp->vsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__vsync)));
    vlTOPp->top__DOT__top__DOT__player_2_bits = vlTOPp->top__DOT__top__DOT__mem_player_2__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_2_addr];
    vlTOPp->top__DOT__top__DOT__player_1_bits = vlTOPp->top__DOT__top__DOT__mem_player_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_1_addr];
    vlTOPp->hsync_no = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__11\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*10:0*/ __Vdly__top__DOT__top__DOT__player_1_score;
    SData/*10:0*/ __Vdly__top__DOT__top__DOT__player_2_score;
    // Body
    __Vdly__top__DOT__top__DOT__player_2_score = vlTOPp->top__DOT__top__DOT__player_2_score;
    __Vdly__top__DOT__top__DOT__player_1_score = vlTOPp->top__DOT__top__DOT__player_1_score;
    if (vlTOPp->reset_i) {
        __Vdly__top__DOT__top__DOT__player_2_score = 0U;
    } else {
        if (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
             & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable))) {
            __Vdly__top__DOT__top__DOT__player_2_score 
                = (0x7ffU & ((IData)(0xaU) + (IData)(vlTOPp->top__DOT__top__DOT__player_2_score)));
        }
        if (((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
             & (IData)(vlTOPp->top__DOT__top__DOT__destroyable_block))) {
            __Vdly__top__DOT__top__DOT__player_2_score 
                = (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_2_score)));
        }
    }
    if (vlTOPp->reset_i) {
        __Vdly__top__DOT__top__DOT__player_1_score = 0U;
    } else {
        if (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet) 
             & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable))) {
            __Vdly__top__DOT__top__DOT__player_1_score 
                = (0x7ffU & ((IData)(0xaU) + (IData)(vlTOPp->top__DOT__top__DOT__player_1_score)));
        }
        if (((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet) 
             & (IData)(vlTOPp->top__DOT__top__DOT__destroyable_block))) {
            __Vdly__top__DOT__top__DOT__player_1_score 
                = (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_1_score)));
        }
    }
    vlTOPp->top__DOT__top__DOT__player_2_score = __Vdly__top__DOT__top__DOT__player_2_score;
    vlTOPp->top__DOT__top__DOT__player_1_score = __Vdly__top__DOT__top__DOT__player_1_score;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[0U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0x3e8U)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[1U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0x64U))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[2U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0xaU))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[3U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_1_score), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[4U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[6U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0x3e8U)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[7U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0x64U))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[8U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, 
                                                          (0x7ffU 
                                                           & VL_DIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0xaU))), (IData)(0xaU)))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score[9U] 
        = (0x3fU & ((IData)(1U) + (0x7ffU & VL_MODDIV_III(11, (IData)(vlTOPp->top__DOT__top__DOT__player_2_score), (IData)(0xaU)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__12\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v845;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1014;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1183;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1352;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1521;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694;
    CData/*6:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left;
    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left 
        = vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v845 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1014 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1183 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1352 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1521 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694 = 0U;
    if (vlTOPp->top__DOT__top__DOT__reset) {
        if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                   - (IData)(1U)))) 
                   | (1U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                     - (IData)(1U))))) 
                  | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                    - (IData)(1U))))) 
                 | (3U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                   - (IData)(1U))))) 
                | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                  - (IData)(1U))))) 
               | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                 - (IData)(1U))))) 
              | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                - (IData)(1U))))) | 
             (7U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                             - (IData)(1U)))))) {
            if ((0U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                - (IData)(1U))))) {
                __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0 = 1U;
            } else {
                if ((1U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                    - (IData)(1U))))) {
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 1U;
                } else {
                    if ((2U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                        - (IData)(1U))))) {
                        __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338 = 1U;
                    } else {
                        if ((3U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                            - (IData)(1U))))) {
                            __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507 = 1U;
                        } else {
                            if ((4U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                                - (IData)(1U))))) {
                                __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676 = 1U;
                            } else {
                                if ((5U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                             - (IData)(1U))))) {
                                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v845 = 1U;
                                } else {
                                    if ((6U == (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                                   - (IData)(1U))))) {
                                        __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1014 = 1U;
                                    } else {
                                        __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1183 = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if ((8U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                - (IData)(1U))))) {
                __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1352 = 1U;
            } else {
                if ((9U == (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__level) 
                                    - (IData)(1U))))) {
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1521 = 1U;
                }
            }
        }
    } else {
        if (((IData)(vlTOPp->top__DOT__top__DOT__destroyable_block) 
             & (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet))) {
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound3 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound3;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690 = 0U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690 
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
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound4;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691 = 1U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691 
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
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound5;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692 = 2U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692 
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
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound6;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693 = 3U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693 
                        = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                    >> 5U) - (IData)(1U)));
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT__bullet_collide_eagle) {
            vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound7 = 0U;
            if (((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 5U) - (IData)(1U)))) 
                 & (0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                      >> 5U) - (IData)(1U)))))) {
                __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694 
                    = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound7;
                __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694 = 1U;
                __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694 
                    = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U) - (IData)(1U)));
                __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694 
                    = (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                >> 5U) - (IData)(1U)));
            }
        }
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0) {
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 3U;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0xfU;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 3U;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0x7fU;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v338) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v507) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x1fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v676) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v845) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x2fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1014) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1183) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0x1aU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x15U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1352) {
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0x3fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1521) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][1U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][6U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xbU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[2U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][1U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][4U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[3U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][3U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][5U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][7U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][9U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xbU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[4U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][1U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][9U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xbU] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[5U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][1U] = 0x1cU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][5U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][6U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][7U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[6U][0xcU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][1U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][3U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][4U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][5U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][7U] = 0x13U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][8U] = 0x2fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][9U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[7U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][4U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][8U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xbU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[8U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][1U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][6U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[9U][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][2U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][3U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][4U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][5U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][7U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][8U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][9U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xaU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xbU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][0xcU] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][5U] = 8U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][6U] = 0xcU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][7U] = 4U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][8U] = 3U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xbU] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xbU][0xcU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][1U] = 0xfU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][2U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][3U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][4U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][5U] = 0xaU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][6U] = 0x4fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][7U] = 5U;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][8U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][9U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xaU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xbU] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xcU][0xcU] = 0x7fU;
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1690)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1691)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1692)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1693)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694] 
            = __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v1694;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__13(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__13\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage;
    // Body
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom;
    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top;
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage))) {
            vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet = 0U;
            vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_dir 
                = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct;
            if ((((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_shoot) 
                  & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__pos_edge_detect_1__DOT__sig_dly))) 
                 & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)))) {
                __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage))) {
                vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet = 1U;
                if (((((((IData)(vlTOPp->top__DOT__top__DOT__all_hard_block) 
                         | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player)) 
                        | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable)) 
                       | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet)) 
                      & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die))) {
                    __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage = 2U;
                    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage))) {
                    __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage = 0U;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = 0U;
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                      >> 3U)))) {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = 0U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((1U == ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = 0U;
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = 0U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((0x20U == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((0x20U == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = 0U;
    } else {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            } else {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = 0U;
                    }
                }
            }
        }
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((1U == ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__vpos))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = 1U;
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bullet_stage 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__bullet_stage;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__14(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__14\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage;
    // Body
    __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage;
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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
                if (((((((IData)(vlTOPp->top__DOT__top__DOT__all_hard_block) 
                         | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player)) 
                        | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable)) 
                       | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                      & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                     | (IData)(vlTOPp->top__DOT__top__DOT__player_1_die))) {
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
    vlTOPp->top__DOT__top__DOT__player_1__DOT__bullet_stage 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__bullet_stage;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__15(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__15\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage;
    // Body
    __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage;
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
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
                if (((((((IData)(vlTOPp->top__DOT__top__DOT__all_hard_block) 
                         | (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player)) 
                        | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable)) 
                       | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                      & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet)) 
                     | (IData)(vlTOPp->top__DOT__top__DOT__player_2_die))) {
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
    vlTOPp->top__DOT__top__DOT__player_2__DOT__bullet_stage 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__bullet_stage;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__16(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__16\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward;
    // Body
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward;
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs;
    if (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))) {
        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward = 0x1eU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward))) {
            __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
         == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))) {
        __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs = 2U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs))) {
            __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs)));
        }
    }
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
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_yofs 
        = __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_yofs;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs_backward 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs_backward;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_yofs 
        = __Vdly__top__DOT__top__DOT__player_2__DOT__tank_yofs;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs_backward 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs_backward;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_yofs 
        = __Vdly__top__DOT__top__DOT__player_1__DOT__tank_yofs;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__17(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__17\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__pos_edge_detect_1__DOT__sig_dly 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_shoot;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__18(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__18\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct = 1U;
    } else {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left)))) {
                            vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct = 8U;
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right)))) {
                            vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct = 4U;
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top)))) {
                            vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct = 2U;
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct = 1U;
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank) {
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 3U;
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bot_stage))) {
            if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bot_stage))) {
                if (((1U >= (0xfU & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))) 
                     & (1U >= (0xfU & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))))) {
                    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move = 0U;
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 0U;
                } else {
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count2 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count2)));
                    if ((0x64U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count2))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 0U;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__dir_stage))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__dir_stage))) {
                        if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage 
                                = ((0x100U > (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))
                                    ? 1U : 0U);
                        } else {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 3U;
                        }
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top) {
                            if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom) {
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage 
                                    = ((0x100U > (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))
                                        ? 1U : 0U);
                            } else {
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 1U;
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 3U;
                            }
                        } else {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 2U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 2U;
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__dir_stage))) {
                        if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right) {
                            if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left) {
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 2U;
                            } else {
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 8U;
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 0U;
                            }
                        } else {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 4U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 1U;
                        }
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 3U;
                        }
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left) {
                            if (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right) {
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 2U;
                            } else {
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 4U;
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 1U;
                            }
                        } else {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 8U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 0U;
                        }
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 1U;
                            vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = 3U;
                        }
                    }
                }
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count = 0U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bot_stage))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count 
                    = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count)));
                vlTOPp->top__DOT__top__DOT__enemy_1__DOT__auto_tank_move 
                    = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__premove_tank;
                if ((3U == (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 3U;
                }
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count2 = 0U;
            } else {
                vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = 2U;
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__bot_stage 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__dir_stage 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count2 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count2;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__premove_tank 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__count 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__count;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__19(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__19\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left = 1U;
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive = 0U;
        vlTOPp->top__DOT__top__DOT__enemy_1_revive = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage))) {
            vlTOPp->top__DOT__top__DOT__enemy_1_die = 0U;
            vlTOPp->top__DOT__top__DOT__enemy_1_revive = 0U;
            if (((IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left 
                    = (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left) 
                               - (IData)(1U)));
                vlTOPp->top__DOT__top__DOT__enemy_1_die = 1U;
                vlTOPp->top__DOT__top__DOT__enemy_1_revive = 1U;
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive = 0U;
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive 
                        = ((IData)(1U) + vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive);
                    if ((1U <= (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left))) {
                        if ((0xf4240U == vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive)) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage = 0U;
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left = 4U;
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive = 0U;
        vlTOPp->top__DOT__top__DOT__player_1_revive = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage))) {
            vlTOPp->top__DOT__top__DOT__player_1_die = 0U;
            vlTOPp->top__DOT__top__DOT__player_1_revive = 0U;
            if (((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left 
                    = (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left) 
                               - (IData)(1U)));
                vlTOPp->top__DOT__top__DOT__player_1_die = 1U;
                vlTOPp->top__DOT__top__DOT__player_1_revive = 1U;
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive = 0U;
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive 
                        = ((IData)(1U) + vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive);
                    if ((1U <= (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left))) {
                        if ((0xf4240U == vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive)) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage = 0U;
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__reset) {
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left = 4U;
        vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive = 0U;
        vlTOPp->top__DOT__top__DOT__player_2_revive = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage))) {
            vlTOPp->top__DOT__top__DOT__player_2_die = 0U;
            vlTOPp->top__DOT__top__DOT__player_2_revive = 0U;
            if (((IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left 
                    = (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left) 
                               - (IData)(1U)));
                vlTOPp->top__DOT__top__DOT__player_2_die = 1U;
                vlTOPp->top__DOT__top__DOT__player_2_revive = 1U;
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive = 0U;
                vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive 
                        = ((IData)(1U) + vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive);
                    if ((1U <= (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left))) {
                        if ((0xf4240U == vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive)) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage = 0U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive;
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__20(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__20\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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

VL_INLINE_OPT void Vtop::_sequent__TOP__21(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__21\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__22(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__22\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right;
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left 
        = vlTOPp->__Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__23(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__23\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
        vlTOPp->top__DOT__top__DOT__is_menu = 0U;
        vlTOPp->top__DOT__top__DOT__is_playing = 0U;
        vlTOPp->top__DOT__top__DOT__is_level_done = 0U;
        vlTOPp->top__DOT__top__DOT__is_game_over = 0U;
        vlTOPp->top__DOT__top__DOT__is_game_win = 0U;
        vlTOPp->top__DOT__top__DOT__reset = 1U;
        vlTOPp->__Vdly__top__DOT__top__DOT__level = 1U;
        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter = 0U;
        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2 = 0U;
    } else {
        vlTOPp->top__DOT__top__DOT__is_menu = 0U;
        vlTOPp->top__DOT__top__DOT__is_playing = 0U;
        vlTOPp->top__DOT__top__DOT__is_level_done = 0U;
        vlTOPp->top__DOT__top__DOT__is_game_over = 0U;
        vlTOPp->top__DOT__top__DOT__is_game_win = 0U;
        vlTOPp->top__DOT__top__DOT__reset = 1U;
        if (((((((((0U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state)) 
                   | (1U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) 
                  | (2U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) 
                 | (5U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) 
                | (4U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) 
               | (6U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) 
              | (3U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) 
             | (7U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state)))) {
            if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__level = 1U;
                vlTOPp->top__DOT__top__DOT__is_menu = 1U;
                vlTOPp->top__DOT__top__DOT__reset = 1U;
                if (vlTOPp->top__DOT__top__DOT____Vcellinp__game_FSM__space_i) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 1U;
                }
            } else {
                if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                    vlTOPp->top__DOT__top__DOT__reset = 0U;
                    vlTOPp->top__DOT__top__DOT__is_playing = 1U;
                    if (vlTOPp->top__DOT__top__DOT__bullet_collide_eagle) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 6U;
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2 = 0U;
                    }
                    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 2U;
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter = 0U;
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter 
                            = (0xffffffU & ((IData)(1U) 
                                            + vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter));
                        vlTOPp->top__DOT__top__DOT__is_level_done = 1U;
                        vlTOPp->top__DOT__top__DOT__reset = 1U;
                        if ((0xbebc20U == vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter)) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 5U;
                            if ((0xaU == (IData)(vlTOPp->top__DOT__top__DOT__level))) {
                                vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 7U;
                            }
                        }
                    } else {
                        if ((5U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                            vlTOPp->top__DOT__top__DOT__is_level_done = 1U;
                            if (vlTOPp->top__DOT__top__DOT____Vcellinp__game_FSM__space_i) {
                                vlTOPp->__Vdly__top__DOT__top__DOT__level 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->top__DOT__top__DOT__level)));
                                vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 4U;
                            }
                        } else {
                            if ((4U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                                vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 1U;
                            } else {
                                if ((6U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                                    vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2 
                                        = (0xffffffU 
                                           & ((IData)(1U) 
                                              + vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter2));
                                    vlTOPp->top__DOT__top__DOT__is_game_over = 1U;
                                    if ((0xbebc20U 
                                         == vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter2)) {
                                        vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 3U;
                                    }
                                } else {
                                    if ((3U == (IData)(vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state))) {
                                        vlTOPp->top__DOT__top__DOT__is_game_over = 1U;
                                        vlTOPp->top__DOT__top__DOT__reset = 1U;
                                        if (vlTOPp->top__DOT__top__DOT____Vcellinp__game_FSM__space_i) {
                                            vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
                                        }
                                    } else {
                                        vlTOPp->top__DOT__top__DOT__is_game_win = 1U;
                                        if (vlTOPp->top__DOT__top__DOT____Vcellinp__game_FSM__space_i) {
                                            vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = 0U;
        }
    }
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__game_state 
        = vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state;
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter 
        = vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter;
    vlTOPp->top__DOT__top__DOT__game_FSM__DOT__counter2 
        = vlTOPp->__Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2;
    vlTOPp->top__DOT__top__DOT__level = vlTOPp->__Vdly__top__DOT__top__DOT__level;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[0U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[1U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[2U] = 0x20U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[3U] = 0xfU;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[4U] = 0x16U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[5U] = 0x25U;
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level[6U] 
        = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__level)));
}

VL_INLINE_OPT void Vtop::_combo__TOP__24(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__24\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank 
        = ((IData)(vlTOPp->top__DOT__top__DOT__reset) 
           | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_revive));
    vlTOPp->top__DOT__top__DOT____Vcellinp__game_FSM__space_i 
        = ((IData)(vlTOPp->player_1_shoot_i) | (IData)(vlTOPp->player_2_shoot_i));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__25(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__25\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((1U == ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((0x20U == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((1U == ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__vpos))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((0x20U == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = 1U;
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__26(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__26\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((1U == ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_left = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((0x20U == ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_right = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((1U == ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__vpos))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_top = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank) {
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
        if (vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i) {
            if ((((0x20U == ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                             - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
                  & (0x1cU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                              - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
                 & (2U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                          - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))))) {
                vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_collide_with_wall_bottom = 1U;
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__27(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__27\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left 
        = vlTOPp->__Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left;
}

VL_INLINE_OPT void Vtop::_combo__TOP__28(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__28\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank 
        = ((IData)(vlTOPp->top__DOT__top__DOT__reset) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_1_revive));
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_shoot 
        = ((IData)(vlTOPp->player_1_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__pos_edge_detect_1__DOT__sig_dly)));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank 
        = ((IData)(vlTOPp->top__DOT__top__DOT__reset) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2_revive));
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_shoot 
        = ((IData)(vlTOPp->player_2_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__pos_edge_detect_1__DOT__sig_dly)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__29(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__29\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_y;
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_1__DOT__tank_x;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__30(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__30\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_y;
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_2__DOT__tank_x;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__31(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__31\n"); );
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
    vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_lives__DOT__mem
        [((0xf0U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                    << 4U)) | (0xfU & (IData)(vlTOPp->top__DOT__top__DOT__hpos)))];
    if (((0x160U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x180U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = 0U;
        if (((0x1e0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & (0x200U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = 0U;
    }
    if (((0x160U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x180U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = 0U;
        if (((0x240U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & (0x260U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = 0U;
    }
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_player_1__DOT__mem
        [((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     << 5U)) | (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))];
    vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__mem_player_2__DOT__mem
        [((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                     << 5U)) | (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))];
    if (((0x1f0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
         & (0x200U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = 0U;
        if (((0x20U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
             & (0x20U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = 0U;
    }
    vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable 
        = (((0xaU == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               >> 5U))) & (0x1cU < 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                             >> 4U)))) 
           & (0x24U > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 4U))));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable 
        = (((0xdU == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                               >> 5U))) & (0x1cU < 
                                           (0x3fU & 
                                            ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                             >> 4U)))) 
           & (0x27U > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 4U))));
    vlTOPp->top__DOT__top__DOT__display_enable = ((0x280U 
                                                   > (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
                                                  & (0x1e0U 
                                                     > (IData)(vlTOPp->top__DOT__top__DOT__vpos)));
    vlTOPp->top__DOT__top__DOT__player_tank_blue = 
        (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)
                   ? (((0xffffffU == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                        ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits) 
                      >> 0x10U) : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)
                                    ? (((0xffffffU 
                                         == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                         ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits) 
                                       >> 0x10U) : 0U)));
    vlTOPp->top__DOT__top__DOT__player_tank_red = (0xffU 
                                                   & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)
                                                       ? 
                                                      ((0xffffffU 
                                                        == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                                                        ? 0U
                                                        : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                                                       : 
                                                      ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)
                                                        ? 
                                                       ((0xffffffU 
                                                         == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                                         ? 0U
                                                         : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                                        : 0U)));
    vlTOPp->top__DOT__top__DOT__player_tank_green = 
        (0xffU & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)
                   ? (((0xffffffU == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits)
                        ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits) 
                      >> 8U) : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)
                                 ? (((0xffffffU == vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits)
                                      ? 0U : vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits) 
                                    >> 8U) : 0U)));
    vlTOPp->top__DOT__top__DOT__player_tank_enable 
        = (((0U != vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_bits) 
            & (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_tank_enable)) 
           | ((0U != vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_bits) 
              & (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_tank_enable)));
    vlTOPp->top__DOT__top__DOT__level_enable = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs = 0U;
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
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

VL_INLINE_OPT void Vtop::_multiclk__TOP__32(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__32\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet 
        = ((((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__show_bullet)) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__33(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__33\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet 
        = ((((~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__show_bullet)) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet_x))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__34(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__34\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet 
        = ((((~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__show_bullet)) 
            & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                     - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_y)))) 
           & (5U > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet_x))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__35(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__35\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box 
        = ((((0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y))) 
             & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                      - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_y)))) 
            & (0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x)))) 
           & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_x))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__36(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__36\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box 
        = ((((0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y))) 
             & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                      - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_y)))) 
            & (0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x)))) 
           & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_x))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__37(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__37\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box 
        = ((((0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                       - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y))) 
             & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                      - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_y)))) 
            & (0x1eU > ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x)))) 
           & (0U < ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                    - (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_x))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__38(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__38\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((0x1e0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
         & (0x1f0U > (IData)(vlTOPp->top__DOT__top__DOT__hpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = 0U;
        if (((0x20U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                < (0x3ffU & ((IData)(0x20U) + ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left) 
                                               << 4U)))))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = 0U;
    }
    if (((0x180U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x190U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable = 0U;
        if (((0x1d0U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                < (0x3ffU & ((IData)(0x1d0U) + ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left) 
                                                << 4U)))))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable = 0U;
    }
    if (((0x180U < (IData)(vlTOPp->top__DOT__top__DOT__vpos)) 
         & (0x190U > (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable = 0U;
        if (((0x230U < (IData)(vlTOPp->top__DOT__top__DOT__hpos)) 
             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                < (0x3ffU & ((IData)(0x230U) + ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left) 
                                                << 4U)))))) {
            vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable = 1U;
        }
    } else {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable = 0U;
    }
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
    vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable 
        = ((((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_16) 
             | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable_32)) 
            | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_1_enable)) 
           | (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__player_2_enable));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
        [(((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type) 
           << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  << 5U)) | (0x1fU 
                                             & (IData)(vlTOPp->top__DOT__top__DOT__hpos))))];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL = 
        (((0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 1U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR = 
        (((0x10U > (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 2U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__hpos))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->top__DOT__top__DOT__vpos)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 3U));
    vlTOPp->top__DOT__top__DOT__tank_left_blue = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                   ? 
                                                  (0xffU 
                                                   & (vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout 
                                                      >> 0x10U))
                                                   : 0U);
    vlTOPp->top__DOT__top__DOT__tank_left_red = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                  ? 
                                                 (0xffU 
                                                  & vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout)
                                                  : 0U);
    vlTOPp->top__DOT__top__DOT__tank_left_green = ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                    ? 
                                                   (0xffU 
                                                    & (vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_dout 
                                                       >> 8U))
                                                    : 0U);
    vlTOPp->top__DOT__top__DOT__destroyable_block = 
        (((((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
            & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL)) 
           | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
              & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
          | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
             & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
         | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
            & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__all_hard_block = ((
                                                   (((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
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
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
                                                  | (4U 
                                                     == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)));
    vlTOPp->top__DOT__top__DOT__cannot_walk_through 
        = ((((((((((((IData)(vlTOPp->top__DOT__top__DOT__display_enable) 
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
               & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
           | (4U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)));
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

VL_INLINE_OPT void Vtop::_multiclk__TOP__39(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__39\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (4U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0x10U > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_menu));
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start_enable 
        = ((((9U == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              >> 5U))) & (0xdU < (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                     >> 4U)))) 
            & (0x1cU > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 4U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_menu));
    vlTOPp->top__DOT__top__DOT__menu__DOT__level_done_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (4U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0xfU > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_level_done));
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable 
        = ((((9U == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              >> 5U))) & (0xdU < (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                     >> 4U)))) 
            & (0x1bU > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 4U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_level_done));
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_over_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (5U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0xfU > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_game_over));
    vlTOPp->top__DOT__top__DOT__menu__DOT__game_win_enable 
        = ((((1U == (7U & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                           >> 7U))) & (6U < (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                >> 5U)))) 
            & (0xeU > (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                >> 5U)))) & (IData)(vlTOPp->top__DOT__top__DOT__is_game_win));
    vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable 
        = ((((9U == (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                              >> 5U))) & (0xcU < (0x3fU 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                                     >> 4U)))) 
            & (0x1dU > (0x3fU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                 >> 4U)))) & ((IData)(vlTOPp->top__DOT__top__DOT__is_game_over) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__is_game_win)));
    vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr = 0U;
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__level_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr 
            = ((((6U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 4U)) - (IData)(5U))))
                  ? vlTOPp->top__DOT__top__DOT__score_board__DOT__level
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U)) - (IData)(5U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT____Vxrand1)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__score_board__DOT__score_enable) {
        vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr 
            = ((((9U >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 4U) - (IData)(0xdU))))
                  ? vlTOPp->top__DOT__top__DOT__score_board__DOT__player_score
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 4U) - (IData)(0xdU)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT____Vxrand2)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs = 0U;
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__title_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__level_done_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_over_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_win_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 2U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs 
            = (7U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                        >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr = 0x20U;
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
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((0xdU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 4U) - (IData)(0xeU))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_start
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 4U) - (IData)(0xeU)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand2)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__level_done_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((9U >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 5U) - (IData)(5U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__level_done
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 5U) - (IData)(5U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand3)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((0xcU >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                    >> 4U) - (IData)(0xeU))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_continue
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 4U) - (IData)(0xeU)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand4)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_over_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((8U >= (0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 5U) - (IData)(6U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__game_over
                 [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                            >> 5U) - (IData)(6U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand5)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__game_win_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((((6U >= (7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                        >> 5U)) - (IData)(7U))))
                  ? vlTOPp->top__DOT__top__DOT__menu__DOT__game_win
                 [(7U & ((0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                                  >> 5U)) - (IData)(7U)))]
                  : (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT____Vxrand6)) 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 3U)));
    }
    if (vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable) {
        vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr 
            = ((vlTOPp->top__DOT__top__DOT__menu__DOT__shoot_to_restart
                [(0xfU & (((IData)(vlTOPp->top__DOT__top__DOT__hpos) 
                           >> 4U) - (IData)(0xdU)))] 
                << 4U) | (0xfU & ((IData)(vlTOPp->top__DOT__top__DOT__vpos) 
                                  >> 1U)));
    }
    vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number 
        = vlTOPp->top__DOT__top__DOT__score_board__DOT__ascii_rom__DOT__mem
        [vlTOPp->top__DOT__top__DOT__score_board__DOT__rom_addr];
    vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable 
        = (1U & (vlTOPp->top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem
                 [vlTOPp->top__DOT__top__DOT__menu__DOT__rom_addr] 
                 >> (IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__x_ofs)));
    vlTOPp->top__DOT__top__DOT__level_blue = ((1U & 
                                               ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number) 
                                                >> (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs)))
                                               ? 0U
                                               : 0xe0U);
    vlTOPp->top__DOT__top__DOT__level_green = ((1U 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number) 
                                                   >> (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs)))
                                                ? 0U
                                                : 0xe0U);
    vlTOPp->top__DOT__top__DOT__level_red = ((1U & 
                                              ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__bit_number) 
                                               >> (IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__x_ofs)))
                                              ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_blue = ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                              ? 0U : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_green = ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                               ? 0U
                                               : 0xe0U);
    vlTOPp->top__DOT__top__DOT__menu_red = ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                             ? 0U : 0xe0U);
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__40(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__40\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__41(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__41\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)));
    vlTOPp->top__DOT__top__DOT__enemy_1_blue = (((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
                                                 & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box))
                                                 ? 
                                                (0xffU 
                                                 & (vlTOPp->top__DOT__top__DOT__enemy_1_bits 
                                                    >> 0x10U))
                                                 : 0U);
    vlTOPp->top__DOT__top__DOT__enemy_1_red = (((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
                                                & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box))
                                                ? (0xffU 
                                                   & vlTOPp->top__DOT__top__DOT__enemy_1_bits)
                                                : 0U);
    vlTOPp->top__DOT__top__DOT__enemy_1_green = (((~ (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_die)) 
                                                  & (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_box))
                                                  ? 
                                                 (0xffU 
                                                  & (vlTOPp->top__DOT__top__DOT__enemy_1_bits 
                                                     >> 8U))
                                                  : 0U);
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__42(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__42\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_1_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_1_die)));
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
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__43(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__43\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_2_tank_enable 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_box) 
           & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_2_die)));
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
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__44(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__44\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet 
        = ((IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet) 
           | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet));
    vlTOPp->top__DOT__top__DOT__bullet_collide_eagle 
        = ((4U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
           & (IData)(vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__45(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__45\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__bullet_collide_1__DOT__all_player 
        = ((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__46(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__46\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_box = ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_tank_enable) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__player_2_tank_enable)) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_tank_enable)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_tank_enable));
    vlTOPp->top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i 
        = ((IData)(vlTOPp->top__DOT__top__DOT__cannot_walk_through) 
           | (IData)(vlTOPp->top__DOT__top__DOT__player_box));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__47(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__47\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
                                                   ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_blue) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__player_2_blue)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_blue)) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_blue)))) 
                                               | ((((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_bullet))
                                                    ? 0xffffffU
                                                    : 0U) 
                                                  >> 0x10U))
                                            : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                ? (IData)(vlTOPp->top__DOT__top__DOT__tank_left_blue)
                                                : ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                                    ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_blue)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                                     ? (IData)(vlTOPp->top__DOT__top__DOT__level_blue)
                                                     : 0xe0U)))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_level_done) {
                    vlTOPp->blue_o = ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                       ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_blue)
                                       : ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                           ? (IData)(vlTOPp->top__DOT__top__DOT__level_blue)
                                           : ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                               ? (IData)(vlTOPp->top__DOT__top__DOT__menu_blue)
                                               : 0xe0U)));
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_game_over) {
                        vlTOPp->blue_o = vlTOPp->top__DOT__top__DOT__menu_blue;
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__is_game_win) {
                            vlTOPp->blue_o = vlTOPp->top__DOT__top__DOT__menu_blue;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->blue_o = 0U;
    }
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
                                                  ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_red) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_2_red)) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_red)) 
                                                   | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_red)))) 
                                              | (((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                    | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                                                   | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                                                  | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_bullet))
                                                  ? 0xffffffU
                                                  : 0U))
                                           : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                               ? (IData)(vlTOPp->top__DOT__top__DOT__tank_left_red)
                                               : ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                                   ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_red)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                                    ? (IData)(vlTOPp->top__DOT__top__DOT__level_red)
                                                    : 0xe0U)))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_level_done) {
                    vlTOPp->red_o = ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                      ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_red)
                                      : ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                          ? (IData)(vlTOPp->top__DOT__top__DOT__level_red)
                                          : ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                              ? (IData)(vlTOPp->top__DOT__top__DOT__menu_red)
                                              : 0xe0U)));
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_game_over) {
                        vlTOPp->red_o = vlTOPp->top__DOT__top__DOT__menu_red;
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__is_game_win) {
                            vlTOPp->red_o = vlTOPp->top__DOT__top__DOT__menu_red;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->red_o = 0U;
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
                                                    ((((IData)(vlTOPp->top__DOT__top__DOT__player_1_green) 
                                                       | (IData)(vlTOPp->top__DOT__top__DOT__player_2_green)) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1_green)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_green)))) 
                                                | ((((((IData)(vlTOPp->top__DOT__top__DOT__player_2__DOT__tank_bullet) 
                                                       | (IData)(vlTOPp->top__DOT__top__DOT__player_1__DOT__tank_bullet)) 
                                                      | (IData)(vlTOPp->top__DOT__top__DOT__enemy_1__DOT__tank_bullet)) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__enemy_2_bullet))
                                                     ? 0xffffffU
                                                     : 0U) 
                                                   >> 8U))
                                             : ((IData)(vlTOPp->top__DOT__top__DOT__score_board__DOT__tank_left_enable)
                                                 ? (IData)(vlTOPp->top__DOT__top__DOT__tank_left_green)
                                                 : 
                                                ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                                  ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_green)
                                                  : 
                                                 ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                                   ? (IData)(vlTOPp->top__DOT__top__DOT__level_green)
                                                   : 0xe0U)))));
            } else {
                if (vlTOPp->top__DOT__top__DOT__is_level_done) {
                    vlTOPp->green_o = ((IData)(vlTOPp->top__DOT__top__DOT__player_tank_enable)
                                        ? (IData)(vlTOPp->top__DOT__top__DOT__player_tank_green)
                                        : ((IData)(vlTOPp->top__DOT__top__DOT__level_enable)
                                            ? (IData)(vlTOPp->top__DOT__top__DOT__level_green)
                                            : ((IData)(vlTOPp->top__DOT__top__DOT__menu__DOT__menu_enable)
                                                ? (IData)(vlTOPp->top__DOT__top__DOT__menu_green)
                                                : 0xe0U)));
                } else {
                    if (vlTOPp->top__DOT__top__DOT__is_game_over) {
                        vlTOPp->green_o = vlTOPp->top__DOT__top__DOT__menu_green;
                    } else {
                        if (vlTOPp->top__DOT__top__DOT__is_game_win) {
                            vlTOPp->green_o = vlTOPp->top__DOT__top__DOT__menu_green;
                        }
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
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
         | ((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    vlTOPp->_combo__TOP__9(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    if (((IData)(vlTOPp->hsync_no) & (~ (IData)(vlTOPp->__Vclklast__TOP__hsync_no)))) {
        vlTOPp->_sequent__TOP__16(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) {
        vlTOPp->_sequent__TOP__17(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__18(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__19(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__20(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__21(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__22(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
         | ((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i))))) {
        vlTOPp->_sequent__TOP__23(vlSymsp);
    }
    vlTOPp->_combo__TOP__24(vlSymsp);
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__25(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__26(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__27(vlSymsp);
    }
    vlTOPp->_combo__TOP__28(vlSymsp);
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__29(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))))) {
        vlTOPp->_sequent__TOP__30(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) {
        vlTOPp->_sequent__TOP__31(vlSymsp);
    }
    if ((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__32(vlSymsp);
    }
    if ((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__33(vlSymsp);
    }
    if ((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__34(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank))))) {
        vlTOPp->_multiclk__TOP__35(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))))) {
        vlTOPp->_multiclk__TOP__36(vlSymsp);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
           & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))))) {
        vlTOPp->_multiclk__TOP__37(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_sequent__TOP__38(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
          | ((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))))) {
        vlTOPp->_multiclk__TOP__39(vlSymsp);
    }
    if (((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
            | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__40(vlSymsp);
    }
    if ((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__41(vlSymsp);
    }
    if ((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__42(vlSymsp);
    }
    if ((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__43(vlSymsp);
    }
    if ((((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
             | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
            | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank)))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__44(vlSymsp);
    }
    if (((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
            | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__45(vlSymsp);
    }
    if ((((((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk))) 
             | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
            | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank)))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__46(vlSymsp);
    }
    if (((((((((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
                | ((IData)(vlTOPp->reset_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset_i)))) 
               | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk) 
                  & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk)))) 
              | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet)))) 
             | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player)))) 
            | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank)))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)))) 
          | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset))))) {
        vlTOPp->_multiclk__TOP__47(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__reset_i = vlTOPp->reset_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset;
    vlTOPp->__Vclklast__TOP__hsync_no = vlTOPp->hsync_no;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->top__DOT__top__DOT__clk_player;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->top__DOT__top__DOT__clk_bullet;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->top__DOT__top__DOT__VGA_clk;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->top__DOT__top__DOT__reset;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__reset_i = vlTOPp->reset_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_player;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_bullet;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__VGA_clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__reset;
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
    vlTOPp->_settle__TOP__4(vlSymsp);
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
         | (vlTOPp->top__DOT__top__DOT__reset ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__reset)
         | (vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank)
         | (vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank)
         | (vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__clk_player ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_player))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:28: top.top.clk_player\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__clk_bullet ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_bullet))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:28: top.top.clk_bullet\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__VGA_clk ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__VGA_clk))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:39: top.top.VGA_clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__reset ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__reset))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:194: top.top.reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank))) VL_DBG_MSGF("        CHANGE: src/tank.sv:54: top.top.player_1.reset_tank\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank))) VL_DBG_MSGF("        CHANGE: src/tank.sv:54: top.top.player_2.reset_tank\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank))) VL_DBG_MSGF("        CHANGE: src/tank_bot.sv:51: top.top.enemy_1.reset_tank\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_player 
        = vlTOPp->top__DOT__top__DOT__clk_player;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_bullet 
        = vlTOPp->top__DOT__top__DOT__clk_bullet;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__VGA_clk 
        = vlTOPp->top__DOT__top__DOT__VGA_clk;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__reset 
        = vlTOPp->top__DOT__top__DOT__reset;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank 
        = vlTOPp->top__DOT__top__DOT__player_1__DOT__reset_tank;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank 
        = vlTOPp->top__DOT__top__DOT__player_2__DOT__reset_tank;
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank 
        = vlTOPp->top__DOT__top__DOT__enemy_1__DOT__reset_tank;
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
    top__DOT__top__DOT__destroyable_block = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__all_hard_block = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__bullet_collide_eagle = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__level_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__menu_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__menu_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__menu_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__tank_left_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__tank_left_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__tank_left_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_tank_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_tank_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_tank_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__level_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__level_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__level_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__hpos = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__vpos = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1_score = VL_RAND_RESET_I(11);
    top__DOT__top__DOT__player_2_score = VL_RAND_RESET_I(11);
    top__DOT__top__DOT__level = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__display_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__VGA_clk = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_menu = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_playing = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_level_done = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_game_over = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__is_game_win = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__reset = VL_RAND_RESET_I(1);
    top__DOT__top__DOT____Vcellinp__game_FSM__space_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_1_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_1_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_1_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_die = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_revive = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__player_1_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_2_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_2_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_2_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_2_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2_die = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2_revive = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_2_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__player_2_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__enemy_1_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_1_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_1_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_1_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1_die = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1_revive = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__enemy_1_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT____Vcellinp__enemy_1__cannot_walk_through_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_2_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_2_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_2_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_2_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_2_tank_enable = VL_RAND_RESET_I(1);
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
    top__DOT__top__DOT__map_rgb__DOT____Vlvbound7 = VL_RAND_RESET_I(7);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    top__DOT__top__DOT__menu__DOT____Vxrand6 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand5 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand4 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand3 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand2 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__menu__DOT____Vxrand1 = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<11; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__title_buffer[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__level_done[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__game_over[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<7; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__game_win[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<14; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__shoot_to_start[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<13; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__shoot_to_continue[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__shoot_to_restart[__Vi0] = VL_RAND_RESET_I(6);
    }}
    top__DOT__top__DOT__menu__DOT__rom_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__menu__DOT__x_ofs = VL_RAND_RESET_I(3);
    top__DOT__top__DOT__menu__DOT__title_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__level_done_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__game_over_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__shoot_to_start_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__shoot_to_continue_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__shoot_to_restart_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__game_win_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__menu__DOT__menu_enable = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__menu__DOT__ascii_rom__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__top__DOT__rgb_render__DOT__map_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__speed_control__DOT__count = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__speed_control__DOT__count2 = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__speed_control__DOT__a = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__bullet_collide_1__DOT__all_player = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__bullet_collide_1__DOT__all_player_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__bullet_collide_1__DOT__all_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive = VL_RAND_RESET_I(32);
    top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive = VL_RAND_RESET_I(32);
    top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive = VL_RAND_RESET_I(32);
    top__DOT__top__DOT__game_FSM__DOT__game_state = VL_RAND_RESET_I(3);
    top__DOT__top__DOT__game_FSM__DOT__counter = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__game_FSM__DOT__counter2 = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__score_board__DOT____Vxrand2 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__score_board__DOT____Vxrand1 = VL_RAND_RESET_I(6);
    top__DOT__top__DOT__score_board__DOT__tank_left_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__tank_left_enable_16 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__tank_left_enable_32 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__player_1_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__player_2_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__tank_left_dout = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__score_board__DOT__player_1_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__player_1_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__score_board__DOT__player_2_tank_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__player_2_bits = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__score_board__DOT__bit_number = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<7; ++__Vi0) {
            top__DOT__top__DOT__score_board__DOT__level[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            top__DOT__top__DOT__score_board__DOT__player_score[__Vi0] = VL_RAND_RESET_I(6);
    }}
    top__DOT__top__DOT__score_board__DOT__rom_addr = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__score_board__DOT__x_ofs = VL_RAND_RESET_I(3);
    top__DOT__top__DOT__score_board__DOT__level_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__score_board__DOT__score_enable = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            top__DOT__top__DOT__score_board__DOT__mem_lives__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__score_board__DOT__mem_player_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__score_board__DOT__mem_player_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__score_board__DOT__ascii_rom__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__top__DOT__player_1__DOT__tank_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1__DOT__tank_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_1__DOT__tank_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_top = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_left = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_collide_with_wall_right = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_1__DOT__tank_prev_direct = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_1__DOT__reset_tank = VL_RAND_RESET_I(1);
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
    top__DOT__top__DOT__player_2__DOT__reset_tank = VL_RAND_RESET_I(1);
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
    top__DOT__top__DOT__enemy_1__DOT__tank_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__enemy_1__DOT__tank_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__enemy_1__DOT__tank_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_prev_direct = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__enemy_1__DOT__auto_tank_move = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__enemy_1__DOT__auto_tank_shoot = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__reset_tank = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_yofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__enemy_1__DOT__tank_xofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__enemy_1__DOT__tank_xofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__enemy_1__DOT__tank_yofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__enemy_1__DOT__tank_bullet_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__enemy_1__DOT__tank_bullet_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__enemy_1__DOT__bullet_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__enemy_1__DOT__bullet_dir = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__enemy_1__DOT__show_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__tank_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__enemy_1__DOT__bot_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__enemy_1__DOT__dir_stage = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__enemy_1__DOT__premove_tank = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__enemy_1__DOT__count = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__enemy_1__DOT__count2 = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__enemy_1__DOT__pos_edge_detect_1__DOT__sig_dly = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__top__DOT__mem_enemy_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    __Vdly__top__DOT__top__DOT__hpos = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__vpos = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_stage = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_live_left = VL_RAND_RESET_I(4);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_1_count_revive = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_stage = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_live_left = VL_RAND_RESET_I(4);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__player_2_count_revive = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_stage = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_live_left = VL_RAND_RESET_I(4);
    __Vdly__top__DOT__top__DOT__bullet_collide_1__DOT__enemy_1_count_revive = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__top__DOT__game_FSM__DOT__game_state = VL_RAND_RESET_I(3);
    __Vdly__top__DOT__top__DOT__level = VL_RAND_RESET_I(4);
    __Vdly__top__DOT__top__DOT__game_FSM__DOT__counter = VL_RAND_RESET_I(24);
    __Vdly__top__DOT__top__DOT__game_FSM__DOT__counter2 = VL_RAND_RESET_I(24);
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_1__DOT__tank_y = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_2__DOT__tank_y = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_top = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_right = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_collide_with_wall_left = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__tank_y = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__bot_stage = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__dir_stage = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__count2 = VL_RAND_RESET_I(8);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__premove_tank = VL_RAND_RESET_I(4);
    __Vdly__top__DOT__top__DOT__enemy_1__DOT__count = VL_RAND_RESET_I(5);
    __VinpClk__TOP__top__DOT__top__DOT__clk_player = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__clk_bullet = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__VGA_clk = VL_RAND_RESET_I(1);
    __VinpClk__TOP__top__DOT__top__DOT__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__clk_player = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__clk_bullet = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__VGA_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__reset = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__player_1__DOT__reset_tank = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__player_2__DOT__reset_tank = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__enemy_1__DOT__reset_tank = VL_RAND_RESET_I(1);
}
