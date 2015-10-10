#include "Vector3d.h"
#include <cmath>

using namespace std;

// TODO: check input to sqrt is not negative

// TODO: divide scalar. remember to check for divide by 0.

Vector3dStack::Vector3dStack(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3dStack::Vector3dStack(const Vector3dStack& copy_from) {
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
  static const int POWER = 2;
  return sqrt(pow(x, POWER) + pow(y, POWER) + pow(z, POWER));
}

Vector3dStack Vector3dStack::add(const Vector3dStack& rhs) const {
  return Vector3dStack(x + rhs.get_x(), y + rhs.get_y(), z + rhs.get_z());
}

Vector3dStack Vector3dStack::subtract(const Vector3dStack& rhs) const {
  return Vector3dStack(x - rhs.get_x(), y - rhs.get_y(), z - rhs.get_z());
}

Vector3dStack Vector3dStack::multiply(const float scalar) const {
  return Vector3dStack(x*scalar, y*scalar, z*scalar);
}

Vector3dStack Vector3dStack::divide(const float scalar) const {
  return Vector3dStack(x/scalar, y/scalar, z/scalar);
}

Vector3dStack Vector3dStack::vector_product(const Vector3dStack& rhs) const {
  return Vector3dStack(
    y*rhs.get_z() - z*rhs.get_y(),
    z*rhs.get_x() - x*rhs.get_z(),
    x*rhs.get_y() - y*rhs.get_x()
  );
}

float Vector3dStack::scalar_product(const Vector3dStack& rhs) const {
  return ((x * rhs.get_x()) + (y * rhs.get_y()) + (z * rhs.get_z()));
}

Vector3dStack Vector3dStack::unit_vector() const {
  return Vector3dStack(
    x/get_magnitude(),
    y/get_magnitude(),
    z/get_magnitude()
  );
}

