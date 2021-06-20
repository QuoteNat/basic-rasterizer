#include "renderer.h"

void PutPixel(int x, int y, color drawColor, SDL_Renderer* renderer, int screenWidth, int screenHeight) {
    SDL_SetRenderDrawColor(renderer, drawColor.r, drawColor.g, drawColor.b, 255);
    SDL_RenderDrawPoint(renderer, (screenWidth/2) + x, (screenHeight / 2) - y);
}

/**
 * @brief Interpolate Interpolates the pixels to draw to from two point coordinates. i is the independent value and d is the dependent value.
 * @param i0 Independent point 1
 * @param d0 Dependent point 1
 * @param i1 Independent point 2
 * @param d1 Dependent point 2
 * @return
 */
std::vector<double> Interpolate(int i0, double d0, int i1, int d1) {
    std::vector<double> points;
    if (i0 == i1) {
        points.push_back(d0);
        return points;
    }
    double a = (d1-d0) / (i1-i0);
    double d = d0;
    for (int i=i0; i <= i1; i++) {
        points.push_back(d);
        d += a;
    }
    return points;
}

void DrawLine(point P0, point P1, color drawColor, SDL_Renderer* renderer, int screenWidth, int screenHeight) {
    double dx = P0.x - P1.x;
    double dy = P0.y - P1.y;
    if (std::abs(dx) > std::abs(dy)) {
        // Make sure x0 < x1
        if (P0.x > P1.x) {
            point temp = P0;
            P0 = P1;
            P1 = temp;
        }

        std::vector<double> ys = Interpolate(P0.x, P0.y, P1.x, P1.y);
        for (int x = P0.x; x <= P1.x; x++) {
            PutPixel(x, ys.at(x - P0.x), drawColor, renderer, screenWidth, screenHeight);
        }
    } else {
        // Make sure x0 < x1
        if (P0.y > P1.y) {
            point temp = P0;
            P0 = P1;
            P1 = temp;
        }

        std::vector<double> xs = Interpolate(P0.y, P0.x, P1.y, P1.x);
        for (int y = P0.y; y <= P1.y; y++) {
            PutPixel(xs.at(y - P0.y), y, drawColor, renderer, screenWidth, screenHeight);
        }
    }
}

void DrawWireframeTriangle(point P0, point P1, point P2, color drawColor, SDL_Renderer *renderer, int screenWidth, int screenHeight) {
    DrawLine(P0, P1, drawColor, renderer, screenWidth, screenHeight);
    DrawLine(P1, P2, drawColor, renderer, screenWidth, screenHeight);
    DrawLine(P2, P0, drawColor, renderer, screenWidth, screenHeight);
}
