#include "Vector3d.h"
#include <cmath>

using namespace std;

Vector3dStack::Vector3dStack(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

/**
* Copy constructor is called when assigning to a new instance of object from another instance.
* This means it needs to create NEW variables instead of updating the old ones (as you would do
* overloading = operator
*/
Vector3dStack::Vector3dStack(const Vector3dStack& rhs) {
  this->x = rhs.x;
  this->y = rhs.y;
  this->z = rhs.z;
}

Vector3dStack::~Vector3dStack() { }

Vector3dStack& Vector3dStack::operator=(const Vector3dStack& rhs) {
  if (this == &rhs) return (*this);

  // assign new data
  x = rhs.get_x();
  y = rhs.get_y();
  z = rhs.get_z();
  return *this;
}

bool Vector3dStack::operator==(const Vector3dStack& rhs) {
  if (this == &rhs) return true;

  if (this->get_x() == rhs.get_x() &&
    this->get_y() == rhs.get_y() &&
    this->get_z() == rhs.get_z())
    return true;
  return false;
}

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

float Vector3dStack::magnitude() const {
  static const int POWER = 2;
  // no need to guard against negative input for sqrt, result of n^2 always positive
  return sqrt(pow(x, POWER) + pow(y, POWER) + pow(z, POWER));
}

std::ostream& operator<<(std::ostream& ostr, const Vector3dStack& vector) {
  ostr << "(x,y,z): (" << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << ")";
  return ostr;
}

Vector3dStack Vector3dStack::add(const Vector3dStack& rhs) const {
  return Vector3dStack(x + rhs.get_x(), y + rhs.get_y(), z + rhs.get_z());
}

Vector3dStack Vector3dStack::operator+(const Vector3dStack& rhs) const {
  return add(rhs);
}

Vector3dStack Vector3dStack::subtract(const Vector3dStack& rhs) const {
  return Vector3dStack(x - rhs.get_x(), y - rhs.get_y(), z - rhs.get_z());
}

Vector3dStack Vector3dStack::operator-(const Vector3dStack& rhs) const {
  return subtract(rhs);
}

Vector3dStack Vector3dStack::multiply(const float scalar) const {
  return Vector3dStack(x*scalar, y*scalar, z*scalar);
}

Vector3dStack Vector3dStack::operator*(const float scalar) const {
  return multiply(scalar);
}

Vector3dStack Vector3dStack::divide(const float scalar) const {
  // TODO: guard against divide by 0?
  return Vector3dStack(x/scalar, y/scalar, z/scalar);
}

Vector3dStack Vector3dStack::operator/(const float scalar) const {
  return divide(scalar);
}

Vector3dStack Vector3dStack::vector_product(const Vector3dStack& rhs) const {
  return Vector3dStack(
    y*rhs.get_z() - z*rhs.get_y(),
    z*rhs.get_x() - x*rhs.get_z(),
    x*rhs.get_y() - y*rhs.get_x()
  );
}

Vector3dStack Vector3dStack::operator%(const Vector3dStack& rhs) const {
  return vector_product(rhs);
}

float Vector3dStack::scalar_product(const Vector3dStack& rhs) const {
  return (float)((x * rhs.get_x()) + (y * rhs.get_y()) + (z * rhs.get_z()));
}

float Vector3dStack::operator*(const Vector3dStack& rhs) const {
  return scalar_product(rhs);
}

Vector3dStack Vector3dStack::unit_vector() const {
  // TODO: guard against divide by 0?
  return Vector3dStack(
    x/magnitude(),
    y/magnitude(),
    z/magnitude()
  );
}

Vector3dStack Vector3dStack::unit_vector_orthogonal(const Vector3dStack& rhs) const {
  return vector_product(rhs).unit_vector();
}
