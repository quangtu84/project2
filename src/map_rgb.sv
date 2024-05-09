module map_rgb #(
    parameter COLOR_BITS = 24
) (
    input logic [1:0] map_type_i,
    input logic bullet_collide_i,
    input logic display_enable_i,
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,
    output logic map_enable_o,
    output logic cannot_walk_through_o,
    output logic destroyable_block_o,
    output logic all_hard_block_o,
    output logic [(COLOR_BITS/3)-1 :0] map_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] map_green_o,
    output logic [(COLOR_BITS/3)-1 :0] map_red_o,
    input logic clk_i,
    input logic reset_i
);
    
    mem_tile #(
        .ADDRESS(13),
        .COLOR_BITS(COLOR_BITS)
    ) tile (
        .addr({block_type,vpos_i[4:0],hpos_i[4:0]}),
        .dout(dout)
    );

    logic [2:0] block_type;
    logic [COLOR_BITS-1:0] dout;
    logic [3:0] block_state;
    logic [3:0] map_x, map_y;
    logic UL, UR, LR, LL;

    assign map_enable_o = display_enable_i && (hpos_i >=32) && (hpos_i <= 447) && (vpos_i >=32) && (vpos_i <= 447);
    assign cannot_walk_through_o = (display_enable_i && !map_enable_o) || block_type == WATER
                                 || ((block_type == BRICK) && UL) || ((block_type == BRICK) && UR)
                                 || ((block_type == BRICK) && LR) || ((block_type == BRICK) && LL)
                                 || ((block_type == WALL) && UL) || ((block_type == WALL) && UR)
                                 || ((block_type == WALL) && LR) || ((block_type == WALL) && LL);
    assign destroyable_block_o = ((block_type == BRICK) && UL) || ((block_type == BRICK) && UR)
                               ||((block_type == BRICK) && LR) || ((block_type == BRICK) && LL);
    assign all_hard_block_o = (display_enable_i && !map_enable_o)
                            || ((block_type == BRICK) && UL) || ((block_type == BRICK) && UR)
                            || ((block_type == BRICK) && LR) || ((block_type == BRICK) && LL)
                            || ((block_type == WALL) && UL) || ((block_type == WALL) && UR)
                            || ((block_type == WALL) && LR) || ((block_type == WALL) && LL);

    localparam BRICK    = 3'b000;
    localparam WALL     = 3'b001;
    localparam TREE     = 3'b010;
    localparam WATER    = 3'b011;
    localparam AIR      = 3'b111;


    assign map_x = hpos_i[8:5] -1;
    assign map_y = vpos_i[8:5] -1;

    always_comb begin
        if (map_enable_o) begin
            block_type = map_tiles [map_y][map_x][6:4];
            block_state = map_tiles [map_y][map_x][3:0];
        end else begin
            block_type = AIR;
            block_state = 4'b0;
        end
    end

    //block_state[0] : UL corner
    //block_state[1] : UR corner
    //block_state[2] : LR corner
    //block_state[3] : LL corner
    assign UL = (hpos_i[4:0] <= 16) && (vpos_i[4:0] <= 16) && block_state[0];
    assign UR = (hpos_i[4:0] >= 16) && (vpos_i[4:0] <= 16) && block_state[1];
    assign LR = (hpos_i[4:0] <= 16) && (vpos_i[4:0] >= 16) && block_state[2];
    assign LL = (hpos_i[4:0] >= 16) && (vpos_i[4:0] >= 16) && block_state[3];

    //block_state
    always_comb begin
        if (UL || UR || LR || LL) begin
            {map_blue_o, map_green_o, map_red_o} = dout;
        end else begin
            {map_blue_o, map_green_o, map_red_o} = 0;
        end
    end

    logic [6:0] map_tiles [12:0][12:0];
    //load map & block state
    always_ff @(posedge clk_i or posedge reset_i) begin
        if(reset_i) begin
            case (map_type_i)
                0: begin //map 1
                    map_tiles[0][0] <= {AIR,4'b1111};
                    map_tiles[0][1] <= {AIR,4'b1111};
                    map_tiles[0][2] <= {AIR,4'b1111};
                    map_tiles[0][3] <= {AIR,4'b1111};
                    map_tiles[0][4] <= {AIR,4'b1111};
                    map_tiles[0][5] <= {AIR,4'b1111};
                    map_tiles[0][6] <= {AIR,4'b1111};
                    map_tiles[0][7] <= {AIR,4'b1111};
                    map_tiles[0][8] <= {AIR,4'b1111};
                    map_tiles[0][9] <= {AIR,4'b1111};
                    map_tiles[0][10] <= {AIR,4'b1111};
                    map_tiles[0][11] <= {AIR,4'b1111};
                    map_tiles[0][12] <= {AIR,4'b1111};
                    map_tiles[1][0] <= {AIR,4'b1111};
                    map_tiles[1][1] <= {BRICK,4'b1111};
                    map_tiles[1][2] <= {AIR,4'b1111};
                    map_tiles[1][3] <= {BRICK,4'b1111};
                    map_tiles[1][4] <= {AIR,4'b1111};
                    map_tiles[1][5] <= {BRICK,4'b1111};
                    map_tiles[1][6] <= {AIR,4'b1111};
                    map_tiles[1][7] <= {BRICK,4'b1111};
                    map_tiles[1][8] <= {AIR,4'b1111};
                    map_tiles[1][9] <= {BRICK,4'b1111};
                    map_tiles[1][10] <= {AIR,4'b1111};
                    map_tiles[1][11] <= {BRICK,4'b1111};
                    map_tiles[1][12] <= {AIR,4'b1111};
                    map_tiles[2][0] <= {AIR,4'b1111};
                    map_tiles[2][1] <= {BRICK,4'b1111};
                    map_tiles[2][2] <= {AIR,4'b1111};
                    map_tiles[2][3] <= {BRICK,4'b1111};
                    map_tiles[2][4] <= {AIR,4'b1111};
                    map_tiles[2][5] <= {BRICK,4'b1111};
                    map_tiles[2][6] <= {AIR,4'b1111};
                    map_tiles[2][7] <= {BRICK,4'b1111};
                    map_tiles[2][8] <= {AIR,4'b1111};
                    map_tiles[2][9] <= {BRICK,4'b1111};
                    map_tiles[2][10] <= {AIR,4'b1111};
                    map_tiles[2][11] <= {BRICK,4'b1111};
                    map_tiles[2][12] <= {AIR,4'b1111};
                    map_tiles[3][0] <= {AIR,4'b1111};
                    map_tiles[3][1] <= {BRICK,4'b1111};
                    map_tiles[3][2] <= {AIR,4'b1111};
                    map_tiles[3][3] <= {BRICK,4'b1111};
                    map_tiles[3][4] <= {AIR,4'b1111};
                    map_tiles[3][5] <= {BRICK,4'b1111};
                    map_tiles[3][6] <= {WALL,4'b1111};
                    map_tiles[3][7] <= {BRICK,4'b1111};
                    map_tiles[3][8] <= {AIR,4'b1111};
                    map_tiles[3][9] <= {BRICK,4'b1111};
                    map_tiles[3][10] <= {AIR,4'b1111};
                    map_tiles[3][11] <= {BRICK,4'b1111};
                    map_tiles[3][12] <= {AIR,4'b1111};
                    map_tiles[4][0] <= {AIR,4'b1111};
                    map_tiles[4][1] <= {BRICK,4'b1111};
                    map_tiles[4][2] <= {AIR,4'b1111};
                    map_tiles[4][3] <= {BRICK,4'b1111};
                    map_tiles[4][4] <= {AIR,4'b1111};
                    map_tiles[4][5] <= {BRICK,4'b1111};
                    map_tiles[4][6] <= {AIR,4'b1111};
                    map_tiles[4][7] <= {BRICK,4'b1111};
                    map_tiles[4][8] <= {AIR,4'b1111};
                    map_tiles[4][9] <= {BRICK,4'b1111};
                    map_tiles[4][10] <= {AIR,4'b1111};
                    map_tiles[4][11] <= {BRICK,4'b1111};
                    map_tiles[4][12] <= {AIR,4'b1111};
                    map_tiles[5][0] <= {AIR,4'b1111};
                    map_tiles[5][1] <= {AIR,4'b1111};
                    map_tiles[5][2] <= {AIR,4'b1111};
                    map_tiles[5][3] <= {AIR,4'b1111};
                    map_tiles[5][4] <= {AIR,4'b1111};
                    map_tiles[5][5] <= {AIR,4'b1111};
                    map_tiles[5][6] <= {AIR,4'b1111};
                    map_tiles[5][7] <= {AIR,4'b1111};
                    map_tiles[5][8] <= {AIR,4'b1111};
                    map_tiles[5][9] <= {AIR,4'b1111};
                    map_tiles[5][10] <= {AIR,4'b1111};
                    map_tiles[5][11] <= {AIR,4'b1111};
                    map_tiles[5][12] <= {AIR,4'b1111};
                    map_tiles[6][0] <= {WALL,4'b1111};
                    map_tiles[6][1] <= {AIR,4'b1111};
                    map_tiles[6][2] <= {BRICK,4'b1111};
                    map_tiles[6][3] <= {BRICK,4'b1111};
                    map_tiles[6][4] <= {AIR,4'b1111};
                    map_tiles[6][5] <= {AIR,4'b1111};
                    map_tiles[6][6] <= {AIR,4'b1111};
                    map_tiles[6][7] <= {AIR,4'b1111};
                    map_tiles[6][8] <= {AIR,4'b1111};
                    map_tiles[6][9] <= {BRICK,4'b1111};
                    map_tiles[6][10] <= {BRICK,4'b1111};
                    map_tiles[6][11] <= {AIR,4'b1111};
                    map_tiles[6][12] <= {WALL,4'b1111};
                    map_tiles[7][0] <= {AIR,4'b1111};
                    map_tiles[7][1] <= {AIR,4'b1111};
                    map_tiles[7][2] <= {AIR,4'b1111};
                    map_tiles[7][3] <= {AIR,4'b1111};
                    map_tiles[7][4] <= {AIR,4'b1111};
                    map_tiles[7][5] <= {AIR,4'b1111};
                    map_tiles[7][6] <= {AIR,4'b1111};
                    map_tiles[7][7] <= {AIR,4'b1111};
                    map_tiles[7][8] <= {AIR,4'b1111};
                    map_tiles[7][9] <= {AIR,4'b1111};
                    map_tiles[7][10] <= {AIR,4'b1111};
                    map_tiles[7][11] <= {AIR,4'b1111};
                    map_tiles[7][12] <= {AIR,4'b1111};
                    map_tiles[8][0] <= {AIR,4'b1111};
                    map_tiles[8][1] <= {BRICK,4'b1111};
                    map_tiles[8][2] <= {AIR,4'b1111};
                    map_tiles[8][3] <= {BRICK,4'b1111};
                    map_tiles[8][4] <= {AIR,4'b1111};
                    map_tiles[8][5] <= {BRICK,4'b1111};
                    map_tiles[8][6] <= {AIR,4'b1111};
                    map_tiles[8][7] <= {BRICK,4'b1111};
                    map_tiles[8][8] <= {AIR,4'b1111};
                    map_tiles[8][9] <= {BRICK,4'b1111};
                    map_tiles[8][10] <= {AIR,4'b1111};
                    map_tiles[8][11] <= {BRICK,4'b1111};
                    map_tiles[8][12] <= {AIR,4'b1111};
                    map_tiles[9][0] <= {AIR,4'b1111};
                    map_tiles[9][1] <= {BRICK,4'b1111};
                    map_tiles[9][2] <= {AIR,4'b1111};
                    map_tiles[9][3] <= {BRICK,4'b1111};
                    map_tiles[9][4] <= {AIR,4'b1111};
                    map_tiles[9][5] <= {BRICK,4'b1111};
                    map_tiles[9][6] <= {AIR,4'b1111};
                    map_tiles[9][7] <= {BRICK,4'b1111};
                    map_tiles[9][8] <= {AIR,4'b1111};
                    map_tiles[9][9] <= {BRICK,4'b1111};
                    map_tiles[9][10] <= {AIR,4'b1111};
                    map_tiles[9][11] <= {BRICK,4'b1111};
                    map_tiles[9][12] <= {AIR,4'b1111};
                    map_tiles[10][0] <= {AIR,4'b1111};
                    map_tiles[10][1] <= {BRICK,4'b1111};
                    map_tiles[10][2] <= {AIR,4'b1111};
                    map_tiles[10][3] <= {BRICK,4'b1111};
                    map_tiles[10][4] <= {AIR,4'b1111};
                    map_tiles[10][5] <= {BRICK,4'b1111};
                    map_tiles[10][6] <= {WALL,4'b1111};
                    map_tiles[10][7] <= {BRICK,4'b1111};
                    map_tiles[10][8] <= {AIR,4'b1111};
                    map_tiles[10][9] <= {BRICK,4'b1111};
                    map_tiles[10][10] <= {AIR,4'b1111};
                    map_tiles[10][11] <= {BRICK,4'b1111};
                    map_tiles[10][12] <= {AIR,4'b1111};
                    map_tiles[11][0] <= {AIR,4'b1111};
                    map_tiles[11][1] <= {BRICK,4'b1111};
                    map_tiles[11][2] <= {AIR,4'b1111};
                    map_tiles[11][3] <= {BRICK,4'b1111};
                    map_tiles[11][4] <= {AIR,4'b1111};
                    map_tiles[11][5] <= {BRICK,4'b1111};
                    map_tiles[11][6] <= {AIR,4'b1111};
                    map_tiles[11][7] <= {BRICK,4'b1111};
                    map_tiles[11][8] <= {AIR,4'b1111};
                    map_tiles[11][9] <= {BRICK,4'b1111};
                    map_tiles[11][10] <= {AIR,4'b1111};
                    map_tiles[11][11] <= {BRICK,4'b1111};
                    map_tiles[11][12] <= {AIR,4'b1111};
                    map_tiles[12][0] <= {AIR,4'b1111};
                    map_tiles[12][1] <= {AIR,4'b1111};
                    map_tiles[12][2] <= {AIR,4'b1111};
                    map_tiles[12][3] <= {AIR,4'b1111};
                    map_tiles[12][4] <= {AIR,4'b1111};
                    map_tiles[12][5] <= {AIR,4'b1111};
                    map_tiles[12][6] <= {AIR,4'b1111};
                    map_tiles[12][7] <= {AIR,4'b1111};
                    map_tiles[12][8] <= {AIR,4'b1111};
                    map_tiles[12][9] <= {AIR,4'b1111};
                    map_tiles[12][10] <= {AIR,4'b1111};
                    map_tiles[12][11] <= {AIR,4'b1111};
                    map_tiles[12][12] <= {AIR,4'b1111};
                end
                1: begin //map 2
                    map_tiles[0][0] <= {AIR,4'b1111};
                    map_tiles[0][1] <= {AIR,4'b1111};
                    map_tiles[0][2] <= {AIR,4'b1111};
                    map_tiles[0][3] <= {AIR,4'b1111};
                    map_tiles[0][4] <= {AIR,4'b1111};
                    map_tiles[0][5] <= {AIR,4'b1111};
                    map_tiles[0][6] <= {AIR,4'b1111};
                    map_tiles[0][7] <= {AIR,4'b1111};
                    map_tiles[0][8] <= {AIR,4'b1111};
                    map_tiles[0][9] <= {AIR,4'b1111};
                    map_tiles[0][10] <= {AIR,4'b1111};
                    map_tiles[0][11] <= {AIR,4'b1111};
                    map_tiles[0][12] <= {AIR,4'b1111};
                    map_tiles[1][0] <= {AIR,4'b1111};
                    map_tiles[1][1] <= {AIR,4'b1111};
                    map_tiles[1][2] <= {AIR,4'b1111};
                    map_tiles[1][3] <= {AIR,4'b1111};
                    map_tiles[1][4] <= {AIR,4'b1111};
                    map_tiles[1][5] <= {BRICK,4'b1100};
                    map_tiles[1][6] <= {BRICK,4'b1100};
                    map_tiles[1][7] <= {AIR,4'b1111};
                    map_tiles[1][8] <= {AIR,4'b1111};
                    map_tiles[1][9] <= {AIR,4'b1111};
                    map_tiles[1][10] <= {WALL,4'b1100};
                    map_tiles[1][11] <= {AIR,4'b1111};
                    map_tiles[1][12] <= {AIR,4'b1111};
                    map_tiles[2][0] <= {AIR,4'b1111};
                    map_tiles[2][1] <= {WALL,4'b1100};
                    map_tiles[2][2] <= {WALL,4'b1100};
                    map_tiles[2][3] <= {AIR,4'b1111};
                    map_tiles[2][4] <= {BRICK,4'b1100};
                    map_tiles[2][5] <= {TREE,4'b1111};
                    map_tiles[2][6] <= {TREE,4'b1111};
                    map_tiles[2][7] <= {WALL,4'b1100};
                    map_tiles[2][8] <= {AIR,4'b1111};
                    map_tiles[2][9] <= {BRICK,4'b1100};
                    map_tiles[2][10] <= {TREE,4'b1111};
                    map_tiles[2][11] <= {BRICK,4'b1100};
                    map_tiles[2][12] <= {AIR,4'b1111};
                    map_tiles[3][0] <= {BRICK,4'b1100};
                    map_tiles[3][1] <= {TREE,4'b1111};
                    map_tiles[3][2] <= {TREE,4'b1111};
                    map_tiles[3][3] <= {BRICK,4'b1100};
                    map_tiles[3][4] <= {TREE,4'b1111};
                    map_tiles[3][5] <= {TREE,4'b1111};
                    map_tiles[3][6] <= {TREE,4'b1111};
                    map_tiles[3][7] <= {TREE,4'b1111};
                    map_tiles[3][8] <= {BRICK,4'b1100};
                    map_tiles[3][9] <= {TREE,4'b1111};
                    map_tiles[3][10] <= {TREE,4'b1111};
                    map_tiles[3][11] <= {TREE,4'b1111};
                    map_tiles[3][12] <= {BRICK,4'b1100};
                    map_tiles[4][0] <= {TREE,4'b1111};
                    map_tiles[4][1] <= {TREE,4'b1111};
                    map_tiles[4][2] <= {TREE,4'b1111};
                    map_tiles[4][3] <= {TREE,4'b1111};
                    map_tiles[4][4] <= {TREE,4'b1111};
                    map_tiles[4][5] <= {TREE,4'b1111};
                    map_tiles[4][6] <= {TREE,4'b1111};
                    map_tiles[4][7] <= {TREE,4'b1111};
                    map_tiles[4][8] <= {TREE,4'b1111};
                    map_tiles[4][9] <= {TREE,4'b1111};
                    map_tiles[4][10] <= {TREE,4'b1111};
                    map_tiles[4][11] <= {TREE,4'b1111};
                    map_tiles[4][12] <= {TREE,4'b1111};
                    map_tiles[5][0] <= {WALL,4'b1111};
                    map_tiles[5][1] <= {TREE,4'b1111};
                    map_tiles[5][2] <= {WATER,4'b1111};
                    map_tiles[5][3] <= {TREE,4'b1111};
                    map_tiles[5][4] <= {TREE,4'b1111};
                    map_tiles[5][5] <= {TREE,4'b1111};
                    map_tiles[5][6] <= {TREE,4'b1111};
                    map_tiles[5][7] <= {TREE,4'b1111};
                    map_tiles[5][8] <= {WATER,4'b1111};
                    map_tiles[5][9] <= {TREE,4'b1111};
                    map_tiles[5][10] <= {TREE,4'b1111};
                    map_tiles[5][11] <= {TREE,4'b1111};
                    map_tiles[5][12] <= {TREE,4'b1111};
                    map_tiles[6][0] <= {TREE,4'b1111};
                    map_tiles[6][1] <= {TREE,4'b1111};
                    map_tiles[6][2] <= {WATER,4'b1111};
                    map_tiles[6][3] <= {WATER,4'b1111};
                    map_tiles[6][4] <= {WATER,4'b1111};
                    map_tiles[6][5] <= {TREE,4'b1111};
                    map_tiles[6][6] <= {TREE,4'b1111};
                    map_tiles[6][7] <= {TREE,4'b1111};
                    map_tiles[6][8] <= {WATER,4'b1111};
                    map_tiles[6][9] <= {WATER,4'b1111};
                    map_tiles[6][10] <= {WATER,4'b1111};
                    map_tiles[6][11] <= {TREE,4'b1111};
                    map_tiles[6][12] <= {WALL,4'b1111};
                    map_tiles[7][0] <= {TREE,4'b1111};
                    map_tiles[7][1] <= {TREE,4'b1111};
                    map_tiles[7][2] <= {TREE,4'b1111};
                    map_tiles[7][3] <= {TREE,4'b1111};
                    map_tiles[7][4] <= {WATER,4'b1111};
                    map_tiles[7][5] <= {TREE,4'b1111};
                    map_tiles[7][6] <= {WALL,4'b1111};
                    map_tiles[7][7] <= {TREE,4'b1111};
                    map_tiles[7][8] <= {TREE,4'b1111};
                    map_tiles[7][9] <= {TREE,4'b1111};
                    map_tiles[7][10] <= {WATER,4'b1111};
                    map_tiles[7][11] <= {TREE,4'b1111};
                    map_tiles[7][12] <= {TREE,4'b1111};
                    map_tiles[8][0] <= {TREE,4'b1111};
                    map_tiles[8][1] <= {TREE,4'b1111};
                    map_tiles[8][2] <= {TREE,4'b1111};
                    map_tiles[8][3] <= {TREE,4'b1111};
                    map_tiles[8][4] <= {TREE,4'b1111};
                    map_tiles[8][5] <= {TREE,4'b1111};
                    map_tiles[8][6] <= {TREE,4'b1111};
                    map_tiles[8][7] <= {TREE,4'b1111};
                    map_tiles[8][8] <= {TREE,4'b1111};
                    map_tiles[8][9] <= {TREE,4'b1111};
                    map_tiles[8][10] <= {TREE,4'b1111};
                    map_tiles[8][11] <= {TREE,4'b1111};
                    map_tiles[8][12] <= {TREE,4'b1111};
                    map_tiles[9][0] <= {TREE,4'b1111};
                    map_tiles[9][1] <= {TREE,4'b1111};
                    map_tiles[9][2] <= {TREE,4'b1111};
                    map_tiles[9][3] <= {TREE,4'b1111};
                    map_tiles[9][4] <= {TREE,4'b1111};
                    map_tiles[9][5] <= {BRICK,4'b0011};
                    map_tiles[9][6] <= {BRICK,4'b0011};
                    map_tiles[9][7] <= {TREE,4'b1111};
                    map_tiles[9][8] <= {TREE,4'b1111};
                    map_tiles[9][9] <= {TREE,4'b1111};
                    map_tiles[9][10] <= {TREE,4'b1111};
                    map_tiles[9][11] <= {TREE,4'b1111};
                    map_tiles[9][12] <= {WALL,4'b0011};
                    map_tiles[10][0] <= {WALL,4'b0011};
                    map_tiles[10][1] <= {TREE,4'b1111};
                    map_tiles[10][2] <= {TREE,4'b1111};
                    map_tiles[10][3] <= {TREE,4'b1111};
                    map_tiles[10][4] <= {BRICK,4'b0011};
                    map_tiles[10][5] <= {AIR,4'b1111};
                    map_tiles[10][6] <= {AIR,4'b1111};
                    map_tiles[10][7] <= {BRICK,4'b0011};
                    map_tiles[10][8] <= {TREE,4'b1111};
                    map_tiles[10][9] <= {TREE,4'b1111};
                    map_tiles[10][10] <= {TREE,4'b1111};
                    map_tiles[10][11] <= {WALL,4'b0011};
                    map_tiles[10][12] <= {AIR,4'b1111};
                    map_tiles[11][0] <= {AIR,4'b1111};
                    map_tiles[11][1] <= {BRICK,4'b0011};
                    map_tiles[11][2] <= {BRICK,4'b0011};
                    map_tiles[11][3] <= {BRICK,4'b0011};
                    map_tiles[11][4] <= {AIR,4'b1111};
                    map_tiles[11][5] <= {AIR,4'b1111};
                    map_tiles[11][6] <= {AIR,4'b1111};
                    map_tiles[11][7] <= {AIR,4'b1111};
                    map_tiles[11][8] <= {WALL,4'b0011};
                    map_tiles[11][9] <= {WALL,4'b0011};
                    map_tiles[11][10] <= {BRICK,4'b0011};
                    map_tiles[11][11] <= {AIR,4'b1111};
                    map_tiles[11][12] <= {AIR,4'b1111};
                    map_tiles[12][0] <= {AIR,4'b1111};
                    map_tiles[12][1] <= {AIR,4'b1111};
                    map_tiles[12][2] <= {AIR,4'b1111};
                    map_tiles[12][3] <= {AIR,4'b1111};
                    map_tiles[12][4] <= {AIR,4'b1111};
                    map_tiles[12][5] <= {AIR,4'b1111};
                    map_tiles[12][6] <= {AIR,4'b1111};
                    map_tiles[12][7] <= {AIR,4'b1111};
                    map_tiles[12][8] <= {AIR,4'b1111};
                    map_tiles[12][9] <= {AIR,4'b1111};
                    map_tiles[12][10] <= {AIR,4'b1111};
                    map_tiles[12][11] <= {AIR,4'b1111};
                    map_tiles[12][12] <= {AIR,4'b1111};
                end
                2: begin //map 3
                    map_tiles[0][0] <= {AIR,4'b1111};
                    map_tiles[0][1] <= {AIR,4'b1111};
                    map_tiles[0][2] <= {AIR,4'b1111};
                    map_tiles[0][3] <= {BRICK,4'b1100};
                    map_tiles[0][4] <= {BRICK,4'b1100};
                    map_tiles[0][5] <= {BRICK,4'b1100};
                    map_tiles[0][6] <= {AIR,4'b1111};
                    map_tiles[0][7] <= {AIR,4'b1111};
                    map_tiles[0][8] <= {BRICK,4'b1100};
                    map_tiles[0][9] <= {AIR,4'b1111};
                    map_tiles[0][10] <= {AIR,4'b1111};
                    map_tiles[0][11] <= {AIR,4'b1111};
                    map_tiles[0][12] <= {AIR,4'b1111};
                    map_tiles[1][0] <= {AIR,4'b1111};
                    map_tiles[1][1] <= {BRICK,4'b1100};
                    map_tiles[1][2] <= {BRICK,4'b1111};
                    map_tiles[1][3] <= {BRICK,4'b1111};
                    map_tiles[1][4] <= {BRICK,4'b1111};
                    map_tiles[1][5] <= {BRICK,4'b1111};
                    map_tiles[1][6] <= {BRICK,4'b1111};
                    map_tiles[1][7] <= {BRICK,4'b1111};
                    map_tiles[1][8] <= {BRICK,4'b1111};
                    map_tiles[1][9] <= {BRICK,4'b1111};
                    map_tiles[1][10] <= {AIR,4'b1111};
                    map_tiles[1][11] <= {AIR,4'b1111};
                    map_tiles[1][12] <= {AIR,4'b1111};
                    map_tiles[2][0] <= {AIR,4'b1111};
                    map_tiles[2][1] <= {TREE,4'b1111};
                    map_tiles[2][2] <= {TREE,4'b1111};
                    map_tiles[2][3] <= {TREE,4'b1111};
                    map_tiles[2][4] <= {TREE,4'b1111};
                    map_tiles[2][5] <= {TREE,4'b1111};
                    map_tiles[2][6] <= {TREE,4'b1111};
                    map_tiles[2][7] <= {TREE,4'b1111};
                    map_tiles[2][8] <= {TREE,4'b1111};
                    map_tiles[2][9] <= {BRICK,4'b1111};
                    map_tiles[2][10] <= {BRICK,4'b1111};
                    map_tiles[2][11] <= {AIR,4'b1111};
                    map_tiles[2][12] <= {AIR,4'b1111};
                    map_tiles[3][0] <= {TREE,4'b1111};
                    map_tiles[3][1] <= {TREE,4'b1111};
                    map_tiles[3][2] <= {AIR,4'b1111};
                    map_tiles[3][3] <= {AIR,4'b1111};
                    map_tiles[3][4] <= {AIR,4'b1111};
                    map_tiles[3][5] <= {AIR,4'b1111};
                    map_tiles[3][6] <= {AIR,4'b1111};
                    map_tiles[3][7] <= {AIR,4'b1111};
                    map_tiles[3][8] <= {TREE,4'b1111};
                    map_tiles[3][9] <= {TREE,4'b1111};
                    map_tiles[3][10] <= {BRICK,4'b1111};
                    map_tiles[3][11] <= {BRICK,4'b1111};
                    map_tiles[3][12] <= {AIR,4'b1111};
                    map_tiles[4][0] <= {TREE,4'b1111};
                    map_tiles[4][1] <= {AIR,4'b1111};
                    map_tiles[4][2] <= {WALL,4'b1111};
                    map_tiles[4][3] <= {AIR,4'b1111};
                    map_tiles[4][4] <= {AIR,4'b1111};
                    map_tiles[4][5] <= {WALL,4'b1111};
                    map_tiles[4][6] <= {AIR,4'b1111};
                    map_tiles[4][7] <= {AIR,4'b1111};
                    map_tiles[4][8] <= {AIR,4'b1111};
                    map_tiles[4][9] <= {TREE,4'b1111};
                    map_tiles[4][10] <= {TREE,4'b1111};
                    map_tiles[4][11] <= {TREE,4'b1111};
                    map_tiles[4][12] <= {AIR,4'b1111};
                    map_tiles[5][0] <= {TREE,4'b1111};
                    map_tiles[5][1] <= {AIR,4'b1111};
                    map_tiles[5][2] <= {WALL,4'b1111};
                    map_tiles[5][3] <= {AIR,4'b1111};
                    map_tiles[5][4] <= {AIR,4'b1111};
                    map_tiles[5][5] <= {WALL,4'b1111};
                    map_tiles[5][6] <= {AIR,4'b1111};
                    map_tiles[5][7] <= {AIR,4'b1111};
                    map_tiles[5][8] <= {AIR,4'b1111};
                    map_tiles[5][9] <= {TREE,4'b1111};
                    map_tiles[5][10] <= {TREE,4'b1111};
                    map_tiles[5][11] <= {TREE,4'b1111};
                    map_tiles[5][12] <= {AIR,4'b1111};
                    map_tiles[6][0] <= {TREE,4'b1111};
                    map_tiles[6][1] <= {AIR,4'b1111};
                    map_tiles[6][2] <= {AIR,4'b1111};
                    map_tiles[6][3] <= {TREE,4'b1111};
                    map_tiles[6][4] <= {AIR,4'b1111};
                    map_tiles[6][5] <= {AIR,4'b1111};
                    map_tiles[6][6] <= {AIR,4'b1111};
                    map_tiles[6][7] <= {AIR,4'b1111};
                    map_tiles[6][8] <= {TREE,4'b1111};
                    map_tiles[6][9] <= {TREE,4'b1111};
                    map_tiles[6][10] <= {TREE,4'b1111};
                    map_tiles[6][11] <= {BRICK,4'b1111};
                    map_tiles[6][12] <= {BRICK,4'b1001};
                    map_tiles[7][0] <= {TREE,4'b1111};
                    map_tiles[7][1] <= {TREE,4'b1111};
                    map_tiles[7][2] <= {TREE,4'b1111};
                    map_tiles[7][3] <= {TREE,4'b1111};
                    map_tiles[7][4] <= {TREE,4'b1111};
                    map_tiles[7][5] <= {TREE,4'b1111};
                    map_tiles[7][6] <= {TREE,4'b1111};
                    map_tiles[7][7] <= {TREE,4'b1111};
                    map_tiles[7][8] <= {TREE,4'b1111};
                    map_tiles[7][9] <= {BRICK,4'b1111};
                    map_tiles[7][10] <= {BRICK,4'b1111};
                    map_tiles[7][11] <= {BRICK,4'b1111};
                    map_tiles[7][12] <= {BRICK,4'b1001};
                    map_tiles[8][0] <= {BRICK,4'b1111};
                    map_tiles[8][1] <= {TREE,4'b1111};
                    map_tiles[8][2] <= {TREE,4'b1111};
                    map_tiles[8][3] <= {BRICK,4'b1111};
                    map_tiles[8][4] <= {BRICK,4'b1111};
                    map_tiles[8][5] <= {TREE,4'b1111};
                    map_tiles[8][6] <= {TREE,4'b1111};
                    map_tiles[8][7] <= {TREE,4'b1111};
                    map_tiles[8][8] <= {BRICK,4'b1111};
                    map_tiles[8][9] <= {BRICK,4'b1111};
                    map_tiles[8][10] <= {BRICK,4'b1111};
                    map_tiles[8][11] <= {BRICK,4'b1111};
                    map_tiles[8][12] <= {AIR,4'b1111};
                    map_tiles[9][0] <= {AIR,4'b1111};
                    map_tiles[9][1] <= {BRICK,4'b1111};
                    map_tiles[9][2] <= {BRICK,4'b1111};
                    map_tiles[9][3] <= {BRICK,4'b1111};
                    map_tiles[9][4] <= {BRICK,4'b1111};
                    map_tiles[9][5] <= {BRICK,4'b1111};
                    map_tiles[9][6] <= {BRICK,4'b1111};
                    map_tiles[9][7] <= {BRICK,4'b1111};
                    map_tiles[9][8] <= {BRICK,4'b1111};
                    map_tiles[9][9] <= {BRICK,4'b1111};
                    map_tiles[9][10] <= {BRICK,4'b1111};
                    map_tiles[9][11] <= {AIR,4'b1111};
                    map_tiles[9][12] <= {WALL,4'b1111};
                    map_tiles[10][0] <= {WALL,4'b1111};
                    map_tiles[10][1] <= {AIR,4'b1111};
                    map_tiles[10][2] <= {BRICK,4'b1111};
                    map_tiles[10][3] <= {WALL,4'b1111};
                    map_tiles[10][4] <= {BRICK,4'b1111};
                    map_tiles[10][5] <= {BRICK,4'b1111};
                    map_tiles[10][6] <= {BRICK,4'b1111};
                    map_tiles[10][7] <= {BRICK,4'b1111};
                    map_tiles[10][8] <= {BRICK,4'b1111};
                    map_tiles[10][9] <= {BRICK,4'b1111};
                    map_tiles[10][10] <= {BRICK,4'b0101};
                    map_tiles[10][11] <= {AIR,4'b1111};
                    map_tiles[10][12] <= {WALL,4'b1111};
                    map_tiles[11][0] <= {AIR,4'b1111};
                    map_tiles[11][1] <= {WALL,4'b1111};
                    map_tiles[11][2] <= {BRICK,4'b1111};
                    map_tiles[11][3] <= {BRICK,4'b0011};
                    map_tiles[11][4] <= {AIR,4'b1111};
                    map_tiles[11][5] <= {AIR,4'b1111};
                    map_tiles[11][6] <= {AIR,4'b1111};
                    map_tiles[11][7] <= {BRICK,4'b1111};
                    map_tiles[11][8] <= {BRICK,4'b1111};
                    map_tiles[11][9] <= {BRICK,4'b1111};
                    map_tiles[11][10] <= {WALL,4'b1111};
                    map_tiles[11][11] <= {WALL,4'b1111};
                    map_tiles[11][12] <= {WALL,4'b1111};
                    map_tiles[12][0] <= {AIR,4'b1111};
                    map_tiles[12][1] <= {AIR,4'b1111};
                    map_tiles[12][2] <= {AIR,4'b1111};
                    map_tiles[12][3] <= {AIR,4'b1111};
                    map_tiles[12][4] <= {AIR,4'b1111};
                    map_tiles[12][5] <= {AIR,4'b1111};
                    map_tiles[12][6] <= {AIR,4'b1111};
                    map_tiles[12][7] <= {AIR,4'b1111};
                    map_tiles[12][8] <= {AIR,4'b1111};
                    map_tiles[12][9] <= {AIR,4'b1111};
                    map_tiles[12][10] <= {AIR,4'b1111};
                    map_tiles[12][11] <= {AIR,4'b1111};
                    map_tiles[12][12] <= {AIR,4'b1111};
                end
                3: begin //map 4
                    map_tiles[0][0] <= {AIR,4'b1111};
                    map_tiles[0][1] <= {AIR,4'b1111};
                    map_tiles[0][2] <= {WATER,4'b1111};
                    map_tiles[0][3] <= {WATER,4'b1111};
                    map_tiles[0][4] <= {AIR,4'b1111};
                    map_tiles[0][5] <= {AIR,4'b1111};
                    map_tiles[0][6] <= {AIR,4'b1111};
                    map_tiles[0][7] <= {AIR,4'b1111};
                    map_tiles[0][8] <= {AIR,4'b1111};
                    map_tiles[0][9] <= {AIR,4'b1111};
                    map_tiles[0][10] <= {AIR,4'b1111};
                    map_tiles[0][11] <= {AIR,4'b1111};
                    map_tiles[0][12] <= {AIR,4'b1111};
                    map_tiles[1][0] <= {WALL,4'b1100};
                    map_tiles[1][1] <= {AIR,4'b1111};
                    map_tiles[1][2] <= {AIR,4'b1111};
                    map_tiles[1][3] <= {WATER,4'b1111};
                    map_tiles[1][4] <= {TREE,4'b1111};
                    map_tiles[1][5] <= {AIR,4'b1111};
                    map_tiles[1][6] <= {BRICK,4'b0101};
                    map_tiles[1][7] <= {AIR,4'b1111};
                    map_tiles[1][8] <= {AIR,4'b1111};
                    map_tiles[1][9] <= {AIR,4'b1111};
                    map_tiles[1][10] <= {AIR,4'b1111};
                    map_tiles[1][11] <= {AIR,4'b1111};
                    map_tiles[1][12] <= {AIR,4'b1111};
                    map_tiles[2][0] <= {TREE,4'b1111};
                    map_tiles[2][1] <= {WALL,4'b1100};
                    map_tiles[2][2] <= {AIR,4'b1111};
                    map_tiles[2][3] <= {AIR,4'b1111};
                    map_tiles[2][4] <= {AIR,4'b1111};
                    map_tiles[2][5] <= {AIR,4'b1111};
                    map_tiles[2][6] <= {WALL,4'b0101};
                    map_tiles[2][7] <= {AIR,4'b1111};
                    map_tiles[2][8] <= {BRICK,4'b0101};
                    map_tiles[2][9] <= {AIR,4'b1111};
                    map_tiles[2][10] <= {WATER,4'b1111};
                    map_tiles[2][11] <= {WATER,4'b1111};
                    map_tiles[2][12] <= {AIR,4'b1111};
                    map_tiles[3][0] <= {TREE,4'b1111};
                    map_tiles[3][1] <= {TREE,4'b1111};
                    map_tiles[3][2] <= {AIR,4'b1111};
                    map_tiles[3][3] <= {WALL,4'b0011};
                    map_tiles[3][4] <= {BRICK,4'b1100};
                    map_tiles[3][5] <= {BRICK,4'b1010};
                    map_tiles[3][6] <= {AIR,4'b1111};
                    map_tiles[3][7] <= {AIR,4'b1111};
                    map_tiles[3][8] <= {WALL,4'b0101};
                    map_tiles[3][9] <= {TREE,4'b1111};
                    map_tiles[3][10] <= {WATER,4'b1111};
                    map_tiles[3][11] <= {AIR,4'b1111};
                    map_tiles[3][12] <= {AIR,4'b1111};
                    map_tiles[4][0] <= {TREE,4'b1111};
                    map_tiles[4][1] <= {TREE,4'b1111};
                    map_tiles[4][2] <= {TREE,4'b1111};
                    map_tiles[4][3] <= {AIR,4'b1111};
                    map_tiles[4][4] <= {AIR,4'b1111};
                    map_tiles[4][5] <= {WALL,4'b1111};
                    map_tiles[4][6] <= {BRICK,4'b1100};
                    map_tiles[4][7] <= {BRICK,4'b1010};
                    map_tiles[4][8] <= {AIR,4'b1111};
                    map_tiles[4][9] <= {AIR,4'b1111};
                    map_tiles[4][10] <= {AIR,4'b1111};
                    map_tiles[4][11] <= {AIR,4'b1111};
                    map_tiles[4][12] <= {WALL,4'b1100};
                    map_tiles[5][0] <= {TREE,4'b1111};
                    map_tiles[5][1] <= {TREE,4'b1111};
                    map_tiles[5][2] <= {WALL,4'b0011};
                    map_tiles[5][3] <= {WALL,4'b1100};
                    map_tiles[5][4] <= {AIR,4'b1111};
                    map_tiles[5][5] <= {BRICK,4'b1010};
                    map_tiles[5][6] <= {AIR,4'b1111};
                    map_tiles[5][7] <= {WALL,4'b1111};
                    map_tiles[5][8] <= {BRICK,4'b1100};
                    map_tiles[5][9] <= {AIR,4'b1111};
                    map_tiles[5][10] <= {AIR,4'b1111};
                    map_tiles[5][11] <= {WALL,4'b1100};
                    map_tiles[5][12] <= {TREE,4'b1111};
                    map_tiles[6][0] <= {TREE,4'b1111};
                    map_tiles[6][1] <= {WALL,4'b0011};
                    map_tiles[6][2] <= {AIR,4'b1111};
                    map_tiles[6][3] <= {AIR,4'b1111};
                    map_tiles[6][4] <= {BRICK,4'b0011};
                    map_tiles[6][5] <= {WALL,4'b1111};
                    map_tiles[6][6] <= {AIR,4'b1111};
                    map_tiles[6][7] <= {BRICK,4'b1010};
                    map_tiles[6][8] <= {AIR,4'b1111};
                    map_tiles[6][9] <= {WALL,4'b0011};
                    map_tiles[6][10] <= {AIR,4'b1111};
                    map_tiles[6][11] <= {TREE,4'b1111};
                    map_tiles[6][12] <= {TREE,4'b1111};
                    map_tiles[7][0] <= {AIR,4'b1111};
                    map_tiles[7][1] <= {AIR,4'b1111};
                    map_tiles[7][2] <= {AIR,4'b1111};
                    map_tiles[7][3] <= {AIR,4'b1111};
                    map_tiles[7][4] <= {AIR,4'b1111};
                    map_tiles[7][5] <= {BRICK,4'b0101};
                    map_tiles[7][6] <= {BRICK,4'b0011};
                    map_tiles[7][7] <= {WALL,4'b1111};
                    map_tiles[7][8] <= {AIR,4'b1111};
                    map_tiles[7][9] <= {AIR,4'b1111};
                    map_tiles[7][10] <= {TREE,4'b1111};
                    map_tiles[7][11] <= {TREE,4'b1111};
                    map_tiles[7][12] <= {TREE,4'b1111};
                    map_tiles[8][0] <= {AIR,4'b1111};
                    map_tiles[8][1] <= {AIR,4'b1111};
                    map_tiles[8][2] <= {WATER,4'b1111};
                    map_tiles[8][3] <= {TREE,4'b1111};
                    map_tiles[8][4] <= {WALL,4'b1010};
                    map_tiles[8][5] <= {AIR,4'b1111};
                    map_tiles[8][6] <= {AIR,4'b1111};
                    map_tiles[8][7] <= {BRICK,4'b0101};
                    map_tiles[8][8] <= {BRICK,4'b0011};
                    map_tiles[8][9] <= {WALL,4'b1100};
                    map_tiles[8][10] <= {WALL,4'b0011};
                    map_tiles[8][11] <= {TREE,4'b1111};
                    map_tiles[8][12] <= {TREE,4'b1111};
                    map_tiles[9][0] <= {AIR,4'b1111};
                    map_tiles[9][1] <= {WATER,4'b1111};
                    map_tiles[9][2] <= {WATER,4'b1111};
                    map_tiles[9][3] <= {AIR,4'b1111};
                    map_tiles[9][4] <= {BRICK,4'b1010};
                    map_tiles[9][5] <= {AIR,4'b1111};
                    map_tiles[9][6] <= {WALL,4'b1010};
                    map_tiles[9][7] <= {AIR,4'b1111};
                    map_tiles[9][8] <= {AIR,4'b1111};
                    map_tiles[9][9] <= {AIR,4'b1111};
                    map_tiles[9][10] <= {AIR,4'b1111};
                    map_tiles[9][11] <= {AIR,4'b1111};
                    map_tiles[9][12] <= {TREE,4'b1111};
                    map_tiles[10][0] <= {AIR,4'b1111};
                    map_tiles[10][1] <= {AIR,4'b1111};
                    map_tiles[10][2] <= {AIR,4'b1111};
                    map_tiles[10][3] <= {AIR,4'b1111};
                    map_tiles[10][4] <= {AIR,4'b1111};
                    map_tiles[10][5] <= {AIR,4'b1111};
                    map_tiles[10][6] <= {BRICK,4'b1010};
                    map_tiles[10][7] <= {AIR,4'b1111};
                    map_tiles[10][8] <= {TREE,4'b1111};
                    map_tiles[10][9] <= {WATER,4'b1111};
                    map_tiles[10][10] <= {AIR,4'b1111};
                    map_tiles[10][11] <= {AIR,4'b1111};
                    map_tiles[10][12] <= {WALL,4'b1111};
                    map_tiles[11][0] <= {WALL,4'b1111};
                    map_tiles[11][1] <= {AIR,4'b1111};
                    map_tiles[11][2] <= {AIR,4'b1111};
                    map_tiles[11][3] <= {AIR,4'b1111};
                    map_tiles[11][4] <= {AIR,4'b1111};
                    map_tiles[11][5] <= {AIR,4'b1111};
                    map_tiles[11][6] <= {AIR,4'b1111};
                    map_tiles[11][7] <= {AIR,4'b1111};
                    map_tiles[11][8] <= {AIR,4'b1111};
                    map_tiles[11][9] <= {WATER,4'b1111};
                    map_tiles[11][10] <= {WATER,4'b1111};
                    map_tiles[11][11] <= {AIR,4'b1111};
                    map_tiles[11][12] <= {AIR,4'b1111};
                    map_tiles[12][0] <= {WALL,4'b1111};
                    map_tiles[12][1] <= {WALL,4'b1111};
                    map_tiles[12][2] <= {AIR,4'b1111};
                    map_tiles[12][3] <= {AIR,4'b1111};
                    map_tiles[12][4] <= {AIR,4'b1111};
                    map_tiles[12][5] <= {AIR,4'b1111};
                    map_tiles[12][6] <= {AIR,4'b1111};
                    map_tiles[12][7] <= {AIR,4'b1111};
                    map_tiles[12][8] <= {AIR,4'b1111};
                    map_tiles[12][9] <= {AIR,4'b1111};
                    map_tiles[12][10] <= {AIR,4'b1111};
                    map_tiles[12][11] <= {AIR,4'b1111};
                    map_tiles[12][12] <= {WALL,4'b1111};
                end
                default:;
            endcase
            
        end else begin
            if(bullet_collide_i) begin
                if(UL) map_tiles[map_y][map_x][0] <= 0;
                if(UR) map_tiles[map_y][map_x][1] <= 0;
                if(LR) map_tiles[map_y][map_x][2] <= 0;
                if(LL) map_tiles[map_y][map_x][3] <= 0;
            end
            //if(block_state == 4'b0000) map_tiles [map_y][map_x][6:4] <= AIR;
        end
    end
endmodule

