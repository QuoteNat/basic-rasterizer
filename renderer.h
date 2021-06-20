#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include "primitives.h"

/**
 * @brief PutPixel Draws a pixel to the window
 * @param x The x position of the pixel
 * @param y The y position of the pixel
 * @param drawColor The color of the pixel in RGB
 * @param renderer The renderer
 * @param screenWidth The width of the screen in pixels
 * @param screenHeight The height of the screen in pixels
 */
void PutPixel(int x, int y, color drawColor, SDL_Renderer *renderer, int screenWidth, int screenHeight);

/**
 * @brief DrawLine Draws a line between two points
 * @param P0 The first point
 * @param P1 The second point
 * @param drawColor The draw color in RG
 * @param renderer The renderer
 * @param screenWidth The width of the screen in pixels
 * @param screenHeight The height of the screen in pixels
 */
void DrawLine(point P0, point P1, color drawColor, SDL_Renderer *renderer, int screenWidth, int screenHeight);

#endif // RENDERER_H
