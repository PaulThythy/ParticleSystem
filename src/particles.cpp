//
// Created by paul on 18/07/23.
//

#include "../include/particles.h"
#include "../include/particle.h"
#include "../include/constants.h"
#include <time.h>
#include <cmath>

const int MAX_PARTICLES_PER_TYPE = 50;

Particles::Particles(int nb_types_particles, int nb_particles_per_type){
    srand(time(NULL));

    int nb_particles;

    for(int i=0;i<nb_types_particles;i++){
        float randSpeed = static_cast<float>(rand() % 200 + 50);
        float randRadius = static_cast<float>(rand() % 7 + 1.0);
        float randWeight = static_cast<float>(rand() % 20 + 1.0);
        int randRed = rand() % 255;
        int randGreen = rand() % 255;
        int randBlue = rand() % 255;

        if(nb_particles_per_type <= 0){
            nb_particles = rand() % MAX_PARTICLES_PER_TYPE + 1;
        }else{
            nb_particles = nb_particles_per_type;
        }

        for(int j=0;j<nb_particles;j++){
            float randX = static_cast<float>(rand() % WINDOW_WIDTH + randRadius);
            float randY = static_cast<float>(rand() % WINDOW_HEIGHT + randRadius);
            float randDirection = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0 * M_PI;

            Particle particle(randX, randY, randSpeed, randDirection, randRadius, randRed, randGreen, randBlue, randWeight);
            particles.push_back(particle);
        }
    }
}

//method to update a particle
void Particles::update(float deltaTime) {

    for(Particle& particle : particles){

        //update position with speed using the delta time
        float nextX = particle.x + particle.speed * std::cos(particle.direction) * deltaTime;
        float nextY = particle.y + particle.speed * std::sin(particle.direction) * deltaTime;

        //collisions with window edges
        if (nextX - particle.radius < 0) {
            particle.x = particle.radius;
            particle.direction = M_PI - particle.direction;
        } else if (nextX + particle.radius > WINDOW_WIDTH) {
            particle.x = WINDOW_WIDTH - particle.radius;
            particle.direction = M_PI - particle.direction;
        } else {
            particle.x = nextX;
        }

        if (nextY - particle.radius < 0) {
            particle.y = particle.radius;
            particle.direction = -particle.direction;
        } else if (nextY + particle.radius > WINDOW_HEIGHT) {
            particle.y = WINDOW_HEIGHT - particle.radius;
            particle.direction = -particle.direction;
        } else {
            particle.y = nextY;
        }
    }
}


//check collisions with other particles
/*bool Particles::checkCollision(const Particle &otherParticle) {
    float dx = otherParticle.x - x;
    float dy = otherParticle.y - y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSquared = radius * radius;
    return distanceSquared <= radiusSquared;
}*/

const std::vector<Particle> &Particles::getVector() const {
    return particles;
}