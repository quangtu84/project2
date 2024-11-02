/* verilator lint_off UNUSED */

module FSM (
    input logic space_i,
    input logic bullet_collide_eagle_i,
    input logic [5:0] enemy_left_i,

    output logic is_menu_o,
    output logic is_playing_o,
    output logic is_level_done_o,
    output logic is_game_over_o,
    output logic is_game_win_o,
    output logic reset_game_o,
    output logic [3:0] level_o,

    input logic reset_i,
    input logic clk_i
);

logic [2:0] game_state;
localparam MENU        = 0;
localparam PLAYING     = 1;
localparam LEVEL_DONE  = 2;
localparam GAMEOVER    = 3;
localparam WAIT_1_CYCLE    = 4;
localparam WAIT_AFTER_LEVEL_DONE  = 5;
localparam WAIT_AFTER_GAME_OVER  = 6;
localparam GAME_WIN  = 7;

    logic [23:0] counter, counter2;

always_ff @(posedge clk_i or posedge reset_i) begin
    if(reset_i) begin
        game_state <= MENU;
        is_menu_o <= 0;
        is_playing_o <= 0;
        is_level_done_o <= 0;
        is_game_over_o <= 0;
        is_game_win_o <= 0;
        reset_game_o <= 1;
        level_o <= 1;
        counter <= 0;
        counter2 <=0;
    end else begin
        is_menu_o <= 0;
        is_playing_o <= 0;
        is_level_done_o <= 0;
        is_game_over_o <= 0;
        is_game_win_o <= 0;
        reset_game_o <= 1;
        case (game_state)
            MENU: begin
                level_o <= 1;
                is_menu_o <= 1;
                reset_game_o <= 1;
                if (space_i) game_state <= PLAYING;
            end
            PLAYING: begin
                reset_game_o <= 0;
                is_playing_o <= 1;
                if (bullet_collide_eagle_i) begin
                    game_state <= WAIT_AFTER_GAME_OVER;
                    counter2 <= 0;
                end
                if (enemy_left_i == 0) begin
                    game_state <= LEVEL_DONE;
                    counter <= 0;
                end
            end
            LEVEL_DONE: begin
                is_level_done_o <= 1;
                reset_game_o <= 1;
                counter <= counter + 1;
                if (counter == 12500000) begin
                    game_state <= WAIT_AFTER_LEVEL_DONE;
                    if (level_o == 10) begin
                        game_state <= GAME_WIN;
                    end
                end
            end
            WAIT_AFTER_LEVEL_DONE: begin
                is_level_done_o <= 1;
                if(space_i) begin 
                    game_state <= WAIT_1_CYCLE;
                    level_o <= level_o + 1;
                end
            end
            WAIT_1_CYCLE: begin
                game_state <= PLAYING;
            end
            WAIT_AFTER_GAME_OVER: begin
                is_game_over_o <= 1;
                counter2 <= counter2 + 1;
                if (counter2 == 12500000) begin
                    game_state <= GAMEOVER;
                end
            end
            GAMEOVER: begin
                is_game_over_o <= 1;
                reset_game_o <= 1;
                if(space_i) game_state <= MENU;
            end
            GAME_WIN: begin
                is_game_win_o <= 1;
                if(space_i) game_state <= MENU;
            end
            default: game_state <= MENU;
        endcase
    end
end

endmodule
/* verilator lint_off UNUSED */
