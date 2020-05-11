#include "display.h"

SDL_Window *window;
SDL_Renderer *renderer;
int window_width;
int window_height;

bool initialize_window()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return false;
    SDL_DisplayMode display_mode;
    SDL_GetCurrentDisplayMode(0, &display_mode);
    window_width = display_mode.w;
    window_height = display_mode.h;
    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_BORDERLESS);
    if (!window)
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;

    return true;
}

void destroy_window()
{
    free(color_buffer);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
