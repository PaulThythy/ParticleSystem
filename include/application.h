//
// Created by paul on 28/07/23.
//

#ifndef PARTICLESYSTEM_APPLICATION_H
#define PARTICLESYSTEM_APPLICATION_H

extern int G_WINDOW_WIDTH;
extern int G_WINDOW_HEIGHT;

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

    int app_window_width;
    int app_window_height;

    bool full_screen=false;

public:
    Application(const int _app_window_width, const int _app_window_height);
    Application();

    int execute();
    bool init();
    void onEvent(SDL_Event* event);
    void render(Particles& particles);
    void exit();
};

#endif //PARTICLESYSTEM_APPLICATION_H
