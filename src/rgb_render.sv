module rgb_render #(
    parameter COLOR_BITS = 24
) (
    input logic map_enable_i,
    input logic display_enable_i,
    input logic [(COLOR_BITS/3)-1 :0] map_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] map_green_i,
    input logic [(COLOR_BITS/3)-1 :0] map_red_i,
    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o
);

    always_comb begin
        if (display_enable_i) begin
            if(map_enable_i) begin
                {blue_o, green_o, red_o} = {map_blue_i, map_green_i, map_red_i};
            end
            else {blue_o, green_o, red_o} = 24'hE0E0E0; //outside of map
        end else begin
            {blue_o, green_o, red_o} = 24'b0;
        end     
    end

endmodule
