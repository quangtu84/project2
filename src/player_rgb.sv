/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
module player_rgb #(
    parameter COLOR_BITS = 24
) (
    //control tanks
    input logic [3:0] player_1_move_i,
    input logic [3:0] player_2_move_i,
    input logic player_1_shoot_i,
    input logic player_2_shoot_i,
    //video signal
    input logic display_enable_i,
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,
    output logic [(COLOR_BITS/3)-1 :0] player_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] player_green_o,
    output logic [(COLOR_BITS/3)-1 :0] player_red_o,
    output logic [(COLOR_BITS/3)-1 :0] bullet_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] bullet_green_o,
    output logic [(COLOR_BITS/3)-1 :0] bullet_red_o,
    //other signal
    input logic map_enable_i,
    input logic destroyable_block_i,
    input logic cannot_walk_through_i,
    input logic all_hard_block_o,
    input logic hsync_i,
    output logic bullet_collide_o,

    input logic clk_slow_i,
    input logic clk_i,
    input logic reset_i
);

    localparam PLAYER_1_X_INIT = 7*32;
    localparam PLAYER_1_Y_INIT = 32;
    localparam PLAYER_2_X_INIT = 7*32;
    localparam PLAYER_2_Y_INIT = 32*13;
    localparam PLAYER_MOVE_SPEED = 1;
    localparam BULLET_MOVE_SPEED = 4;
    localparam PLAYER_BOUND = 28;
    localparam PLAYER_BOUND_2 = 3;
    localparam BULLET_BOUND = 4;

    logic [9:0] player_1_x, player_1_y, player_2_x, player_2_y;  //upper left point of tank
    logic player_1_box, player_1_collide_with_wall_top, player_1_collide_with_wall_bottom, player_1_collide_with_wall_left, player_1_collide_with_wall_right;
    logic player_2_box, player_2_collide_with_wall_top, player_2_collide_with_wall_bottom, player_2_collide_with_wall_left, player_2_collide_with_wall_right;
    logic [3:0] player_1_prev_direct, player_2_prev_direct;

    logic player_1_top, player_1_bottom, player_1_left, player_1_right;
    logic player_2_top, player_2_bottom, player_2_left, player_2_right;

    ///////////////////////////////////////////
    //       player collide with walls
    ///////////////////////////////////////////
    assign player_1_top     = ((vpos_i - player_1_y) == PLAYER_BOUND_2-1)   && ((hpos_i - player_1_x) <= PLAYER_BOUND-1)  && ((hpos_i - player_1_x) >= PLAYER_BOUND_2+1);
    assign player_1_bottom  = ((vpos_i - player_1_y) == PLAYER_BOUND+1)     && ((hpos_i - player_1_x) <= PLAYER_BOUND-1)  && ((hpos_i - player_1_x) >= PLAYER_BOUND_2+1);
    assign player_1_left    = ((hpos_i - player_1_x) == PLAYER_BOUND_2-1)   && ((vpos_i - player_1_y) <= PLAYER_BOUND-1)  && ((vpos_i - player_1_y) >= PLAYER_BOUND_2+1);
    assign player_1_right   = ((hpos_i - player_1_x) == PLAYER_BOUND+1)     && ((vpos_i - player_1_y) <= PLAYER_BOUND-1)  && ((vpos_i - player_1_y) >= PLAYER_BOUND_2+1);

    assign player_2_top     = ((vpos_i - player_2_y) == PLAYER_BOUND_2-1)   && ((hpos_i - player_2_x) <= PLAYER_BOUND-1)  && ((hpos_i - player_2_x) >= PLAYER_BOUND_2+1);
    assign player_2_bottom  = ((vpos_i - player_2_y) == PLAYER_BOUND+1)     && ((hpos_i - player_2_x) <= PLAYER_BOUND-1)  && ((hpos_i - player_2_x) >= PLAYER_BOUND_2+1);
    assign player_2_left    = ((hpos_i - player_2_x) == PLAYER_BOUND_2-1)   && ((vpos_i - player_2_y) <= PLAYER_BOUND-1)  && ((vpos_i - player_2_y) >= PLAYER_BOUND_2+1);
    assign player_2_right   = ((hpos_i - player_2_x) == PLAYER_BOUND+1)     && ((vpos_i - player_2_y) <= PLAYER_BOUND-1)  && ((vpos_i - player_2_y) >= PLAYER_BOUND_2+1);

    assign player_1_box = ((vpos_i - player_1_y) <= PLAYER_BOUND) && ((vpos_i - player_1_y) >= PLAYER_BOUND_2) && ((hpos_i - player_1_x) <= PLAYER_BOUND) && ((hpos_i - player_1_x) >= PLAYER_BOUND_2);
    assign player_2_box = ((vpos_i - player_2_y) <= PLAYER_BOUND) && ((vpos_i - player_2_y) >= PLAYER_BOUND_2) && ((hpos_i - player_2_x) <= PLAYER_BOUND) && ((hpos_i - player_2_x) >= PLAYER_BOUND_2);

    always_ff @(posedge clk_i) begin
        case (player_1_move_i)
            4'b0001: begin //move down
                player_1_collide_with_wall_top     <= 1'b0;
                player_1_collide_with_wall_left     <= 1'b0;
                player_1_collide_with_wall_right     <= 1'b0;                 
            end
            4'b0010: begin //move up
                player_1_collide_with_wall_bottom     <= 1'b0;
                player_1_collide_with_wall_left     <= 1'b0;
                player_1_collide_with_wall_right     <= 1'b0;                 
            end
            4'b0100: begin //move right
                player_1_collide_with_wall_top     <= 1'b0;
                player_1_collide_with_wall_bottom     <= 1'b0;
                player_1_collide_with_wall_left     <= 1'b0;                 
            end
            4'b1000: begin //move left
                player_1_collide_with_wall_top     <= 1'b0;
                player_1_collide_with_wall_bottom     <= 1'b0;
                player_1_collide_with_wall_right     <= 1'b0;                 
            end
            default:;
        endcase
        case (player_2_move_i)
            4'b0001: begin //move down
                player_2_collide_with_wall_top     <= 1'b0;
                player_2_collide_with_wall_left     <= 1'b0;
                player_2_collide_with_wall_right     <= 1'b0;                 
            end
            4'b0010: begin //move up
                player_2_collide_with_wall_bottom     <= 1'b0;
                player_2_collide_with_wall_left     <= 1'b0;
                player_2_collide_with_wall_right     <= 1'b0;                 
            end
            4'b0100: begin //move right
                player_2_collide_with_wall_top     <= 1'b0;
                player_2_collide_with_wall_bottom     <= 1'b0;
                player_2_collide_with_wall_left     <= 1'b0;                 
            end
            4'b1000: begin //move left
                player_2_collide_with_wall_top     <= 1'b0;
                player_2_collide_with_wall_bottom     <= 1'b0;
                player_2_collide_with_wall_right     <= 1'b0;                 
            end
            default:;
        endcase
        if(cannot_walk_through_i) begin
            if (player_1_top)           player_1_collide_with_wall_top      <= 1'b1;
            if (player_1_bottom)        player_1_collide_with_wall_bottom   <= 1'b1;
            if (player_1_left)          player_1_collide_with_wall_left     <= 1'b1;
            if (player_1_right)         player_1_collide_with_wall_right    <= 1'b1; 
        end
        if(cannot_walk_through_i) begin
            if (player_2_top)           player_2_collide_with_wall_top      <= 1'b1;
            if (player_2_bottom)        player_2_collide_with_wall_bottom   <= 1'b1;
            if (player_2_left)          player_2_collide_with_wall_left     <= 1'b1;
            if (player_2_right)         player_2_collide_with_wall_right    <= 1'b1; 
        end
    end

    initial begin
        player_1_x = PLAYER_1_X_INIT;
        player_1_y = PLAYER_1_Y_INIT;
        player_2_x = PLAYER_2_X_INIT;
        player_2_y = PLAYER_2_Y_INIT;
    end
    ///////////////////////////////////////////
    //              player move
    ///////////////////////////////////////////
    always_ff @(posedge clk_slow_i) begin
        if(reset_i) begin
            player_1_x <= PLAYER_1_X_INIT;
            player_1_y <= PLAYER_1_Y_INIT;
            player_2_x <= PLAYER_2_X_INIT;
            player_2_y <= PLAYER_2_Y_INIT;
            player_1_prev_direct <= 4'b0001;
            player_2_prev_direct <= 4'b0010;
        end else begin
                case (player_1_move_i)
                    4'b0001: begin //down
                        if(!player_1_collide_with_wall_bottom)  begin player_1_y <= player_1_y + PLAYER_MOVE_SPEED; player_1_prev_direct <= 4'b0001; end
                    end
                    4'b0010: begin //up
                        if(!player_1_collide_with_wall_top)     begin player_1_y <= player_1_y - PLAYER_MOVE_SPEED; player_1_prev_direct <= 4'b0010; end
                    end
                    4'b0100: begin //right
                        if(!player_1_collide_with_wall_right)   begin player_1_x <= player_1_x + PLAYER_MOVE_SPEED; player_1_prev_direct <= 4'b0100; end
                    end
                    4'b1000: begin //left
                        if(!player_1_collide_with_wall_left)    begin player_1_x <= player_1_x - PLAYER_MOVE_SPEED; player_1_prev_direct <= 4'b1000; end
                    end
                    default: begin
                        player_1_x <= player_1_x;
                        player_1_y <= player_1_y;
                    end
                endcase
                case (player_2_move_i)
                    4'b0001: begin //down
                        if(!player_2_collide_with_wall_bottom)  begin player_2_y <= player_2_y + PLAYER_MOVE_SPEED; player_2_prev_direct <= 4'b0001; end
                    end
                    4'b0010: begin //up
                        if(!player_2_collide_with_wall_top)     begin player_2_y <= player_2_y - PLAYER_MOVE_SPEED; player_2_prev_direct <= 4'b0010; end
                    end
                    4'b0100: begin //right
                        if(!player_2_collide_with_wall_right)   begin player_2_x <= player_2_x + PLAYER_MOVE_SPEED; player_2_prev_direct <= 4'b0100; end
                    end
                    4'b1000: begin //left
                        if(!player_2_collide_with_wall_left)    begin player_2_x <= player_2_x - PLAYER_MOVE_SPEED; player_2_prev_direct <= 4'b1000; end
                    end
                    default: begin
                        player_2_x <= player_2_x;
                        player_2_y <= player_2_y;
                    end
                endcase
        end
    end
    ///////////////////////////////////////////
    //              player_1 GFX
    ///////////////////////////////////////////
    logic [9:0] addr_1;
    logic [COLOR_BITS-1 :0] dout_1;
    logic [4:0] player_1_yofs_backward, player_1_xofs_backward;
    logic [4:0] player_1_xofs, player_1_yofs;
    always @(posedge hsync_i) begin
        if (vpos_i == player_1_y)
            player_1_yofs <= 1;
        else if (player_1_yofs != 31)
            player_1_yofs <= player_1_yofs + 1;
        if (vpos_i == player_1_y)
            player_1_yofs_backward <= 30;
        else if (player_1_yofs_backward != 0)
            player_1_yofs_backward <= player_1_yofs_backward - 1;
    end

    always @(posedge clk_i) begin
        if (hpos_i == player_1_x)
            player_1_xofs <= 1;
        else if (player_1_xofs != 31)
            player_1_xofs <= player_1_xofs + 1;
        if (hpos_i == player_1_x)
            player_1_xofs_backward <= 28;
        else if (player_1_xofs_backward != 0)
            player_1_xofs_backward <= player_1_xofs_backward - 1; 
    end


    mem_player_1  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_player_1 (
        .addr({1'b0,addr_1}),
        .dout(dout_1)
    );

    always_ff @(posedge clk_i) begin
        case (player_1_prev_direct)
            4'b0001: begin //down
                addr_1 <= {player_1_xofs, player_1_yofs};
            end
            4'b0010: begin //up
                addr_1 <= {player_1_xofs, player_1_yofs_backward};
            end
            4'b0100: begin //right
                addr_1 <= {player_1_yofs, player_1_xofs};
            end
            4'b1000: begin //left
                addr_1 <= {player_1_yofs, player_1_xofs_backward};
            end
            default:;
        endcase
    end
    ///////////////////////////////////////////
    //              player_2 GFX
    ///////////////////////////////////////////
    logic [9:0] addr_2;
    logic [COLOR_BITS-1 :0] dout_2;
    logic [4:0] player_2_yofs_backward, player_2_xofs_backward;
    logic [4:0] player_2_xofs, player_2_yofs;
    always @(posedge hsync_i) begin
        if (vpos_i == player_2_y)
            player_2_yofs <= 0;
        else if (player_2_yofs != 31)
            player_2_yofs <= player_2_yofs + 1;
        if (vpos_i == player_2_y)
            player_2_yofs_backward <= 31;
        else if (player_2_yofs_backward != 0)
            player_2_yofs_backward <= player_2_yofs_backward - 1;
    end

    always @(posedge clk_i) begin
        if (hpos_i == player_2_x)
            player_2_xofs <= 1;
        else if (player_2_xofs != 31)
            player_2_xofs <= player_2_xofs + 1;
        if (hpos_i == player_2_x)
            player_2_xofs_backward <= 30;
        else if (player_2_xofs_backward != 0)
            player_2_xofs_backward <= player_2_xofs_backward - 1; 
    end


    mem_player_2  #(
        .COLOR_BITS(COLOR_BITS)
    ) mem_player_2 (
        .addr({1'b1,addr_2}),
        .dout(dout_2)
    );

    always_ff @(posedge clk_i) begin
        case (player_2_prev_direct)
            4'b0001: begin //down
                addr_2 <= {player_2_xofs, player_2_yofs_backward};
            end
            4'b0010: begin //up
                addr_2 <= {player_2_xofs, player_2_yofs};
            end
            4'b0100: begin //right
                addr_2 <= {player_2_yofs, player_2_xofs_backward};
            end
            4'b1000: begin //left
                addr_2 <= {player_2_yofs, player_2_xofs};
            end
            default:;
        endcase
    end

    always_comb begin
        if (player_1_box) {player_blue_o, player_green_o, player_red_o} = dout_1;
        else if (player_2_box) {player_blue_o, player_green_o, player_red_o} = dout_2;
        else {player_blue_o, player_green_o, player_red_o} = 0;
    end
    ///////////////////////////////////////////
    //              bullet_1 FSM
    ///////////////////////////////////////////
    logic [9:0] player_1_bullet_x, player_1_bullet_y;
    logic [1:0] bullet_1_state;
    logic [3:0] bullet_1_dir;
    logic show_bullet_1, bullet_1_collide, player_1_bullet, player_1_shoot;
    localparam NOT_SHOOT = 2'b00;
    localparam SHOOT = 2'b01;
    localparam COLLIDE = 2'b10;

    pos_edge_detect pos_edge_detect_1(
        .sig(player_1_shoot_i),           
        .clk(clk_i),            
        .pe(player_1_shoot)
    );

    always_ff @(posedge clk_i) begin
        if(reset_i) begin
            bullet_1_state <= NOT_SHOOT;
        end else begin
            case(bullet_1_state)
                NOT_SHOOT: begin
                    show_bullet_1 <= 0;
                    bullet_1_dir <= player_1_prev_direct;
                    if (player_1_shoot) begin
                        bullet_1_state <= SHOOT;
                    end
                end
                SHOOT: begin
                    show_bullet_1 <= 1;
                    if (bullet_1_collide) begin
                        bullet_1_state <= COLLIDE;
                        show_bullet_1 <= 0;
                    end
                end
                COLLIDE: begin
                    bullet_1_state <= NOT_SHOOT;
                end
            
                default: ;
            endcase
        end
    end

    always_ff @(posedge clk_slow_i) begin
        if(bullet_1_state == SHOOT) begin
            case (bullet_1_dir)
                4'b0001: begin //down
                    player_1_bullet_y <= player_1_bullet_y + BULLET_MOVE_SPEED;
                end
                4'b0010: begin //up
                    player_1_bullet_y <= player_1_bullet_y - BULLET_MOVE_SPEED;
                end
                4'b0100: begin //right
                    player_1_bullet_x <= player_1_bullet_x + BULLET_MOVE_SPEED;
                end
                4'b1000: begin //left
                    player_1_bullet_x <= player_1_bullet_x - BULLET_MOVE_SPEED;
                end
                default:;
            endcase
        end
        if(bullet_1_state == NOT_SHOOT) begin
            case (player_1_prev_direct)
                4'b0001: begin //down
                    player_1_bullet_x <= player_1_x + 14;
                    player_1_bullet_y <= player_1_y + 32;
                end
                4'b0010: begin //up
                    player_1_bullet_x <= player_1_x + 14;
                    player_1_bullet_y <= player_1_y - 4;
                end
                4'b0100: begin //right
                    player_1_bullet_x <= player_1_x + 32;
                    player_1_bullet_y <= player_1_y + 14;
                end
                4'b1000: begin //left
                    player_1_bullet_x <= player_1_x - 4;
                    player_1_bullet_y <= player_1_y + 14;
                end
                default:;
            endcase
        end
    end
    assign bullet_1_collide = player_1_bullet && all_hard_block_o;

    assign player_1_bullet = show_bullet_1 && ((vpos_i - player_1_bullet_y) <= BULLET_BOUND)  && ((hpos_i - player_1_bullet_x) <= BULLET_BOUND);

    ///////////////////////////////////////////
    //              bullet_2 FSM
    ///////////////////////////////////////////

    logic [9:0] player_2_bullet_x, player_2_bullet_y;
    logic [1:0] bullet_2_state;
    logic [3:0] bullet_2_dir;
    logic show_bullet_2, bullet_2_collide, player_2_bullet, player_2_shoot;

    pos_edge_detect pos_edge_detect_2(
        .sig(player_2_shoot_i),           
        .clk(clk_i),            
        .pe(player_2_shoot)
    );

    always_ff @(posedge clk_i) begin
        if(reset_i) begin
            bullet_2_state <= NOT_SHOOT;
        end else begin
            case(bullet_2_state)
                NOT_SHOOT: begin
                    show_bullet_2 <= 0;
                    bullet_2_dir <= player_2_prev_direct;
                    if (player_2_shoot) begin
                        bullet_2_state <= SHOOT;
                    end
                end
                SHOOT: begin
                    show_bullet_2 <= 1;
                    if (bullet_2_collide) begin
                        bullet_2_state <= COLLIDE;
                        show_bullet_2 <= 0;
                    end
                end
                COLLIDE: begin
                    bullet_2_state <= NOT_SHOOT;
                end
            
                default: ;
            endcase
        end
    end

    always_ff @(posedge clk_slow_i) begin
        if(bullet_2_state == SHOOT) begin
            case (bullet_2_dir)
                4'b0001: begin //down
                    player_2_bullet_y <= player_2_bullet_y + BULLET_MOVE_SPEED;
                end
                4'b0010: begin //up
                    player_2_bullet_y <= player_2_bullet_y - BULLET_MOVE_SPEED;
                end
                4'b0100: begin //right
                    player_2_bullet_x <= player_2_bullet_x + BULLET_MOVE_SPEED;
                end
                4'b1000: begin //left
                    player_2_bullet_x <= player_2_bullet_x - BULLET_MOVE_SPEED;
                end
                default:;
            endcase
        end
        if(bullet_2_state == NOT_SHOOT) begin
            case (player_2_prev_direct)
                4'b0001: begin //down
                    player_2_bullet_x <= player_2_x + 14;
                    player_2_bullet_y <= player_2_y + 32;
                end
                4'b0010: begin //up
                    player_2_bullet_x <= player_2_x + 14;
                    player_2_bullet_y <= player_2_y - 4;
                end
                4'b0100: begin //right
                    player_2_bullet_x <= player_2_x + 32;
                    player_2_bullet_y <= player_2_y + 14;
                end
                4'b1000: begin //left
                    player_2_bullet_x <= player_2_x - 4;
                    player_2_bullet_y <= player_2_y + 14;
                end
                default:;
            endcase
        end
    end
    assign bullet_2_collide = player_2_bullet && all_hard_block_o;

    assign player_2_bullet = show_bullet_2 && ((vpos_i - player_2_bullet_y) <= BULLET_BOUND)  && ((hpos_i - player_2_bullet_x) <= BULLET_BOUND);

    ///////////////////////////////////////////////
    //              Bullet GFX
    ///////////////////////////////////////////////

    assign {bullet_blue_o, bullet_green_o, bullet_red_o} = (player_1_bullet | player_2_bullet) ? 24'hFFFFFF : 24'b0;

    ///////////////////////////////////////////////
    //        Bullet collide with bricks
    ///////////////////////////////////////////////

    assign bullet_collide_o = destroyable_block_i && (player_1_bullet | player_2_bullet);

endmodule
/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
