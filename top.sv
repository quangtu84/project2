module top #(
    parameter COLOR_BITS = 24
) (
    input logic clk_i,
    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic [(COLOR_BITS/3)-1 :0] blue_o, green_o, red_o
);

    game_top #(
        .COLOR_BITS(COLOR_BITS)
    ) top(
        .*
    );

endmodule
