#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "../include/constants.h"
#include "../include/particle.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

std::vector<Particle> particles;

void render(SDL_Renderer* renderer) {
    //screen cleaning
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //drawing particles
    for (const Particle& particle : particles) {
        particle.draw(renderer);
    }

    //screen update
#include "../include/constants.h"
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    //SDL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    //window creation
    SDL_Window* window = SDL_CreateWindow("Simulateur de particules", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Erreur lors de la création de la fenêtre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    //render creation
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Erreur lors de la création du rendu : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    srand(time(NULL));

    for(int i=0;i<1000;i++) {
        float randX = rand() % WINDOW_WIDTH + 1.5;
        float randY = rand() % WINDOW_HEIGHT + 1.5;
        float randVelX = rand() % 200 + 50;
        float randVelY = rand() % 200 + 50;
        int randRed = rand() % 255;
        int randGreen = rand() % 255;
        int randBlue = rand() % 255;

        Particle particle(randX, randY, randVelX, randVelY, 1.5, randRed, randGreen, randBlue, 10);
        particles.push_back(particle);
    }

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
        for (Particle& particle : particles) {
            particle.update(deltaTime);
        }

        //render particles
        render(renderer);
    }

    //free up resources and leave SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}