#include "renderer.h"

void PutPixel(int x, int y, color drawColor, SDL_Renderer* renderer, int screenWidth, int screenHeight) {
    SDL_SetRenderDrawColor(renderer, drawColor.r, drawColor.g, drawColor.b, 255);
    SDL_RenderDrawPoint(renderer, (screenWidth/2) + x, (screenHeight / 2) - y);
}

void DrawLine(point P0, point P1, color drawColor, SDL_Renderer* renderer, int screenWidth, int screenHeight) {
    // Make sure x0 < x1
    if (P0.x > P1.x) {
        point temp = P0;
        P0 = P1;
        P1 = temp;
    }

    double a = (P1.y - P0.y) / (P1.x - P0.x);
    int y = P0.y;
    for (int x = P0.x; x <= P1.x; x++) {
        PutPixel(x, y, drawColor, renderer, screenWidth, screenHeight);
        y = y + a;
    }
}
