//
// Created by paul on 28/07/23.
//

#include <iostream>
#include <thread>

#include "../include/application.h"

int G_WINDOW_WIDTH;
int G_WINDOW_HEIGHT;

//unsigned int G_NUMBER_OF_CORES = std::thread::hardware_concurrency();

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

    if(full_screen) {
        //window creation
        SDL_DisplayMode dm;
        if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
            SDL_Log("Erreur lors de la récupération du mode d'affichage : %s", SDL_GetError());
            SDL_Quit();
            return 1;
        }
        SDL_GetDesktopDisplayMode(0, &dm);
        app_window_width = dm.w;
        app_window_height = dm.h;

        window = SDL_CreateWindow("SDL Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  app_window_width, app_window_height, SDL_WINDOW_FULLSCREEN);
    }
    else{
        window = SDL_CreateWindow("SDL Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  app_window_width, app_window_height, SDL_WINDOW_SHOWN);
    }

    if (window == nullptr) {
        std::cout << "Error during window creation : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    G_WINDOW_WIDTH = app_window_width;
    G_WINDOW_HEIGHT = app_window_height;

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
    for (Particle particle : particles.getVector()) {
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

    Particles particles(1000, 1);

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

        particles.updateAll(deltaTime);

        render(particles);
    }
    exit();
    return 0;
}

void Application::exit(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}