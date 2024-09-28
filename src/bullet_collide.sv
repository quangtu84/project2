/* verilator lint_off UNUSED */

module bullet_collide (
    input logic player_1_box_i,
    input logic player_1_bullet_i,
    output logic player_1_bullet_explose_o,
    output logic player_1_die_o,

    input logic player_2_box_i,
    input logic player_2_bullet_i,
    output logic player_2_bullet_explose_o,
    output logic player_2_die_o,

    input logic all_hard_block_i,
    input logic destroyable_block_i,
    output logic bullet_collide_wall_o,

    input logic clk_i
);
    logic all_player ;
    assign all_player = player_1_box_i || player_2_box_i;
    assign player_1_bullet_explose_o = (all_hard_block_i || all_player) && player_1_bullet_i;
    assign player_2_bullet_explose_o = (all_hard_block_i || all_player) && player_2_bullet_i;

    assign bullet_collide_wall_o = destroyable_block_i && (player_1_bullet_i || player_2_bullet_i);

    always_ff @( posedge clk_i) begin
        if (player_1_box_i  && player_2_bullet_i) begin
            player_1_die_o <= 1;
        end
        if (player_2_box_i  && player_1_bullet_i) begin
            player_2_die_o <= 1;
        end
    end

endmodule
/* verilator lint_off UNUSED */
