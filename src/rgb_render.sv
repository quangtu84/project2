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

    input logic [(COLOR_BITS/3)-1 :0] menu_blue_i,
    input logic [(COLOR_BITS/3)-1 :0] menu_green_i,
    input logic [(COLOR_BITS/3)-1 :0] menu_red_i,

    input logic is_menu_i,
    input logic is_playing_i,
    input logic is_continue_i,
    input logic is_final_i,

    output logic [(COLOR_BITS/3)-1 :0] blue_o,
    output logic [(COLOR_BITS/3)-1 :0] green_o,
    output logic [(COLOR_BITS/3)-1 :0] red_o
);

    logic map_enable;
    logic [(COLOR_BITS/3)-1 :0] player_blue;
    logic [(COLOR_BITS/3)-1 :0] player_green;
    logic [(COLOR_BITS/3)-1 :0] player_red;


    assign map_enable = |map_blue_i || |map_green_i || |map_green_i;
    assign player_blue = map_enable ? 0 : player_blue_i;
    assign player_green = map_enable ? 0 : player_green_i;
    assign player_red = map_enable ? 0 : player_red_i;

    always_comb begin
        {blue_o, green_o, red_o} = 0;
        if (display_enable_i) begin
            if(is_menu_i) begin 
                {blue_o, green_o, red_o} = {menu_blue_i, menu_green_i, menu_red_i};

            end else if (is_playing_i) begin
                if(map_enable_i) begin
                    blue_o  = map_blue_i  | player_blue     | bullet_blue_i;
                    green_o = map_green_i | player_green    | bullet_green_i;
                    red_o   = map_red_i   | player_red      | bullet_red_i;
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
