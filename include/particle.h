//
// Created by paul on 18/07/23.
//

#ifndef PARTICLESYSTEM_PARTICLE_H
#define PARTICLESYSTEM_PARTICLE_H

#include <SDL2/SDL.h>

class Particle{
private:
    float x;
    float y;

    float velX;
    float velY;

    const float radius;

    const int red;
    const int green;
    const int blue;

    const float weight;

    void drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const;

public:
    Particle(float _x, float _y, float _velX, float _velY,
            const float _radius, const int _red, const int _green, const int _blue,
            const float _weight):
            x(_x), y(_y), velX(_velX), velY(_velY), radius(_radius), red(_red), green(_green), blue(_blue), weight(_weight){}

    void update(float deltaTime);

    bool checkCollision(const Particle& otherParticle);

    void draw(SDL_Renderer* renderer) const;
};

#endif //PARTICLESYSTEM_PARTICLE_H
