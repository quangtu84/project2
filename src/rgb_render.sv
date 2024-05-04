module rgb_render #(
    parameter COLOR_BITS = 24
) (
    input logic map_enable_i,
    input logic display_enable_i,

    input logic [(COLOR_BITS/3)-1 :0] map_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] map_green_i,
    input logic [(COLOR_BITS/3)-1 :0] map_red_i,

    input logic [(COLOR_BITS/3)-1 :0] player_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] player_green_i,
    input logic [(COLOR_BITS/3)-1 :0] player_red_i,

    input logic [(COLOR_BITS/3)-1 :0] bullet_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] bullet_green_i,
    input logic [(COLOR_BITS/3)-1 :0] bullet_red_i,

    input logic [(COLOR_BITS/3)-1 :0] number_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] number_green_i,
    input logic [(COLOR_BITS/3)-1 :0] number_red_i,
    input logic number_enable_i, 

    input logic [(COLOR_BITS/3)-1 :0] tank_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] tank_green_i,
    input logic [(COLOR_BITS/3)-1 :0] tank_red_i,
    input logic tank_enable_i,

    input logic is_menu_i,
    input logic is_playing_i,
    input logic is_continue_i,
    input logic is_final_i,

    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o
);

    always_comb begin
        {blue_o, green_o, red_o} = 0;
        if (display_enable_i) begin
            if(is_menu_i) begin 
                {blue_o, green_o, red_o} = 24'hE0E0E0;

            end else if (is_playing_i) begin
                if(map_enable_i) begin
                    blue_o  = map_blue_i  | player_blue_i     | bullet_blue_i;
                    green_o = map_green_i | player_green_i    | bullet_green_i;
                    red_o   = map_red_i   | player_red_i      | bullet_red_i;
                end else begin
                    if (number_enable_i) begin
                        {blue_o, green_o, red_o} = {number_blue_i, number_green_i, number_red_i};
                    end else if (tank_enable_i) begin
                        {blue_o, green_o, red_o} = {tank_blue_i, tank_green_i, tank_red_i};
                    end else begin
                        {blue_o, green_o, red_o} = 24'hE0E0E0; //outside of map
                    end
                end
                
            end else if (is_continue_i) begin
                {blue_o, green_o, red_o} = 24'hE0E0E0;
            end else if (is_final_i) begin
                {blue_o, green_o, red_o} = 24'hE0E0E0;
            end

        end else begin
            {blue_o, green_o, red_o} = 24'b0;
        end
    end

endmodule
