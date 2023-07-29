//
// Created by paul on 18/07/23.
//

#ifndef PARTICLESYSTEM_PARTICLES_H
#define PARTICLESYSTEM_PARTICLES_H

#include "../include/particle.h"
#include <vector>

class Particles{
private:
    std::vector<Particle> particles;

public:
    //a random nb of particles per type if nb_particles_per_type = -1
    Particles(int nb_types_particles, int nb_particles_per_type, int WINDOW_WIDTH, int WINDOW_HEIGHT);

    const std::vector<Particle> &getVector() const;
    void update(float deltaTime, int WINDOW_WIDTH, int WINDOW_HEIGHT);
    bool checkCollision(const Particle& otherParticle);
};

#endif //PARTICLESYSTEM_PARTICLES_H
