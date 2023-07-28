#ifdef _WIN32
	#include <SDL.h>
#elif __linux__
	#include <SDL2/SDL.h>
#endif

#include <iostream>
#include "../include/constants.h"
#include "../include/particles.h"

const int WINDOW_WIDTH = 1100;
const int WINDOW_HEIGHT = 650;

void render(SDL_Renderer* renderer, Particles particles) {
    //screen cleaning
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //drawing particles
    for (const Particle& particle : particles.getVector()) {
        particle.draw(renderer);
    }

    //screen update
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    //SDL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error during SDL initialization: " << SDL_GetError() << std::endl;
        return 1;
    }

    //window creation
    SDL_Window* window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Error during window creation : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    //render creation
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Error during renderer creation : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Particles particles(100, -1);

    Uint32 previousTime = 0;
    //Event handling loop
    bool quit = false;
    SDL_Event event;
    while (!quit) {

        //delta time
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - previousTime) / 1000.0f; // Conversion en secondes
        previousTime = currentTime;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        //particle update
        particles.update(deltaTime);

        //render particles
        render(renderer, particles);
    }

    //free up resources and leave SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
