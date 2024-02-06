//
// Created by paul on 18/07/23.
//

#include "../include/particle.h"
#include "../include/application.h"

//y axis inverted
Vector2 G_GRAVITY(0.0f, 9.81);

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
    drawCircle(renderer, position.getX(), position.getY(), radius);
}

void Particle::update(float deltaTime) {
    Vector2 acc = G_GRAVITY/getMass();

    //updating position using verlet integration
    float nextX = position.getX() + velocity.getX() * deltaTime + ((deltaTime * deltaTime)/2) * acceleration.getX();
    float nextY = position.getY() + velocity.getY() * deltaTime + ((deltaTime * deltaTime)/2) * acceleration.getY();

    //updating velocity
    float nextVelX = velocity.getX() + (deltaTime/2) * acceleration.getX() + acceleration.getX();
    float nextVelY = velocity.getY() + (deltaTime/2) * acceleration.getY() + acceleration.getY();

    Vector2 nextVel(nextVelX, nextVelY);
    setVelocity(nextVel);

    //updating acceleration
    setAcceleration(acc);

    //collisions with window edges
    if (nextX - radius < 0) {
        position.setX(radius);
        velocity.setX(-velocity.getX());

    } else if (nextX + radius > G_WINDOW_WIDTH) {
        position.setX(G_WINDOW_WIDTH - radius);
        velocity.setX(-velocity.getX());

    } else {
        position.setX(nextX);
    }

    if (nextY - radius < 0) {
        position.setY(radius);
        velocity.setY(-velocity.getY());

    } else if (nextY + radius > G_WINDOW_HEIGHT) {
        position.setY(G_WINDOW_HEIGHT - radius);
        velocity.setY(-velocity.getY());

    } else {
        position.setY(nextY);
    }
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