#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern int window_width;
extern int window_height;

extern uint32_t* color_buffer;
extern SDL_Texture* color_buffer_texture;

bool initialize_window();
void destroy_window();
void clear_color_buffer(uint32_t color);
void render_color_buffer();
void display_grid();
void draw_rectangle(int x, int y, int width, int height, uint32_t color);
void draw_pixel(int x, int y, uint32_t color);

#endif