#include<stdio.h>
#include<SDL2/SDL.h>

#include"video.h"
#include"defines.h"

int main()
{
    SDL_Window* pwindow = NULL;
    SDL_Renderer* prenderer = NULL;

    if(!(initVideo(&pwindow, &prenderer)))
    {
        printf("Unable to setup SDL video\n");
    }

    SDL_Rect testRect = { 0, 0, TILE_WIDTH, TILE_HEIGHT };

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
        SDL_SetRenderDrawColor(prenderer, 255, 255, 255, 255);
        SDL_RenderClear(prenderer);

        SDL_SetRenderDrawColor(prenderer, 255, 0, 0, 255);
        SDL_RenderFillRect(prenderer, &testRect);

        SDL_RenderPresent(prenderer);
    }

    SDL_DestroyWindow(pwindow);
    SDL_DestroyRenderer(prenderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}