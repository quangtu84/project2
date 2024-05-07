/* verilator lint_off UNUSED */
module menu #(
    parameter COLOR_BITS = 24
) (
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,

    output logic [(COLOR_BITS/3)-1 :0] menu_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_green_o,
    output logic [(COLOR_BITS/3)-1 :0] menu_red_o
);

    logic [7:0] bit_number;

    ascii_rom ascii_rom (
        .addr_i({hpos_i[9:4],vpos_i[3:0]}),
        .data_o(bit_number)
    );

    always_comb begin
        if(bit_number[~hpos_i[3:1]])begin
            {menu_blue_o, menu_green_o, menu_red_o} = 0;
        end else begin
            {menu_blue_o, menu_green_o, menu_red_o} = 24'hE0E0E0;
        end
    end


endmodule
/* verilator lint_off UNUSED */
