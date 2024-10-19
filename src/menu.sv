/* verilator lint_off UNUSED */
module menu #(
    parameter COLOR_BITS = 24
) (
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,

    output logic [(COLOR_BITS/3)-1 :0] menu_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_green_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_red_o,

    input logic clk_i,
    input logic reset_i
);

    logic [7:0] bit_number;
    logic [5:0] title_buffer [10:0];
    logic [5:0] game_start [13:0];
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
        game_start[0]    = 6'd29; // S
        game_start[1]    = 6'd26; // P
        game_start[2]    = 6'd11; // A
        game_start[3]    = 6'd13; // C
        game_start[4]    = 6'd15; // E
        game_start[5]    = 6'd37; // 
        game_start[6]    = 6'd30; // T
        game_start[7]    = 6'd25; // O
        game_start[8]    = 6'd37; // 
        game_start[9]    = 6'd29; // S
        game_start[10]    = 6'd30; // T
        game_start[11]    = 6'd11; // A
        game_start[12]    = 6'd28; // R
        game_start[13]    = 6'd30; // T
    end

    logic [9:0] rom_addr;
    logic [2:0] x_ofs;

    ascii_rom ascii_rom (
        .addr_i(rom_addr),
        .data_o(bit_number)
    );

    logic title_enable, game_start_enable;

    assign title_enable = (vpos_i[9:7] == 1) && (hpos_i[9:5] > 4) && (hpos_i[9:5] < 16);
    assign game_start_enable = (vpos_i[9:5] == 9) && (hpos_i[9:4] > 13) && (hpos_i[9:4] < 28);

    always_comb begin
        rom_addr = 0;
        x_ofs = 0;
        if (title_enable) begin 
            rom_addr = {title_buffer[hpos_i[8:5]-5],vpos_i[6:3]};
            x_ofs = ~hpos_i[4:2];
        end
        if (game_start_enable) begin
            rom_addr = {game_start[hpos_i[7:4]-14],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
    end

    always_comb begin
        if(bit_number[x_ofs])begin
            {menu_blue_o, menu_green_o, menu_red_o} = 0;
        end else begin
            {menu_blue_o, menu_green_o, menu_red_o} = 24'hE0E0E0;
        end
    end


endmodule
/* verilator lint_off UNUSED */
