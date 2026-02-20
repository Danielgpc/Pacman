#include"video.h"

#include"defines.h"

int initVideo(SDL_Window** pwindow, SDL_Renderer** prenderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }

    *pwindow = SDL_CreateWindow(
        "Pacman", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WIDTH, 
        HEIGHT, 
        0
    );
    if (!*pwindow) {
        // Handle window creation error
        SDL_Log("Window could not be created: %s", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    *prenderer = SDL_CreateRenderer(*pwindow, -1, 0);
    if (!*prenderer) {
        // Handle window creation error
        SDL_Log("Renderer could not be created: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    return 1;
}