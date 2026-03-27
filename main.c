#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "src/defines.h"
#include "src/video.h"

int main() {
  SDL_Window *pwindow = NULL;
  SDL_Renderer *prenderer = NULL;
  SDL_Texture *menutexture = NULL;

  // Initialize video subsystem
  if (!initVideo(&pwindow, &prenderer)) {
    fprintf(stderr, "Error: Unable to setup SDL video\n");
    endVideo(prenderer, pwindow);
    return EXIT_FAILURE;
  }

  // Load and convert image to texture
  SDL_Surface *mainMenu = IMG_Load("assets/Sprites.png");
  if (!mainMenu) {
    fprintf(stderr, "Error: Unable to load image: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  menutexture = SDL_CreateTextureFromSurface(prenderer, mainMenu);
  SDL_FreeSurface(mainMenu);

  if (!menutexture) {
    fprintf(stderr, "Error: Unable to create texture: %s\n", SDL_GetError());
    endVideo(prenderer, pwindow);
    return EXIT_FAILURE;
  }

  // Main game loop
  SDL_Event e;
  int quit = 0;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
    }

    // Clear screen
    SDL_RenderClear(prenderer);

    // Crop from image
    SDL_Rect src = {.x = 0, .y = 0, .w = HEIGHT, .h = WIDTH};

    // Destination on screen
    SDL_Rect dest = {.x = 0, .y = 0, .w = HEIGHT * RES, .h = WIDTH * RES};

    SDL_RenderCopy(prenderer, menutexture, &src, &dest);

    // Present rendered frame
    SDL_RenderPresent(prenderer);
  }

  // Cleanup resources
  SDL_DestroyTexture(menutexture);
  SDL_DestroyRenderer(prenderer);
  SDL_DestroyWindow(pwindow);
  SDL_Quit();

  return EXIT_SUCCESS;
}
