//
// Created by paul on 18/07/23.
//

#include "../include/particles.h"
#include "../include/particle.h"
#include "../include/application.h"
#include <time.h>
#include <cmath>
#include <iostream>

const int MAX_PARTICLES_PER_TYPE = 50;

const int MIN_SPEED = 50;
const int MAX_SPEED = 200;

const int MIN_RADIUS = 1;
const int MAX_RADIUS = 7;

const int MIN_MASS = 1;
const int MAX_MASS = 20;

Particles::Particles(int nb_types_particles, int nb_particles_per_type){
    srand(time(NULL));

    int nb_particles;

    for(int i=0;i<nb_types_particles;i++){
        float randSpeed = static_cast<float>(rand() % MAX_SPEED + MIN_SPEED);
        float randRadius = static_cast<float>(rand() % MAX_RADIUS + MIN_RADIUS);
        float randMass = static_cast<float>(rand() % MAX_MASS + MIN_MASS);
        int randRed = rand() % 255;
        int randGreen = rand() % 255;
        int randBlue = rand() % 255;

        if(nb_particles_per_type <= 0){
            nb_particles = rand() % MAX_PARTICLES_PER_TYPE + 1;
        }else{
            nb_particles = nb_particles_per_type;
        }

        for(int j=0;j<nb_particles;j++){
            float randX = static_cast<float>(rand() % G_WINDOW_WIDTH + randRadius);
            float randY = static_cast<float>(rand() % G_WINDOW_HEIGHT + randRadius);
            float randDirection = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0 * M_PI;

            Vector2 pos(randX, randY);
            Vector2 vel(static_cast<float>(std::cos(randDirection) * randSpeed), static_cast<float>(std::sin(randDirection) * randSpeed));

            Particle particle(pos, vel, randRadius, randRed, randGreen, randBlue, randMass);
            particles.push_back(particle);
        }
    }
}

//method to update a particle
void Particles::update(float deltaTime) {

    for(Particle& particle : particles){

        //update position with speed using the delta time
        float nextX = particle.getPosition().getX() + particle.getVelocity().getX() * deltaTime;
        float nextY = particle.getPosition().getY() + particle.getVelocity().getY() * deltaTime;

        //collisions with window edges
        if (nextX - particle.getRadius() < 0) {
            particle.getPosition().setX(particle.getRadius());
            particle.getVelocity().bounceX();

        } else if (nextX + particle.getRadius() > G_WINDOW_WIDTH) {
            particle.getPosition().setX(G_WINDOW_WIDTH - particle.getRadius());
            particle.getVelocity().bounceX();

        } else {
            particle.getPosition().setX(nextX);
        }

        if (nextY - particle.getRadius() < 0) {
            particle.getPosition().setY(particle.getRadius());
            particle.getVelocity().bounceY();

        } else if (nextY + particle.getRadius() > G_WINDOW_HEIGHT) {
            particle.getPosition().setY(G_WINDOW_HEIGHT - particle.getRadius());
            particle.getVelocity().bounceY();

        } else {
            particle.getPosition().setY(nextY);
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