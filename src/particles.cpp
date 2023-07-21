//
// Created by paul on 18/07/23.
//

#include "../include/particles.h"
#include "../include/particle.h"
#include "../include/constants.h"
#include <time.h>

Particles::Particles(int nb_types_particles, int nb_particles_per_type){
    srand(time(NULL));

    for(int i=0;i<nb_types_particles;i++){
        float randVelX = rand() % 200 + 50;
        float randVelY = rand() % 200 + 50;
        float randRadius = rand() % 5 + 0.5;
        int randRed = rand() % 255;
        int randGreen = rand() % 255;
        int randBlue = rand() % 255;

        // Calculate weight based on the square of the radius
        float minRadius = 0.5; // Minimum allowed radius to avoid division by zero
        float normalizedRadius = (randRadius - minRadius) / (5.0 - minRadius); // Normalize randRadius between 0 and 1
        float randWeight = 10.0 * normalizedRadius * normalizedRadius + 1; // Weight proportional to the square of the normalized radius

        for(int j=0;j<nb_particles_per_type;j++){
            float randX = rand() % WINDOW_WIDTH + randRadius;
            float randY = rand() % WINDOW_HEIGHT + randRadius;

            Particle particle(randX, randY, randVelX, randVelY, randRadius, randRed, randGreen, randBlue, randWeight);
            particles.push_back(particle);
        }
    }
}

Particles::Particles(int nb_types_particles){
    srand(time(NULL));

    for(int i=0;i<nb_types_particles;i++){
        int nb_particles = rand() % max_particles_per_type + 1;

        float randVelX = rand() % 200 + 50;
        float randVelY = rand() % 200 + 50;
        float randRadius = rand() % 5 + 0.5;
        int randRed = rand() % 255;
        int randGreen = rand() % 255;
        int randBlue = rand() % 255;

        // Calculate weight based on the square of the radius
        float minRadius = 0.5; // Minimum allowed radius to avoid division by zero
        float normalizedRadius = (randRadius - minRadius) / (5.0 - minRadius); // Normalize randRadius between 0 and 1
        float randWeight = 10.0 * normalizedRadius * normalizedRadius + 1; // Weight proportional to the square of the normalized radius

        for(int j=0;j<max_particles_per_type;j++){
            float randX = rand() % WINDOW_WIDTH + randRadius;
            float randY = rand() % WINDOW_HEIGHT + randRadius;

            Particle particle(randX, randY, randVelX, randVelY, randRadius, randRed, randGreen, randBlue, randWeight);
            particles.push_back(particle);
        }
    }
}


//method to update a particle
void Particles::update(float deltaTime) {

    for(Particle& particle : particles){

        //update position with speed using the delta time
        float nextX = particle.x + static_cast<float>(particle.velX * deltaTime);
        float nextY = particle.y + static_cast<float>(particle.velY * deltaTime);

        //collisions with window edges
        if (nextX - particle.radius < 0) {
            particle.x = particle.radius;
            particle.velX = -particle.velX;
        } else if (nextX + particle.radius > WINDOW_WIDTH) {
            particle.x = WINDOW_WIDTH - particle.radius;
            particle.velX = -particle.velX;
        } else {
            particle.x = nextX;
        }

        if (nextY - particle.radius < 0) {
            particle.y = particle.radius;
            particle.velY = -particle.velY;
        } else if (nextY + particle.radius > WINDOW_HEIGHT) {
            particle.y = WINDOW_HEIGHT - particle.radius;
            particle.velY = -particle.velY;
        } else {
            particle.y = nextY;
        }
    }
}


//check collisions with other particles
bool Particles::checkCollision(const Particle &otherParticle) {
    /*float dx = otherParticle.x - x;
    float dy = otherParticle.y - y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSquared = radius * radius;
    return distanceSquared <= radiusSquared;*/
}

const std::vector<Particle> &Particles::getVector() const {
    return particles;
}