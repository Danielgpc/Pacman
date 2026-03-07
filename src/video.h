#ifndef VIDEO_H
#define VIDEO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int initVideo(SDL_Window **pwindow, SDL_Renderer **prenderer);
void endVideo(SDL_Renderer *prenderer, SDL_Window *pwindow);

#endif
