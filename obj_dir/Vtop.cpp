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
    WData/*127:0*/ __Vtemp1[4];
    // Body
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x5f726762U;
    __Vtemp1[2U] = 0x34626974U;
    __Vtemp1[3U] = 0x32U;
    VL_READMEM_N(true, 24, 8192, 0, VL_CVT_PACK_STR_NW(4, __Vtemp1)
                 , vlTOPp->top__DOT__top__DOT__tile__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__top__DOT__map_block__DOT____Vxrand1 
        = VL_RAND_RESET_I(3);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[0U] = VL_ULL(0x7fffffffff);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[1U] = VL_ULL(0x71c71c71c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[2U] = VL_ULL(0x71c71c71c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[3U] = VL_ULL(0x71c70471c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[4U] = VL_ULL(0x71c71c71c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[5U] = VL_ULL(0x7fffffffff);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[6U] = VL_ULL(0x1e07fff039);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[7U] = VL_ULL(0x7fffffffff);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[8U] = VL_ULL(0x71c71c71c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[9U] = VL_ULL(0x71c71c71c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[0xaU] = VL_ULL(0x71c70071c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[0xbU] = VL_ULL(0x71c71c71c7);
    vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles[0xcU] = VL_ULL(0x7fffffffff);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__hpos_o;
    // Body
    __Vdly__hpos_o = vlTOPp->hpos_o;
    __Vdly__hpos_o = ((IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed)
                       ? 0U : (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->hpos_o))));
    if ((0x31fU == (IData)(vlTOPp->hpos_o))) {
        vlTOPp->vpos_o = ((IData)(vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed)
                           ? 0U : (0x3ffU & ((IData)(1U) 
                                             + (IData)(vlTOPp->vpos_o))));
    }
    vlTOPp->hpos_o = __Vdly__hpos_o;
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed 
        = (0x31fU == (IData)(vlTOPp->hpos_o));
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed 
        = (0x20cU == (IData)(vlTOPp->vpos_o));
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
    vlTOPp->top__DOT__top__DOT__dout = vlTOPp->top__DOT__top__DOT__tile__DOT__mem
        [((((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
             ? (7U & ((0x26U >= (0x3fU & ((IData)(3U) 
                                          * (0xfU & 
                                             (((IData)(vlTOPp->hpos_o) 
                                               >> 5U) 
                                              - (IData)(1U))))))
                       ? (IData)((vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles
                                  [((0xcU >= (0xfU 
                                              & (((IData)(vlTOPp->vpos_o) 
                                                  >> 5U) 
                                                 - (IData)(1U))))
                                     ? (0xfU & (((IData)(vlTOPp->vpos_o) 
                                                 >> 5U) 
                                                - (IData)(1U)))
                                     : 0U)] >> (0x3fU 
                                                & ((IData)(3U) 
                                                   * 
                                                   (0xfU 
                                                    & (((IData)(vlTOPp->hpos_o) 
                                                        >> 5U) 
                                                       - (IData)(1U)))))))
                       : (IData)(vlTOPp->top__DOT__top__DOT__map_block__DOT____Vxrand1)))
             : 7U) << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->vpos_o) 
                                          << 5U)) | 
                               (0x1fU & (IData)(vlTOPp->hpos_o))))];
    vlTOPp->green_o = ((IData)(vlTOPp->display_enable_o)
                        ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                            ? (0xffU & (vlTOPp->top__DOT__top__DOT__dout 
                                        >> 8U)) : 0xe0U)
                        : 0U);
    vlTOPp->blue_o = ((IData)(vlTOPp->display_enable_o)
                       ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                           ? (0xffU & (vlTOPp->top__DOT__top__DOT__dout 
                                       >> 0x10U)) : 0xe0U)
                       : 0U);
    vlTOPp->red_o = ((IData)(vlTOPp->display_enable_o)
                      ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                          ? (0xffU & vlTOPp->top__DOT__top__DOT__dout)
                          : 0xe0U) : 0U);
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed 
        = (0x31fU == (IData)(vlTOPp->hpos_o));
    vlTOPp->top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed 
        = (0x20cU == (IData)(vlTOPp->vpos_o));
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
    vlTOPp->top__DOT__top__DOT__dout = vlTOPp->top__DOT__top__DOT__tile__DOT__mem
        [((((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
             ? (7U & ((0x26U >= (0x3fU & ((IData)(3U) 
                                          * (0xfU & 
                                             (((IData)(vlTOPp->hpos_o) 
                                               >> 5U) 
                                              - (IData)(1U))))))
                       ? (IData)((vlTOPp->top__DOT__top__DOT__map_block__DOT__map_tiles
                                  [((0xcU >= (0xfU 
                                              & (((IData)(vlTOPp->vpos_o) 
                                                  >> 5U) 
                                                 - (IData)(1U))))
                                     ? (0xfU & (((IData)(vlTOPp->vpos_o) 
                                                 >> 5U) 
                                                - (IData)(1U)))
                                     : 0U)] >> (0x3fU 
                                                & ((IData)(3U) 
                                                   * 
                                                   (0xfU 
                                                    & (((IData)(vlTOPp->hpos_o) 
                                                        >> 5U) 
                                                       - (IData)(1U)))))))
                       : (IData)(vlTOPp->top__DOT__top__DOT__map_block__DOT____Vxrand1)))
             : 7U) << 0xaU) | ((0x3e0U & ((IData)(vlTOPp->vpos_o) 
                                          << 5U)) | 
                               (0x1fU & (IData)(vlTOPp->hpos_o))))];
    vlTOPp->green_o = ((IData)(vlTOPp->display_enable_o)
                        ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                            ? (0xffU & (vlTOPp->top__DOT__top__DOT__dout 
                                        >> 8U)) : 0xe0U)
                        : 0U);
    vlTOPp->blue_o = ((IData)(vlTOPp->display_enable_o)
                       ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                           ? (0xffU & (vlTOPp->top__DOT__top__DOT__dout 
                                       >> 0x10U)) : 0xe0U)
                       : 0U);
    vlTOPp->red_o = ((IData)(vlTOPp->display_enable_o)
                      ? ((IData)(vlTOPp->top__DOT__top__DOT__map_enable)
                          ? (0xffU & vlTOPp->top__DOT__top__DOT__dout)
                          : 0xe0U) : 0U);
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
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
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    display_enable_o = VL_RAND_RESET_I(1);
    hpos_o = VL_RAND_RESET_I(10);
    vpos_o = VL_RAND_RESET_I(10);
    blue_o = VL_RAND_RESET_I(8);
    green_o = VL_RAND_RESET_I(8);
    red_o = VL_RAND_RESET_I(8);
    top__DOT__top__DOT__map_enable = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__dout = VL_RAND_RESET_I(24);
    { int __Vi0=0; for (; __Vi0<8192; ++__Vi0) {
            top__DOT__top__DOT__tile__DOT__mem[__Vi0] = VL_RAND_RESET_I(24);
    }}
    top__DOT__top__DOT__map_block__DOT____Vxrand1 = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<13; ++__Vi0) {
            top__DOT__top__DOT__map_block__DOT__map_tiles[__Vi0] = VL_RAND_RESET_Q(39);
    }}
    top__DOT__top__DOT__hvsync_gen__DOT__h_maxxed = VL_RAND_RESET_I(1);
    top__DOT__top__DOT__hvsync_gen__DOT__v_maxxed = VL_RAND_RESET_I(1);
}
