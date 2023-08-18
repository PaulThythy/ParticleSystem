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

class Particle{
private:
    float x;
    float y;

    float speed;
    float acceleration;
    float direction;

    float radius;

    int red;
    int green;
    int blue;

    float weight;

    void drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const;

public:
    Particle(float _x, float _y, float _speed, float _direction,
            const float _radius, const int _red, const int _green, const int _blue,
            const float _weight):
            x(_x), y(_y), speed(_speed), direction(_direction), radius(_radius), red(_red), green(_green), blue(_blue), weight(_weight){}

    void draw(SDL_Renderer* max_particles_per_typerenderer) const;

    //getters
    float getX();
    float getY();
    float getSpeed();
    float getAcceleration();
    float getDirection();
    float getRadius();
    int getRed();
    int getGreen();
    int getBlue();
    float getWeight();

    //setters
    void setX(float _x);
    void setY(float _y);
    void setSpeed(float _speed);
    void setAcceleration(float _acceleration);
    void setDirection(float _direction);
    void setRadius(float _radius);
    void setRed(int _red);
    void setGreen(int _green);
    void setBlue(int _blue);
    void setWeight(float _weight);

};

#endif //PARTICLESYSTEM_PARTICLE_H
