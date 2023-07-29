//
// Created by paul on 18/07/23.
//

#include "../include/particle.h"

//method to draw a circle
void Particle::drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const{
    for (int y = -_radius; y <= _radius; y++) {
        for (int x = -_radius; x <= _radius; x++) {
            if (x * x + y * y <= _radius * _radius) {
                SDL_RenderDrawPoint(renderer, _x + x, _y + y);
            }
        }
    }
}

//draw a particle
void Particle::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    drawCircle(renderer, x, y, radius);
}