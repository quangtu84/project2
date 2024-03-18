module top #(
    parameter COLOR_BITS = 24
) (
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

    game_top #(
        .COLOR_BITS(COLOR_BITS)
    ) top(
        .*
    );

endmodule
