module top #(
    parameter COLOR_BITS = 24
) (
    input logic [3:0] player_1_move_i,
    input logic [3:0] player_2_move_i,

    output logic display_enable_o,
    output logic [9:0] hpos_o,
    output logic [9:0] vpos_o,
    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o,
    output logic [9:0] player_1_x_o,
    output logic [9:0] player_1_y_o,
    output logic [9:0] player_2_x_o,
    output logic [9:0] player_2_y_o,
    output logic player_1_collide_with_wall_top_o, 
    output logic player_1_collide_with_wall_bottom_o, 
    output logic player_1_collide_with_wall_left_o, 
    output logic player_1_collide_with_wall_right_o,
    input logic clk_i,
    input logic reset_i
);

    game_top #(
        .COLOR_BITS(COLOR_BITS)
    ) top(
        .*
    );

endmodule
