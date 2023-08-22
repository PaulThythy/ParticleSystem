//
// Created by paul on 21/08/23.
//

#ifndef PARTICLESYSTEM_VECTOR2_H
#define PARTICLESYSTEM_VECTOR2_H

#include <iostream>

class Vector2{
private:
    float x;
    float y;

public:
    Vector2(const float _x, const float _y): x(_x), y(_y) {}
    Vector2(): x(0.0f), y(0.0f){}

    void setX(const float _x);
    void setY(const float _y);
    
    float getX();
    float getY();

    void bounceX();
    void bounceY();

    float length();
    float length_squared();

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
    Vector2 operator+(Vector2& otherVect);
    Vector2 operator-(Vector2& otherVect);
    Vector2 operator*(Vector2& otherVect);
    
    Vector2 operator/(const float scalar);
    Vector2 operator*(const float scalar);
};

#endif //PARTICLESYSTEM_PARTICLES_H
