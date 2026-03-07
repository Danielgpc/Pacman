#include "video.h"
#include "defines.h"
#include <SDL2/SDL.h>

int initVideo(SDL_Window **pwindow, SDL_Renderer **prenderer) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("Error: Unable to initialize SDL Video: %s", SDL_GetError());
    return 0;
  }

  if (IMG_Init(IMG_INIT_PNG) < 0) {
    SDL_Log("Error: Unable to initialize SDL Image: %s", SDL_GetError());
    SDL_Quit();
    return 0;
  }

  *pwindow = SDL_CreateWindow(
      "Pacman",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      WIDTH,
      HEIGHT,
      0);

  if (!*pwindow) {
    SDL_Log("Error: Window could not be created: %s", SDL_GetError());
    SDL_Quit();
    return 0;
  }

  *prenderer = SDL_CreateRenderer(*pwindow, -1, 0);
  if (!*prenderer) {
    SDL_Log("Error: Renderer could not be created: %s", SDL_GetError());
    SDL_DestroyWindow(*pwindow);
    SDL_Quit();
    return 0;
  }

  return 1;
}

void endVideo(SDL_Renderer *prenderer, SDL_Window *pwindow) { 
    SDL_DestroyRenderer(prenderer);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}
