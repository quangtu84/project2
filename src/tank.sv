/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
module tank #(
    parameter COLOR_BITS = 24,
    parameter [9:0] TANK_X_INIT = 10'd32,
    parameter [9:0] TANK_Y_INIT = 10'd416,
    parameter [3:0] TANK_DIR_INIT = 4'b0001,
    parameter [9:0] TANK_MOVE_SPEED = 1,
    parameter [9:0] BULLET_MOVE_SPEED = 1
) (
    //control tanks
    input logic [3:0] tank_move_i,
    input logic tank_shoot_i,
    input logic bullet_collide_i,
    input logic tank_die_i,

    //video signal
    input logic [9:0] hpos_i,
    input logic [9:0] vpos_i,
    input logic [COLOR_BITS-1 :0] tank_gfx_bit_i,
    output logic [9:0] tank_gfx_addr_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_blue_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_green_o,
    output logic [(COLOR_BITS/3)-1 :0] tank_red_o,
    output logic bullet_enable_o,
    output logic tank_enable_o,

    //other control signal
    input logic cannot_walk_through_i,
    
    output logic tank_collide_with_wall_top_o,
    output logic tank_collide_with_wall_bottom_o,
    output logic tank_collide_with_wall_right_o,
    output logic tank_collide_with_wall_left_o,

    //clock
    input logic hsync_i,
    input logic player_clk_i,
    input logic bullet_clk_i,
    input logic clk_i,
    input logic reset_i
);

    localparam PLAYER_BOUND = 30;
    localparam PLAYER_BOUND_2 = 1;
    localparam BULLET_BOUND = 5;

    logic [9:0] tank_x, tank_y;  //upper left point of tank
    logic tank_box, tank_collide_with_wall_top, tank_collide_with_wall_bottom, tank_collide_with_wall_left, tank_collide_with_wall_right;
    logic [3:0] tank_prev_direct;

    logic tank_top, tank_bottom, tank_left, tank_right;

    ///////////////////////////////////////////
    //       player collide with walls
    ///////////////////////////////////////////
    assign tank_top     = ((vpos_i - tank_y) == PLAYER_BOUND_2-1)   && ((hpos_i - tank_x) <= PLAYER_BOUND-1)  && ((hpos_i - tank_x) >= PLAYER_BOUND_2+1);
    assign tank_bottom  = ((vpos_i - tank_y) == PLAYER_BOUND+1)     && ((hpos_i - tank_x) <= PLAYER_BOUND-1)  && ((hpos_i - tank_x) >= PLAYER_BOUND_2+1);
    assign tank_left    = ((hpos_i - tank_x) == PLAYER_BOUND_2-1)   && ((vpos_i - tank_y) <= PLAYER_BOUND-1)  && ((vpos_i - tank_y) >= PLAYER_BOUND_2+1);
    assign tank_right   = ((hpos_i - tank_x) == PLAYER_BOUND+1)     && ((vpos_i - tank_y) <= PLAYER_BOUND-1)  && ((vpos_i - tank_y) >= PLAYER_BOUND_2+1);

    assign tank_box = ((vpos_i - tank_y) <= PLAYER_BOUND) && ((vpos_i - tank_y) >= PLAYER_BOUND_2) && ((hpos_i - tank_x) <= PLAYER_BOUND) && ((hpos_i - tank_x) >= PLAYER_BOUND_2);
    assign tank_enable_o = tank_box && !tank_die_i;

    assign tank_collide_with_wall_top_o     = tank_collide_with_wall_top;
    assign tank_collide_with_wall_bottom_o  = tank_collide_with_wall_bottom;
    assign tank_collide_with_wall_right_o   = tank_collide_with_wall_right;
    assign tank_collide_with_wall_left_o    = tank_collide_with_wall_left;

    always_ff @(posedge clk_i or posedge reset_i) begin
        if(reset_i) begin
            tank_collide_with_wall_top          <= 1'b0;
            tank_collide_with_wall_bottom       <= 1'b0;
            tank_collide_with_wall_right        <= 1'b0;
            tank_collide_with_wall_left         <= 1'b0;
        end
        else begin
            case (tank_move_i)
                4'b0001: begin //move down
                    tank_collide_with_wall_top     <= 1'b0;
                    tank_collide_with_wall_left     <= 1'b0;
                    tank_collide_with_wall_right     <= 1'b0;                 
                end
                4'b0010: begin //move up
                    tank_collide_with_wall_bottom     <= 1'b0;
                    tank_collide_with_wall_left     <= 1'b0;
                    tank_collide_with_wall_right     <= 1'b0;                 
                end
                4'b0100: begin //move right
                    tank_collide_with_wall_top     <= 1'b0;
                    tank_collide_with_wall_bottom     <= 1'b0;
                    tank_collide_with_wall_left     <= 1'b0;                 
                end
                4'b1000: begin //move left
                    tank_collide_with_wall_top     <= 1'b0;
                    tank_collide_with_wall_bottom     <= 1'b0;
                    tank_collide_with_wall_right     <= 1'b0;                 
                end
                default:;
            endcase
            if(tank_shoot) begin
                    tank_collide_with_wall_top     <= 1'b0;
                    tank_collide_with_wall_bottom     <= 1'b0;
                    tank_collide_with_wall_right     <= 1'b0;
                    tank_collide_with_wall_left     <= 1'b0;       
            end
            if(cannot_walk_through_i) begin
                if (tank_top)           tank_collide_with_wall_top      <= 1'b1;
                if (tank_bottom)        tank_collide_with_wall_bottom   <= 1'b1;
                if (tank_left)          tank_collide_with_wall_left     <= 1'b1;
                if (tank_right)         tank_collide_with_wall_right    <= 1'b1; 
            end
        end
    end

    ///////////////////////////////////////////
    //              player move
    ///////////////////////////////////////////
    always_ff @(posedge player_clk_i or posedge reset_i) begin
        if(reset_i) begin
            tank_x <= TANK_X_INIT;
            tank_y <= TANK_Y_INIT;
            tank_prev_direct <= TANK_DIR_INIT;
        end else begin
                case (tank_move_i)
                    4'b0001: begin //down
                        if(!tank_collide_with_wall_bottom)  begin tank_y <= tank_y + TANK_MOVE_SPEED; tank_prev_direct <= 4'b0001; end
                    end
                    4'b0010: begin //up
                        if(!tank_collide_with_wall_top)     begin tank_y <= tank_y - TANK_MOVE_SPEED; tank_prev_direct <= 4'b0010; end
                    end
                    4'b0100: begin //right
                        if(!tank_collide_with_wall_right)   begin tank_x <= tank_x + TANK_MOVE_SPEED; tank_prev_direct <= 4'b0100; end
                    end
                    4'b1000: begin //left
                        if(!tank_collide_with_wall_left)    begin tank_x <= tank_x - TANK_MOVE_SPEED; tank_prev_direct <= 4'b1000; end
                    end
                    default: begin
                        tank_x <= tank_x;
                        tank_y <= tank_y;
                    end
                endcase
        end
    end
    ///////////////////////////////////////////
    //              tank GFX
    ///////////////////////////////////////////
    
    
    logic [4:0] tank_yofs_backward, tank_xofs_backward;
    logic [4:0] tank_xofs, tank_yofs;
    always @(posedge hsync_i) begin
        if (vpos_i == tank_y)
            tank_yofs <= 2;
        else if (tank_yofs != 31)
            tank_yofs <= tank_yofs + 1;
        if (vpos_i == tank_y)
            tank_yofs_backward <= 30;
        else if (tank_yofs_backward != 0)
            tank_yofs_backward <= tank_yofs_backward - 1;
    end

    always @(posedge clk_i) begin
        if (hpos_i == tank_x)
            tank_xofs <= 2;
        else if (tank_xofs != 31)
            tank_xofs <= tank_xofs + 1;
        if (hpos_i == tank_x)
            tank_xofs_backward <= 31;
        else if (tank_xofs_backward != 0)
            tank_xofs_backward <= tank_xofs_backward - 1; 
    end

    always_ff @(posedge clk_i) begin
        case (tank_prev_direct)
            4'b0001: begin //down
                tank_gfx_addr_o <= {tank_xofs, tank_yofs};
            end
            4'b0010: begin //up
                tank_gfx_addr_o <= {tank_xofs, tank_yofs_backward};
            end
            4'b0100: begin //right
                tank_gfx_addr_o <= {tank_yofs, tank_xofs};
            end
            4'b1000: begin //left
                tank_gfx_addr_o <= {tank_yofs, tank_xofs_backward};
            end
            default:;
        endcase
    end
    
    always_comb begin
        if (!tank_die_i && tank_box) {tank_blue_o, tank_green_o, tank_red_o} = tank_gfx_bit_i;
        else {tank_blue_o, tank_green_o, tank_red_o} = 0;
    end
    ///////////////////////////////////////////
    //              bullet_1 FSM
    ///////////////////////////////////////////
    logic [9:0] tank_bullet_x, tank_bullet_y;
    logic [1:0] bullet_stage;
    logic [3:0] bullet_dir;
    logic show_bullet, tank_bullet, tank_shoot;
    localparam NOT_SHOOT = 2'b00;
    localparam SHOOT = 2'b01;
    localparam COLLIDE = 2'b10;

    pos_edge_detect pos_edge_detect_1(
        .sig(tank_shoot_i),           
        .clk(clk_i),            
        .pe(tank_shoot)
    );

    always_ff @(posedge clk_i or posedge reset_i) begin
        if(reset_i) begin
            bullet_stage <= NOT_SHOOT;
        end else begin
            case(bullet_stage)
                NOT_SHOOT: begin
                    show_bullet <= 0;
                    bullet_dir <= tank_prev_direct;
                    if (tank_shoot && !tank_die_i ) begin
                        bullet_stage <= SHOOT;
                    end
                end
                SHOOT: begin
                    show_bullet <= 1;
                    if (bullet_collide_i) begin
                        bullet_stage <= COLLIDE;
                        show_bullet <= 0;
                    end
                end
                COLLIDE: begin
                    bullet_stage <= NOT_SHOOT;
                end
            
                default: ;
            endcase
        end
    end

    always_ff @(posedge bullet_clk_i) begin
        if(bullet_stage == SHOOT && show_bullet) begin
            case (bullet_dir)
                4'b0001: begin //down
                    tank_bullet_y <= tank_bullet_y + BULLET_MOVE_SPEED;
                end
                4'b0010: begin //up
                    tank_bullet_y <= tank_bullet_y - BULLET_MOVE_SPEED;
                end
                4'b0100: begin //right
                    tank_bullet_x <= tank_bullet_x + BULLET_MOVE_SPEED;
                end
                4'b1000: begin //left
                    tank_bullet_x <= tank_bullet_x - BULLET_MOVE_SPEED;
                end
                default:;
            endcase
        end
        if(bullet_stage == NOT_SHOOT) begin
            case (tank_prev_direct)
                4'b0001: begin //down
                    tank_bullet_x <= tank_x + 14;
                    tank_bullet_y <= tank_y + 32;
                end
                4'b0010: begin //up
                    tank_bullet_x <= tank_x + 14;
                    tank_bullet_y <= tank_y - 4;
                end
                4'b0100: begin //right
                    tank_bullet_x <= tank_x + 32;
                    tank_bullet_y <= tank_y + 14;
                end
                4'b1000: begin //left
                    tank_bullet_x <= tank_x - 4;
                    tank_bullet_y <= tank_y + 14;
                end
                default:;
            endcase
        end
    end

    assign tank_bullet = show_bullet && ((vpos_i - tank_bullet_y) < BULLET_BOUND)  && ((hpos_i - tank_bullet_x) < BULLET_BOUND);
    assign bullet_enable_o = tank_bullet;

endmodule
/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
