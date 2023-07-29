//
// Created by paul on 28/07/23.
//

#include <iostream>
#include "../include/application.h"

int WINDOW_WIDTH;
int WINDOW_HEIGHT;

Application::Application(const int _app_window_width, const int _app_window_height) {
    isRunning = true;
    window = NULL;
    renderer = NULL;

    app_window_width = _app_window_width;
    app_window_height = _app_window_height;
}

Application::Application(){
    isRunning = true;
    window = NULL;
    renderer = NULL;

    full_screen = true;
}

bool Application::init(){
    //SDL init
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error during SDL initialization: " << SDL_GetError() << std::endl;
        return false;
    }

    if(full_screen){
        SDL_DisplayMode dm;
        if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
            SDL_Log("Erreur lors de la récupération du mode d'affichage : %s", SDL_GetError());
            SDL_Quit();
            return 1;
        }
        //window creation
        window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                dm.w, dm.h, SDL_WINDOW_FULLSCREEN);
        WINDOW_WIDTH = dm.w;
        WINDOW_HEIGHT = dm.h;

    }
    else{
        window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                app_window_width, app_window_height, SDL_WINDOW_SHOWN);
        WINDOW_WIDTH = app_window_width;
        WINDOW_HEIGHT = app_window_height;
    }
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
    SDL_Event event;

    if (!init()) {
        return -1;
    }

    Particles particles(100, -1, WINDOW_WIDTH, WINDOW_HEIGHT);

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

        particles.update(deltaTime, WINDOW_WIDTH, WINDOW_HEIGHT);

        render(particles);
    }
    exit();
}

void Application::exit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}