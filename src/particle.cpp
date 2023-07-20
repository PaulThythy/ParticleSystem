//
// Created by paul on 18/07/23.
//

#include "../include/particle.h"
#include "../include/constants.h"

// Méthode pour dessiner un cercle
void Particle::drawCircle(SDL_Renderer* renderer, float _x, float _y, float _radius) const{
    for (int y = -_radius; y <= _radius; y++) {
        for (int x = -_radius; x <= _radius; x++) {
            if (x * x + y * y <= _radius * _radius) {
                SDL_RenderDrawPoint(renderer, _x + x, _y + y);
            }
        }
    }
}

// Méthode pour mettre à jour la particule
void Particle::update(float deltaTime) {
    // Mettre à jour la position avec la vitesse
    float nextX = x + static_cast<float>(velX * deltaTime);
    float nextY = y + static_cast<float>(velY * deltaTime);

    // Gestion des collisions avec les bords de la fenêtre en rebondissant
    if (nextX - radius < 0) {
        x = radius;
        velX = -velX;
    } else if (nextX + radius > WINDOW_WIDTH) {
        x = WINDOW_WIDTH - radius;
        velX = -velX;
    } else {
        x = nextX;
    }

    if (nextY - radius < 0) {
        y = radius;
        velY = -velY;
    } else if (nextY + radius > WINDOW_HEIGHT) {
        y = WINDOW_HEIGHT - radius;
        velY = -velY;
    } else {
        y = nextY;
    }
}


// Méthode pour vérifier les collisions avec une autre particule
bool Particle::checkCollision(const Particle &otherParticle) {
    int dx = otherParticle.x - x;
    int dy = otherParticle.y - y;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSquared = radius * radius;
    return distanceSquared <= radiusSquared;
}

// Méthode pour dessiner la particule
void Particle::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    drawCircle(renderer, x, y, radius);
}