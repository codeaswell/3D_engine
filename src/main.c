#define SDL_MAIN_HANDLED

#include "display.h"

bool is_running = false;

void set_up(void)
{
    color_buffer = (uint32_t *)malloc(sizeof(uint32_t) * window_width * window_height);
    color_buffer_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, window_width, window_height);
}

void process_input()
{
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            is_running = false;
        break;
    }
}

// Handle Event
void update(void)
{
}

void render(void)
{
    render_color_buffer();
    clear_color_buffer(0xFF000000);

    display_grid();

    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
    SDL_SetMainReady();
    is_running = initialize_window();

    set_up();

    while (is_running)
    {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}