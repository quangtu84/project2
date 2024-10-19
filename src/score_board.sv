/* verilator lint_off UNUSED */
module score_board #(
    parameter COLOR_BITS = 24
) (
    input logic [5:0] tank_left_i,
    input logic [3:0] level_i,
    input logic [3:0] player_1_live_left_i,
    input logic [3:0] player_2_live_left_i,
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,

    output logic [(COLOR_BITS/3)-1 :0] tank_left_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_left_green_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_left_red_o,
    output logic tank_left_enable_o,

    output logic [(COLOR_BITS/3)-1 :0] player_tank_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] player_tank_green_o,
    output logic [(COLOR_BITS/3)-1 :0] player_tank_red_o,
    output logic player_tank_enable_o,

    output logic [(COLOR_BITS/3)-1 :0] level_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] level_green_o,
    output logic [(COLOR_BITS/3)-1 :0] level_red_o,
    output logic level_enable_o
);

    logic tank_left_enable, tank_left_enable_16, tank_left_enable_32, player_1_enable, player_2_enable;
    logic [9:0] tank_left_enable_16_compare, tank_left_enable_32_compare, player_1_compare, player_2_compare;
    logic [COLOR_BITS-1 : 0] tank_left_dout;

    assign tank_left_enable_o = tank_left_enable;
    assign tank_left_enable = tank_left_enable_16 || tank_left_enable_32 || player_1_enable || player_2_enable;

    always_comb begin
        if (tank_left_i > 16) begin
            tank_left_enable_32_compare = ({4'b0, tank_left_i} - 10'd16) * 10'd16 + 10'd32;
            tank_left_enable_16_compare = 288;
        end else begin
            tank_left_enable_32_compare = 32;
            tank_left_enable_16_compare = {4'b0, tank_left_i} * 10'd16 + 10'd32;
        end
    end

    always_comb begin
        if (hpos_i > 480 && hpos_i < 496) begin
            tank_left_enable_16 = 0;
            if (vpos_i > 32 && vpos_i < tank_left_enable_16_compare) begin
                tank_left_enable_16 = 1;
            end
        end else begin
            tank_left_enable_16 = 0;
        end
    end

    always_comb begin
        if (hpos_i > 496 && hpos_i < 512) begin
            tank_left_enable_32 = 0;
            if (vpos_i > 32 && vpos_i < tank_left_enable_32_compare) begin
                tank_left_enable_32 = 1;
            end
        end else begin
            tank_left_enable_32 = 0;
        end
    end

    always_comb begin
        player_1_compare = 10'd464 + {6'b0,player_1_live_left_i} * 10'd16;
        player_2_compare = 10'd576 + {6'b0,player_2_live_left_i} * 10'd16;
    end
    
    always_comb begin
        if (vpos_i > 384 && vpos_i < 400) begin
            player_1_enable = 0;
            if (hpos_i > 464 && hpos_i < player_1_compare) begin
                player_1_enable = 1;
            end
        end else begin
            player_1_enable = 0;
        end
    end

    always_comb begin
        if (vpos_i > 384 && vpos_i < 400) begin
            player_2_enable = 0;
            if (hpos_i > 576 && hpos_i < player_2_compare) begin
                player_2_enable = 1;
            end
        end else begin
            player_2_enable = 0;
        end
    end

    mem_lives #(
        .ADDRESS(8),
        .COLOR_BITS(COLOR_BITS)
    ) mem_lives (
        .addr({vpos_i[3:0],hpos_i[3:0]}),
        .dout(tank_left_dout)
    );

    always_comb begin
        if (tank_left_enable) {tank_left_blue_o, tank_left_green_o, tank_left_red_o} = tank_left_dout;
        else {tank_left_blue_o, tank_left_green_o, tank_left_red_o} = 0;
    end

    logic player_1_tank_enable;
    logic [COLOR_BITS-1 :0] player_1_bits;
    logic [9:0] player_1_addr;

    assign player_1_addr = {hpos_i[4:0], vpos_i[4:0]};

    always_comb begin
        if (vpos_i > 352 && vpos_i < 384) begin
            player_1_tank_enable = 0;
            if (hpos_i > 480 && hpos_i < 512) begin
                player_1_tank_enable = 1;
            end
        end else begin
            player_1_tank_enable = 0;
        end
    end

    mem_player_1  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_player_1 (
        .addr(player_1_addr),
        .dout(player_1_bits)
    );

    logic player_2_tank_enable;
    logic [COLOR_BITS-1 :0] player_2_bits;
    logic [9:0] player_2_addr;

    assign player_2_addr = {hpos_i[4:0], vpos_i[4:0]};

    always_comb begin
        if (vpos_i > 352 && vpos_i < 384) begin
            player_2_tank_enable = 0;
            if (hpos_i > 576 && hpos_i < 608) begin
                player_2_tank_enable = 1;
            end
        end else begin
            player_2_tank_enable = 0;
        end
    end

    assign player_tank_enable_o = ((|player_1_bits) && player_1_tank_enable) || ((|player_2_bits) && player_2_tank_enable);

    mem_player_2  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_player_2 (
        .addr(player_2_addr),
        .dout(player_2_bits)
    );

    always_comb begin
        if (player_1_tank_enable) {player_tank_blue_o, player_tank_green_o, player_tank_red_o} = &player_1_bits ? 0 : player_1_bits;
        else if (player_2_tank_enable) {player_tank_blue_o, player_tank_green_o, player_tank_red_o} = &player_2_bits ? 0 : player_2_bits;
        else {player_tank_blue_o, player_tank_green_o, player_tank_red_o} = 0;
    end

    logic [7:0] bit_number;
    logic [5:0] game_start [6:0];
    always_comb begin
        game_start[0]    = 6'd22; // L
        game_start[1]    = 6'd15; // E
        game_start[2]    = 6'd32; // V
        game_start[3]    = 6'd15; // E
        game_start[4]    = 6'd22; // L
        game_start[5]    = 6'd37; // 
        game_start[6]    = 6'd1 + {2'b0, level_i}; // O

    end

    logic [9:0] rom_addr;
    logic [2:0] x_ofs;

    ascii_rom ascii_rom (
        .addr_i(rom_addr),
        .data_o(bit_number)
    );

    logic level_enable;

    assign level_enable = (vpos_i[9:5] == 10) && (hpos_i[9:4] > 28) && (hpos_i[9:4] < 36);
    assign level_enable_o = level_enable;
    always_comb begin
        rom_addr = 0;
        x_ofs = 0;
        if (level_enable) begin
            rom_addr = {game_start[hpos_i[7:4]-29],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
    end

    always_comb begin
        if(bit_number[x_ofs])begin
            {level_blue_o, level_green_o, level_red_o} = 0;
        end else begin
            {level_blue_o, level_green_o, level_red_o} = 24'hE0E0E0;
        end
    end

endmodule
/* verilator lint_off UNUSED */
