//
// Created by paul on 21/08/23.
//

#include <iostream>
#include <cmath>
#include "../include/vector2.h"

void Vector2::setX(const float _x) { x = _x; }
void Vector2::setY(const float _y) { y = _y; }

float Vector2::getX() { return x; }
float Vector2::getY() { return y; }

void Vector2::bounceX() { x = -x; }
void Vector2::bounceY() { y = -y; }

float Vector2::length() {
    return std::sqrt(x * x + y * y);
}

float Vector2::length_squared(){
    return length() * length();
}

std::ostream& operator<<(std::ostream& os, const Vector2& v){
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

Vector2 Vector2::operator+(Vector2& otherVect) {
    return Vector2(x + otherVect.getX(), y + otherVect.getY());
}

Vector2 Vector2::operator-(Vector2& otherVect) {
    return Vector2(x - otherVect.getX(), y - otherVect.getY());
}

Vector2 Vector2::operator*(Vector2& otherVect) {
    return Vector2(x - otherVect.getX(), y - otherVect.getY());
}

Vector2 Vector2::operator/(const float scalar) {
    return Vector2(x / scalar, y / scalar);
}

Vector2 Vector2::operator*(const float scalar) {
    return Vector2(x * scalar, y * scalar);
}