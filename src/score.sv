/* verilator lint_off UNUSED */
module score #(
    parameter COLOR_BITS = 24
) (
    input logic clk_i,
    input logic [5:0] score_player_1_i,
    input logic [5:0] score_player_2_i,
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,

    output logic [(COLOR_BITS/3)-1 :0] number_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] number_green_o,
    output logic [(COLOR_BITS/3)-1 :0] number_red_o,
    output logic number_enable_o,

    output logic [(COLOR_BITS/3)-1 :0] tank_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_green_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_red_o,
    output logic tank_enable_o

);
    parameter SCORE_Y = 32*5;
    parameter SCORE_X_1 = 32*15;
    parameter SCORE_X_2 = SCORE_X_1 + 16;
    parameter SCORE_X_3 = 32*18;
    parameter SCORE_X_4 = SCORE_X_3 + 16;
    parameter TANK_Y = 32*4;
    parameter TANK_X_1 = 32*15;
    parameter TANK_X_2 = 32*18;

    logic [COLOR_BITS-1 :0] dout_1, dout_2;
    logic [5:0] player_1_1, player_1_10, player_2_1, player_2_10;
    logic enable_player_1_1, enable_player_1_10, enable_player_2_1, enable_player_2_10, enable_tank_1, enable_tank_2;
    logic data_player_1_1, data_player_1_10, data_player_2_1, data_player_2_10;

    assign number_enable_o = enable_player_1_1 || enable_player_1_10 || enable_player_2_1 || enable_player_2_10;
    assign tank_enable_o = enable_tank_1 || enable_tank_2;
    assign player_1_1  = score_player_1_i %10;
    assign player_1_10 = score_player_1_i /10;
    assign player_2_1  = score_player_2_i %10;
    assign player_2_10 = score_player_2_i /10;

    always_comb begin
        enable_player_1_1  = 0; 
        enable_player_1_10 = 0; 
        enable_player_2_1  = 0;
        enable_player_2_10 = 0;
        if((vpos_i >= SCORE_Y) && (vpos_i < SCORE_Y + 16)) begin
            if((hpos_i >= SCORE_X_1) && (hpos_i < SCORE_X_1 + 16)) enable_player_1_10 = 1;
            if((hpos_i >= SCORE_X_2) && (hpos_i < SCORE_X_2 + 16)) enable_player_1_1  = 1;
            if((hpos_i >= SCORE_X_3) && (hpos_i < SCORE_X_3 + 16)) enable_player_2_10 = 1;
            if((hpos_i >= SCORE_X_4) && (hpos_i < SCORE_X_4 + 16)) enable_player_2_1  = 1;
        end
    end

    always_comb begin
        enable_tank_1  = 0; 
        enable_tank_2 = 0; 
        if((vpos_i >= TANK_Y) && (vpos_i < TANK_Y + 32)) begin
            if((hpos_i >= TANK_X_1) && (hpos_i < TANK_X_1 + 32)) enable_tank_1 = 1;
            if((hpos_i >= TANK_X_2) && (hpos_i < TANK_X_2 + 32)) enable_tank_2 = 1;
        end
    end

    number number_player_1_1(
        .enable_i(enable_player_1_1),
        .number_i(player_1_1[3:0]),
        .x_ofs_i(hpos_i[3:0]),
        .y_ofs_i(vpos_i[3:0]),
        .number_bit_o(data_player_1_1)
    );
    number number_player_1_10(
        .enable_i(enable_player_1_10),
        .number_i(player_1_10[3:0] == 0 ? 10 : player_1_10[3:0]),
        .x_ofs_i(hpos_i[3:0]),
        .y_ofs_i(vpos_i[3:0]),
        .number_bit_o(data_player_1_10)
    );
    number number_player_2_1(
        .enable_i(enable_player_2_1),
        .number_i(player_2_1[3:0]),
        .x_ofs_i(hpos_i[3:0]),
        .y_ofs_i(vpos_i[3:0]),
        .number_bit_o(data_player_2_1)
    );
    number number_player_2_10(
        .enable_i(enable_player_2_10),
        .number_i(player_2_10[3:0] == 0 ? 10 : player_2_10[3:0]),
        .x_ofs_i(hpos_i[3:0]),
        .y_ofs_i(vpos_i[3:0]),
        .number_bit_o(data_player_2_10)
    );

    mem_player_1  #(
        .COLOR_BITS(COLOR_BITS)
    ) tank_player_1 (
        .addr({vpos_i[4:0], hpos_i[4:0]}),
        .dout(dout_1)
    );

    mem_player_2  #(
        .COLOR_BITS(COLOR_BITS)
    ) tank_player_2 (
        .addr({vpos_i[4:0], hpos_i[4:0]}),
        .dout(dout_2)
    );

    always_ff @(posedge clk_i) begin
        if(enable_tank_1) begin
            {tank_blue_o, tank_green_o, tank_red_o} <= dout_1 == 0 ? 24'hE0E0E0 : dout_1;
        end
        if(enable_tank_2) begin
            {tank_blue_o, tank_green_o, tank_red_o} <= dout_2 == 0 ? 24'hE0E0E0 : dout_2;
        end
    end

    always_comb begin
        if(number_enable_o) begin
            if(data_player_1_1 || data_player_1_10 || data_player_2_1 || data_player_2_10) begin
                {number_blue_o, number_green_o, number_red_o} = 0;
            end else begin
                {number_blue_o, number_green_o, number_red_o} = 24'hE0E0E0;
            end
        end else {number_blue_o, number_green_o, number_red_o} = 0;
    end
endmodule
/* verilator lint_off UNUSED */
