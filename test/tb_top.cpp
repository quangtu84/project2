// Project F: FPGA Graphics - Square Verilator C++
// (C)2023 Will Green, open source software released under the MIT License
// Learn more at https://projectf.io/posts/fpga-graphics/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <verilated.h>
#include <SDL.h>
#include "Vtop.h"

// screen dimensions
const int H_RES = 640;
const int V_RES = 480;

typedef struct Pixel {  // for SDL texture
    uint8_t a;  // transparency
    uint8_t b;  // blue
    uint8_t g;  // green
    uint8_t r;  // red
} Pixel;

int main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL init failed.\n");
        return 1;
    }

    Pixel screenbuffer[H_RES*V_RES];

    SDL_Window*   sdl_window   = NULL;
    SDL_Renderer* sdl_renderer = NULL;
    SDL_Texture*  sdl_texture  = NULL;

    sdl_window = SDL_CreateWindow("Square", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, H_RES, V_RES, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED);
    if (!sdl_window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!sdl_renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    sdl_texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, H_RES, V_RES);
    if (!sdl_texture) {
        printf("Texture creation failed: %s\n", SDL_GetError());
        return 1;
    }

    // reference SDL keyboard state array: https://wiki.libsdl.org/SDL_GetKeyboardState
    const Uint8 *keyb_state = SDL_GetKeyboardState(NULL);

    printf("Simulation running. Press 'Q' in simulation window to quit.\n\n");

    // initialize Verilog module
    Vtop* top = new Vtop;

    // reset
    // top->sim_rst = 1;
    // top->clk_i = 0;
    // top->eval();
    // top->clk_i = 1;
    // top->eval();
    // top->sim_rst = 0;
    // top->clk_i = 0;
    // top->eval();

    // initialize frame rate
    uint64_t start_ticks = SDL_GetPerformanceCounter();
    uint64_t frame_count = 0;

    // main loop
    while (1) {
        // cycle the clock
        top->clk_i = 1;
        top->eval();
        top->clk_i = 0;
        top->eval();

        // update pixel if not in blanking interval
        if (top->display_enable_o) {
            Pixel* p = &screenbuffer[top->vpos_o*H_RES + top->hpos_o];
            p->a = 0xFF;  // transparency
            p->b = top->blue_o;
            p->g = top->green_o;
            p->r = top->red_o;
        }

        // update texture once per frame (in blanking)
        if (top->vpos_o == V_RES && top->hpos_o == 0) {
            // check for quit event
            SDL_Event e;
            if (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    break;
                }
            }

            if (keyb_state[SDL_SCANCODE_Q]) {
                break;  // quit if user presses 'Q'
            }
            if (keyb_state[SDL_SCANCODE_C]) {
                std::cout << "x1 "  << top->player_1_x_o;
                std::cout << " y1 " << top->player_1_y_o;
                std::cout << " x2 " << top->player_2_x_o;
                std::cout << " y2 " << top->player_2_y_o;
                std::cout << "       " ;
                if (top->player_1_collide_with_wall_top_o){std::cout << " t ";}
                if (top->player_1_collide_with_wall_bottom_o){std::cout << " b ";}
                if (top->player_1_collide_with_wall_left_o){std::cout << " l ";}
                if (top->player_1_collide_with_wall_right_o){std::cout << " r ";}
                std::cout << std::endl;
            }
            top->player_1_move_i = 0;
            top->player_2_move_i = 0;
            if (keyb_state[SDL_SCANCODE_R]) {
                top->reset_i = 1;
            } else {
                top->reset_i = 0;
            }
            if (keyb_state[SDL_SCANCODE_S]) {
                top->player_1_move_i = 1;
            } 
            if (keyb_state[SDL_SCANCODE_W]) {
                top->player_1_move_i = 2;
            } 
            if (keyb_state[SDL_SCANCODE_D]) {
                top->player_1_move_i = 4;
            } 
            if (keyb_state[SDL_SCANCODE_A]) {
                top->player_1_move_i = 8;
            }

            if (keyb_state[SDL_SCANCODE_DOWN]) {
                top->player_2_move_i = 1;
            } 
            if (keyb_state[SDL_SCANCODE_UP]) {
                top->player_2_move_i = 2;
            } 
            if (keyb_state[SDL_SCANCODE_RIGHT]) {
                top->player_2_move_i = 4;
            } 
            if (keyb_state[SDL_SCANCODE_LEFT]) {
                top->player_2_move_i = 8;
            }
            top->eval();

            SDL_UpdateTexture(sdl_texture, NULL, screenbuffer, H_RES*sizeof(Pixel));
            SDL_RenderClear(sdl_renderer);
            SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
            SDL_RenderPresent(sdl_renderer);
            frame_count++;
        }
    }

    // calculate frame rate
    uint64_t end_ticks = SDL_GetPerformanceCounter();
    double duration = ((double)(end_ticks-start_ticks))/SDL_GetPerformanceFrequency();
    double fps = (double)frame_count/duration;
    printf("Frames per second: %.1f\n", fps);

    top->final();  // simulation done

    SDL_DestroyTexture(sdl_texture);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    return 0;
}
