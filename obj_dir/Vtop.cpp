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
    WData/*191:0*/ __Vtemp1[6];
    WData/*191:0*/ __Vtemp2[6];
    WData/*127:0*/ __Vtemp3[4];
    // Body
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x65725f31U;
    __Vtemp1[2U] = 0x706c6179U;
    __Vtemp1[3U] = 0x7267625fU;
    __Vtemp1[4U] = 0x6269745fU;
    __Vtemp1[5U] = 0x3234U;
    VL_READMEM_N(true, 24, 2048, 0, VL_CVT_PACK_STR_NW(6, __Vtemp1)
                 , vlTOPp->top__DOT__top__DOT__player_rgb__DOT__mem_player_1__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e747874U;
    __Vtemp2[1U] = 0x65725f32U;
    __Vtemp2[2U] = 0x706c6179U;
    __Vtemp2[3U] = 0x7267625fU;
    __Vtemp2[4U] = 0x6269745fU;
    __Vtemp2[5U] = 0x3234U;
    VL_READMEM_N(true, 24, 2048, 0, VL_CVT_PACK_STR_NW(6, __Vtemp2)
                 , vlTOPp->top__DOT__top__DOT__player_rgb__DOT__mem_player_2__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp3[0U] = 0x2e747874U;
    __Vtemp3[1U] = 0x5f726762U;
    __Vtemp3[2U] = 0x34626974U;
    __Vtemp3[3U] = 0x32U;
    VL_READMEM_N(true, 24, 8192, 0, VL_CVT_PACK_STR_NW(4, __Vtemp3)
                 , vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1 
        = VL_RAND_RESET_I(7);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2 
        = VL_RAND_RESET_I(7);
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x = 0xe0U;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y = 0x20U;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x = 0xe0U;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y = 0x1a0U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172;
    CData/*3:0*/ __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172;
    CData/*2:0*/ __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172;
    CData/*0:0*/ __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172;
    CData/*0:0*/ __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward;
    IData/*24:0*/ __Vdly__top__DOT__top__DOT__speed_control__DOT__count;
    // Body
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs;
    vlTOPp->__Vdly__vpos_o = vlTOPp->vpos_o;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state;
    vlTOPp->__Vdly__hpos_o = vlTOPp->hpos_o;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171 = 0U;
    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172 = 0U;
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count 
        = vlTOPp->top__DOT__top__DOT__speed_control__DOT__count;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_2__DOT__sig_dly 
        = vlTOPp->player_2_shoot_i;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_1__DOT__sig_dly 
        = vlTOPp->player_1_shoot_i;
    if (((IData)(vlTOPp->hpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward = 0x1eU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->hpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs = 1U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs)));
        }
    }
    if (((IData)(vlTOPp->hpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward = 0x1cU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->hpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs = 1U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs)));
        }
    }
    if ((0x31fU == (IData)(vlTOPp->hpos_o))) {
        vlTOPp->__Vdly__vpos_o = ((IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed)
                                   ? 0U : (0x3ffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlTOPp->vpos_o))));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_2 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs));
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_2 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward));
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_2 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs));
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_2 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward));
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_1 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward));
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_1 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs));
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_1 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward));
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_1 
                        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs) 
                            << 5U) | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs));
                }
            }
        }
    }
    if (vlTOPp->reset_i) {
        __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v0 = 1U;
    } else {
        if (vlTOPp->top__DOT__top__DOT__bullet_collide) {
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound3 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound3;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 = 0U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 
                        = (0xfU & (((IData)(vlTOPp->hpos_o) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169 
                        = (0xfU & (((IData)(vlTOPp->vpos_o) 
                                    >> 5U) - (IData)(1U)));
                }
            }
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound4 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound4;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170 = 1U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170 
                        = (0xfU & (((IData)(vlTOPp->hpos_o) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170 
                        = (0xfU & (((IData)(vlTOPp->vpos_o) 
                                    >> 5U) - (IData)(1U)));
                }
            }
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound5 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound5;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171 = 2U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171 
                        = (0xfU & (((IData)(vlTOPp->hpos_o) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171 
                        = (0xfU & (((IData)(vlTOPp->vpos_o) 
                                    >> 5U) - (IData)(1U)));
                }
            }
            if (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL) {
                vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound6 = 0U;
                if (((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                        >> 5U) - (IData)(1U)))) 
                     & (0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                          >> 5U) - (IData)(1U)))))) {
                    __Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172 
                        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vlvbound6;
                    __Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172 = 1U;
                    __Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172 = 3U;
                    __Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172 
                        = (0xfU & (((IData)(vlTOPp->hpos_o) 
                                    >> 5U) - (IData)(1U)));
                    __Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172 
                        = (0xfU & (((IData)(vlTOPp->vpos_o) 
                                    >> 5U) - (IData)(1U)));
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync 
        = ((0x28fU <= (IData)(vlTOPp->hpos_o)) & (0x2eeU 
                                                  >= (IData)(vlTOPp->hpos_o)));
    vlTOPp->__Vdly__hpos_o = ((IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed)
                               ? 0U : (0x3ffU & ((IData)(1U) 
                                                 + (IData)(vlTOPp->hpos_o))));
    __Vdly__top__DOT__top__DOT__speed_control__DOT__count 
        = (0x1ffffffU & ((IData)(1U) + vlTOPp->top__DOT__top__DOT__speed_control__DOT__count));
    if ((0x124f8U == vlTOPp->top__DOT__top__DOT__speed_control__DOT__count)) {
        vlTOPp->top__DOT__top__DOT__clk_slow = (1U 
                                                & (~ (IData)(vlTOPp->top__DOT__top__DOT__clk_slow)));
        __Vdly__top__DOT__top__DOT__speed_control__DOT__count = 0U;
    }
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_xofs 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_xofs;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][5U] = 0x1fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][6U] = 0x7fU;
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[1U][7U] = 0x1fU;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[0xaU][6U] = 0xfU;
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
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v169)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v170)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v171)));
    }
    if (__Vdlyvset__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172) {
        vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles[__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172][__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172] 
            = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172))) 
                & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                [__Vdlyvdim0__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172]
                [__Vdlyvdim1__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172]) 
               | ((IData)(__Vdlyvval__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172) 
                  << (IData)(__Vdlyvlsb__top__DOT__top__DOT__map_rgb__DOT__map_tiles__v172)));
    }
    vlTOPp->top__DOT__top__DOT__speed_control__DOT__count 
        = __Vdly__top__DOT__top__DOT__speed_control__DOT__count;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__mem_player_2__DOT__mem
        [(0x400U | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_2))];
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__mem_player_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_1];
    vlTOPp->top__DOT__top__DOT__hsync = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync)));
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__hsync = (1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__hsync)));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot 
        = ((IData)(vlTOPp->player_1_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_1__DOT__sig_dly)));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot 
        = ((IData)(vlTOPp->player_2_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_2__DOT__sig_dly)));
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed 
        = (0x31fU == (IData)(vlTOPp->hpos_o));
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed 
        = (0x20cU == (IData)(vlTOPp->vpos_o));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_1) 
            & (4U >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y)))) 
           & (4U >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_2) 
            & (4U >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y)))) 
           & (4U >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x))));
    vlTOPp->display_enable_o = ((0x280U > (IData)(vlTOPp->hpos_o)) 
                                & (0x1e0U > (IData)(vlTOPp->vpos_o)));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__mem_player_1__DOT__mem
        [vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_1];
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__mem_player_2__DOT__mem
        [(0x400U | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__addr_2))];
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box 
        = ((((0x1cU >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))) 
             & (3U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)))) 
            & (0x1cU >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)))) 
           & (3U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box 
        = ((((0x1cU >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))) 
             & (3U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)))) 
            & (0x1cU >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)))) 
           & (3U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))));
    vlTOPp->top__DOT__top__DOT__map_enable = (((((IData)(vlTOPp->display_enable_o) 
                                                 & (0x20U 
                                                    <= (IData)(vlTOPp->hpos_o))) 
                                                & (0x1bfU 
                                                   >= (IData)(vlTOPp->hpos_o))) 
                                               & (0x20U 
                                                  <= (IData)(vlTOPp->vpos_o))) 
                                              & (0x1bfU 
                                                 >= (IData)(vlTOPp->vpos_o)));
    vlTOPp->top__DOT__top__DOT__player_blue = (0xffU 
                                               & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box)
                                                   ? 
                                                  (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1 
                                                   >> 0x10U)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box)
                                                    ? 
                                                   (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2 
                                                    >> 0x10U)
                                                    : 0U)));
    vlTOPp->top__DOT__top__DOT__player_red = (0xffU 
                                              & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box)
                                                  ? vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1
                                                  : 
                                                 ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box)
                                                   ? vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2
                                                   : 0U)));
    vlTOPp->top__DOT__top__DOT__player_green = (0xffU 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box)
                                                    ? 
                                                   (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1 
                                                    >> 8U)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box)
                                                     ? 
                                                    (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2 
                                                     >> 8U)
                                                     : 0U)));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (7U & (((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                         >> 5U) - (IData)(1U))))
                       ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                      [((0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                           >> 5U) - (IData)(1U))))
                         ? (0xfU & (((IData)(vlTOPp->vpos_o) 
                                     >> 5U) - (IData)(1U)))
                         : 0U)][(0xfU & (((IData)(vlTOPp->hpos_o) 
                                          >> 5U) - (IData)(1U)))]
                       : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1)) 
                     >> 4U)) : 7U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (0xfU & ((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                          >> 5U) - (IData)(1U))))
                        ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                       [((0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                            >> 5U) 
                                           - (IData)(1U))))
                          ? (0xfU & (((IData)(vlTOPp->vpos_o) 
                                      >> 5U) - (IData)(1U)))
                          : 0U)][(0xfU & (((IData)(vlTOPp->hpos_o) 
                                           >> 5U) - (IData)(1U)))]
                        : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2)))
            : 0U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
        [(((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type) 
           << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->vpos_o) 
                                  << 5U)) | (0x1fU 
                                             & (IData)(vlTOPp->hpos_o))))];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 1U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 2U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 3U));
    vlTOPp->top__DOT__top__DOT__cannot_walk_through 
        = ((((((((IData)(vlTOPp->display_enable_o) 
                 & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable))) 
                | (1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type))) 
               | (3U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type))) 
              | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
             | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
            | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
               & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
           | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
              & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__all_hard_block = ((
                                                   ((((1U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      | ((IData)(vlTOPp->display_enable_o) 
                                                         & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable)))) 
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
                                                     & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__bullet_collide = ((
                                                   ((((0U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL)) 
                                                     | ((0U 
                                                         == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                        & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                                                    | ((0U 
                                                        == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                       & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
                                                   | ((0U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet)));
    vlTOPp->top__DOT__top__DOT__map_blue = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                             ? (0xffU 
                                                & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                   >> 0x10U))
                                             : 0U);
    vlTOPp->top__DOT__top__DOT__map_red = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                            | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                            ? (0xffU 
                                               & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout)
                                            : 0U);
    vlTOPp->top__DOT__top__DOT__map_green = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                              ? (0xffU 
                                                 & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                    >> 8U))
                                              : 0U);
    vlTOPp->blue_o = ((IData)(vlTOPp->display_enable_o)
                       ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                           ? (0xffU & (((IData)(vlTOPp->top__DOT__top__DOT__map_blue) 
                                        | (IData)(vlTOPp->top__DOT__top__DOT__player_blue)) 
                                       | ((((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                            | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet))
                                            ? 0xffffffU
                                            : 0U) >> 0x10U)))
                           : 0xe0U) : 0U);
    vlTOPp->red_o = ((IData)(vlTOPp->display_enable_o)
                      ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                          ? (0xffU & (((IData)(vlTOPp->top__DOT__top__DOT__map_red) 
                                       | (IData)(vlTOPp->top__DOT__top__DOT__player_red)) 
                                      | (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                          | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet))
                                          ? 0xffffffU
                                          : 0U))) : 0xe0U)
                      : 0U);
    vlTOPp->green_o = ((IData)(vlTOPp->display_enable_o)
                        ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                            ? (0xffU & (((IData)(vlTOPp->top__DOT__top__DOT__map_green) 
                                         | (IData)(vlTOPp->top__DOT__top__DOT__player_green)) 
                                        | ((((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet))
                                             ? 0xffffffU
                                             : 0U) 
                                           >> 8U)))
                            : 0xe0U) : 0U);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y;
    SData/*9:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x;
    // Body
    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y;
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y = 0x20U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                    = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y) 
                                             - (IData)(1U)));
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)));
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y;
                    }
                }
            }
        }
    }
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x = 0xe0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                    = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x) 
                                             - (IData)(1U)));
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)));
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x;
                    }
                }
            }
        }
    }
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y = 0x1a0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                    = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y) 
                                             - (IData)(1U)));
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)));
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y;
                    }
                }
            }
        }
    }
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x = 0xe0U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                    = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                                = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x) 
                                             - (IData)(1U)));
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right)))) {
                            vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                                = (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)));
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x 
                            = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x;
                    }
                }
            }
        }
    }
    if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
                            = (0x3ffU & ((IData)(4U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)));
                    }
                }
            }
        }
    }
    if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
                            = (0x3ffU & ((IData)(4U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)));
                    }
                }
            }
        }
    }
    if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
                            = (0x3ffU & ((IData)(4U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x) 
                                         - (IData)(4U)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)));
                    }
                }
            }
        }
    }
    if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
                            = (0x3ffU & ((IData)(4U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y)));
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)));
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
                            = (0x3ffU & ((IData)(0xeU) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)));
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct)))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
                            = (0x3ffU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y) 
                                         - (IData)(4U)));
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct))) {
                        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
                            = (0x3ffU & ((IData)(0x20U) 
                                         + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)));
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs;
    CData/*4:0*/ __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward;
    // Body
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward;
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs 
        = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs;
    if (((IData)(vlTOPp->vpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward = 0x1fU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->vpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs = 0U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs)));
        }
    }
    if (((IData)(vlTOPp->vpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward = 0x1eU;
    } else {
        if ((0U != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward) 
                            - (IData)(1U)));
        }
    }
    if (((IData)(vlTOPp->vpos_o) == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))) {
        __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs = 1U;
    } else {
        if ((0x1fU != (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs))) {
            __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs)));
        }
    }
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_yofs 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_yofs;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_yofs 
        = __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_yofs;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_2 = 0U;
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir 
                = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct;
            if (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
                vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_2 = 1U;
                if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet) 
                     & (IData)(vlTOPp->top__DOT__top__DOT__all_hard_block))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state = 2U;
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_2 = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset_i) {
        vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_1 = 0U;
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir 
                = vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct;
            if (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) {
                vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state = 1U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
                vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_1 = 1U;
                if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                     & (IData)(vlTOPp->top__DOT__top__DOT__all_hard_block))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state = 2U;
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_1 = 0U;
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state))) {
                    vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state = 0U;
                }
            }
        }
    }
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_2_state 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__bullet_1_state 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset_i) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct = 2U;
    } else {
        if ((8U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct = 8U;
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct = 4U;
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct = 2U;
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct = 1U;
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset_i) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct = 1U;
    } else {
        if ((8U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct = 8U;
                        }
                    }
                }
            }
        } else {
            if ((4U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct = 4U;
                        }
                    }
                }
            } else {
                if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                    if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct = 2U;
                        }
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom)))) {
                            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct = 1U;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((2U == ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))) 
              & (0x1bU >= ((IData)(vlTOPp->vpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)))) 
             & (4U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left = 1U;
        }
    }
    if ((8U & (IData)(vlTOPp->player_2_move_i))) {
        if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right = 0U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                      >> 2U)))) {
            if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((0x1dU == ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))) 
              & (0x1bU >= ((IData)(vlTOPp->vpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)))) 
             & (4U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right = 1U;
        }
    }
    if ((8U & (IData)(vlTOPp->player_2_move_i))) {
        if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top = 0U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top = 0U;
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->player_2_move_i))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((2U == ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))) 
              & (0x1bU >= ((IData)(vlTOPp->hpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)))) 
             & (4U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top = 1U;
        }
    }
    if ((8U & (IData)(vlTOPp->player_2_move_i))) {
        if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom = 0U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->player_2_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_2_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->player_2_move_i))) {
                if ((1U & (~ (IData)(vlTOPp->player_2_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((0x1dU == ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))) 
              & (0x1bU >= ((IData)(vlTOPp->hpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)))) 
             & (4U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom = 1U;
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((2U == ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))) 
              & (0x1bU >= ((IData)(vlTOPp->vpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)))) 
             & (4U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left = 1U;
        }
    }
    if ((8U & (IData)(vlTOPp->player_1_move_i))) {
        if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right = 0U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                      >> 2U)))) {
            if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((0x1dU == ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))) 
              & (0x1bU >= ((IData)(vlTOPp->vpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)))) 
             & (4U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right = 1U;
        }
    }
    if ((8U & (IData)(vlTOPp->player_1_move_i))) {
        if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top = 0U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top = 0U;
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->player_1_move_i))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((2U == ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))) 
              & (0x1bU >= ((IData)(vlTOPp->hpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)))) 
             & (4U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top = 1U;
        }
    }
    if ((8U & (IData)(vlTOPp->player_1_move_i))) {
        if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom = 0U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->player_1_move_i))) {
            if ((1U & (~ ((IData)(vlTOPp->player_1_move_i) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->player_1_move_i))) {
                if ((1U & (~ (IData)(vlTOPp->player_1_move_i)))) {
                    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom = 0U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot) 
         | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot))) {
        vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom = 0U;
    }
    if (vlTOPp->top__DOT__top__DOT__cannot_walk_through) {
        if ((((0x1dU == ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))) 
              & (0x1bU >= ((IData)(vlTOPp->hpos_o) 
                           - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)))) 
             & (4U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))))) {
            vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom = 1U;
        }
    }
    vlTOPp->vpos_o = vlTOPp->__Vdly__vpos_o;
    vlTOPp->hpos_o = vlTOPp->__Vdly__hpos_o;
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed 
        = (0x20cU == (IData)(vlTOPp->vpos_o));
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed 
        = (0x31fU == (IData)(vlTOPp->hpos_o));
    vlTOPp->display_enable_o = ((0x280U > (IData)(vlTOPp->hpos_o)) 
                                & (0x1e0U > (IData)(vlTOPp->vpos_o)));
    vlTOPp->top__DOT__top__DOT__map_enable = (((((IData)(vlTOPp->display_enable_o) 
                                                 & (0x20U 
                                                    <= (IData)(vlTOPp->hpos_o))) 
                                                & (0x1bfU 
                                                   >= (IData)(vlTOPp->hpos_o))) 
                                               & (0x20U 
                                                  <= (IData)(vlTOPp->vpos_o))) 
                                              & (0x1bfU 
                                                 >= (IData)(vlTOPp->vpos_o)));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (7U & (((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                         >> 5U) - (IData)(1U))))
                       ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                      [((0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                           >> 5U) - (IData)(1U))))
                         ? (0xfU & (((IData)(vlTOPp->vpos_o) 
                                     >> 5U) - (IData)(1U)))
                         : 0U)][(0xfU & (((IData)(vlTOPp->hpos_o) 
                                          >> 5U) - (IData)(1U)))]
                       : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand1)) 
                     >> 4U)) : 7U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state 
        = ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
            ? (0xfU & ((0xcU >= (0xfU & (((IData)(vlTOPp->hpos_o) 
                                          >> 5U) - (IData)(1U))))
                        ? vlTOPp->top__DOT__top__DOT__map_rgb__DOT__map_tiles
                       [((0xcU >= (0xfU & (((IData)(vlTOPp->vpos_o) 
                                            >> 5U) 
                                           - (IData)(1U))))
                          ? (0xfU & (((IData)(vlTOPp->vpos_o) 
                                      >> 5U) - (IData)(1U)))
                          : 0U)][(0xfU & (((IData)(vlTOPp->hpos_o) 
                                           >> 5U) - (IData)(1U)))]
                        : (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT____Vxrand2)))
            : 0U);
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
        = vlTOPp->top__DOT__top__DOT__map_rgb__DOT__tile__DOT__mem
        [(((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type) 
           << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->vpos_o) 
                                  << 5U)) | (0x1fU 
                                             & (IData)(vlTOPp->hpos_o))))];
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U >= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 1U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR = 
        (((0x10U >= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 2U));
    vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL = 
        (((0x10U <= (0x1fU & (IData)(vlTOPp->hpos_o))) 
          & (0x10U <= (0x1fU & (IData)(vlTOPp->vpos_o)))) 
         & ((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_state) 
            >> 3U));
    vlTOPp->top__DOT__top__DOT__cannot_walk_through 
        = ((((((((IData)(vlTOPp->display_enable_o) 
                 & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable))) 
                | (1U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type))) 
               | (3U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type))) 
              | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                 & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL))) 
             | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
            | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
               & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
           | ((0U == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
              & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__all_hard_block = ((
                                                   ((((1U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      | ((IData)(vlTOPp->display_enable_o) 
                                                         & (~ (IData)(vlTOPp->top__DOT__top__DOT__map_enable)))) 
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
                                                     & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL)));
    vlTOPp->top__DOT__top__DOT__map_blue = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                             ? (0xffU 
                                                & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                   >> 0x10U))
                                             : 0U);
    vlTOPp->top__DOT__top__DOT__map_red = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                            | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                            ? (0xffU 
                                               & vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout)
                                            : 0U);
    vlTOPp->top__DOT__top__DOT__map_green = (((((IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL) 
                                                | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR)) 
                                               | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR)) 
                                              | (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))
                                              ? (0xffU 
                                                 & (vlTOPp->top__DOT__top__DOT__map_rgb__DOT__dout 
                                                    >> 8U))
                                              : 0U);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__9\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y;
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x 
        = vlTOPp->__Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x;
}

VL_INLINE_OPT void Vtop::_combo__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__10\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_shoot 
        = ((IData)(vlTOPp->player_1_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_1__DOT__sig_dly)));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_shoot 
        = ((IData)(vlTOPp->player_2_shoot_i) & (~ (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_2__DOT__sig_dly)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__11\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_1) 
            & (4U >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y)))) 
           & (4U >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet 
        = (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__show_bullet_2) 
            & (4U >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y)))) 
           & (4U >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x))));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box 
        = ((((0x1cU >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y))) 
             & (3U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_y)))) 
            & (0x1cU >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x)))) 
           & (3U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_x))));
    vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box 
        = ((((0x1cU >= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y))) 
             & (3U <= ((IData)(vlTOPp->vpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_y)))) 
            & (0x1cU >= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x)))) 
           & (3U <= ((IData)(vlTOPp->hpos_o) - (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_x))));
    vlTOPp->top__DOT__top__DOT__bullet_collide = ((
                                                   ((((0U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UL)) 
                                                     | ((0U 
                                                         == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                        & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__UR))) 
                                                    | ((0U 
                                                        == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                       & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LR))) 
                                                   | ((0U 
                                                       == (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__block_type)) 
                                                      & (IData)(vlTOPp->top__DOT__top__DOT__map_rgb__DOT__LL))) 
                                                  & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                                     | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet)));
    vlTOPp->top__DOT__top__DOT__player_blue = (0xffU 
                                               & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box)
                                                   ? 
                                                  (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1 
                                                   >> 0x10U)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box)
                                                    ? 
                                                   (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2 
                                                    >> 0x10U)
                                                    : 0U)));
    vlTOPp->top__DOT__top__DOT__player_red = (0xffU 
                                              & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box)
                                                  ? vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1
                                                  : 
                                                 ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box)
                                                   ? vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2
                                                   : 0U)));
    vlTOPp->top__DOT__top__DOT__player_green = (0xffU 
                                                & ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_box)
                                                    ? 
                                                   (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_1 
                                                    >> 8U)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_box)
                                                     ? 
                                                    (vlTOPp->top__DOT__top__DOT__player_rgb__DOT__dout_2 
                                                     >> 8U)
                                                     : 0U)));
    vlTOPp->blue_o = ((IData)(vlTOPp->display_enable_o)
                       ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                           ? (0xffU & (((IData)(vlTOPp->top__DOT__top__DOT__map_blue) 
                                        | (IData)(vlTOPp->top__DOT__top__DOT__player_blue)) 
                                       | ((((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                            | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet))
                                            ? 0xffffffU
                                            : 0U) >> 0x10U)))
                           : 0xe0U) : 0U);
    vlTOPp->red_o = ((IData)(vlTOPp->display_enable_o)
                      ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                          ? (0xffU & (((IData)(vlTOPp->top__DOT__top__DOT__map_red) 
                                       | (IData)(vlTOPp->top__DOT__top__DOT__player_red)) 
                                      | (((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                          | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet))
                                          ? 0xffffffU
                                          : 0U))) : 0xe0U)
                      : 0U);
    vlTOPp->green_o = ((IData)(vlTOPp->display_enable_o)
                        ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                            ? (0xffU & (((IData)(vlTOPp->top__DOT__top__DOT__map_green) 
                                         | (IData)(vlTOPp->top__DOT__top__DOT__player_green)) 
                                        | ((((IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_1_bullet) 
                                             | (IData)(vlTOPp->top__DOT__top__DOT__player_rgb__DOT__player_2_bullet))
                                             ? 0xffffffU
                                             : 0U) 
                                           >> 8U)))
                            : 0xe0U) : 0U);
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__top__DOT__hsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__top__DOT__hsync)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow)))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    vlTOPp->_combo__TOP__10(vlSymsp);
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow))))) {
        vlTOPp->_multiclk__TOP__11(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow;
    vlTOPp->__Vclklast__TOP__top__DOT__top__DOT__hsync 
        = vlTOPp->top__DOT__top__DOT__hsync;
    vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow 
        = vlTOPp->top__DOT__top__DOT__clk_slow;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__top__DOT__clk_slow 
        = vlTOPp->__VinpClk__TOP__top__DOT__top__DOT__clk_slow;
    vlTOPp->__Vclklast__TOP__top__DOT__top__DOT__hsync 
        = vlTOPp->top__DOT__top__DOT__hsync;
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
    __req |= ((vlTOPp->top__DOT__top__DOT__clk_slow ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_slow));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__top__DOT__clk_slow ^ vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_slow))) VL_DBG_MSGF("        CHANGE: src/game_top.sv:18: top.top.clk_slow\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__top__DOT__clk_slow 
        = vlTOPp->top__DOT__top__DOT__clk_slow;
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
    display_enable_o = VL_RAND_RESET_I(1);
    hpos_o = VL_RAND_RESET_I(10);
    vpos_o = VL_RAND_RESET_I(10);
    blue_o = VL_RAND_RESET_I(8);
    green_o = VL_RAND_RESET_I(8);
    red_o = VL_RAND_RESET_I(8);
    clk_i = VL_RAND_RESET_I(1);
    reset_i = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__clk_slow = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__cannot_walk_through = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__hsync = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__all_hard_block = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__bullet_collide = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__map_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_red = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_green = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__player_blue = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__hvsync_gen__DOT__hsync = VL_RAND_RESET_I(1);
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
    top__DOT__top__DOT__speed_control__DOT__count = VL_RAND_RESET_I(25);
    top__DOT__top__DOT__player_rgb__DOT__player_1_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__player_1_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__player_2_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__player_2_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__player_1_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_top = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_left = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_collide_with_wall_right = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_box = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_top = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_bottom = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_left = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_collide_with_wall_right = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_prev_direct = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_rgb__DOT__player_2_prev_direct = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_rgb__DOT__addr_1 = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__dout_1 = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__player_rgb__DOT__player_1_yofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_1_xofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_1_xofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_1_yofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__addr_2 = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__dout_2 = VL_RAND_RESET_I(24);
    top__DOT__top__DOT__player_rgb__DOT__player_2_yofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_2_xofs_backward = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_2_xofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_2_yofs = VL_RAND_RESET_I(5);
    top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__player_1_bullet_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__bullet_1_state = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__player_rgb__DOT__bullet_1_dir = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_rgb__DOT__show_bullet_1 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_1_shoot = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_x = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__player_2_bullet_y = VL_RAND_RESET_I(10);
    top__DOT__top__DOT__player_rgb__DOT__bullet_2_state = VL_RAND_RESET_I(2);
    top__DOT__top__DOT__player_rgb__DOT__bullet_2_dir = VL_RAND_RESET_I(4);
    top__DOT__top__DOT__player_rgb__DOT__show_bullet_2 = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_bullet = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__player_2_shoot = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
            top__DOT__top__DOT__player_rgb__DOT__mem_player_1__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
            top__DOT__top__DOT__player_rgb__DOT__mem_player_2__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_1__DOT__sig_dly = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__player_rgb__DOT__pos_edge_detect_2__DOT__sig_dly = VL_RAND_RESET_I(1);
    __Vdly__hpos_o = VL_RAND_RESET_I(10);
    __Vdly__vpos_o = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_1_state = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__bullet_2_state = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_2_y = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_x = VL_RAND_RESET_I(10);
    __Vdly__top__DOT__top__DOT__player_rgb__DOT__player_1_y = VL_RAND_RESET_I(10);
    __VinpClk__TOP__top__DOT__top__DOT__clk_slow = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__top__DOT__clk_slow = VL_RAND_RESET_I(1);
}
