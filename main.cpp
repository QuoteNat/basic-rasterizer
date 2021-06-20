#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "primitives.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const color BACKGROUND = {255, 255, 255};


int main()
{
    SDL_Event event;
    bool quit = false;

    // create window and renderer
    SDL_Window *window = SDL_CreateWindow("Basic Rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 2, 0);

    // line points

    // render the image
    std::cout << BACKGROUND.r << ", " << BACKGROUND.g  << ", " << BACKGROUND.b << std::endl;
    bool success = SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    std::cout << success << std::endl;

    success = SDL_RenderClear(renderer);
    std::cout << success << std::endl;

    DrawFilledTriangle({-200, -250}, {200, 50}, {20, 250}, {0, 255, 0}, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    DrawWireframeTriangle({-200, -250}, {200, 50}, {20, 250}, {0, 0, 0}, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_RenderPresent(renderer);

    // keep window open until it is quit
    while (!quit) {
        SDL_WaitEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }
        SDL_RenderPresent(renderer);
    }

    //cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
