//
// Created by paul on 18/07/23.
//

#ifndef PARTICLESYSTEM_PARTICLE_H
#define PARTICLESYSTEM_PARTICLE_H

#ifdef _WIN32
        #include <SDL.h>
#elif __linux__
        #include <SDL2/SDL.h>
#endif

#include "../include/vector2.h"

class Particle{
private:
    float x;
    float y;

    Vector2 velocity;
    Vector2 acceleration;

    float radius;

    int red;
    int green;
    int blue;

    float weight;

    void drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const;

public:
    Particle(float _x, float _y, Vector2 _velocity, Vector2 _acceleration, const float _radius, 
                const int _red, const int _green, const int _blue, const float _weight):
            x(_x), y(_y), velocity(_velocity), acceleration(_acceleration), radius(_radius), red(_red), green(_green), blue(_blue), weight(_weight){}

    void draw(SDL_Renderer* max_particles_per_typerenderer) const;

    //getters
    float getX();
    float getY();
    Vector2 getVelocity();
    Vector2 getAcceleration();
    float getRadius();
    int getRed();
    int getGreen();
    int getBlue();
    float getWeight();

    //setters
    void setX(float _x);
    void setY(float _y);
    void setVelocity(Vector2 _velocity);
    void setAcceleration(Vector2 _acceleration);
    void setRadius(float _radius);
    void setRed(int _red);
    void setGreen(int _green);
    void setBlue(int _blue);
    void setWeight(float _weight);

};

#endif //PARTICLESYSTEM_PARTICLE_H
