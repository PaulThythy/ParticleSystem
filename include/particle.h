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

#include "vector2.h"
#include "application.h"

//y axis inverted
Vector2 G_GRAVITY(0.0f, 9.81);

class Particle{
private:
    Vector2 position;
    Vector2 prevPosition;
    Vector2 velocity;
    Vector2 acceleration;

    float radius;

    int red;
    int green;
    int blue;

    float mass;

    void drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const;

public:
    Particle(Vector2& _position, Vector2& _velocity, const float _radius,
            const int _red, const int _green, const int _blue, const float _mass):
            position(_position), velocity(_velocity), radius(_radius), 
            red(_red), green(_green), blue(_blue), mass(_mass){}

    void draw(SDL_Renderer* renderer);

    void update(float deltaTime);

    //getters
    Vector2& getPosition();
    Vector2& getPrevPosition();
    Vector2& getVelocity();
    Vector2& getAcceleration();
    float getRadius();
    int getRed();
    int getGreen();
    int getBlue();
    float getMass();

    //setters
    void setPosition(Vector2& _position);
    void setPrevPosition(Vector2& _prevPosition);
    void setVelocity(Vector2& _velocity);
    void setAcceleration(Vector2& _acceleration);
    void setRadius(float _radius);
    void setRed(int _red);
    void setGreen(int _green);
    void setBlue(int _blue);
    void setMass(float _mass);

};

#endif //PARTICLESYSTEM_PARTICLE_H
