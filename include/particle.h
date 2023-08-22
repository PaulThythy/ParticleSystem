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
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;

    float radius;

    int red;
    int green;
    int blue;

    float weight;
    //very small value because negligible
    float drag = 0.001; // rho (density) * C (drag coefficient) * Area (Area projected)

    void drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const;

public:
    Particle(Vector2& _position, Vector2& _velocity, Vector2& _acceleration, const float _radius,
                const int _red, const int _green, const int _blue, const float _weight):
            position(_position), velocity(_velocity), acceleration(_acceleration), radius(_radius), red(_red), green(_green), blue(_blue), weight(_weight){}

    void draw(SDL_Renderer* renderer);

    //getters
    Vector2& getPosition();
    Vector2& getVelocity();
    Vector2& getAcceleration();
    float getRadius();
    int getRed();
    int getGreen();
    int getBlue();
    float getWeight();
    float getDrag();

    //setters
    void setPosition(Vector2& _position);
    void setVelocity(Vector2& _velocity);
    void setAcceleration(Vector2& _acceleration);
    void setRadius(float _radius);
    void setRed(int _red);
    void setGreen(int _green);
    void setBlue(int _blue);
    void setWeight(float _weight);
    void setDrag(float _drag);

};

#endif //PARTICLESYSTEM_PARTICLE_H
