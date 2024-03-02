module map_block (
    input logic map_enable_i,
    input logic [3:0] map_x_i,
    input logic [3:0] map_y_i,
    output logic [2:0] block_type_o
);

    localparam BRICK    = 3'b000;
    localparam WALL     = 3'b001;
    localparam TREE     = 3'b010;
    localparam WATER    = 3'b011;
    // localparam BRICK    = 3'b000;
    // localparam BRICK    = 3'b000;
    // localparam BRICK    = 3'b000;
    localparam AIR      = 3'b111;


    logic [12:0][2:0] map_tiles [12:0];
    initial begin
        //                    1       2       3       4       5       6       7       8       9       10      11      12      13
        map_tiles [0]   =     {AIR,   AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR};
        map_tiles [1]   =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [2]   =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [3]   =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  WALL,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [4]   =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [5]   =     {AIR,   AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR};
        map_tiles [6]   =     {WALL,  AIR,    BRICK,  BRICK,  AIR,    AIR,    AIR,    AIR,    AIR,    BRICK,  BRICK,  AIR,    WALL};
        map_tiles [7]   =     {AIR,   AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR};
        map_tiles [8]   =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [9]   =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [10]  =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  BRICK,  BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [11]  =     {AIR,   BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR,    BRICK,  AIR};
        map_tiles [12]  =     {AIR,   AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR,    AIR};
    end
    
    always_comb begin
        if (map_enable_i) begin
            block_type_o = map_tiles [map_y_i][map_x_i];
        end else begin
            block_type_o = AIR;
        end
        
    end

endmodule
