module map_block (
    input logic map_enable_i,
    input logic [3:0] map_x_i,
    input logic [3:0] map_y_i,
    output logic [2:0] block_type_o,
    output logic [3:0] block_state_o
);

    localparam BRICK    = 3'b000;
    localparam WALL     = 3'b001;
    localparam TREE     = 3'b010;
    localparam WATER    = 3'b011;
    // localparam BRICK    = 3'b000;
    // localparam BRICK    = 3'b000;
    // localparam BRICK    = 3'b000;
    localparam AIR      = 3'b111;

    always_comb begin
        if (map_enable_i) begin
            block_type_o = map_tiles [map_y_i][map_x_i][6:4];
            block_state_o = map_tiles [map_y_i][map_x_i][3:0];
        end else begin
            block_type_o = AIR;
            block_state_o = 4'b0;
        end
    end

    logic [6:0] map_tiles [12:0][12:0];
    initial begin
        map_tiles[0][0] = {AIR,4'b1111};
        map_tiles[0][1] = {AIR,4'b1111};
        map_tiles[0][2] = {AIR,4'b1111};
        map_tiles[0][3] = {AIR,4'b1111};
        map_tiles[0][4] = {AIR,4'b1111};
        map_tiles[0][5] = {AIR,4'b1111};
        map_tiles[0][6] = {AIR,4'b1111};
        map_tiles[0][7] = {AIR,4'b1111};
        map_tiles[0][8] = {AIR,4'b1111};
        map_tiles[0][9] = {AIR,4'b1111};
        map_tiles[0][10] = {AIR,4'b1111};
        map_tiles[0][11] = {AIR,4'b1111};
        map_tiles[0][12] = {AIR,4'b1111};
        map_tiles[1][0] = {AIR,4'b1111};
        map_tiles[1][1] = {BRICK,4'b1111};
        map_tiles[1][2] = {AIR,4'b1111};
        map_tiles[1][3] = {BRICK,4'b1111};
        map_tiles[1][4] = {AIR,4'b1111};
        map_tiles[1][5] = {BRICK,4'b1111};
        map_tiles[1][6] = {AIR,4'b1111};
        map_tiles[1][7] = {BRICK,4'b1111};
        map_tiles[1][8] = {AIR,4'b1111};
        map_tiles[1][9] = {BRICK,4'b1111};
        map_tiles[1][10] = {AIR,4'b1111};
        map_tiles[1][11] = {BRICK,4'b1111};
        map_tiles[1][12] = {AIR,4'b1111};
        map_tiles[2][0] = {AIR,4'b1111};
        map_tiles[2][1] = {BRICK,4'b1111};
        map_tiles[2][2] = {AIR,4'b1111};
        map_tiles[2][3] = {BRICK,4'b1111};
        map_tiles[2][4] = {AIR,4'b1111};
        map_tiles[2][5] = {BRICK,4'b1111};
        map_tiles[2][6] = {AIR,4'b1111};
        map_tiles[2][7] = {BRICK,4'b1111};
        map_tiles[2][8] = {AIR,4'b1111};
        map_tiles[2][9] = {BRICK,4'b1111};
        map_tiles[2][10] = {AIR,4'b1111};
        map_tiles[2][11] = {BRICK,4'b1111};
        map_tiles[2][12] = {AIR,4'b1111};
        map_tiles[3][0] = {AIR,4'b1111};
        map_tiles[3][1] = {BRICK,4'b1111};
        map_tiles[3][2] = {AIR,4'b1111};
        map_tiles[3][3] = {BRICK,4'b1111};
        map_tiles[3][4] = {AIR,4'b1111};
        map_tiles[3][5] = {BRICK,4'b1111};
        map_tiles[3][6] = {WALL,4'b1111};
        map_tiles[3][7] = {BRICK,4'b1111};
        map_tiles[3][8] = {AIR,4'b1111};
        map_tiles[3][9] = {BRICK,4'b1111};
        map_tiles[3][10] = {AIR,4'b1111};
        map_tiles[3][11] = {BRICK,4'b1111};
        map_tiles[3][12] = {AIR,4'b1111};
        map_tiles[4][0] = {AIR,4'b1111};
        map_tiles[4][1] = {BRICK,4'b1111};
        map_tiles[4][2] = {AIR,4'b1111};
        map_tiles[4][3] = {BRICK,4'b1111};
        map_tiles[4][4] = {AIR,4'b1111};
        map_tiles[4][5] = {BRICK,4'b1111};
        map_tiles[4][6] = {AIR,4'b1111};
        map_tiles[4][7] = {BRICK,4'b1111};
        map_tiles[4][8] = {AIR,4'b1111};
        map_tiles[4][9] = {BRICK,4'b1111};
        map_tiles[4][10] = {AIR,4'b1111};
        map_tiles[4][11] = {BRICK,4'b1111};
        map_tiles[4][12] = {AIR,4'b1111};
        map_tiles[5][0] = {AIR,4'b1111};
        map_tiles[5][1] = {AIR,4'b1111};
        map_tiles[5][2] = {AIR,4'b1111};
        map_tiles[5][3] = {AIR,4'b1111};
        map_tiles[5][4] = {AIR,4'b1111};
        map_tiles[5][5] = {AIR,4'b1111};
        map_tiles[5][6] = {AIR,4'b1111};
        map_tiles[5][7] = {AIR,4'b1111};
        map_tiles[5][8] = {AIR,4'b1111};
        map_tiles[5][9] = {AIR,4'b1111};
        map_tiles[5][10] = {AIR,4'b1111};
        map_tiles[5][11] = {AIR,4'b1111};
        map_tiles[5][12] = {AIR,4'b1111};
        map_tiles[6][0] = {WALL,4'b1111};
        map_tiles[6][1] = {AIR,4'b1111};
        map_tiles[6][2] = {BRICK,4'b1111};
        map_tiles[6][3] = {BRICK,4'b1111};
        map_tiles[6][4] = {AIR,4'b1111};
        map_tiles[6][5] = {AIR,4'b1111};
        map_tiles[6][6] = {AIR,4'b1111};
        map_tiles[6][7] = {AIR,4'b1111};
        map_tiles[6][8] = {AIR,4'b1111};
        map_tiles[6][9] = {BRICK,4'b1111};
        map_tiles[6][10] = {BRICK,4'b1111};
        map_tiles[6][11] = {AIR,4'b1111};
        map_tiles[6][12] = {WALL,4'b1111};
        map_tiles[7][0] = {AIR,4'b1111};
        map_tiles[7][1] = {AIR,4'b1111};
        map_tiles[7][2] = {AIR,4'b1111};
        map_tiles[7][3] = {AIR,4'b1111};
        map_tiles[7][4] = {AIR,4'b1111};
        map_tiles[7][5] = {AIR,4'b1111};
        map_tiles[7][6] = {AIR,4'b1111};
        map_tiles[7][7] = {AIR,4'b1111};
        map_tiles[7][8] = {AIR,4'b1111};
        map_tiles[7][9] = {AIR,4'b1111};
        map_tiles[7][10] = {AIR,4'b1111};
        map_tiles[7][11] = {AIR,4'b1111};
        map_tiles[7][12] = {AIR,4'b1111};
        map_tiles[8][0] = {AIR,4'b1111};
        map_tiles[8][1] = {BRICK,4'b1111};
        map_tiles[8][2] = {AIR,4'b1111};
        map_tiles[8][3] = {BRICK,4'b1111};
        map_tiles[8][4] = {AIR,4'b1111};
        map_tiles[8][5] = {BRICK,4'b1111};
        map_tiles[8][6] = {AIR,4'b1111};
        map_tiles[8][7] = {BRICK,4'b1111};
        map_tiles[8][8] = {AIR,4'b1111};
        map_tiles[8][9] = {BRICK,4'b1111};
        map_tiles[8][10] = {AIR,4'b1111};
        map_tiles[8][11] = {BRICK,4'b1111};
        map_tiles[8][12] = {AIR,4'b1111};
        map_tiles[9][0] = {AIR,4'b1111};
        map_tiles[9][1] = {BRICK,4'b1111};
        map_tiles[9][2] = {AIR,4'b1111};
        map_tiles[9][3] = {BRICK,4'b1111};
        map_tiles[9][4] = {AIR,4'b1111};
        map_tiles[9][5] = {BRICK,4'b1111};
        map_tiles[9][6] = {AIR,4'b1111};
        map_tiles[9][7] = {BRICK,4'b1111};
        map_tiles[9][8] = {AIR,4'b1111};
        map_tiles[9][9] = {BRICK,4'b1111};
        map_tiles[9][10] = {AIR,4'b1111};
        map_tiles[9][11] = {BRICK,4'b1111};
        map_tiles[9][12] = {AIR,4'b1111};
        map_tiles[10][0] = {AIR,4'b1111};
        map_tiles[10][1] = {BRICK,4'b1111};
        map_tiles[10][2] = {AIR,4'b1111};
        map_tiles[10][3] = {BRICK,4'b1111};
        map_tiles[10][4] = {AIR,4'b1111};
        map_tiles[10][5] = {BRICK,4'b1111};
        map_tiles[10][6] = {BRICK,4'b1111};
        map_tiles[10][7] = {BRICK,4'b1111};
        map_tiles[10][8] = {AIR,4'b1111};
        map_tiles[10][9] = {BRICK,4'b1111};
        map_tiles[10][10] = {AIR,4'b1111};
        map_tiles[10][11] = {BRICK,4'b1111};
        map_tiles[10][12] = {AIR,4'b1111};
        map_tiles[11][0] = {AIR,4'b1111};
        map_tiles[11][1] = {BRICK,4'b1111};
        map_tiles[11][2] = {AIR,4'b1111};
        map_tiles[11][3] = {BRICK,4'b1111};
        map_tiles[11][4] = {AIR,4'b1111};
        map_tiles[11][5] = {BRICK,4'b1111};
        map_tiles[11][6] = {AIR,4'b1111};
        map_tiles[11][7] = {BRICK,4'b1111};
        map_tiles[11][8] = {AIR,4'b1111};
        map_tiles[11][9] = {BRICK,4'b1111};
        map_tiles[11][10] = {AIR,4'b1111};
        map_tiles[11][11] = {BRICK,4'b1111};
        map_tiles[11][12] = {AIR,4'b1111};
        map_tiles[12][0] = {AIR,4'b1111};
        map_tiles[12][1] = {AIR,4'b1111};
        map_tiles[12][2] = {AIR,4'b1111};
        map_tiles[12][3] = {AIR,4'b1111};
        map_tiles[12][4] = {AIR,4'b1111};
        map_tiles[12][5] = {AIR,4'b1111};
        map_tiles[12][6] = {AIR,4'b1111};
        map_tiles[12][7] = {AIR,4'b1111};
        map_tiles[12][8] = {AIR,4'b1111};
        map_tiles[12][9] = {AIR,4'b1111};
        map_tiles[12][10] = {AIR,4'b1111};
        map_tiles[12][11] = {AIR,4'b1111};
        map_tiles[12][12] = {AIR,4'b1111};
    end

endmodule