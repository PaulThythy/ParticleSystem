//
// Created by paul on 21/08/23.
//

#include <iostream>
#include "../include/vector2.h"

void Vector2::setX(const float _x) { x = _x; }
void Vector2::setY(const float _y) { y = _y; }

float Vector2::getX() { return x; }
float Vector2::getY() { return y; }

void Vector2::bounceX() { x = -x; }
void Vector2::bounceY() { y = -y; }