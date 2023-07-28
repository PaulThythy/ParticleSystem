//
// Created by paul on 28/07/23.
//

#ifndef PARTICLESYSTEM_APPLICATION_H
#define PARTICLESYSTEM_APPLICATION_H

#ifdef _WIN32
    #include <SDL.h>
#elif __linux__
    #include <SDL2/SDL.h>
#endif

#include "../include/particles.h"

class Application {
private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;

public:
    Application(const int _WINDOW_WIDTH, const int _WINDOW_HEIGHT);

    int execute();
    bool init();
    void onEvent(SDL_Event* event);
    void render(Particles& particles);
    void exit();
};

#endif //PARTICLESYSTEM_APPLICATION_H
