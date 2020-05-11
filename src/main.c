#define SDL_MAIN_HANDLED

#include "display.h"
#include "vector.h"

bool is_running = false;

void set_up(void)
{
   
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

void update(void)
{
}

void render(void)
{
   
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