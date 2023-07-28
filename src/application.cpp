//
// Created by paul on 28/07/23.
//

#include <iostream>
#include "../include/application.h"

Application::Application(const int _WINDOW_WIDTH, const int _WINDOW_HEIGHT) {
    isRunning = true;
    window = NULL;
    renderer = NULL;

    WINDOW_WIDTH = _WINDOW_WIDTH;
    WINDOW_HEIGHT = _WINDOW_HEIGHT;
}

bool Application::init(){
    //SDL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error during SDL initialization: " << SDL_GetError() << std::endl;
        return false;
    }

    //window creation
    window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Error during window creation : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    //render creation
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Error during renderer creation : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}

void Application::onEvent(SDL_Event* event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
}

void Application::render(Particles& particles) {
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

int Application::execute(){
    Particles particles(100, -1);

    SDL_Event event;

    if (!init()) {
        return -1;
    }

    Uint32 previousTime = 0;

    //Event handling loop
    while (isRunning) {

        //delta time
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - previousTime) / 1000.0f; // Conversion en secondes
        previousTime = currentTime;

        while (SDL_PollEvent(&event) != 0) {
            onEvent(&event);
        }

        particles.update(deltaTime);

        render(particles);
    }
    exit();
}

void Application::exit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}