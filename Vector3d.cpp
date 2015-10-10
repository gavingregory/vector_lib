#include "Vector3d.h"
#include <cmath>

using namespace std;

// TODO: check input to sqrt is not negative

// TODO: divide scalar. remember to check for divide by 0.

Vector3dStack::Vector3dStack(float x, float y, float z):
  POWER(2) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3dStack::Vector3dStack(const Vector3dStack& copy_from):
  POWER(2) {
  // TODO: fill in this copy constructor
}

Vector3dStack::~Vector3dStack() { }

float Vector3dStack::get_x() const {
  return x;
}

float Vector3dStack::get_y() const {
  return y;
}

float Vector3dStack::get_z() const {
  return z;
}

void Vector3dStack::set_x(const float x) {
  this->x = x;
}

void Vector3dStack::set_y(const float y) {
  this->y = y;
}

void Vector3dStack::set_z(const float z) {
  this->z = z;
}

float Vector3dStack::get_magnitude() const {
  return sqrt(pow(x, POWER) + pow(y, POWER) + pow(z, POWER));
}

void Vector3dStack::add(const Vector3dStack& rhs) {
  x += rhs.get_x();
  y += rhs.get_y();
  z += rhs.get_z();
}

void Vector3dStack::subtract(const Vector3dStack& rhs) {
  x -= rhs.get_x();
  y -= rhs.get_y();
  z -= rhs.get_z();
}

void Vector3dStack::multiply(const float scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;
}

void Vector3dStack::divide(const float scalar) {
  x /= scalar;
  y /= scalar;
  z /= scalar;
}

