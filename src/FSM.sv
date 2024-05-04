/* verilator lint_off UNUSED */

module FSM (
    input logic space_i,
    input logic sellect_up_i,
    input logic sellect_down_i,
    input logic bullet_collide_player_1_i,
    input logic bullet_collide_player_2_i,

    output logic [5:0] score_player_1_o,
    output logic [5:0] score_player_2_o,

    output logic is_menu_o,
    output logic is_playing_o,
    output logic is_continue_o,
    output logic is_final_o,
    output logic reset_o,

    input logic reset_i,
    input logic clk_i
);

logic [1:0] game_state;
localparam MENU        = 0;
localparam START       = 1;
localparam CONTINUE    = 2;
localparam FINAL_SCORE = 3;

logic [5:0] score_player_1, score_player_2;
logic bullet_collide_player_1, bullet_collide_player_2;

assign score_player_1_o = score_player_1;
assign score_player_2_o = score_player_2;

pos_edge_detect pos_edge_detect_bullet_1 (
    .sig(bullet_collide_player_1_i),           
    .clk(clk_i),            
    .pe(bullet_collide_player_1)
);

pos_edge_detect pos_edge_detect_bullet_2 (
    .sig(bullet_collide_player_2_i),           
    .clk(clk_i),            
    .pe(bullet_collide_player_2)
);

always_ff @(posedge clk_i) begin
    if(reset_i) begin
        game_state <= MENU;
        score_player_1 <= 0;
        score_player_2 <= 0;
    end else begin
        is_menu_o <= 0;
        is_playing_o <= 0;
        is_continue_o <= 0;
        is_final_o <= 0;
        reset_o <= 1;
        case (game_state)
            MENU: begin
                is_menu_o <= 1;
                reset_o <= 1;
                if(space_i) game_state <= START;
            end
            START: begin
                reset_o <= 0;
                is_playing_o <= 1;
                if(bullet_collide_player_1) begin
                    score_player_2 <= score_player_2 + 1;
                    game_state <= CONTINUE;
                end
                if(bullet_collide_player_2) begin
                    score_player_1 <= score_player_1 + 1;
                    game_state <= CONTINUE;
                end
            end
            CONTINUE: begin
                is_continue_o <= 1;
                reset_o <= 1;
                if(space_i) game_state <= START;
            end
            FINAL_SCORE: begin
                is_final_o <= 1;
            end
            default: game_state <= MENU;
        endcase
    end
end

endmodule
/* verilator lint_off UNUSED */
