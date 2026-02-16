#include <stdio.h>
#include <SDL2/SDL.h>

#include "consts.h"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* pwindow = SDL_CreateWindow(
        "Pacman", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WIDTH, 
        HEIGHT, 
        0
    );
    if (!pwindow) {
        // Handle window creation error
        SDL_Log("Window could not be created: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            // Add other event handling here (keyboard, mouse, etc.)
        }
        // Add rendering code here
    }

    SDL_DestroyWindow(pwindow);
    SDL_Quit();

    return EXIT_SUCCESS;
}