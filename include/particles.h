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
    //in the case
    int max_particles_per_type = 30;

    //version with a number of particles per type
    Particles(int nb_types_particles, int nb_particles_per_type);
    //version with a random number of particles per type
    Particles(int nb_types_particles);

    const std::vector<Particle> &getVector() const;
    void update(float deltaTime);
    bool checkCollision(const Particle& otherParticle);
};

#endif //PARTICLESYSTEM_PARTICLES_H
