/* verilator lint_off UNUSED */
module menu #(
    parameter COLOR_BITS = 24
) (
    
    input logic sellect_up_i,
    input logic sellect_down_i,
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,

    output logic [(COLOR_BITS/3)-1 :0] menu_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_green_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_red_o,

    output logic [1:0] map_type_o,

    input logic clk_i,
    input logic reset_i
);

    logic [7:0] bit_number;
    logic [5:0] title_buffer [10:0];
    logic [5:0] map1_buffer [4:0];
    logic [5:0] map2_buffer [4:0];
    logic [5:0] map3_buffer [4:0];
    logic [5:0] map4_buffer [4:0];
    logic [5:0] arrow;
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
        map1_buffer[0]    = 6'd23; // M
        map1_buffer[1]    = 6'd11; // A
        map1_buffer[2]    = 6'd26; // P
        map1_buffer[3]    = 6'd37; //
        map1_buffer[4]    = 6'd2;  // 1
        map2_buffer[0]    = 6'd23; // M
        map2_buffer[1]    = 6'd11; // A
        map2_buffer[2]    = 6'd26; // P
        map2_buffer[3]    = 6'd37; //
        map2_buffer[4]    = 6'd3;  // 2
        map3_buffer[0]    = 6'd23; // M
        map3_buffer[1]    = 6'd11; // A
        map3_buffer[2]    = 6'd26; // P
        map3_buffer[3]    = 6'd37; //
        map3_buffer[4]    = 6'd4;  // 3
        map4_buffer[0]    = 6'd23; // M
        map4_buffer[1]    = 6'd11; // A
        map4_buffer[2]    = 6'd26; // P
        map4_buffer[3]    = 6'd37; //
        map4_buffer[4]    = 6'd5;  // 4
        arrow             = 6'd0;  // ->
        arrow_pos         = 5'd9;
    end

    logic [9:0] rom_addr;
    logic [2:0] x_ofs;

    ascii_rom ascii_rom (
        .addr_i(rom_addr),
        .data_o(bit_number)
    );
    pos_edge_detect sellect_up_edge_dect(
        .sig(sellect_up_i),           
        .clk(clk_i),            
        .pe(sellect_up)
    );
    pos_edge_detect sellect_down_edge_dect(
        .sig(sellect_down_i),           
        .clk(clk_i),            
        .pe(sellect_down)
    );

    logic title_enable, map1, map2, map3, map4, arrow_en, sellect_up, sellect_down;
    logic [4:0] arrow_pos;

    assign title_enable = (vpos_i[9:7] == 1) && (hpos_i[9:5] > 4) && (hpos_i[9:5] < 16);
    assign map1 = (vpos_i[9:5] == 9) && (hpos_i[9:4] > 16) && (hpos_i[9:4] < 22);
    assign map2 = (vpos_i[9:5] == 10) && (hpos_i[9:4] > 16) && (hpos_i[9:4] < 22);
    assign map3 = (vpos_i[9:5] == 11) && (hpos_i[9:4] > 16) && (hpos_i[9:4] < 22);
    assign map4 = (vpos_i[9:5] == 12) && (hpos_i[9:4] > 16) && (hpos_i[9:4] < 22);

    assign arrow_en = (vpos_i[9:5] == arrow_pos) && (hpos_i[9:4] > 14) && (hpos_i[9:4] < 16);
    
    always_ff @(posedge clk_i or posedge reset_i) begin
        if(reset_i) begin
            arrow_pos <= 9;
        end else begin
            if (sellect_down && (arrow_pos < 12)) arrow_pos <= arrow_pos + 1;
            else  if (sellect_down) arrow_pos <= 9;
            if (sellect_up && (arrow_pos > 9)) arrow_pos <= arrow_pos - 1;
            else if (sellect_up) arrow_pos <= 12;
        end
    end

    always_comb begin
        case (arrow_pos)
            9:          map_type_o = 0;
            10:         map_type_o = 1;
            11:         map_type_o = 2;
            12:         map_type_o = 3;
            default:    map_type_o = 0;
        endcase
    end

    always_comb begin
        rom_addr = 0;
        if (title_enable) begin 
            rom_addr = {title_buffer[hpos_i[8:5]-5],vpos_i[6:3]};
            x_ofs = ~hpos_i[4:2];
        end
        if (map1) begin
            rom_addr = {map1_buffer[hpos_i[7:4]-17],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
        if (map2) begin
            rom_addr = {map2_buffer[hpos_i[7:4]-17],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
        if (map3) begin
            rom_addr = {map3_buffer[hpos_i[7:4]-17],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
        if (map4) begin
            rom_addr = {map4_buffer[hpos_i[7:4]-17],vpos_i[4:1]};
            x_ofs = ~hpos_i[3:1];
        end
        if (arrow_en) begin
            rom_addr = {arrow,vpos_i[4:1]};
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
