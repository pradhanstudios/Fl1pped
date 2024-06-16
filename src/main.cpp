#include <SDL2/SDL.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);


    
    const int width = 800;
    const int height = 800;

    SDL_Window *window = SDL_CreateWindow(
        "Fl1pped",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        0
    );


    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    const unsigned int background_color = SDL_MapRGB(window_surface->format,
        68, // R
        85, // G
        90  // B
    );

    SDL_FillRect(window_surface, nullptr, background_color);

    SDL_Event e;
    bool open = true;
    while (open)
    {
        SDL_PollEvent(&e);

        if (e.type == SDL_QUIT) {
            open = false;
        }

        SDL_UpdateWindowSurface(window);
    }

    SDL_Quit();
}