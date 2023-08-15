//
// Created by paul on 18/07/23.
//

#include "../include/particle.h"

// method to draw a circle
void Particle::drawCircle(SDL_Renderer *renderer, float _x, float _y, float _radius) const
{
    for (int y = -_radius; y <= _radius; y++)
    {
        for (int x = -_radius; x <= _radius; x++)
        {
            if (x * x + y * y <= _radius * _radius)
            {
                SDL_RenderDrawPoint(renderer, _x + x, _y + y);
            }
        }
    }
}

// draw a particle
void Particle::draw(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    drawCircle(renderer, x, y, radius);
}

float Particle::getX() { return x; }
float Particle::getY() { return y; }
float Particle::getSpeed() { return speed; }
float Particle::getDirection() { return direction; }
float Particle::getRadius() { return radius; }
int Particle::getRed() { return red; }
int Particle::getGreen() { return green; }
int Particle::getBlue() { return blue; }
float Particle::getWeight() { return weight; }

void Particle::setX(float _x) { x = _x; }
void Particle::setY(float _y) { y = _y; }
void Particle::setSpeed(float _speed) { speed = _speed; }
void Particle::setDirection(float _direction) { direction = _direction; }
void Particle::setRadius(float _radius) { radius = _radius; }
void Particle::setRed(int _red) { red = _red; }
void Particle::setGreen(int _green) { green = _green; }
void Particle::setBlue(int _blue) { blue = _blue; }
void Particle::setWeight(float _weight) { weight = _weight; }