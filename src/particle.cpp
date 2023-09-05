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
void Particle::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    drawCircle(renderer, getPosition().getX(), getPosition().getY(), radius);
}

Vector2& Particle::getPosition() { return position; }
Vector2& Particle::getPrevPosition() { return prevPosition; }
Vector2& Particle::getVelocity() { return velocity; }
Vector2& Particle::getAcceleration() { return acceleration; }
float Particle::getRadius() { return radius; }
int Particle::getRed() { return red; }
int Particle::getGreen() { return green; }
int Particle::getBlue() { return blue; }
float Particle::getMass() { return mass; }

void Particle::setPosition(Vector2& _position) { position = _position; }
void Particle::setPrevPosition(Vector2& _prevPosition) { prevPosition = _prevPosition; }
void Particle::setVelocity(Vector2& _velocity) { velocity = _velocity; }
void Particle::setAcceleration(Vector2& _acceleration) { acceleration = _acceleration; }
void Particle::setRadius(float _radius) { radius = _radius; }
void Particle::setRed(int _red) { red = _red; }
void Particle::setGreen(int _green) { green = _green; }
void Particle::setBlue(int _blue) { blue = _blue; }
void Particle::setMass(float _mass) { mass = _mass; }