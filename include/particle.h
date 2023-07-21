//
// Created by paul on 18/07/23.
//

#ifndef PARTICLESYSTEM_PARTICLE_H
#define PARTICLESYSTEM_PARTICLE_H

#include <SDL2/SDL.h>

class Particle{
private:
    const int red;
    const int green;
    const int blue;

    const float weight;

    void drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const;

public:
    float x;
    float y;

    float velX;
    float velY;

    const float radius;

    Particle(float _x, float _y, float _velX, float _velY,
            const float _radius, const int _red, const int _green, const int _blue,
            const float _weight):
            x(_x), y(_y), velX(_velX), velY(_velY), radius(_radius), red(_red), green(_green), blue(_blue), weight(_weight){}

    void draw(SDL_Renderer* max_particles_per_typerenderer) const;
};

#endif //PARTICLESYSTEM_PARTICLE_H
