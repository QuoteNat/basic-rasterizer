#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "primitives.h"

void PutPixel(int x, int y, color drawColor, SDL_Renderer *renderer, int screenWidth, int screenHeight);

void DrawLine(point P0, point P1, color drawColor, SDL_Renderer *renderer, int screenWidth, int screenHeight);

#endif // RENDERER_H
