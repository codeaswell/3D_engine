#include "display.h"

SDL_Window *window;
SDL_Renderer *renderer;
int window_width;
int window_height;
uint32_t* color_buffer;
SDL_Texture* color_buffer_texture;

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
void clear_color_buffer(uint32_t color)
{
  for (int j = 0; j < window_height; j++)
  {
    for (int i = 0; i < window_width; i++)
    {
      int index = (window_width * j) + i;
      color_buffer[index] = color;
    }
  }
}

void render_color_buffer()
{
  SDL_UpdateTexture(color_buffer_texture, NULL, color_buffer, sizeof(uint32_t) * window_width);
  SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL);
}

void display_grid()
{
  for (int j = 0; j < window_height; j+=10)
  {
    for (int i = 0; i < window_width; i+=10)
    {
      color_buffer[(window_width * j) + i] = 0xFF333333;
    }
  }
}

void draw_rectangle(int x, int y, int width, int height, uint32_t color)
{
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      int current_x = i + x;
      int current_y = j + y;
      draw_pixel(current_x, current_y, color);
    }
  }
}

void draw_pixel(int x, int y, uint32_t color)
{
  if (x < 0 || x > window_width || y < 0 || y > window_height)
    return;

  color_buffer[(window_width * y) + x] = color;
}

void destroy_window()
{
  free(color_buffer);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
