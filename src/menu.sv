/* verilator lint_off UNUSED */
module menu #(
    parameter COLOR_BITS = 24
) (
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,

    input logic is_menu_i,
    input logic is_playing_i,
    input logic is_level_done_i,
    input logic is_game_over_i,
    input logic is_game_win_i,

    output logic [(COLOR_BITS/3)-1 :0] menu_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_green_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_red_o,
    output logic menu_enable_o,

    input logic clk_i,
    input logic reset_i
);

    logic [7:0] bit_number;
    logic [5:0] title_buffer [10:0];
    logic [5:0] level_done [9:0];
    logic [5:0] game_over [8:0];
    logic [5:0] game_win [6:0];
    logic [5:0] shoot_to_start [13:0];
    logic [5:0] shoot_to_continue [12:0];
    logic [5:0] shoot_to_restart [15:0];

    initial begin
        title_buffer[0]  = 6'd12; // B
        title_buffer[1]  = 6'd11; // A
        title_buffer[2]  = 6'd30; // T
        title_buffer[3]  = 6'd30; // T
        title_buffer[4]  = 6'd22; // L
        title_buffer[5]  = 6'd15; // E
        title_buffer[6]  = 6'd37; //  
        title_buffer[7]  = 6'd13; // C
        title_buffer[8]  = 6'd19; // I
        title_buffer[9]  = 6'd30; // T
        title_buffer[10] = 6'd35; // Y
        shoot_to_start[0]    = 6'd29; // S
        shoot_to_start[1]    = 6'd18; // H
        shoot_to_start[2]    = 6'd25; // O
        shoot_to_start[3]    = 6'd25; // O
        shoot_to_start[4]    = 6'd30; // T
        shoot_to_start[5]    = 6'd37; // 
        shoot_to_start[6]    = 6'd30; // T
        shoot_to_start[7]    = 6'd25; // O
        shoot_to_start[8]    = 6'd37; // 
        shoot_to_start[9]     = 6'd29; // S
        shoot_to_start[10]    = 6'd30; // T
        shoot_to_start[11]    = 6'd11; // A
        shoot_to_start[12]    = 6'd28; // R
        shoot_to_start[13]    = 6'd30; // T

        level_done[0]  = 6'd22; // L
        level_done[1]  = 6'd15; // E
        level_done[2]  = 6'd32; // V
        level_done[3]  = 6'd15; // E
        level_done[4]  = 6'd22; // L
        level_done[5]  = 6'd37; // 
        level_done[6]  = 6'd14; // D
        level_done[7]  = 6'd25; // O
        level_done[8]  = 6'd24; // N
        level_done[9]  = 6'd15; // E

        shoot_to_continue[0]    = 6'd29; // S
        shoot_to_continue[1]    = 6'd18; // H
        shoot_to_continue[2]    = 6'd25; // O
        shoot_to_continue[3]    = 6'd25; // O
        shoot_to_continue[4]    = 6'd30; // T
        shoot_to_continue[5]    = 6'd37; // 
        shoot_to_continue[6]    = 6'd30; // T
        shoot_to_continue[7]    = 6'd25; // O
        shoot_to_continue[8]    = 6'd37; // 
        shoot_to_continue[9]     = 6'd13; // C
        shoot_to_continue[10]    = 6'd25; // O
        shoot_to_continue[11]    = 6'd24; // N
        shoot_to_continue[12]    = 6'd30; // T
        // shoot_to_continue[13]    = 6'd19; // I
        // shoot_to_continue[14]    = 6'd24; // N
        // shoot_to_continue[15]    = 6'd31; // U
        // shoot_to_continue[16]    = 6'd15; // E

        game_over[0]  = 6'd17; // G
        game_over[1]  = 6'd11; // A
        game_over[2]  = 6'd23; // M
        game_over[3]  = 6'd15; // E
        game_over[4]  = 6'd37; // 
        game_over[5]  = 6'd25; // O
        game_over[6]  = 6'd32; // V
        game_over[7]  = 6'd15; // E
        game_over[8]  = 6'd28; // R

        game_win[0]  = 6'd32; // V
        game_win[1]  = 6'd19; // I
        game_win[2]  = 6'd13; // C
        game_win[3]  = 6'd30; // T
        game_win[4]  = 6'd25; // O
        game_win[5]  = 6'd28; // R
        game_win[6]  = 6'd35; // Y

        shoot_to_restart[0]    = 6'd29; // S
        shoot_to_restart[1]    = 6'd18; // H
        shoot_to_restart[2]    = 6'd25; // O
        shoot_to_restart[3]    = 6'd25; // O
        shoot_to_restart[4]    = 6'd30; // T
        shoot_to_restart[5]    = 6'd37; // 
        shoot_to_restart[6]    = 6'd30; // T
        shoot_to_restart[7]    = 6'd25; // O
        shoot_to_restart[8]    = 6'd37; // 
        shoot_to_restart[9]     = 6'd28; // R
        shoot_to_restart[10]    = 6'd15; // E
        shoot_to_restart[11]    = 6'd29; // S
        shoot_to_restart[12]    = 6'd30; // T
        shoot_to_restart[13]    = 6'd11; // A
        shoot_to_restart[14]    = 6'd28; // R
        shoot_to_restart[15]    = 6'd30; // T
    end

    logic [9:0] rom_addr;
    logic [2:0] x_ofs;

    ascii_rom ascii_rom (
        .addr_i(rom_addr),
        .data_o(bit_number)
    );

    logic title_enable, level_done_enable, game_over_enable, shoot_to_start_enable, shoot_to_continue_enable, shoot_to_restart_enable, game_win_enable;

    assign title_enable = (vpos_i[9:7] == 1) && (hpos_i[9:5] > 4) && (hpos_i[9:5] < 16) && is_menu_i;
    assign shoot_to_start_enable = (vpos_i[9:5] == 9) && (hpos_i[9:4] > 13) && (hpos_i[9:4] < 28) && is_menu_i;

    assign level_done_enable = (vpos_i[9:7] == 1) && (hpos_i[9:5] > 4) && (hpos_i[9:5] < 15) && is_level_done_i;
    assign shoot_to_continue_enable = (vpos_i[9:5] == 9) && (hpos_i[9:4] > 13) && (hpos_i[9:4] < 27) && is_level_done_i;

    assign game_over_enable = (vpos_i[9:7] == 1) && (hpos_i[9:5] > 5) && (hpos_i[9:5] < 15) && is_game_over_i;
    assign game_win_enable = (vpos_i[9:7] == 1) && (hpos_i[9:5] > 6) && (hpos_i[9:5] < 14) && is_game_win_i;
    assign shoot_to_restart_enable = (vpos_i[9:5] == 9) && (hpos_i[9:4] > 12) && (hpos_i[9:4] < 29) && (is_game_over_i || is_game_win_i);


    always_comb begin
        rom_addr = 32;
        x_ofs = 0;
        if (title_enable) begin 
            rom_addr = {title_buffer[hpos_i[8:5]-5],vpos_i[6:3]};
            x_ofs = ~hpos_i[4:2];
        end
        if (shoot_to_start_enable) begin
            rom_addr = {shoot_to_start[hpos_i[7:4]-14],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end

        if (level_done_enable) begin 
            rom_addr = {level_done[hpos_i[8:5]-5],vpos_i[6:3]};
            x_ofs = ~hpos_i[4:2];
        end
        if (shoot_to_continue_enable) begin
            rom_addr = {shoot_to_continue[hpos_i[7:4] - 14],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end

        if (game_over_enable) begin 
            rom_addr = {game_over[hpos_i[8:5]-6],vpos_i[6:3]};
            x_ofs = ~hpos_i[4:2];
        end
        if (game_win_enable) begin 
            rom_addr = {game_win[hpos_i[8:5]-7],vpos_i[6:3]};
            x_ofs = ~hpos_i[4:2];
        end
        if (shoot_to_restart_enable) begin
            rom_addr = {shoot_to_restart[hpos_i[7:4]-13],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
    end

    logic menu_enable;
    assign menu_enable = bit_number[x_ofs];
    assign menu_enable_o = menu_enable;

    always_comb begin
        if(menu_enable)begin
            {menu_blue_o, menu_green_o, menu_red_o} = 0;
        end else begin
            {menu_blue_o, menu_green_o, menu_red_o} = 24'hE0E0E0;
        end
    end


endmodule
/* verilator lint_off UNUSED */
