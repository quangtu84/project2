/* verilator lint_off UNUSED */

module bullet_collide (
    input logic [3:0] player_1_lives_i,
    input logic player_1_box_i,
    input logic player_1_bullet_i,
    output logic player_1_bullet_explose_o,
    output logic player_1_die_o,
    output logic player_1_revive_o,

    input logic [3:0] player_2_lives_i,
    input logic player_2_box_i,
    input logic player_2_bullet_i,
    output logic player_2_bullet_explose_o,
    output logic player_2_die_o,
    output logic player_2_revive_o,

    input logic [3:0] enemy_1_lives_i,
    input logic enemy_1_box_i,
    input logic enemy_1_bullet_i,
    output logic enemy_1_bullet_explose_o,
    output logic enemy_1_die_o,
    output logic enemy_1_revive_o,

    input logic eagle_block_i,
    input logic all_hard_block_i,
    input logic destroyable_block_i,
    output logic bullet_collide_wall_o,
    output logic bullet_collide_eagle_o,

    input logic clk_i,
    input logic reset_i
);
    logic all_player, all_enemy, all_player_bullet, all_enemy_bullet, all_bullet;

    assign all_player = player_1_box_i || player_2_box_i;
    assign all_player_bullet = player_1_bullet_i || player_2_bullet_i;
    
    assign all_enemy = enemy_1_box_i;
    assign all_enemy_bullet = enemy_1_bullet_i;

    assign all_bullet = all_player_bullet || all_enemy_bullet;
    assign player_1_bullet_explose_o = (all_hard_block_i || all_player || all_enemy || all_enemy_bullet) && player_1_bullet_i;
    assign player_2_bullet_explose_o = (all_hard_block_i || all_player || all_enemy || all_enemy_bullet) && player_2_bullet_i;
    assign enemy_1_bullet_explose_o = (all_hard_block_i || all_player || all_enemy || all_player_bullet) && enemy_1_bullet_i;

    assign bullet_collide_wall_o = destroyable_block_i && all_bullet;
    assign bullet_collide_eagle_o = eagle_block_i && all_bullet;

    localparam LIVING = 1'b0;
    localparam DEAD = 1'b1;

/////////////////////////////////
//          PLAYER 1           //
/////////////////////////////////
    logic player_1_live_stage;
    logic [3:0] player_1_live_left;
    logic [31:0] player_1_count_revive;

    always_ff @(posedge clk_i or posedge reset_i) begin
        if (reset_i) begin
            player_1_live_stage <= LIVING;
            player_1_live_left  <= player_1_lives_i  - 4'b1;
            player_1_count_revive <= 0;
            player_1_revive_o <= 0;
        end else begin
            case (player_1_live_stage)
                LIVING: begin
                    player_1_die_o <= 0;
                    player_1_revive_o <= 0;
                    if (player_1_box_i  && all_enemy_bullet) begin
                        player_1_count_revive <= 0;
                        player_1_live_stage <= DEAD;
                    end
                end
                DEAD: begin
                    player_1_die_o <= 1;
                    player_1_revive_o <= 1;
                    player_1_count_revive <= player_1_count_revive + 1;
                    if (player_1_live_left > 0) begin
                        if (player_1_count_revive == 32'd1000000) begin
                            player_1_live_left <= player_1_live_left -4'b1;
                            player_1_live_stage <= LIVING;
                        end
                    end
                end
                default: ;
            endcase
        end
    end

/////////////////////////////////
//          PLAYER 2           //
/////////////////////////////////
    logic player_2_live_stage;
    logic [3:0] player_2_live_left;
    logic [31:0] player_2_count_revive;

    always_ff @(posedge clk_i or posedge reset_i) begin
        if (reset_i) begin
            player_2_live_stage <= LIVING;
            player_2_live_left  <= player_2_lives_i  - 4'b1;
            player_2_count_revive <= 0;
            player_2_revive_o <= 0;
        end else begin
            case (player_2_live_stage)
                LIVING: begin
                    player_2_die_o <= 0;
                    player_2_revive_o <= 0;
                    if (player_2_box_i  && all_enemy_bullet) begin
                        player_2_count_revive <= 0;
                        player_2_live_stage <= DEAD;
                    end
                end
                DEAD: begin
                    player_2_die_o <= 1;
                    player_2_revive_o <= 1;
                    player_2_count_revive <= player_2_count_revive + 1;
                    if (player_2_live_left > 0) begin
                        if (player_2_count_revive == 32'd1000000) begin
                            player_2_live_left <= player_2_live_left -4'b1;
                            player_2_live_stage <= LIVING;
                        end
                    end
                end
                default: ;
            endcase
        end
    end

/////////////////////////////////
//          ENEMY 1            //
/////////////////////////////////
    logic enemy_1_live_stage;
    logic [3:0] enemy_1_live_left;
    logic [31:0] enemy_1_count_revive;

    always_ff @(posedge clk_i or posedge reset_i) begin
        if (reset_i) begin
            enemy_1_live_stage <= LIVING;
            enemy_1_live_left  <= enemy_1_lives_i - 4'b1;
            enemy_1_count_revive <= 0;
            enemy_1_revive_o <= 0;
        end else begin
            case (enemy_1_live_stage)
                LIVING: begin
                    enemy_1_die_o <= 0;
                    enemy_1_revive_o <= 0;
                    if (enemy_1_box_i  && all_player_bullet) begin
                        enemy_1_count_revive <= 0;
                        enemy_1_live_stage <= DEAD;
                    end
                end
                DEAD: begin
                    enemy_1_die_o <= 1;
                    enemy_1_revive_o <= 1;
                    enemy_1_count_revive <= enemy_1_count_revive + 1;
                    if (enemy_1_live_left != 0) begin
                        if (enemy_1_count_revive == 32'd5000000) begin
                            enemy_1_live_left <= enemy_1_live_left -4'b1;
                            enemy_1_live_stage <= LIVING;
                        end
                    end
                end
                default: ;
            endcase
        end
    end
endmodule
/* verilator lint_off UNUSED */
